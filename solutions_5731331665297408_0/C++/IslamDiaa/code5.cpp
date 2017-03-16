#include<iostream>
#include<string>
#include<vector>
using namespace std;

int T,N,M;
int w[105][105],in[105];
string codes[105];
vector<int> arr;
bool vis[105];
int turn;
void dfs(int idx)
{
     while(1)
     {
             if(turn == N)
                     return;
             int cur = arr[idx];
             int com = arr[turn];
             if(w[cur][com] == 1)
             {
                    dfs(turn++);
             }
             else
                 break;  
     }  
}

bool check()
{
     turn = 1;
     memset(vis,0,sizeof vis);
     dfs(0);
     return turn == N;
}

int main()
{
    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
    cin >> T;
    int t = 1;
    while(T--)
    {
              memset(w,0,sizeof w);
              memset(in,0,sizeof in);
              arr.clear();
              cin >> N >> M;
              for(int i = 0 ; i < N; i++)
              {
                      cin >> codes[i];
                      arr.push_back(i);
              }
              while(M--)
              {
                        int a,b;
                        cin >> a >> b;
                        w[a-1][b-1] = w[b-1][a-1] = 1;
              }            
              string ans = "";
              do
              {
                           if(check())
                           {
                              string tmp;
                              for(int i = 0 ; i < N; i++)
                                      tmp += codes[arr[i]]; 
                              if(ans.size() == 0 || tmp < ans)
                                            ans = tmp;                        
                           }
              }
              while(next_permutation(arr.begin(),arr.end()));
              cout << "Case #"<<t++<<": "<< ans << endl;
    }
}
