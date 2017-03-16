#include <iostream>
#include <fstream>
#include <set>
using namespace std;

int calculate(int left , int right)
{
	int ans = 0;
	int len = 0;
	int origin;
	int translate;
	int max = 1;
	for (int i = left;i<=right;i++)
	{
		
		if (i<10)
			continue;
		origin = i;
		len = 0;
		max =1;
		set<int> data;
		while (origin>0)
		{
			origin/=10;
			len ++;
		}
		origin = i;

		for (int t = 1;t<len;t++)
		{
			int moveright = 1;
			int moveleft = 1;
			for (int j = 0 ;j <t ;j++)
			{
				moveright *= 10;
			}
			for (int j = 0;j < len-t;j++)
			{
				moveleft *= 10;
			}
			
			translate = origin/moveright+origin%moveright*moveleft;
			if (translate>=left && translate<=right && (translate != origin))
			{
				data.insert(translate);
			}
			
		}
		ans += data.size();
	}
	
	return ans;
}
int main()
{
	ifstream input("input.txt");
	ofstream output("ans.out");

	int t , a ,b ;
	int ans;
	while (input>>t)
	{
		for (int i = 0;i<t;i++)
		{
			input >>a>>b;
			ans = calculate(a ,b);
			output<<"Case #"<<i<<": "<<ans/2<<endl;
		}

	}
	return 1;
}
