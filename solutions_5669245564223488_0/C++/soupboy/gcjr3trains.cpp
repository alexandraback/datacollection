#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <string.h>
#include <climits>

#define repx(i,x,n) for(int i=x;i<n;i++)
#define rep(i,n) repx(i,0,n)
#define pb push_back
#define full(v)	v.begin(),v.end()
#define VI vector<int>
#define VS vector<string>
#define LL long long
using namespace std;

int main()
{
    ifstream cin("trainsmall.in");
    ofstream cout("trainsmallout.txt");
    int test,cas=0;
    cin>>test;
    while(test-- && ++cas)
    {

        int n;
        cin>>n;
        VI v;
        rep(i,n)
        v.pb(i);
        int ret =0;
        VS s;
        rep(i,n)
        {
            string temp;cin>>temp;s.pb(temp);
        }
        int betw[27] = {0};
        bool noway = false;
        rep(i,s.size())
        {

          string cur = s[i];
          int ins[27]={0};
          rep(j,cur.size())
          {
             char c = cur[j];
             if(ins[c - 'a'])
             {
                 noway = true;
                 i=s.size();
                 break;
             }
             ins[c - 'a'] = 1;
             if(betw[c - 'a'])
             {
                 noway = true;
                 i=s.size();
                 break;
             }
             int k;
             for(k=j; k<cur.size() && cur[k] == c ; k++);
             if(j!=0 && k!= cur.size())
                betw[c - 'a'] = 1;
             j = k-1;

          }
        }
        if(noway)
        {
                cout<<"Case #"<<cas<<": 0"<<"\n";
                continue;
        }

        do
        {
            int vis[27] = {0};
            string prev = s[v[0]];
            vis[prev[0] - 'a' ] = 1;
            vis[prev[prev.size()-1] - 'a'] =1;
            bool b = true;
            repx(i,1,v.size())
            {
                string curstr = s[v[i]];
                if( curstr[0] == prev[prev.size()-1] && curstr[0] == curstr[curstr.size()-1])
                    continue;
                if(curstr[0] != prev[prev.size()-1] )
                {
                    if( vis [curstr[0] - 'a'] )
                    {
                        b=false;
                        break;
                    }
                     vis [curstr[0] - 'a'] =1;
                }
                if( (curstr[0] != curstr[curstr.size()-1]) && vis[ curstr[curstr.size()-1] - 'a'  ])
                {
                    b=false;
                    break;
                }
                vis[ curstr[curstr.size()-1] - 'a'  ] = 1;
                prev = curstr;
            }
            if(b)
                ret++;
        }while(next_permutation(v.begin(),v.end()));
        cout<<"Case #"<<cas<<": "<<ret<<"\n";

    }
    return 0;
}
