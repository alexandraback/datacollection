
#include <vector>
#include <set>
#include <iterator>
#include <algorithm>
#include <functional>
#include <list>
#include <cmath>
#include <string>
#include <iostream>
#include <map>
#include <stack>
#include <cstdio>
#include <fstream>
#include <sstream>

using namespace std;

typedef long long ll;

const int MAXN = 2000002;

bool f[MAXN];

ll solve(ll A, ll B)
{
	int i,j,k,m,n;

	vector<int> a;
	a.clear();

	for(i=0;i<MAXN;i++)
		f[i] = true;

	int digit =1;   // number of digits
	ll C = A;
	while(C/10 !=0)
	{digit++; C=C/10;}

	int num = 0;
	for (i=A; i<=B; i++)
	{
		if (!f[i])
			continue;
		f[i] = false;
		num = 1;
		for(j=1;j<digit;j++)
		{
			int init=1;
			k=0;
			while(k<j)
			{init =init*10;k++;}

			int res = i%init;
			int leftp = i/init;

			k=0;
			while(k<digit-j)
			{ res =res*10; k++;}

			int newn = res + leftp;

			if (newn>=A &&newn <=B)
				if (f[newn] && newn>=A &&newn <=B )
					{f[newn] = false; num++;}
		}


		a.push_back(num);
	}


	ll result = 0;

	for(i=0;i<a.size();i++)
	{
		if(a[i]>1)
			result += (a[i]*(a[i]-1))/2;
	}

	return result; 
}


int main()
{

	


	//freopen("C-small-attempt1.in","r", stdin);
	freopen("C-large.in","r", stdin);
	freopen("c.out","w", stdout);

	int T,A,B;
	int i,j,k;
	cin>>T;

	for (i=1;i<=T;i++)
	{
		cin>>A>>B;


		cout<<"Case #"<<i<<": " <<solve(A,B)<<endl;
	}





	fclose(stdin);
	fclose(stdout);
	
	
	


}
