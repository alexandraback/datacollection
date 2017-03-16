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
	ofstream fout("yayz.out"); ifstream fin("A-small-attempt3.in");
	int a; fin >> a;
	for (int g=0; g<a; g++)
	{
		int b; fin >> b;
		char t; fin >> t;
		int c; fin >> c;
		if (b==c)
		{
			fout << "Case #" << g+1 << ": " << 0 << '\n'; continue;
		}
		if (b>c)
		{
			fout << "Case #" << g+1 << ": " << "impossible" << '\n';continue;
		}
		int xx=min(b,c);
		for (int g=2; g<=xx; g++)
		{
			if (b%g==0 && c%g==0)
			{
				b/=g; c/=g;
			}
		}int x=0; int l=0;
		for (int g=1; g<=40; g++)
		{
			long long tt= pow(2,g);
			if (tt==c)
			{
				x=1;l=g; 
			}
		}
		if (x!=1)
		{
			fout << "Case #" << g+1 << ": " << "impossible" << '\n'; continue;
		}
		if (b==1 && c==2)
		{
			fout << "Case #" << g+1 << ": " << 1 << '\n'; continue;
		}int ans=0;
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
