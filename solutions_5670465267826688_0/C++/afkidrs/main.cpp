#include <iostream>
#include <string>

using namespace std;

const string no="NO";
const string yes="YES";
int v[5][5]={
	0,0,0,0,0,
	0,1,2,3,4,
	0,2,-1,4,-3,
	0,3,-4,-1,2,
	0,4,3,-2,-1
};
int t,X,L;
string s;

bool Compute()
{
	bool ifound=false;
	bool jfound=false;
	int current=1;
	int sign=1;
	for(int i=0;i<X;++i)
	{
		for(int j=0;j<L;++j)
		{
			current=v[current][s[j]-'i'+2];
			if(current<0)
			{
				sign=-sign;
				current=-current;
			}
			if(current>0 && sign>0)
			{
				if(current==2 && !ifound)
				{
					ifound=true;
					current=1;
				}
				if(current==3 && !jfound && ifound)
				{
					jfound=true;
					current=1;
				}
			}
		}
	}
	if(current==4 && sign>0 && ifound && jfound)
		return true;
	else return false;
}

int main()
{
	cin>>t;
	for(int i=1;i<=t;++i)
	{
		cout<<"Case #"<<i<<": ";
		cin>>L>>X;
		cin>>s;
		if(Compute())
			cout<<yes<<endl;
		else cout<<no<<endl;
	}	
	return 0;
}