#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<map>
#include<set>
#include<vector>

using namespace std;

typedef pair<int,int> pii;
typedef vector<pii> vii;
typedef vector<int> vi;

#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define DFOR(i,a,b) for(int i=a;i>=b;i--)
#define mp(x,y) make_pair((int)x,(int)y)
#define fi first
#define se second
#define all(a) (a).begin(),(a).end()
#define BUG(x) {cout << #x << " = " << x << endl;}
#define PR(x,a,b) {cout << #x << " = "; FOR(i,a,b) cout << x[i] << ' '; cout << endl;}
#define ll long long
#define DEBUG 1
#define nmax 200
#define mod 1000000007LL
int nTest;
int n;
char c[nmax][nmax];
char d[nmax];
ll ans;
char pre[300];
char ne[300];
void readInput(){
    scanf("%d\n",&n);
    //cout<<n<<endl;
    FOR(i,1,n){
        scanf("%s",c[i]);
    }
}
void init(){
    ans=0LL;
    FOR(cs,0,256) pre[cs]=ne[cs]=0;
}

bool checkOrder(){
    FOR(i,1,n){
        //printf("SS: %s\n",c[i]);
        int d=strlen(c[i]);
        if (d<2) continue;
        {
           // cout<<j<<endl;
            char c1= c[i][0];
            char c2=c[i][d-1];
            //printf("%d %d\n",c1,c2);
            if (c1!=c2){
                 if (ne[c1]==0) ne[c1]=c2; else if (ne[c1]!=c2) return false;
                 if (pre[c2]==0) pre[c2]=c1; else if (pre[c2]!=c1) return false;
            }
        }
    }
    return true;
}
void reduce(){
    FOR(i,1,n){
        //cout<<"reduce:"<<i<<endl;
        int j=1;
        int jj=0;
        while (j<strlen(c[i])){
            if (c[i][j]!=c[i][jj]){
                jj++;
                c[i][jj]=c[i][j];
            }
            j++;
        }
        jj++;
        c[i][jj]=0;
    }
    /*
    FOR(i,1,n) {
        printf("%s\n",c[i]);
    }
    */
}
bool inArray[300];
void calInArray(){
    FOR(i,0,256) inArray[i]=false;
    FOR(i,1,n){
        FOR(j,0,strlen(c[i])-1) inArray[c[i][j]]=true;
    }
    /*
    FOR(i,0,256) if (inArray[i]){
        printf("%c\n",i);
    }
    */
}
ll gt[nmax];
int dem[300];
void initGiaiThua(){
    gt[0]=1LL;
    FOR(i,1,111) gt[i]=(gt[i-1]*(ll)(i))%mod;
    FOR(i,0,256) dem[i]=0;
    FOR(i,1,n){
        if (strlen(c[i])>1) continue;
        dem[c[i][0]]++;
    }
}
int demB[300];
bool check(char ch){
    demB[ch]++;
    if (demB[ch]>1) return true;
    FOR(i,1,n){
        int d= strlen(c[i]);
        if (ch==c[i][0]) return true;
        if (ch==c[i][d-1]) return true;
    }
    return false;
}
bool checkBetween(){
    FOR(i,0,256) demB[i]=0;
    FOR(i,1,n){
        if (strlen(c[i])<3) continue;
        FOR(j,1,strlen(c[i])-2){
            if (check(c[i][j])) return false;
        }
    }
    return true;
}
ll calFrom(int u){
    //printf("Cal: %c\n",u);
    ll res=gt[dem[u]];
    while (ne[u]!=0){
        int v=ne[u];
        res=(res*gt[dem[v]])%mod;
        //printf("%c __ %lld\n",v,res);
        u=v;
    }
    return res;
}
void tinhToan(){
    ans=1LL;
    int cc=0;
    FOR(i,0,256) if (inArray[i] && pre[i]==0) {
        ll number= calFrom(i);
        ans= (ans*number)%mod;
        cc++;
    }
    ans= (ans*gt[cc])%mod;
}
int main(){
    if (DEBUG==1){
        freopen("B-small-attempt2.in","r",stdin);
        freopen("output.txt","w",stdout);
    }
    scanf("%d",&nTest);
    FOR(test,1,nTest){
        readInput();
        init();
        reduce();
        if (checkOrder()){
            calInArray();
            initGiaiThua();
            if (checkBetween()){
                //cout<<"Vuot vong kiem tra"<<endl;
                tinhToan();
            }
        }
        printf("Case #%d: ",test);
        cout<<ans<<endl;
    }
    return 0;
}
/*
3
3
ab bbbc cd
4
aa aa bc c
2
abc bcd
*/
