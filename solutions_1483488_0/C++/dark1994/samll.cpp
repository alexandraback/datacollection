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

int isPair(int n,int m)
{
	int i,len;
	int x,y,t;

	x=n,len=0;
	while(x>0)
		x/=10,++len;

	i=1;
	while(1)
	{
		t=pow(10,i);
		if(n/t<=0)
			break;

		x=n%t;
		y=n/t;

		if(x*pow(10,len-i)+y==m)
			return 1;
		++i;
	}

	return 0;
}


void main()
{
	int i,j,k,num;
	int n,m,ret,a,b;
	vector<int> v;
	ifstream fin("C:\\Documents and Settings\\Administrator\\×ÀÃæ\\gcj\\C\\C-small-attempt0.in");
	ofstream fout("C:\\Documents and Settings\\Administrator\\×ÀÃæ\\gcj\\C\\C-small.txt");
	
	fin>>num;

	for(i=1;i<=num;++i)
	{
		ret=0;
		fin>>a>>b;
		
		for(n=a;n<=b;++n)
		for(m=n+1;m<=b;++m)
			ret+=isPair(n,m);

		fout<<"Case #"<<i<<": ";
		fout<<ret<<endl;
	}
}

