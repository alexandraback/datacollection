#include <iostream>
#include <cstdio>
#include <set>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

int main()
{
    freopen("A-small-attempt3.in","r",stdin);
    freopen("output.txt","w",stdout);
    int T;
    cin >> T;
    for(int qwe = 0; qwe < T;qwe ++){
      int a,n;
      set<int > inp;
      unordered_map<int,int> was;
      scanf("%d%d",&a,&n);
      int curpos=0;
      int num = n;
      for(int i = 0; i < n; i ++){
        int tmp;
        scanf("%d",&tmp);
        was[tmp]++;
        inp.insert(tmp);
        if(tmp < a){
            a += tmp;
            curpos ++;
            was[tmp]--;
            inp.erase(tmp);
            num --;
        }
      }
      while((*inp.begin() < a)&&(!inp.empty())){
          a += *inp.begin()*was[*inp.begin()];
          num -= was[*inp.begin()];

          was[*inp.begin()] =  0;
          inp.erase(inp.begin());
          if(inp.empty()){
            break;
          }
      }
      int step = 0;
      int ans=1000000;

      ans = min(ans,step+num);

      while((!inp.empty())&& (curpos+step<n)){
        step ++;
        inp.insert(a-1);
        was[a-1] ++;
        num ++;
        while(*inp.begin() < a){
          a += *inp.begin()*was[*inp.begin()];

          num -= was[*inp.begin()];
          was[*inp.begin()] =  0;
          inp.erase(inp.begin());

          if(inp.empty()){
            break;
          }
        }
        ans = min(ans,step+num);

      }
      printf("Case #%d: %d\n",qwe+1,ans);

    }
}
