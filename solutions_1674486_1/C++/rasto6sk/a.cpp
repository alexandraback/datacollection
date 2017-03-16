#include<iostream>
#include<vector>
#include<map>
#include<string>
#include<sstream>
#include<cmath>
#include<algorithm>
#include<deque>
#include<set>
using namespace std;
#define ll long long
#define VI vector<ll>
#define VS vector<string>
#define PI pair<int,int>
#define MP make_pair
#define PB push_back

int main() {
    int T; cin >> T;
    for (int t=0;t<T;t++) {
        cout<<"Case #"<<t+1<<": ";
        int n;
        cin>>n;
        vector<VI> e = vector<VI>(n,VI(0,0));
        vector<VI> ie = e;
        VI roots;
        for (int i=0;i<n;i++) {
            int m;
            cin>>m;
            
            for (int j=0;j<m;j++) {
                int x; cin>>x; x--;
                e[i].PB(x);
                ie[x].PB(i);
            }
        }
        for (int i=0;i<n;i++) if (ie[i].size()==0) roots.PB(i);

            bool diamond = false;

        for (int r=0;r<roots.size();r++) {
            deque<int> q;
            q.PB(roots[r]);
            VI visited = VI(n,0);
            visited[roots[r]] = 1;
            while (q.size()>0) {
                int akt = q.front();q.pop_front();
                for (int j=0;j<e[akt].size();j++) if (visited[e[akt][j]]==0) {
                    visited[e[akt][j]] = 1;
                    q.PB(e[akt][j]);
                }
            }
            for (int i=0;i<n&&!diamond;i++) {
                int sum =0;
                for (int j=0;j<ie[i].size();j++) {
                    sum+=visited[ie[i][j]];
                }
                if (sum>1) diamond = true;
            } 
        }
            if (diamond) cout<<"Yes"<<endl; else cout<<"No"<<endl;

        
    
    }
}
