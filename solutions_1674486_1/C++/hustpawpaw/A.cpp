#include<iostream>
bool flag;
int t,n;
int father[2000][2000];
int node[2000];
using namespace std;
void solve(int i)
{
  if (flag)
     return ;
     //   cout <<i << "aaa"<<father[i][0] <<endl;
  for (int j = 1; j <= father[i][0] ; ++j)
  {
   
      if (node[father[i][j]] == 1)
      {
         flag = true;
      }
      if (flag)
         return;
    //  cout << "ttt" << father[i][j] << endl;
      node[father[i][j]] = 1;
      solve(father[i][j]);
  }
}
int main()
{
    freopen("a.in","r",stdin);
    freopen("a.out", "w", stdout);
    cin  >> t; 
    for (int test = 1 ; test <= t; ++test)
    {
        cin >> n;
        for (int i = 1; i <= n; ++i)
        {
            cin >>father[i][0];
            for (int j = 1; j <= father[i][0]; ++j)
            cin >> father[i][j];
        }
      //  cout <<"start"<<endl;
    
      //  cout << "end" <<endl;
        flag = false;
        for (int i = 1; i <=n; ++i)
        {
            memset(node, 0 ,sizeof(node));
            node[i] = 1;
            solve(i);
          //  cout << i << endl;
            if (flag)
               break;
        }
         cout <<"Case #"<<test<<": ";
         if(flag)
             cout << "Yes" << endl;
         else
             cout << "No" << endl;
    }
    return 0;
}
