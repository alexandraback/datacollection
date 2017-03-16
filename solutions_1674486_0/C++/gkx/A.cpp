#include <vector>
#include <valarray>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <algorithm>
#include <sstream>
#include <bitset>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <cstring>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cfloat>
#include <complex>
using namespace std;

int G[2000][2000];
int color[1000];
bool flag = false;
//void DFS(int cur, int pre) {
//    if(color[cur]==1) {
//        toBeRemoved.push_back(make_pair(cur,pre));
//    }
//    else if(!color[cur]) {
//        color[cur]=1;
//        int a=E[cur].size();
//        for(int i=0; i<a; ++i)
//            DFS(E[cur][i], cur);
//        color[cur]=2;
//        T.push_back(cur);
//    }
//}

bool Dfs(int cur, int N) {
    if(color[cur]!=0)
        flag = true;
    else {
        color[cur] = 1;
        for (int i = 0; i < N; ++i) {
            if(G[cur][i]==1)
                Dfs(i, N);
        }
        color[cur] = 2;
    }
 }


int main(){
	
	freopen("input.txt","rt",stdin);
    freopen("out.txt","wt",stdout);
    
    string line;
    int i,j,k,l,temp;
    int t, N, M;
	cin>>t;

	for ( k=1; k<=t; k++){
        flag = false;

        cin>>N;

        for(int i=0; i< N; i++) {
          for (int j = 0; j < N; ++j) {
                G[i][j] = 0;
          }
        }


        for (int i = 0; i < N; ++i) {
            cin>>M;
            for (int j = 0; j < M; ++j) {
                cin>>temp;
                G[i][temp-1] = 1;
            }
        }

//            cout<<endl;
//        }

        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < 1000; ++j) {
                color[j] = 0;
            }
            Dfs(i,N);
        }

        if(flag)
            cout<<"Case #"<<k<<": Yes"<<endl;
        else
            cout<<"Case #"<<k<<": No"<<endl;

    }
	


	return 0;
	
}
		
			
			
			
			
			
			

        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
