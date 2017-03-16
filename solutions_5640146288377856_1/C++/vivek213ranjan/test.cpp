#include<bits/stdc++.h>
#define ll long long
using namespace std;
int func(int a,int b,int c)
{
	int res;
	if(b==c)
        	res=(a-1+c);
       	else if(c==1)
       		res=(a*b); 
        else
        	res=((a*(b-1))/c+c);
	return res;
	
}
int main()
{
freopen("input.in","r",stdin);
freopen("output1.txt","w",stdout);
    ll t,cases;
    cin >>t;
    for(cases=1;cases<=t;cases++)
    {
	ll a,b,c;
	cin>>a>>b>>c;
        if(b==c)
        cout<< "Case #" <<cases<< ": " << a-1+c <<"\n";
       	else if(c==1)
       	cout << "Case #" << cases << ": " << a*b << "\n"; 
        else
        cout << "Case #" << cases<< ": " << (a*(b-1))/c+c << "\n";
    }
}
 
