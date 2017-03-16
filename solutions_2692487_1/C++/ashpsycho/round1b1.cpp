#include<iostream>
#include<queue>
#include<fstream>
using namespace std;
int main()
{
	long long n,a;
	priority_queue<int> q;
	static int t,te,i,j,k,arr[1000000];
	ifstream file1;
	ofstream file2;
	file1.open("ain.txt");
	file2.open("aout.txt");
	file1>>t;
	for(te=0;te<t;te++)
	{
		file1>>a>>n;
		for(i=0;i<n;i++)
		{
			file1>>j;
			q.push(j);
		}
		for(i=0;i<n;i++)
		{
			arr[n-(i+1)]=q.top();
			q.pop();
		}
		for(i=0;arr[i]<a&&i<n;i++)
			a+=arr[i];
		int minop=n-i,i1=i;
		for(int op=1;op<100&&i1<n;op++)
		{
			a+=(a-1);
			for(i=i1;arr[i]<a&&i<n;i++)
				a+=arr[i];
			i1=i;
			if((op+n-i1)<minop)
				minop=op+n-i1;
			if(i1==n)
				break;
		}
		file2<<"Case #"<<1+te<<": "<<minop<<"\n";
	}
	file1.close();
	file2.close();
	return 0;
}
