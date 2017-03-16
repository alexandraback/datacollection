#include<iostream>
#include<vector>
using namespace std;
int inv(int);
int pow(int,int);
int res(int,int);
int get(char);
int calc(string);
static int a[]={	0,1,2,3,4,5,6,7,
			1,4,3,6,5,0,7,2,
			2,7,4,1,6,3,0,5,
			3,2,5,4,7,6,1,0,
			4,5,6,7,0,1,2,3,
			5,0,7,2,1,4,3,6,
			6,3,0,5,2,7,4,1,
			7,6,1,0,3,2,5,4
		};
int main()
{
//	cout<<pow(calc("ijk"),3)<<endl;
	int T;
	cin>>T;
	for(int t=1;t<=T;t++){
	int L,X;
	cin>>L>>X;
	string s;
	cin>>s;
	int possible=pow(calc(s),X);
	cout<<"Case #"<<t<<": ";
	if(possible!=4)
	cout<<"NO"<<endl;
	else{
		vector<int> v;
		int cur=0;
		int got=0;
		for(int x=0;x<X&&got==0;x++)
		{
			for(int i=0;i<L&&got==0;i++)
			{
				int gr=get(s[i]);
				for(int j=0;j<v.size()&&got==0;j++)
				{
					v[j]=res(v[j],gr);
					if(v[j]==2)
					{
						got=1;
						break;
					}
				}	
				cur=res(cur,gr);
				if(cur==1)
				{
					v.push_back(0);
//					cout<<"tea"<<endl;
				}
//				cout<<cur<<endl;
			}
		}
		if(got==1)
		cout<<"YES"<<endl;	
		else
		cout<<"NO"<<endl;
	}

	}		
	
	return 0;
}
int inv(int g)
{
	if(g>=4)
	return g-4;
	else
	return g+4;
}
int pow(int g,int n)
{
	if(g==0)
	return 0;
	if(g==4)
	{
		if(n%2==0)
		return 0;
		else
		return 4;
	}
	if(n%4==0)
	return 0;
	if(n%4==1)
	return g;
	if(n%4==2)
	return 4;
	return inv(g);
}
int res(int g,int h)
{
	return a[8*g+h];
}
int get(char c)
{
	if(c=='i')
	return 1;
	if(c=='j')
	return 2;
	return 3;
}
int calc(string s)
{
	int ans=get(s[0]);
	for(int i=1;i<s.length();i++)
	ans=res(ans,get(s[i]));
	return ans;
}
