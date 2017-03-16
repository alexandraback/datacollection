#include <fstream>
#include <iostream>

using namespace std;

const int maxn=21;
const int maxk=201;

int h[1048576],f[1048576],pre[1048576];
int st[maxk];
int key[maxn][maxk];
int need[maxn];
int t,tt,k,n,i,j,ks,x,p,q;

ifstream fin("D.in");
ofstream fout("D.txt");

	void print(int pos)
	{
		if (pos==0)
			return;

		print(pos-(1<<pre[pos]));
		if (pos-(1<<pre[pos]))
			fout<<" ";
		fout<<pre[pos]+1;
	}

int main()
{

	fin>>t;
	for(tt=1;tt<=t;tt++)
	{
		memset(st,0,sizeof(st));
		memset(key,0,sizeof(key));
		memset(need,0,sizeof(need));
		memset(h,0,sizeof(h));
		memset(f,0,sizeof(f));
		memset(pre,0,sizeof(pre));
		fin>>k>>n;
		for(i=0;i<k;i++)
		{
			fin>>x;
			st[x]++;
		}
		for(i=0;i<n;i++)
		{
			fin>>need[i];
			key[i][need[i]]--;
			fin>>ks;
			for(j=0;j<ks;j++)
			{
				fin>>x;
				key[i][x]++;
			}
		}

		h[0]=1;f[0]=0;
		p=0;q=1;
		while(p<q)
		{
			for(i=0;i<n;i++)
			if(!((f[p]>>i)&1))
			{
				x=st[need[i]];
				for(j=0;j<n;j++)
					if ((f[p]>>j)&1)
						x+=key[j][need[i]];
				j=f[p]+(1<<i);
				if (x && h[j]==0)
				{
					h[j]=1;
					f[q]=j;
					pre[j]=i;
					q++;
				}
			}
			p++;
		}

		fout<<"Case #"<<tt<<": ";
		i=(1<<n)-1;
		if (h[i])
		{
			print(i);
		}
		else
		{
			fout<<"IMPOSSIBLE";
		}
		fout<<endl;
	}
	return 0;
}