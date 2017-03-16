#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<set>
#include<algorithm>
#include<numeric>
#include<cmath>
#include<fstream>

using namespace std;

typedef _int64 i64;

int next(int n,int len,bool &cha)
{
	int x,y;

	x=(n%10)*pow(10,len-1),y=n/10;

	if(x==0)
		cha=true;

	return x+y;
}

int getLen(int n)
{
	int len;

	len=0;
	while(n> 0)
		n/=10,++len;

	return len;
}

i64 getCount(int a,int b)
{
	bool cha;
	int i,j,len,t,n;
	int *select;
	i64 ret=0,sum;

	select=(int *)new int[b+10];
	memset(select,0,(b+8)*sizeof(int));
	
	for(n=a;n<=b;++n)
	{
		if(!select[n])
		{
			len=getLen(n);
			i=n;
			sum=1;

			t=n;
			cha=false;
			while((t=next(t,len,cha))!=n)
			{
				if(t>=a && t<=b && !cha)
					++sum,select[t]=1;

				cha=false;
			}

			ret+=sum*(sum-1)/2;
		}
	}

	delete select;

	return ret;
}

i64 atoi64(string s)
{
	i64 ret=0,i,j,k;

	for(i=s.size();i>=1;--i)
	{
		for(j=1,k=1;j<=i-1;++j)
			k*=10;
		ret+=(s[s.size()-i]-'0')*k;
	}

	return ret;
}

string i64toa(i64 n)
{
	string s;

	while(n)
	{
		s.insert(s.begin(),n%10+'0'),n/=10;
	}

	return s;
}


void main()
{
	int i,j,k,num;
	int n,m,ret,a,b;
	vector<int> v;
	ifstream fin("C:\\Documents and Settings\\Administrator\\×ÀÃæ\\gcj\\C\\C-large.in");
	ofstream fout("C:\\Documents and Settings\\Administrator\\×ÀÃæ\\gcj\\C\\C-large.txt");
	
	fin>>num;

	for(i=1;i<=num;++i)
	{
		ret=0;
		fin>>a>>b;
		
		ret+=getCount(a,b);

		fout<<"Case #"<<i<<": ";
		fout<<ret<<endl;
	}
}

