/**
 * @author neko01
 */
//#pragma comment(linker, "/STACK:102400000,102400000")
#include <cstdio>
#include <cstring>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <cmath>
#include <set>
#include <map>
using namespace std;
typedef long long LL;
#define min3(a,b,c) min(a,min(b,c))
#define max3(a,b,c) max(a,max(b,c))
#define pb push_back
#define mp(a,b) make_pair(a,b)
#define clr(a) memset(a,0,sizeof a)
#define clr1(a) memset(a,-1,sizeof a)
#define dbg(a) printf("%d\n",a)
typedef pair<int,int> pp;
const double eps=1e-9;
const double pi=acos(-1.0);
const int INF=0x3f3f3f3f;
const LL inf=(((LL)1)<<61)+5;
const int N=81005;
char s[N];
int pre[N];
int next[N];
int a[300][300];
int l;
LL x;
bool gao()
{
    for(int i=0;i<x;i++)
        for(int j=1;j<=l;j++)
            s[i*l+j]=s[j];
    int cao=1,i=1;
    for(i=1;i<=l*x;i++){
        cao=cao>0?a[cao][s[i]]:-1*a[-cao][s[i]];
        if(cao=='i') break;
    }
    if(i>l*x) return false;
    cao=1;
    for(i++;i<=l*x;i++){
        cao=cao>0?a[cao][s[i]]:-1*a[-cao][s[i]];
        if(cao=='j') break;
    }
    if(i>l*x) return false;
    cao=1;
    for(i++;i<=l*x;i++){
        cao=cao>0?a[cao][s[i]]:-1*a[-cao][s[i]];
    }
    if(cao=='k') return true;
    else return false;
}
int cheng(int x,int y)
{
    if(x>0&&y>0) return a[x][y];
    if(x<0&&y<0) return a[-x][-y];
    if(x<0) x=-x;
    if(y<0) y=-y;
    return -1*a[x][y];
}
int fuck(LL y)
{
    int tmp=y%4;
    if(tmp==1) return pre[l];
    if(tmp==2) return cheng(pre[l],pre[l]);
    if(tmp==3) return cheng(cheng(pre[l],pre[l]),pre[l]);
}
int main()
{
    int t,cnt=0;
    freopen("C-small-attempt2.in" , "r" , stdin);
    freopen("C-small-attempt2.out" , "w" , stdout);
    scanf("%d",&t);
    a[1][1]=1,a[1]['i']='i',a[1]['j']='j',a[1]['k']='k';
    a['i'][1]='i',a['i']['i']=-1,a['i']['j']='k',a['i']['k']='j'*-1;
    a['j'][1]='j',a['j']['i']='k'*-1,a['j']['j']=-1,a['j']['k']='i';
    a['k'][1]='k',a['k']['i']='j',a['k']['j']='i'*-1,a['k']['k']=-1;
    while(t--){
        scanf("%d%lld",&l,&x);
        scanf("%s",s+1);
        if(x<=8){
            if(gao())
                printf("Case #%d: YES\n",++cnt);
            else printf("Case #%d: NO\n",++cnt);
            continue;
        }
       /* for(int i=1;i<=3;i++)
            for(int j=1;j<=l;j++)
                s[i*l+j]=s[j];
        pre[0]=1,next[4*l+1]=1;
        int iflag=-1,kflag=-1;
        for(int i=1;i<=4*l;i++){
            pre[i]=pre[i-1]>0?a[pre[i-1]][s[i]]:-1*a[-1*pre[i-1]][s[i]];
            if(pre[i]=='i'&&iflag==-1)
                iflag=i;
        }
        for(int i=4*l;i>0;i--){
            next[i]=next[i+1]>0?a[s[i]][next[i+1]]:-1*a[s[i]][-1*next[i+1]];
            if(next[i]=='k'&&kflag==-1)
                kflag=i;
        }
        if(iflag==-1||kflag==-1){
            printf("Case #%d: NO\n",++cnt);
            continue;
        }
        int l1=(iflag-1)/l+1,l2=(4*l-kflag)/l+1;
        LL sum=x-l1-l2;
        int tmp=fuck(sum);
        if(iflag%l==0) iflag=l;
        else iflag%=l;
        if(kflag%l==0) kflag=l;
        else kflag%=l;
        int tmp1=next[3*l+iflag+1];
        int tmp2=pre[kflag-1];
        int ans=cheng(tmp,tmp1);
        ans=cheng(ans,tmp2);*/
        for(int i=1;i<=7;i++)
            for(int j=1;j<=l;j++)
                s[i*l+j]=s[j];
        int iflag=-1,kflag=-1,now=1;
        pre[0]=1;
        for(int i=1;i<=8*l;i++){
            now=cheng(now,s[i]);
            pre[i]=now;
            if(now=='i'&&iflag==-1){
                iflag=i;
            }
        }
        now=1;
        for(int i=8*l;i>0;i--){
            now=cheng(s[i],now);
            if(now=='k'){
                kflag=i;
                break;
            }
        }
       // cout<<iflag<<" "<<kflag<<endl;
        if(iflag==-1||kflag==-1){
            printf("Case #%d: NO\n",++cnt);
            continue;
        }
        int ans=1;
        if(iflag%l!=0)
        {
            for(int i=iflag+1;i<=8*l;i++){
                ans=cheng(ans,s[i]);
                if(i%l==0){
                    iflag=i;
                    break;
                }
            }
        }
      //  cout<<ans<<endl;
        ans=cheng(ans,fuck(x-8));
       // cout<<ans<<endl;
        for(int i=iflag+1;i<kflag;i++)
            ans=cheng(ans,s[i]);
       // cout<<ans<<int('j')<<endl;
        if(ans=='j')
            printf("Case #%d: YES\n",++cnt);
        else printf("Case #%d: NO\n",++cnt);
    }
    return 0;
}
