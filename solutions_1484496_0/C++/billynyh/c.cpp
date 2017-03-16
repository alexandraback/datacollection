#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <math.h>
#include <vector>
#include <string>
#include <queue>
#include <iostream>
using namespace std;

bool fless(double a,double b){ return b-a>1e-6; }
bool fequal(double a,double b){ return fabs(b-a)<=1e-6; }

vector<pair<int,int> >S(1024*1024+10);

int main(){
    int tt; scanf("%d",&tt);
    for (int ti=1;ti<=tt;ti++){
        int n; scanf("%d", &n);
        int a[n];
        S.clear();
        for (int i=0;i<n;i++){
          scanf("%d", &a[i]);
        }
        int bn = 1<<n;
        for (int i=1;i<bn;i++){
          int sum = 0;
          for (int j=0;j<n;j++){
            if ((i>>j)&1){
              sum += a[j];
            }
          }
          S.push_back(make_pair(sum, i));
        }

        sort(S.begin(), S.end());
        //for (int i=0;i<bn;i++)printf("%d %x\n", S[i].first, S[i].second);

        int bit, bit2;
        bool done = false;
        for (int i=0;i<bn && !done;i++){
          int x = S[i].first;
          bit = S[i].second;
          for (int j=i+1;j<bn && !done && S[j].first==x;j++){
            if (bit & S[j].second){
              continue;
            }else{
              bit2 = S[j].second;
              //printf("sum %d\n", x);
              done = true;
            }
          }
        }

        printf("Case #%d:\n",ti);

        //printf("%x %x\n", bit, bit2);

        bool first = true;
        for (int i=0;i<n;i++){
          if ((bit>>i)&1){
            if (first){
              first=false;
            }else{
              printf(" ");
            }
            printf("%d", a[i]);
          }
        }
        puts("");

        first = true;
        for (int i=0;i<n;i++){
          if ((bit2>>i)&1){
            if (first){
              first=false;
            }else{
              printf(" ");
            }
            printf("%d", a[i]);
          }
        }
        puts("");

    }
    return 0;
}
