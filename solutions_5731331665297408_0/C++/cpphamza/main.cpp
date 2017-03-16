//Catch me if you can!
#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<deque>
#include<string>
#include<cctype>
#include<cmath>
#include<string>
#include<sstream>
#include<numeric>
#include<complex>
#include<queue>
#include<cassert>
using namespace std;

#define big long long
#define EPS 1e-9
#define s(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

const int SIZE = 200;
int N, M;
string zip[SIZE];
bool adj[SIZE][SIZE];


int main() {
    
    //freopen("/Users/hibrahim/workspace/contest/app/1.in", "rt", stdin);
    freopen("/Users/hibrahim/Downloads/C-small-attempt0.in", "rt", stdin);
    //freopen("/Users/hibrahim/Downloads/A-large.in", "rt", stdin);
    freopen("/Users/hibrahim/workspace/contest/app/app/1.out", "wt", stdout);

    int tt; cin >> tt;
    for(int t = 1 ; t <= tt ; t++){
        
        cin >> N >> M;
        cerr << t << " " << N << " " << M << endl;
        
        vector<int> v;
        for(int i = 0 ; i < N ; i++){
            cin >> zip[i];
            v.push_back(i);
        }
        memset(adj, 0, sizeof adj);
        
        for(int i = 0 ; i < M ; i++){
            int a, b; cin >> a >> b;
            a--; b--;
            adj[a][b] = adj[b][a] = true;
        }
        
        string best = "";
        do{
            map<int, int> back;

            string str = zip[v[0]];
            int current = v[0], i;
            back[current] = -1;
            for(i = 1 ; i < v.size() ; i++){
                
                bool outbound = false;
                while(true){
                    //outbound flight to next city
                    if(adj[current][v[i]]){
                        outbound = true;
                        back[v[i]] = current;
                        
                        current = v[i];
                        str += zip[v[i]];
                        outbound = true;
                        break;
                    }
                
                    //retreat using return flight
                    if(back.find(current) == back.end() || back[current] == -1)
                        break;
                    current = back[current];
                }
                
                if(!outbound)
                    break;
            }
            
            if(i == v.size()) {
                if(best.empty() || str < best)
                    best = str;
            }
            
            
        }while(next_permutation(v.begin(), v.end()));
        
        cout << "Case #" << t << ": " << best << endl;
    }
    
    return 0;
}

