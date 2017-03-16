#include<bits/stdc++.h>
using namespace std;
#define V 6
int countwalks(int graph[][V], int u, int v, int k, int N ) {
    int count[V][V][k+1];
 for (int e = 0; e <= k; e++)  {
        for (int i = 0; i < N ; i++)  {
            for (int j = 0; j < N; j++) {
                count[i][j][e] = 0;
                if (e == 0 && i == j)
                    count[i][j][e] = 1;
                if (e == 1 && graph[i][j])
                    count[i][j][e] = 1;
       if (e > 1)  {
                    for (int a = 0; a < V; a++)
                        if (graph[i][a])
                            count[i][j][e] += count[a][j][e-1];
                }
           }
        }
    }
    int ans = 0;
    for(int i = 0 ; i <= k ; ++i )
    ans += count[u][v][i];
    return ans;
}
int main(){

  ifstream cin("a.txt");
     ofstream cout("b.txt");
     int t , tt = 1;
     cin >> t;
     while( t-- ){
        int B , M;
        cin >> B >> M;
        int flag = 0;
         vector< pair< int, int > > v;
         for( int i = 1; i <= B ; ++i ){
            for(int j = i + 1 ; j <= B ; ++j ){
              v.push_back(make_pair(i,j));
               if( j  != B )
              v.push_back(make_pair(j,i));
            }
         }
         int sz = v.size();
         for(int i = 0 ; i < (1<<sz) ; ++i ){
               int graph[6][6] = {0};
               for(int j = 0 ; j < sz; ++j ){
                 if((i >> j ) & 1 )
                   graph[v[j].first-1][v[j].second-1] = 1;
               }
               int val = countwalks(graph, 0 , B -1 , 2 * B , B );
               if(val == M ){
               cout << "Case #"<<tt++<<": POSSIBLE" << endl;
                for(int k = 0 ; k < B ; ++k ){
                 for(int l = 0 ; l < B ; ++l )
                 cout << graph[k][l];
                 cout << endl;
                }
                flag = 1;
                break;
               }
         }
         if(!flag)
         cout << "Case #"<<tt++<<": IMPOSSIBLE" << endl;
     }
}
