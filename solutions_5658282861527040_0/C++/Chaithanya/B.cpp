//
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD 1000000007
#define INF 2147483647
#define PI 3.1415926535897932384626433832795
#define all(cont) cont.begin(),cont.end()
#define init(a,val) memset(a,val,sizeof(a))
#define F first
#define S second
#define mp make_pair
//GLOBAL

int main()
{
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    int test_cases,Testno;
    int a,b,k,cnt,i,j;

    cin>>test_cases;
    for(Testno=1;Testno<=test_cases;Testno++)
    {
        printf("Case #%d: ",Testno);
//___________________________________________
        cin>>a>>b>>k;cnt=0;
        for(i=0;i<a;i++)for(j=0;j<b;j++)if((i&j)<k)cnt++;
        cout<<cnt;


//___________________________________________
        Done: printf("\n");
    }

return 0;
}
