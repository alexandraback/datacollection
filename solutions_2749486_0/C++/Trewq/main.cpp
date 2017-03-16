#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<string>
#include<memory.h>
#include<queue>
#include<stack>
using namespace std;

struct Stat
{
	int n,x,y;
	string d;
};
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int nc;
	cin>>nc;

	int x,y;
	Stat st,st2;
	stack<Stat> q;
	for(int tc=1;tc<=nc;tc++)
	{
		cin>>x>>y;
		st.d="";
		if(x>0)
			while(x--)
				st.d+="WE";
		else if(x<0)
			while(x++)
				st.d+="EW";
		if(y>0)
			while(y--)
				st.d+="SN";
		else if(y<0)
			while(y++)
				st.d+="NS";
		cout<<"Case #"<<tc<<": "<<st.d<<endl;	
	}	
	return 0;
}