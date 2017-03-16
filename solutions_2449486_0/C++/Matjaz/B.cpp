#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <string.h>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
using namespace std; 

int T;

int a[105][105];
int s[105];
int b[105];
int n,m;


bool solve(){
     scanf("%d %d",&n,&m);
     for (int i=0;i<n;i++)
     for (int j=0;j<m;j++) scanf("%d",&a[i][j]);
     memset(b,0,sizeof b);
     memset(s,0,sizeof s);
     for (int i=0;i<n;i++){
         for (int j=0;j<m;j++) s[i]=max(s[i],a[i][j]);
         }
     for (int j=0;j<m;j++){
         for (int i=0;i<n;i++) b[j]=max(b[j],a[i][j]);
         }
     for (int i=0;i<n;i++)
     for (int j=0;j<m;j++){
         if (a[i][j]<s[i]&&a[i][j]<b[j]) return false;
         }
     
     return true;
     }

int main(){
    scanf("%d",&T);
    for (int i=0;i<T;i++){
        if (solve()) printf("Case #%d: YES\n",i+1); else printf("Case #%d: NO\n",i+1);
        }
    return 0;
    }
