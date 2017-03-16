/*
 * b.cpp
 *
 *  Created on: Apr 12, 2014
 *      Author: AhmedHamza
 */

#include<cstdio>
#include<queue>
using namespace std;

struct Event
{
		double t, p;
		bool f;
		bool operator <(const Event& e) const
		{
			if (t != e.t)
				return t > e.t;
			if (f != e.f)
				return f < e.f;
			return p > e.p;
		}
};

int main()
{

	freopen("B-small-attempt0.in", "rt", stdin);
	freopen("B-small-attempt0.txt", "wt", stdout);

	int tc;
	double c, f, x;
	scanf("%d", &tc);
	for (int t = 1; t <= tc; ++t)
	{
		scanf("%lf%lf%lf", &c, &f, &x);
		priority_queue<Event> q;
		q.push( { 0, 2, 0 });
		while (!q.empty())
		{
			Event e = q.top();
			//			printf("%lf\n",e.t);
			q.pop();
			if (e.f)
			{
				printf("Case #%d: %0.7lf\n", t, e.t);
				break;
			}
			q.push( { e.t + c / e.p, e.p + f, 0 });
			q.push( { e.t + x / e.p, e.p + f, 1 });
		}
	}
	return 0;
}
