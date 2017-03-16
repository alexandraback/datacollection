/* shivamrana */
#include <cassert>
#include <cctype>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <list>
#include <deque>
#include <stack>
#include <iterator>
#include <string>
#include <sstream>
#include <iostream>
#include <fstream>
#include <functional>
#include <numeric>
#include <algorithm>
#define f0r(i,n) for(int i=0;i<n;i++)
#define fOr(i,n) for(int i=1;i<=n;i++)
#define si(a) scanf("%d",&a)
#define sl(a) scanf("%I64d",&a)
#define pi(a) printf("%d",a)
#define pl(a) printf("%I64d",a)
#define n(l) cout<<endl
#define ll long long
#define mod 1000000007
#define vi vector<int>
#define pb(a) push_back(a)
using namespace std;
int grass[10][10];
int main(){
    freopen("lawn.in","r",stdin);
    freopen("lawn.out","w",stdout);
    int t,n,m,cs=1,c;
    bool flag;
    si(t);
    for(int cases=1;cases<=t;cases++){
        flag=true;
       cin>>n>>m;
        for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
        cin>>grass[i][j];
        for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)
        {
                if(grass[i][j]==1){
                    c=0;
                    
                    for(int k=0;k<n;k++)
                        if(grass[k][j]==2){
                            c++;
                            break;
                        }
                    for(int k=0;k<m;k++)
                        if(grass[i][k]==2){
                            c++;
                            break;
                        }
                    
                    if(c==2)
                        flag=false;
                }
                
            }
            if(!flag)
                break;
        }
        if(flag)
            printf("Case #%d: YES\n",cases);
        else
            printf("Case #%d: NO\n",cases);
    }
    return 0;
}
