#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<set>
#include<cmath>
#include<bitset>
#define rep(i,a,b) for(int i=a,_b=b;i<=_b;i++)
#define per(i,a,b) for(int i=a,_b=b;i>=_b;i--)
#define For(i,b) for(int i=0,_b=b;i<_b;i++)
#define upmax(a,b) if ((a)<(b)) (a)=(b)
#define upmin(a,b) if ((a)>(b)) (a)=(b)
using namespace std;

string s;
int T,x,minx,top,eed,g[120];
char c,a[5000];

void put1(char c){
    For(i,26) if (g[i]!=-1) g[i]++;
    g[c-'A']=0;
    a[--top]=c;
}

void put2(char c){
    if (g[c-'A']==-1) g[c-'A']=eed-top+1;
    a[++eed]=c;
}

int main(){
//freopen("A.in","r",stdin);
//freopen("A.out","w",stdout);
    cin>>T;
    rep(ca,1,T){
        cin>>s;
        For(i,26) g[i]=-1;
        top=eed=2000;
        For(ii,s.size()){
            c=s[ii];
            if (!ii){
                a[top]=c;
                g[c-'A']=0;
                continue;
            }
            if (c>a[top]) put1(c);
            else if (c<a[top]) put2(c);
            else{
                x=-1; minx=12000;
                For(i,26) if (g[i]!=-1 && g[i]!=0 && g[i]<minx){ x=i; minx=g[i]; }
                if (x==-1) put2(c);
                else if (c>'A'+x) put1(c);
                else put2(c);
            }
        }
        cout<<"Case #"<<ca<<": ";
        rep(i,top,eed) cout<<a[i];cout<<endl;
    }
}