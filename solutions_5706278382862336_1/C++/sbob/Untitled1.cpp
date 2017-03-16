#include <fstream>
#include <algorithm>
#include <vector>
#include <map>
#include <string>
#include <string.h>
#include <cmath>
#include <cstdio>
using namespace std;
int main()
{
	ofstream fout("yayz.out"); ifstream fin("A-large (1).in");
	long long a; fin >> a;
	for (int g=0; g<a; g++)
	{
		long long b; fin >> b;
		char t; fin >> t;
		long long c; fin >> c;
		if (b==c)
		{
			fout << "Case #" << g+1 << ": " << 0 << '\n'; continue;
		}
		if (b>c)
		{
			fout << "Case #" << g+1 << ": " << "impossible" << '\n';continue;
		}long long xxx=b; long long y=c; 
		while (xxx!=0 && y!=0)
		{
			if (xxx>y)
			{
				long long ppp= floor(xxx/y);
				xxx-=y*ppp;
			}
			else
			{
				long long pp=floor(y/xxx);
				y-=pp*xxx;
			}
		}long long operator2=0;
		if (xxx==0)
		{
			operator2=y;
		}
		else
		{
			operator2=xxx;
		}
		b/=operator2; c/=operator2; long long x=0;

		for (int g=1; g<=40; g++)
		{
			long long tt= pow(2,g);
			if (tt==c)
			{
				x=1;
			}
		}
		if (x!=1)
		{
			fout << "Case #" << g+1 << ": " << "impossible" << '\n'; continue;
		}
		if (b==1 && c==2)
		{
			fout << "Case #" << g+1 << ": " << 1 << '\n'; continue;
		}long long ans=0; 
		while (true)
		{
			if (b>=c)
			{
				break;
			}
			else
			{
				c/=2;
			}ans+=1;
		}
			fout << "Case #" << g+1 << ": " << ans << '\n';
		
	}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
}
