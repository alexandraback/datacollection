
#include<iostream>

using namespace std;


struct sec
{
	int type;
	long long time;
	sec *next;

	sec(int ty, long long ti, sec *ne)
	{
		type = ty;
		time = ti;
		next = ne;
	}
};

void recdel(sec *x)
{
	if (x == 0) return;
	recdel(x->next);
	delete x;
}

long long decide(sec *a, sec *b)
{
	if (a == 0 || b == 0) return 0;

	//cout << "decicing: " << a->type << " " << a->time << " " << b->type << " " << b->time << endl;

	if (a->type == b-> type)
	{
		if (a->time == b->time)
		{
			return a->time + decide(a->next, b->next);
		} else if (a->time < b->time)
		{
			sec *ns = new sec(b->type, b->time - a->time, b->next);
			long long res = a->time + decide(a->next, ns);
			delete ns;
			return res;
		} else //(b->time < a->time)
		{
			sec *ns = new sec(a->type, a->time - b->time, a->next);
			long long res = b->time + decide(b->next, ns);
			delete ns;
			return res;
		}
	} else
	{
		long long d1, d2;
		//if (a->time == b->time)
		{
			d1 = decide(a->next, b);
			d2 = decide(a, b->next);
		} /*else if (b->time < a->time)
		{
			sec *ns = new sec(a->type, a->time - b->time, a->next);
			d1 = decide(ns, b);
			d2 = decide(a, b->next);
			delete ns;
		} else //(a->time < b->time)
		{
			sec *ns = new sec(b->type, b->time - a->time, b->next);
			d1 = decide(a->next, b);
			d2 = decide(a, ns);
			delete ns;
		}*/
		return d1 < d2 ? d2 : d1;
	}
}

int main()
{
	int T;
	cin >> T;

	for (int t = 0; t < T; t++)
	{
		cout << "Case #" << (t+1) << ": ";

		int N, M;

		cin >> N >> M;

		sec *roota, *rootb, *lasta, *lastb;

		roota = new sec(-1, 0, 0);
		rootb = new sec(-1, 0, 0);
		lasta = roota;
		lastb = rootb;

		for (int i = 0; i < N; i++)
		{
			int t;
			long long c;
			cin >> c >> t;
			lasta->next = new sec(t, c, 0);
			lasta = lasta->next;
		}

		for (int i = 0; i < M; i++)
		{
			int t;
			long long c;
			cin >> c >> t;
			lastb->next = new sec(t, c, 0);
			lastb = lastb->next;
		}

		cout << decide(roota, rootb);

		recdel(roota);
		recdel(rootb);

		cout << endl;
	}

	return 0;

}
