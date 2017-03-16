#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
using namespace std;
int main()
{
	freopen("A-large.in","r",stdin);
	freopen("A.out","w",stdout);
	int time;
	double res=1.0,p,expect,t;
	int A,B;
	cin>>time;
	for(int k=0;k<time;++k)
	{
		cin>>A>>B;
		res=1.0;
		expect=B*2.0;
		for(int i=0;i<A;++i)
		{
			cin>>p;
			res*=p;
			t=res*(B-i+1)+(1-res)*(B-i+1+B+1);
			if(expect>t)expect=t;
		}
		t=res*(B-A+1)+(1-res)*(B-A+1+B+1);
		if(t<expect)expect=t;
		if(expect>B+2)expect=B+2;
		printf("Case #%d: %.6f\n",k+1,expect);
	}
}
