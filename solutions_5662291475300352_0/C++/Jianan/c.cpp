#include <iostream>
#include <vector>
#include <fstream>
using namespace std;
vector<int> a,b;
int len;
int xiangyu(int x)
{
	int i,ret=0;
	float t=1.0*(360-a[x])/360*b[x],t1;
	for (i=0;i<len;i++)
	{
		if (i==x || b[i]==b[x]) continue;
		if (b[i]<b[x])
		{
			t1=1.0*(360-a[i])/360*b[i];
			ret+=((int)(t-t1))/b[i];
			if (a[i]<a[x]) ret++;

		}
		else
		{
			t1=1.0*(360-a[i])/360*b[i];
			if (t1>t && a[i]>=a[x]) ret++;
		}
	}
	return ret;
}
int after(int x)
{
	int i,ret=0;
	float t=1.0*(360-a[x])/360*b[x],t1;

	for (i=0;i<len;i++)
	{
		if (i==x || a[i]>=a[x]) continue;
		t1=1.0*(360-a[i])/360*b[i];
		if (t1>t) ret++;
	}
	return ret;
}
int main()
{
	ifstream fin("5.txt");
	ofstream fout("6.txt");
	int T,o,i,tmp,n,min,x,y,z,j;
	fin >> T;

	for (o=1;o<=T;o++)
	{
		fin >> n;
		a.clear();
		b.clear();
		min=0;
		for (i=0;i<n;i++)
		{
			fin >> x >> y >> z;
			for (j=0;j<y;j++)
			{
				a.push_back(x);
				b.push_back(z+j);
			}
		}
		min=a.size();
		len=a.size();
		for (i=0;i<len;i++)
		{
			tmp=after(i)+xiangyu(i);
			cout << i  << ":" << after(i) << "  " << xiangyu(i) << endl;
			if (tmp<min) min=tmp;
		}
		cout << "Case #" << o << ": " << min << endl;
		fout << "Case #" << o << ": " << min << endl;
	}
	return 0;
}