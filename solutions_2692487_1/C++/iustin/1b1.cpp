# include <fstream>
# include <iostream>
# include <algorithm>
# define DIM 103
using namespace std;
int v[DIM], n, m, cant;

int add (int m, int k)
{
	cant = 0;
	int r=0;
	
	while(m<=k)
	{
		cant += m-1;
		m+=m-1;
		++r;
	}
	
	return r;
}

int main ()
{
	int nt;
	
	ifstream fin ("f.in");
	ofstream fout ("f.out");
	fin>>nt;
	
	for(int t=1;t<=nt;++t)
	{
		fin>>m>>n;
		for(int i=1;i<=n;++i)
			fin>>v[i];
		
		
		int sol = 0;
		
		sort(v+1, v+n+1);
		
		if (m==1)
			sol = n;
		else		
			for(int i=1;i<=n;++i)
			{
				if (m<=v[i])
				{
				//	cout<<"#"<<t<<"   "<<m<<" "<<v[i]<<endl;
					int ad = add(m, v[i]);
					if (ad > n-i+1)
					{
						sol+=n-i+1;
						break;
					}
					else
						sol+=ad, 
						m+=cant;
				}
				m+=v[i];
			}/*
		if (sol>n)
		{
			cout<<"BĂ! "<<t<<"   "<<sol<<endl;
			cout<<m<<" "<<n<<endl;
			for(int i=1;i<=n;++i)
				cout<<v[i]<<" ";
			cout<<endl;
		}*/
		fout<<"Case #"<<t<<": "<<(sol>n?n:sol)<<"\n";
	}
	
	return 0;
}
