#include<fstream>
#include<vector>
#include<algorithm>
using namespace std;
int findAns(vector<double> &finder, vector<double> &base)
{
	int index = 0;
	int ans = 0;
	for (int k=0;k<finder.size();++k)
	{
		while (index < base.size() && base[index]<finder[k])
			index++;
		if (index < base.size())
		{
			ans++;
			index++;
		}
	}
	return ans;
}
int main()
{
	ifstream fin ("D-large.in");
	ofstream fout("Deceitful War.out");
	int n;
	fin>>n;
	for (int i=0;i<n;++i)
	{
		int m;
		fin>>m;
		vector<double> naomi,ken;
		for (int j=0;j<m;++j)
		{
			double x;
			fin>>x;
			naomi.push_back(x);
		}
		for (int j=0;j<m;++j)
		{
			double x;
			fin>>x;
			ken.push_back(x);
		}
		sort(naomi.begin(),naomi.end());
		sort(ken.begin(),ken.end());
		fout<<"Case #"<< i+1<< ": "<<findAns(ken,naomi)<<' '<<m-findAns(naomi,ken)<<endl;
	}
	return 0;
}