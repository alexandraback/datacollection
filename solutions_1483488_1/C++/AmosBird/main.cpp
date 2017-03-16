#include<iostream>
#include<cstring>
#include<cstdio>
#include<map>
#include<set>
#include<cmath>
#include<algorithm>
#include<functional>
int adder[10] = {0};
using namespace std;
bool vstd[2000005];
int shft(int a,int p){
int f = a%10;
    a/=10;
    return adder[f]+a;
}
int main()
{
    int t;

    freopen("C-large.in","r",stdin);
    freopen("C-large.out","w",stdout);
	cin>>t;
	for (int i=1;i<=t;i++)
	{
	    int a,b,ans=0;
	    memset(vstd,0,sizeof(vstd));
		cin>>a>>b;
		int cnt = (int)log10(a);
		for (int j=1;j<10;j++)
		{
			adder[j] = j * pow(10,cnt);
		}
        for (int j=a;j<b;j++)
        {
            if(vstd[j]) continue;
            int l = 0;
            int sj = j;
            for(int k=0;k<cnt;k++){
                sj = shft(sj,cnt);
                if(sj <= j || sj > b || vstd[sj]) continue;
                l++;
                vstd[sj] = true;
            }
            ans += l*(l+1)/2;
        }
        cout<<"Case #"<<i<<": "<<ans<<endl;

	}
	return 0;
}
