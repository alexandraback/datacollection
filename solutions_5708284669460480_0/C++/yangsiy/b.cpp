#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iomanip>
using namespace std;
ifstream cin("B-small-attempt0.in");
ofstream cout("out.txt");

char typed[10], key[10], target[10];
int k,l,s;
double prob;
int maxx;

int check()
{
	int rtn=0;
	bool flag;
	for (int i=0;i<s;i++)
	{
		flag=1;
		for (int j=0;j<l;j++)
		{
			if (i+j>=s) 
			{
				flag=0;
				break;
			}
			if (typed[i+j]!=target[j])
			{
				flag=0;
				break;
			}
		}
		if (flag) rtn++;
	}
	return rtn;
}

void work(int x)
{
	if (x==s)
	{
		int p=check();
		if (p>maxx) maxx=p;
		prob+=p;
		return;
	}
	for (int i=0;i<k;i++)
	{
		typed[x]=key[i];
		work(x+1);
	}
}

int main()
{
	int t,i,j,caseNum=0;

	cin>>t;
	while (t--)
	{
		caseNum++;
		cin>>k>>l>>s;
		cin>>key;
		cin>>target;
		prob=0;
		maxx=0;
		work(0);
		//cout<<prob<<"\t"<<maxx<<endl;
		for (i=1;i<=s;i++) prob/=k;
		cout<<"Case #"<<caseNum<<": ";
		cout<<fixed<<setprecision(7)<<maxx-prob<<endl;
	}
	return 0;
}