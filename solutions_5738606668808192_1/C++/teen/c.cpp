#include <bits\stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<bitset<16>, vector<LL> > P;
bitset<16>a;
vector <LL> tmp;
vector<P > an;
LL test(LL a)
{
	for(LL i = 2; i * i <= a;i++)
		if(a%i == 0)
			return i;
	return 1;
}
bool exits;
void find(int d)
{
	if(exits) return ;
	if(d == 15)
	{
		bool is = true;
		tmp.clear();
		for(int base = 2;base <= 10;base++)
		{
			LL ans = 0;
			for(int i = 0;i < 16; i++)
				ans = ans*base+ a[i];
			LL ss = test(ans);
			if(ss == 1)
			{
				is = false;
				break;
			}
			tmp.push_back(ss);
		}
		if(is)
		{
			an.push_back(make_pair(a,tmp));
			if(an.size() == 50)
				exits = true;
		}
		return;
	}
	for(int i = 0; i < 2; i++)
	{
		a[d] = i;
		find(d+1);
	}
}
int main()
{
	freopen("1.out","w",stdout);
	printf("Case #1:\n");
	exits = false;
	a[0] = 1;
	a[15] = 1;
	find(1);
	for(int i = 0; i < an.size();i++)
	{
		for(int j = 0;j < 16;j++)
			cout<<an[i].first[j];
		for(int j = 0; j < an[i].second.size();j++)
			cout<<" "<<an[i].second[j];
		cout<<endl;
	}
	return 0;
}