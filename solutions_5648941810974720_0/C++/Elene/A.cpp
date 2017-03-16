#include <bits/stdc++.h>
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define F first
#define S second
#define pp pair<int,int>
#define mp make_pair
#define pb push_back
#define ll long long
#define INF 2000000
#define P 1000000007
#define E 10000000
#define vec vector<vector<ll> >
using namespace std;
const int N=100005;
int cnt[500],okey,all;
string s;
vector<char> ans;
string o[15];
int need[15][500];

bool tryy(int x){
    for(int i='A';i<='Z';i++)
        if(cnt[i]<need[x][i])return 0;
    return 1;
}
void doo(int x,int k){
    for(int i='A';i<='Z';i++)
        cnt[i]+=k*need[x][i],all+=k*need[x][i];
}

void go(){
    if(all==0){
        okey=1;
        return;
    }

    for(int i=0;i<10;i++)
    if(tryy(i)){
        doo(i,-1);

        ans.pb(char('0'+i));


        go();
        if(okey)return;

        ans.pop_back();

        doo(i,1);
    }

}


int main()
{   freopen("A-small-attempt0.in","r",stdin);
   freopen("out.txt","w",stdout);
    int T;

    o[0]="ZERO";
    o[1]="ONE";
    o[2]="TWO";
    o[3]="THREE";
    o[4]="FOUR";
    o[5]="FIVE";
    o[6]="SIX";
    o[7]="SEVEN";
    o[8]="EIGHT";
    o[9]="NINE";

    for(int i=0;i<10;i++)
        for(int j=0;j<o[i].size();j++)
        need[i][o[i][j]]++;

    cin>>T;
    for(int t=1;t<=T;t++){

        cin>>s;
        for(int i=0;i<s.size();i++)cnt[s[i]]++;

        okey=0;
        all=s.size();
        go();

        if(!okey)assert(0);

        cout<<"Case #"<<t<<": ";
        sort(ans.begin(),ans.end());
        for(int i=0;i<ans.size();i++)cout<<ans[i];cout<<endl;

        for(int i='A';i<='Z';i++)cnt[i]=0;
        ans.clear();
    }


    return 0;
}
