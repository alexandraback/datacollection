#include<fstream>
#include<algorithm>
#include<iostream>
using namespace std;
int T,n,star,sol;
struct Nivel{int nr,ind;};
Nivel v1[1010],v2[1010];
bool gata[1010],gata2[1010];

inline bool Sortare(Nivel A,Nivel B)
{
	return A.nr<B.nr;
}

int main()
{
	int t,i,j;
	bool ok;
	ifstream fin("B.in");
	ofstream fout("B.out");
	fin>>T;
	for(t=1;t<=T;t++)
	{
		//cout<<t<<"\n";
		fin>>n;
		for(i=1;i<=n;i++)
		{
			fin>>v1[i].nr>>v2[i].nr;
			v1[i].ind=v2[i].ind=i;
			gata[i]=gata2[i]=false;
		}
		star=0;
		sol=0;
		sort(v2+1,v2+n+1,Sortare);
		sort(v1+1,v1+n+1,Sortare);
		ok=true;
		for(i=1,j=1;j<=n && ok;)
		{
			while(j<=n && v2[j].nr<=star)
			{
				if(gata[v2[j].ind])
					star++;
				else
					star+=2;
				gata2[v2[j].ind]=true;
				//cout<<v2[j].nr<<' '<<v2[j].ind<<"\n";
				j++;
				sol++;
			}
			if(j<n+1)
			{
				if(i==n+1)
					ok=false;
				else
				{
					if(gata2[v1[i].ind])
					{
						i++;
						continue;
					}
					if(v1[i].nr<=star)
					{
						sol++;
						star++;
						gata[v1[i].ind]=true;
						//cout<<v1[i].nr<<' '<<v1[i].ind<<"\n";
						i++;
					}
					else
						ok=false;
				}
			}
		}
		if(!ok)
			fout<<"Case #"<<t<<": "<<"Too Bad"<<"\n";
		else
			fout<<"Case #"<<t<<": "<<sol<<"\n";
		//cout<<"\n";
	}
	fin.close();
	fout.close();
	return 0;
}

