#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<string>
#include<fstream>
using namespace std;
struct subs
{
	int sp,ep;
};
bool isvowel(char x)
{
	if((x=='a')||(x=='e')||(x=='i')||(x=='o')||(x=='u'))
	return true;
	else
	return false;
}
int main()
{
	ifstream fin("A.in");
	ofstream fout("A.out");
	int t;
	vector <long long> ans;
	fin>>t;
	while(t--)
	{
		string x;
		int n,count=0;
		subs xy;
		vector <subs> A;
		fin>>x>>n;
		for(int i=0;i<x.size();i++)
		{
			if(isvowel(x[i]))
			count=0;
			else
			count++;
			if(count>=n)
			{
				xy.ep=i;
				xy.sp=i+1-n;
				//cout<<xy.sp<<" "<<xy.ep<<"\n";
				A.push_back(xy);
			}
		}
		int tans=0,i=0;
		if(A.size()<=0)
		{
			ans.push_back(0);
			continue;
		}
		for(i=0;i<A.size()-1;i++)
		{
			tans+=(A[i].sp+1)*(A[i+1].ep-A[i].ep);
		}
		tans+=(A[i].sp+1)*(x.size()-A[i].ep);
		ans.push_back(tans);
	}
	for(int i=0;i<ans.size();i++)
	fout<<"Case #"<<i+1<<": "<<ans[i]<<"\n";
	return 0;
}
