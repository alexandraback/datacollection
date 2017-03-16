#include<iostream>
#include<cstdio>
#include<string>
#include<vector>
using namespace std;

typedef long long ll;

struct g
{
	int D;
	int m;
	g(): D(0), m(0) {};
	g(int D, int m): D(D), m(m) {};
};

int N;
int ans;
int main()
{
	int T;
	cin>>T;
	for(int test_num=1;test_num<=T;test_num++)
	{
		vector<g> p;
		cin >> N;
		for(int i=0;i<N;i++)
		{
			int D, H, M;
			cin >> D >> H >> M;
			for(int j=0;j<H;j++)
			{
				p.push_back(g(D, M+j));
			}
		}
		if (p.size() < 2)
		{
			ans = 0;
		}
		else
		{
			ll d1 = p[0].D, d2 = p[1].D;
			ll m1 = p[0].m, m2 = p[1].m;
			if (d1 < d2)
			{
				swap(d1, d2);
				swap(m1, m2);
			}
			if (m1 == m2) ans = 0;
			else if (m1 < m2)
			{
				//double ta = (360-d2)*m2;
				//double tb = (360-d1+d2)*m1*m2 / m2-m1
				
				if ((360-d2)*(m2-m1) < (360-d1+d2)*m1) ans = 0;
				else ans = 1;
			}
			else
			{
				//double ta = (360-d1)*m1;
				//double tb = (360+d1-d2)*m1*m2 / m1-m2
				if ((360-d1)*(m1-m2) < (360+d1-d2)*m2) ans = 0;
				else ans = 1;				
			}		
			
		}

		printf("Case #%d: %d\n", test_num, ans);	
	}
	
	return 0;
}
