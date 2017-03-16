#include <bits/stdc++.h>
using namespace std;
int t;
long long int x;
string l;
//1 is 0, i is 1, j is 2, k is 3
int mult[4][4]=
{
	0,1,2,3,
	1,0,3,2,
	2,3,0,1,
	3,2,1,0
};
int sig[4][4]=
{
	1,1,1,1,
	1,-1,1,-1,
	1,-1,-1,1,
	1,1,-1,-1
};
int main() {
	// your code goes here
	cin>>t;
	for(int c=1;c<=t;++c)
	{
		cin>>x;
		cin>>x;
		cin>>l;
		x= min(x,(x&3)+12);
		int cur = 0;
		int sign = 1;
		int lett;
		int req=1;
		//int la = 12;
		for(int i=0;i<x;++i)
		{
			for(int j=0;j<l.size();++j)
			{
				lett = l[j]-'i'+1;
				sign *= sig[cur][lett];
				cur = mult[cur][lett];
	//			cout<<(char)(lett-1+'i')<<" "<<sign<<" "<<(char)(cur-1+'i')<<endl;
				if(sign ==1 && cur==req)
				{
	//				cout<<"got "<<((char)('i'-1+req))<<endl;
					++req;
					cur=0;
					sign=1;
				}
			}
		}
		cout<<"Case #"<<c<<": ";
		if(cur!=0 || sign!=1 || req!=4)
			cout<<"NO"<<endl;
		else
			cout<<"YES"<<endl;
		
	
	}
	return 0;
}