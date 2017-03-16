

#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cmath>
#include<cstring>
#include<map>
#include<queue>
#include<stack>
#include<utility>
#include<cstdlib>
#include<string>
#include<sstream>
#include<fstream>
#include<set>
using namespace std;

#define MAX 1000100
#define ll long long
int aray[MAX];

int main()
{
	//freopen("B-small-attempt0.in","r",stdin);
	//freopen("output.txt","w",stdout);
	int t;
	cin>>t;
	int x,y;
	for(int cas=0;cas<t;cas++)
	{
		cin>>x>>y;
		string str;
		for(int i=0;i<abs(x);i++)
		{
			if(x>0)
				str.append("WE");
			else
				str.append("EW");
		}
		for(int i=0;i<abs(y);i++)
		{
			if(y>0)
				str.append("SN");
			else
				str.append("NS");
		}
		printf("Case #%d: ",cas+1);
		cout<<str<<endl;
	}
    return 0;
}
