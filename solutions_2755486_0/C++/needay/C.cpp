#include <iostream>
#include <fstream>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;

int T;

long long wall[600];
int pos = 300;

class Tribe {
public:
    int d;
    int n;
    int curn;
    int w;
    int e;
    long long s;
    int d_d;
    int d_p;
    long long d_s;
    Tribe(int d,int n,int w,int e,long long s,int d_d,int d_p,long long d_s) {
        curn = 0;
        Tribe::d = d;
        Tribe::n = n;
        Tribe::w = w;
        Tribe::e = e;
        Tribe::s = s;
        Tribe::d_d = d_d;
        Tribe::d_p = d_p;
        Tribe::d_s = d_s;
    }
    
    bool next() {
        curn++;
        if(curn >= n) return false;
        d += d_d;
        s += d_s;
        w += d_p;
        e += d_p;
        return true;
    }
};

bool operator< (Tribe a,Tribe b) {
    return a.d > b.d;
}

void raise(int start,int end,long long s) {
    for(int i = start + pos; i <= end + pos; i++) {
        if(wall[i] < s) {
            wall[i] = s;
        }
    }
}

bool attack(int start,int end,long long s) {
    //cout << "HIT" << start << " " << end << endl;
    for(int i = start + pos; i <= end + pos; i++) {
        if(wall[i] < s) {
            return true;
        }
    }
    return false;
}

int main(int argc, char* argv[]) {
    ifstream fin(argv[1]);
    ofstream fout(argv[2]);
    
    fin >> T;
    
    for(int ct = 1; ct <= T; ct++) {
        memset(wall,0,sizeof(wall));
        int N = 0;
        fin >> N;
        priority_queue<Tribe> triq;
        
        int d,n,w,e,d_p,d_d;
        long long s,d_s;
        for(int i = 0; i < N; i++) {
            fin >> d >> n >> w >> e >> s >> d_d >> d_p >> d_s;
            Tribe tribe(d,n,w,e-1,s,d_d,d_p,d_s);
            triq.push(tribe);
        }
        int ans = 0;
        while(!triq.empty()) {
            vector<Tribe> tmp;
            int tmpd = triq.top().d;
            //cout << "DAY" << tmpd << endl;
            while(!triq.empty() && triq.top().d == tmpd) {
                tmp.push_back(triq.top());
                triq.pop();
            }
            for(int i = 0; i < tmp.size(); i++) {
                if(attack(tmp[i].w,tmp[i].e,tmp[i].s)) ans++;
            }
            for(int i = 0; i < tmp.size(); i++) {
                raise(tmp[i].w,tmp[i].e,tmp[i].s);
                if(tmp[i].next()) triq.push(tmp[i]);
            }   
        }
        
        fout << "Case #" << ct << ": " << ans << endl;
    }
    
    
    return 0;
}
