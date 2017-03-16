
#include<bits/stdc++.h>
/*
ID: rahulch1
PROG: 
LANG: C++                  
*/


using namespace std;

struct c
{
		float d,h, m;
};
int main()
{
		ofstream fout ("me.out");
    ifstream fin ("y.in");
		int tes;
		fin>>tes;
		for(int i=1;i<=tes;i++)
		{
				fout<<"Case #"<<i<<": ";
				int n;
				fin>>n;
				if(n==0)
				fout<<0<<'\n';
				if(n==1)			//WRONG
				{
						int a,b,c;
						fin>>a>>b>>c;
						fout<<0<<'\n';
				}
				if(n==2)
				{
						c c1,c2;
						fin>>c1.d>>c1.h>>c1.m;
						fin>>c2.d>>c2.h>>c2.m;
						if(c1.m>c2.m)
						{
								swap(c1,c2);
						}
						if(c2.m*(c2.d/360)>=(c1.m*(c2.d/360)+c1.m))
						{
								fout<<1<<'\n';
						}
						else
						fout<<0<<'\n';
				}
				
		}
}
						
						
