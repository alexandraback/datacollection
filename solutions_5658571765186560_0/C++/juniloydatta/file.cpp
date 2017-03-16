#include<bits/stdc++.h>

#define xx first
#define yy second
#define LL long long
#define inf 100000000
#define pb push_back
#define vsort(v) sort(v.begin(),v.end())
#define pi acos(-1)
#define clr(a,b) memset(a,b,sizeof a)
#define bclr(a) memset(a,false,sizeof a)
#define pii pair<int,int>
#define MOD 1000000007
#define MP make_pair
#define MX 10000000

using namespace std;
int mat[6][6];
void pre(){
    mat[1][1]=1;
    mat[1][2]=2;
    mat[1][3]=3;
    mat[1][4]=4;

    mat[2][1]=2;
    mat[2][2]=-1;
    mat[2][3]=4;
    mat[2][4]=-3;

    mat[3][1]=3;
    mat[3][2]=-4;
    mat[3][3]=-1;
    mat[3][4]=2;

    mat[4][1]=4;
    mat[4][2]=3;
    mat[4][3]=-2;
    mat[4][4]=-1;
}
int ar[10004];
pii P[10004];

int main(){
    freopen("fileIN.in","r",stdin);
    freopen("fileOUT.out","w",stdout);
    pre();
    int test;
    cin>>test;
    for(int kase=1;kase<=test;kase++){
        int L,X;
        string s;
        cin>>L>>X>>s;
        string ss=s;
        for(int i=1;i<X;i++) s+=ss;
        L*=X;
        for(int i=1;i<=L;i++){
            if(s[i-1]=='i') ar[i]=2;
            else if(s[i-1]=='j') ar[i]=3;
            else ar[i]=4;
        }
        P[0]=MP(1,1);
        int cnt=0;
        for(int i=1;i<=L;i++){
            int now=mat[P[i-1].xx][ar[i]];
            now*=P[i-1].yy;
            if(now<0) P[i]=MP(abs(now),-1);
            else P[i]=MP(now,1);
            if(P[i].yy==1){
                if(cnt==0 && P[i].xx==2) cnt++;
                else if(cnt==1 && P[i].xx==4) cnt++;
            }
        }
        if(cnt==2 && P[L].yy==-1 && P[L].xx==1) cnt++;
        if(cnt==3) cout<<"Case #"<<kase<<": YES"<<endl;
        else cout<<"Case #"<<kase<<": NO"<<endl;
    }
    return 0;
}
