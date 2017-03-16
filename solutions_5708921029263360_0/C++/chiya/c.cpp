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

int n,T,ans,now,A,B,C,K,tot,cnt1[10][10],cnt2[10][10],cnt3[10][10];
struct node{
    int a,b,c;
    bool operator <(const node& f)const{
        return a<f.a||(a==f.a && b<f.b)||(a==f.a && b==f.b && c<f.c);
    }
}a[1000],ANS[1000],li[1000];

void dfs(int p){
    if (p>n){
        now=tot;
        if (now>ans){
            ans=now;
            rep(i,1,ans) ANS[i]=li[i];
        }
        return;
    }
    int i=p;

        li[++tot]=a[i];
        cnt1[a[i].a][a[i].b]++;
        cnt2[a[i].a][a[i].c]++;
        cnt3[a[i].b][a[i].c]++;
        if (cnt1[a[i].a][a[i].b]>K || cnt2[a[i].a][a[i].c]>K || cnt3[a[i].b][a[i].c]>K){
            now=tot-1;
            if (now>ans){
                ans=now;
                rep(i,1,ans) ANS[i]=li[i];
            }
        }
        else dfs(p+1);
        tot--;
        cnt1[a[i].a][a[i].b]--;
        cnt2[a[i].a][a[i].c]--;
        cnt3[a[i].b][a[i].c]--;
        dfs(p+1);
}

int main(){
freopen("C.in","r",stdin);
freopen("C.out","w",stdout);
    cin>>T;
    rep(ca,1,T){
        cin>>A>>B>>C>>K;
        n=0;
        rep(i,1,A) rep(j,1,B) rep(k,1,C){
            a[++n].a=i;
            a[n].b=j;
            a[n].c=k;
        }
        ans=0;
        dfs(1);
        /*do{
            now=n;
            rep(i,1,n){
                if (++cnt[a[i].a][a[i].b]>K){
                    now=i-1;
                    break;
                }
            }
            rep(i,1,A) rep(j,1,B) cnt[i][j]=0;

            rep(i,1,n){
                if (++cnt[a[i].a][a[i].c]>K){
                    now=min(now,i-1);
                    break;
                }
            }
            rep(i,1,A) rep(j,1,C) cnt[i][j]=0;

            rep(i,1,n){
                if (++cnt[a[i].b][a[i].c]>K){
                    now=min(now,i-1);
                    break;
                }
            }
            rep(i,1,B) rep(j,1,C) cnt[i][j]=0;

            if (now>ans){
                ans=now;
                rep(i,1,ans) ANS[i]=a[i];
            }
        }while(next_permutation(a+1,a+n+1));*/

        cout<<"Case #"<<ca<<": "<<ans<<endl;
        rep(i,1,ans) cout<<ANS[i].a<<' '<<ANS[i].b<<' '<<ANS[i].c<<endl;
    }
}