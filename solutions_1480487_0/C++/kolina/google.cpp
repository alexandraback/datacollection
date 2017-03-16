#include <vector>
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int t;
	cin >>t;
	for (int i=0; i<t; ++i)
	{
		cout <<"Case #" <<i+1 <<": ";
		int s;
		cin >>s;
		vector <int> v(s),ans(s),u(s);
		for (int j=0; j<s; ++j)
			cin >>v[j];
		int sum=0;
		for (int j=0; j<s; ++j)
			sum+=v[j];
		int sumn=0,kol=0;
		for (int j=0; j<s; ++j)
			if (v[j]*s<2*sum)
			{
				sumn+=v[j];
				++kol;
			}
		vector <int> mas(s);
		for (int j=0; j<s; ++j)
		{
			double ans=((sum+sumn+0.0)/kol-(v[j]+0.0))/sum*100;
			if (v[j]*s>=2*sum)
				ans=0.0;
			cout <<fixed <<setprecision(7) <<ans;
			if (j<s-1)
				cout <<" ";
		}
		if (i<t-1)
			cout <<endl;
	}
	return 0;
}