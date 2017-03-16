#include<bits/stdc++.h>
using namespace std;
int x,R,C;
bool check()
{
	if(x>=7 || max(R,C)<x || R*C%x || min(R,C)<(x+1)/2)
		return false;
	return true;
}
int main()
{	
	freopen("D-small-attempt0.in","r",stdin);
	freopen("D-small-attempt0.out","w",stdout);
	int T;
	cin>>T;
	for(int t=1;t<=T;++t)
	{
		cin>>x>>R>>C;
		cout<<"Case #"<<t<<": "<<(check() ? "GABRIEL" : "RICHARD")<<endl;
	}
	return 0;
}
