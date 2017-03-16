#include<bits/stdc++.h>
using namespace std;
int main()
{
	fstream fin,fout;
	fin.open("B-large.in",ios::in);
	fout.open("large-out.txt",ios::out);
	
	int t,q;
	fin>>t;
	for(q=0;q<t;++q)
	{
		fout<<"Case #"<<q+1<<": ";
		
		int freq[2501] = {0},i,n,j,tmp;
		fin>>n;
		for(i=0;i<n*2-1;++i)
		{
			for(j=0;j<n;++j)
			{
				fin>>tmp;
				freq[tmp]++;
			}
		}
		
		for(i=0;i<2501;++i)
		{
			if(freq[i]%2)
				fout<<i<<" ";
		}
		fout<<"\n";
		
	}
	
	fout.close();
	fin.close();
	return 0;
}
