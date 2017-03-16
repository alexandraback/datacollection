#include<fstream>
#include<queue>
#include<string>
using namespace std;

ifstream fin("kingdom.in");
ofstream fout("kingdom.out");

int T, N;
int a[1005], b[1005];
int s[1005];

int main()
{
    fin >> T;
    for(int t=0; t<T; t++){
        fin >> N;
        
        priority_queue<pair<int, int> > pq1;
        priority_queue<pair<int, int> > pq2;
        
        int f = 0, p = 0, got = 0;
        for(int i=0; i<N; i++){
            fin >> a[i] >> b[i];
            s[i] = 0;
            pq1.push(pair<int,int>(-1*(2002*a[i]+(2001-b[i])), i));
            pq2.push(pair<int,int>(-1*b[i], i));
        }
        while(f<N){
            if(!pq2.empty())
            if((-1*pq2.top().first) <= got){
                got += 2-s[pq2.top().second];
                s[pq2.top().second] = 2;
                f++;
                p++;
                pq2.pop();
                continue;
            }
            if(!pq1.empty())
            if((-1*pq1.top().first/2002) <= got){
                if(s[pq1.top().second]>0);
                else{
                    got += 1;
                    s[pq1.top().second] = 1;
                    p++;
                }
                pq1.pop();
                continue;
            }
            break;
        }
        fout << "Case #" << t+1 << ": ";
        if(f!=N) fout << "Too bad" << endl;
        else fout << p << endl;
    }
    return 0;
}
