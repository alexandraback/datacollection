#include<bits/stdc++.h>
using namespace std;

// Input macros
#define s(n)                        scanf("%d",&n)
#define sl(n)                       scanf("%ld",&n)
#define sll(n)                      scanf("%lld",&n)
#define sllu(n)                     scanf("%llu",&n)
#define p(n)						printf("%d\n",n)
#define pl(n)						printf("%ld\n",n)
#define pll(n)						printf("%lld\n",n)
#define pllu(n)						printf("%llu\n",n)

typedef long long int ll;

FILE *fin=freopen("A-large (1).in","r",stdin);
FILE *fout=freopen("A_large.txt","w",stdout);

string ToStr( char c ) {
   return string( 1, c );
}

int main()
{
    int t;s(t);
    for(int i=1;i<=t;i++)
    {
        string S;cin>>S;
        string S2;S2.insert(0,ToStr(S[0]));
        for(int x=1;x<S.size();x++)
        {
            if(S[x]>=S2[0])
            {
                S2.insert(0,ToStr(S[x]));
                ///cout<<S2<<"#######"<<endl;
            }
            else{
                S2.append(ToStr(S[x]));
                //cout<<S2<<"!!!!!!"<<endl;
            }
        }
        //printf("Case #%d: %s\n",i,S2);
        cout<<"Case #"<<i<<": "<<S2<<"\n";
    }
}
