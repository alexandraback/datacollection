/*
  ------ HachiInfinity ------
  ------ Worrachate Bosri ------
  ------ Mahidol Wittayanusorn ------
*/
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>
#include<set>
#include<map>
#include<string>
#include<utility>

using namespace std;
#define FOR(i,ST,FN) for(int i=ST;i<FN;i++)
#define FOR2(x) for(it=x.begin();it!=x.end();it++)
#define mod
#define inf
#define PAUSE system("pause")
#define S scanf
#define P printf
#define MAXN

int n,m;
int ans,sum,tmp;
int MAX,MIN;

char a[110],b[30]={"yhesocvxduiglbkrztnwjpfmaq"};

int main(){

    freopen("A-small-attempt0.in","r",stdin);
    freopen("ppp","w",stdout);

    S("%d",&n);
    for(int k=1;k<=n;k++)
    {
     S(" ");
     gets(a);
     int l=strlen(a);
     P("Case #%d: ",k);
     FOR(i,0,l)
     {
      if(a[i]==' ') P(" ");
      else P("%c",b[a[i]-'a']);
     }
     P("\n");
    }
}
