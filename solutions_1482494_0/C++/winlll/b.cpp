#include<fstream>
#include<iostream>
using namespace std;

int main()
{
	ifstream fin;
	ofstream fout;
	fin.open("b.in");
	fout.open("b.out");
	int p[2000],q[2000];
	bool b[2000];
	int tr,rnd,n,i,j,v,min,now,star,tot;
	bool flag;
	fin>>tr;
	for (rnd=1;rnd<=tr;rnd++)
	{
		fin>>n;
		for (i=0;i<n;i++)
			fin>>p[i]>>q[i];
		for (i=0;i<n-1;i++)
			for (j=0;j<n-1;j++)
				if (q[j]>q[j+1] || q[j]==q[j+1] && p[j]<p[j+1])
				{
					v=p[j];p[j]=p[j+1];p[j+1]=v;
					v=q[j];q[j]=q[j+1];q[j+1]=v;
				}
		for (i=0;i<n;i++)
			b[i]=false;
		now=0;star=0;tot=0;
		flag=true;
		while (flag)
		{
			cout<<star<<' '<<now<<' '<<tot<<"S"<<endl;
			while (now<n && star>=q[now])
			{
				if (b[now])
					star++;
				else
					star=star+2;
				tot++;
				now++;
			}
			cout<<star<<' '<<now<<' '<<tot<<"E"<<endl;
			if (now>=n)
				flag=false;
			min=n-1;
			while (min>=now && (b[min] || p[min]>star))
				min--;
			
			if (min>=now)
			{
				b[min]=true;
				tot++;
				star++;
			}
			else
				flag=false;
		}
		fout<<"Case #"<<rnd<<": ";
		if (star==n*2)
			fout<<tot<<endl;
		else
			fout<<"Too Bad"<<endl;
	}
	fin.close();
	fout.close();
}