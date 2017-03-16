#include<iostream>
#include<iomanip>
#include<fstream>
#include<vector>
#include<algorithm>
using namespace std;

static const int KEYNUM = 40;
static const int BOXNUM = 20;

struct Box {
    int lock;
    vector<int> keys;
    Box::Box() : lock(-1), keys(KEYNUM) {}
};

int own[KEYNUM];
vector<Box> boxes;


struct solution {
    int ok;
    unsigned long long prev;
    int box;
};

static const unsigned long long MAX = (1u<<BOXNUM);
solution ans[MAX];

int K;
int N;

void reset()
{
    memset(own, 0, sizeof(int) * KEYNUM);
    boxes.clear();
    unsigned long long n = (1u<<N);
    for (unsigned long long i=0; i<n; i++)
        ans[i].ok=0;
}

int comp(unsigned long long p1, unsigned long long p2)
{
    if (p1==p2)
        return 0;

    int ret = comp(ans[p1].prev, ans[p2].prev);
    if (ret == 0)
        return ans[p1].box < ans[p2].box? -1: 1;
    else
        return ret;
}

void solve(unsigned long long n)
{
//    if (ans[n].ok==1)
//        return;

    int savebox = -1;
    unsigned long long saveprev = 0;

    ans[n].ok=-1;
    for(int i=N-1; i>=0; i--){
        unsigned long long boxBit = (1u<<i);
        if (n&boxBit) {
            unsigned long long m = (n&(~boxBit));
            if (ans[m].ok==0)
                solve(m);
            if (ans[m].ok==1) {
                int needKey = boxes[i].lock;
                int have = own[needKey];
                for (int j=0; j<N; j++) {
                    unsigned long long b = (1u<<j);
                    if (m&b) {
                        have += boxes[j].keys[needKey];
                        if (boxes[j].lock==needKey)
                            have--;
                    }
                }
                if (have>0) {
                    ans[n].ok = 1;
                    ans[n].prev = m;
                    ans[n].box = i;
                    
                    if (savebox < 0 || (comp(m, saveprev)==-1)) {
                        savebox = i;
                        saveprev = m;
                    }
                }
            }
        }
    }

    if (ans[n].ok==1) {
        ans[n].prev = saveprev;
        ans[n].box = savebox;
    }
}

int main(){

    ifstream infile("file.in");
    ofstream outfile("file.out");

    int T;
    infile>>T;

    for (int t=0; t<T; t++){
        infile>>K>>N;

        reset();

        for(int i=0; i<K; i++) {
            int k;
            infile>>k;
            own[k-1]++;
        }

        for(int i=0; i<N; i++) {            
            boxes.push_back(Box());
            int k;
            infile>>k;
            boxes.back().lock = k-1;
            int n;
            infile>>n;
            for (int j=0; j<n; j++) {
                infile>>k;
                boxes.back().keys[k-1]++;
            }
        }

//for(int i=0; i<5; i++)
//cout<<"own "<<k<<' '<<own[k];


        ans[0].ok=1;
        
        unsigned long long target = ((1u<<N) -1);
        solve(target);
        outfile<<"Case #"<<t+1<<": ";
        if (ans[target].ok==-1)
            outfile<<"IMPOSSIBLE"<<endl;
        else {
            unsigned long long cur = target;
            vector<int> result;
            while (cur!=0) {
                result.push_back(ans[cur].box+1);
                cur = ans[cur].prev;
            }
            for (int i=result.size()-1; i>=0; i--) {
                outfile<<result[i];
                if (i>0)
                    outfile<<' ';
            }
            outfile<<endl;
        }
    }

}
    
