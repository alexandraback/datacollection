#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iomanip>
using namespace std;
ifstream cin("C-small-attempt3.in");
ofstream cout("out.txt");

bool curr[35], price[35];
int c,d,v,ans,tmp;

bool check()
{
	int i,j;
	memset(price,0,sizeof(price));
	price[0]=1;
	for (i=1;i<=v;i++)
	{
		if (!curr[i]) continue;
		for (j=v;j>=i;j--)
			if (price[j-i])
				price[j]=1;
	}
	for (i=1;i<=v;i++)
		if (!price[i])
			return false;
	return true;
}

void calc(int x)
{
	if (check())
	{
		if (tmp<ans)
			ans=tmp;
		return;
	}

	int num=0,notvalid=0,i=1;
	for (int i=1;i<=v;i++)
		if (!price[i]) num++;
	while (i*(i-1)<=v)
	{
		if (!price[i]) notvalid++;
		i++;
	}
	if (num<x)
	{
		if (num<ans)
			ans=tmp;
		return;
	}

	if ((x-1)*(x-2)/2>v) return;
	//if (x>8) return;
	if (curr[x])
	{
		calc(x+1);
		return;
	}
	calc(x+1);
	curr[x]=1;
	tmp++;
	calc(x+1);
	tmp--;
	curr[x]=0;
}

int main()
{
	int t,i,j,k,caseNum=0;

	cin>>t;
	while (t--)
	{
		caseNum++;
		cout<<"Case #"<<caseNum<<": ";
		memset(curr,0,sizeof(curr));
		cin>>c>>d>>v;
		for (i=1;i<=d;i++)
		{
			cin>>k;
			curr[k]=1;
		}
		ans=31;
		tmp=0;
		calc(1);
		cout<<ans<<endl;
	}
	return 0;
}
