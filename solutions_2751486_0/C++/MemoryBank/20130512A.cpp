#include <algorithm>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

const int maxn=100;

char a[100];
int t1,t2,n,i,j,k,l,c,ans,flag;
char ch;

ifstream fin("a.in");
ofstream fout("a.out");


int main()
{
	fin>>t1;
	for(t2=1;t2<=t1;t2++)
	{
		l=0;
		ans=0;
		fin.get(ch);
		while(fin.get(ch) && ch!=' ')
		{
			a[l]=ch;
			l++;
		}
		fin>>n;
		for(i=0;i<l;i++)
		for(j=i;j<l;j++)
		{
			c=0;
			flag=0;
			for(k=i;k<=j;k++)
			{
				if ((a[k]!='a') && (a[k]!='e') && (a[k]!='i') && (a[k]!='o') && (a[k]!='u'))
					c++;
				else
					c=0;
				if (c>=n)
					flag=1;
			}
			if (flag)
				ans++;
		}
		fout<<"Case #"<<t2<<": "<<ans<<endl;
	}

	return 0;
}