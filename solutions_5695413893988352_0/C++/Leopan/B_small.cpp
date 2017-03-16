#include<bits/stdc++.h>
#define X first
#define Y second
using namespace std;
typedef pair<int,int> pii;
char a[20],b[20];
int la,lb;
pii ans;
void dfs(int nowa,int nowb,pii t){
    if(nowa==la&&nowb==lb){
        if(ans.first==-1)ans=t;
        else if(abs(t.X-t.Y)<abs(ans.X-ans.Y)||abs(t.X-t.Y)<abs(ans.X-ans.Y)&&ans>t)ans=t;
        return;
    }
    if(nowa<la){
        if(a[nowa]!='?')dfs(nowa+1,nowb,make_pair(t.first*10+a[nowa]-'0',t.second));
        else{
            for(int i=0;i<10;i++){
                dfs(nowa+1,nowb,make_pair(t.first*10+i,t.second));
            }
        }
    }
    else{
        if(b[nowb]!='?')dfs(nowa,nowb+1,make_pair(t.first,t.second*10+b[nowb]-'0'));
        else{
            for(int i=0;i<10;i++){
                dfs(nowa,nowb+1,make_pair(t.first,t.second*10+i));
            }
        }
    }
}
int main(){
    freopen("B-small-attempt0.in","r",stdin);
    freopen("B-small-attempt0.out","w",stdout);
    int T,Case=0;
    scanf("%d",&T);
    while(T--){
        scanf("%s%s",a,b);
        la=strlen(a),lb=strlen(b);
        ans=make_pair(-1,-1);
        dfs(0,0,make_pair(0,0));
        int ta=0,tb=0;
        while(la){
            a[ta++]=ans.X%10+'0';
            ans.X/=10;
            la--;
        }
        while(lb){
            b[tb++]=ans.Y%10+'0';
            ans.Y/=10;
            lb--;
        }

        printf("Case #%d: ",++Case);
        for(int i=ta-1;i>=0;i--)printf("%c",a[i]);
        printf(" ");
        for(int i=tb-1;i>=0;i--)printf("%c",b[i]);
        printf("\n");
    }
    return 0;
}
