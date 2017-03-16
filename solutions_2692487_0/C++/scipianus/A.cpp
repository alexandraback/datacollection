#include<fstream>
#include<algorithm>
#include<cmath>
using namespace std;
int T,n,A,val[110],sol;

inline void Back(int k,int now,int a)
{
	if(k==n+1)
	{
		sol=min(sol,now);
		return;
	}
	sol=min(sol,now+n-k+1);
	if(now>=sol)
		return;
	if(a>val[k])
		Back(k+1,now,a+val[k]);
	else
	{
		if(a==1)
			return;
		while(a<=val[k])
		{
			a+=a-1;
			now++;
		}
		Back(k+1,now,a+val[k]);
	}
}

int main()
{
	int t,i,j,pas,a;
	ifstream fin("A.in");
	ofstream fout("A.out");
	fin>>T;
	for(t=1;t<=T;t++)
	{
		fin>>A>>n;
		for(i=1;i<=n;i++)
			fin>>val[i];
		sort(val+1,val+n+1);
		sol=n;
		Back(1,0,A);
		/*i=1;
		j=n;
		while(i<=j)
		{
			if(A>val[i])
			{
				A+=val[i];
				i++;
			}
			else
			{
				if(i==j)
				{
					sol++;
					i++;
				}
				else
				{
					if(A==1)
					{
						sol+=(j-i+1);
						i=j+1;
					}
					else
					{
						pas=0;
						a=A;
						while(a<=val[i])
						{
							pas++;
							a+=a-1;
						}
						if(pas>j-i+1)
						{
							sol+=j-i+1;
							i=j+1;
						}
						else
						{
							sol+=pas;
							A=a;
						}
					}
				}
			}
		}
		sol=min(sol,n);*/
		fout<<"Case #"<<t<<": "<<sol<<"\n";
	}
	fin.close();
	fout.close();
	return 0;
}
