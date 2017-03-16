#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define si(x) scanf("%d",&x)
#define sl(x) scanf("%I64d",&x)
#define fora(x,y,z) for(int x=y;x<=(z);x++)
#define PNL printf("\n")
#define FL(a,n,x) fill(a,a+n,x)
#define pii pair<int,int>
#define F first
#define S second
#define mp make_pair
#define MOD 1000000007
#define debug(x) cout<<"here"<<x<<endl;

char dgt[10][10]={"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};
int cnt[559];
 vector<int> ans;
int dec(int in,char z){
int x=cnt[z];
//cout<<in<<" "<<x<<" "<<dgt[in]<<endl;
int len=strlen(dgt[in]);
fora(i,0,len-1){
int x1=dgt[in][i];
cnt[x1]-=x;
}
fora(i,0,x-1)
ans.pb(in);
}

char s[5000];
int main(){
   freopen("Input.in","r",stdin);
   freopen("Output.txt","w",stdout);
   int te;
   si(te);
   int ts=0;
   while(te--){
        ts++;
    fora(i,0,300)
    cnt[i]=0;
    scanf(" %s",s);
    int n=strlen(s);
    fora(i,0,n-1){
     int x=s[i];
     cnt[x]++;
    }
    ans.clear();
    dec(0,'Z');
    dec(2,'W');
    dec(4,'U');
    dec(6,'X');
    dec(8,'G');
    dec(1,'O');
    dec(3,'T');
    dec(5,'F');
    dec(7,'S');
    dec(9,'I');
    sort(ans.begin(),ans.end());
    cout<<"Case #"<<ts<<": ";
    int l1=ans.size();
    fora(i,0,l1-1)
    cout<<ans[i];
    cout<<endl;
   }
   return 0;
}
