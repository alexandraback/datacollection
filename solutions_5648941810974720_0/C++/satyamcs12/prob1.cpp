#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(i=0;i<n;i++)
#define sd(n) scanf("%d",&n);
#define sl(n) scanf("%lld",&n);
#define pd(n) printf("%d ",n);
#define pl(n) printf("%lld ",n);
#define pln printf("\n");
#define pb push_back
int ar2[50],ar1[50];
char ar[3000];

int main()
{
int t,i,j;

scanf("%d",&t);
for(j=0;j<t;j++)
{

        cout<<"Case #"<<j+1<<": ";
    scanf("%s",&ar);

    for(i=0;i<50;i++)
    ar1[i]=0;

    for(i=0;ar[i];i++)
    {
        ar1[ar[i]-'A']++;

    }
    ar2[0]=ar1['Z'-'A'];
    ar2[2]=ar1['W'-'A'];
    ar2[4]=ar1['U'-'A'];
    ar2[6]=ar1['X'-'A'];
    ar2[7]=ar1['S'-'A']-ar2[6];
    ar2[5]=ar1['V'-'A']-ar2[7];
    ar2[8]=ar1['G'-'A'];
    ar2[3]=ar1['H'-'A']-ar2[8];
    ar2[1]=ar1['O'-'A']-ar2[0]-ar2[2]-ar2[4];
    ar2[9]=ar1['I'-'A']-ar2[6]-ar2[5]-ar2[8];


    for(i=0;i<10;i++)
    {

        while(ar2[i]!=0)
        {
            cout<<i;
            ar2[i]--;
        }
    }
    cout<<endl;


}

    return 0;

}
