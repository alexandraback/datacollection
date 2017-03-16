#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long int
#define pb push_back
#define mp make_pair
#define lf long double
#define VI vector<ll>
#define ppl pair<ll,ll>
#define ppi pair<int,int>
#define  F first
#define S Second
#define ML map<ll,ll>
#define itm map<ll,ll>::iterator
#define f_inp ios_base::sync_with_stdio(false)
int Z[10000],C[20];
int main()
{
    f_inp;
    ll n,m,a,b,c,d,i,j;
    freopen("1.in","r",stdin);
   freopen("2.out","w",stdout);
  cin>>n;
  string str;
    int test=1;
    string str1[]={"ZERO", "ONE", "TWO","THREE","FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};
    while(n>0)
    {
        cin>>str;
        n--;
        int pos;
        memset(Z,0,sizeof(Z));
        memset(C,0,sizeof(C));
        for(i=0;i<str.length();i++)
            Z[str[i]-'A']++;
         C[4]=Z['U'-'A'];
            Z['F'-'A']-=Z['U'-'A'];

         Z['O'-'A']-=Z['U'-'A'];

         Z['R'-'A']-=Z['U'-'A'];
           Z['U'-'A']-=Z['U'-'A'];;
         C[5]=Z['F'-'A'];
         Z['I'-'A']-=Z['F'-'A'];
         Z['V'-'A']-=Z['F'-'A'];
         Z['E'-'A']-=Z['F'-'A'];
         Z['F'-'A']-=Z['F'-'A'];;
         C[6]=Z['X'-'A'];
         Z['I'-'A']-=Z['X'-'A'];
         Z['S'-'A']-=Z['S'-'A'];
         C[7]=Z['V'-'A'];
         Z['S'-'A']-=Z['V'-'A'];
         Z['E'-'A']-=2*Z['V'-'A'];
         Z['N'-'A']-=Z['V'-'A'];
         Z['V'-'A']-=Z['V'-'A'];
         C[8]=Z['G'-'A'];
         Z['I'-'A']-=Z['G'-'A'];
         Z['E'-'A']-=Z['G'-'A'];
         Z['H'-'A']-=Z['G'-'A'];
         Z['T'-'A']-=Z['G'-'A'];
          Z['G'-'A']-=Z['G'-'A'];
         C[2]=Z['W'-'A'];
         Z['T'-'A']-=Z['W'-'A'];
         Z['O'-'A']-=Z['W'-'A'];
          Z['W'-'A']-=Z['W'-'A'];
         C[3]=Z['H'-'A'];
         Z['T'-'A']-=Z['H'-'A'];
         Z['R'-'A']-=Z['H'-'A'];
         Z['E'-'A']-=2*Z['H'-'A'];
          Z['H'-'A']-=Z['H'-'A'];
          C[0]=Z['Z'-'A'];
          Z['O'-'A']-=Z['Z'-'A'];
         C[1]=Z['O'-'A'];
         Z['N'-'A']-=Z['O'-'A'];
        Z['E'-'A']-=Z['O'-'A'];
         Z['O'-'A']-=Z['O'-'A'];
    C[9]=Z['I'-'A'];
    //cout<<C[9]<<" ";
cout<<"Case #"<<test<<": ";
for(i=0;i<10;i++)
{
        while(C[i]>0){
            cout<<i;
            C[i]--;
        }
}
cout<<endl;
test++;
    }
            return 0;

}


