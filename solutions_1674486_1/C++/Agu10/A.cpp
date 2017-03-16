#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <stack>
#include <queue>
#include <algorithm>

using namespace std;

#define forn(i,n) for(int i=0; i<n; i++)
#define dbg(n) cout<<#n<<": "<<n<<endl;
#define mp make_pair


bool dfs(int N, vector<int>* inheritance, bool* taken)
{
     for(int first = 1; first<=N; first++)
     {
         if(taken[first]) continue;
         
         stack<int> pila;
         bool used[N+1];
         memset(used, 0, N+1);
         
         pila.push(first);
         used[first]=true;
         taken[first]=true;
         
         while(!pila.empty())
         {
          int n = pila.top();
          pila.pop();       
          forn(i, inheritance[n].size())
          {
           int c = inheritance[n][i];
           if(!used[c])
           {
            pila.push(c);
            used[c]=true;   
            taken[c]=true;         
           }else
           {
            return true;     
           }        
          }             
         }
     }
     
     
     return false;
}

int main()
{
    ifstream input("A.in");
    ofstream output("A.out");
    
    int T;
    input>>T;
    forn(t, T)
    {
     int N;
     input>>N;
     
     vector<int> inheritance[N+1];
     bool taken[N+1];
     memset(taken, 0, N+1);
     
     forn(i, N)
     {
      int M;
      input>>M;
      inheritance[i+1].resize(M);
      forn(j, M)
      {
       input>>inheritance[i+1][j];
      }        
     }
     bool can = dfs(N, inheritance, taken);
     
     output<<"Case #"<<t+1<<": "<<(can?"Yes":"No")<<endl;     
     cout<<"Case #"<<t+1<<": "<<(can?"Yes":"No")<<endl;
    }
    cout<<"FINISHED"<<endl;
    cin.get();
    
}
