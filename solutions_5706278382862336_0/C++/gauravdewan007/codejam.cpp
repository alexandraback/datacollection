#include <fstream>
#include <iostream>
#include <cstdio>

using namespace std;

long long int p,q, qorig; //remember on 32 bit compiler
int ans = 0;
FILE* fp;

int main()
{
	fp = fopen("c:\\test\\a.in","r");
	ofstream fout("c:\\test\\a.out",ios::out);
	long long int t,i,j;
	fscanf(fp,"%lld",&t);
	//cin>>t;
	for(i=1;i<=t;i++)
	{
		fscanf(fp,"%lld/%lld",&p,&q); //on 32 bit compiler
		fout<<"Case #"<<i<<": ";
		ans = -1;
		if(q>p)
		{
			qorig = q;
			while(q%2==0){
				q/=2; //compiler optimization
			}
			if(p%q==0)
			{
				p = p/q;
				qorig /= q;
				q = qorig;
				ans = 0;
				while(q>p)
				{
					q/=2;ans++;
				}

			}
		}

		if(ans>0 && ans<=40)
			fout<<ans;
		else
			fout<<"impossible";
		fout<<endl;
	}
	return 0;
}