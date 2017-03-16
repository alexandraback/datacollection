#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

//#define DEBUG

struct car
{
	char lane;
	long double speed;
	long double pos;
};

struct event
{
	long double time;
	int changeLaneCar;
	bool willCollide;
};

ostream& operator << (ostream& os, const car& c)
{
	os << '[' << c.lane << ' ' << c.speed << ' ' <<c.pos<<']';
}

ostream& operator << (ostream& os, const event& c)
{
	os << '(' << c.time << ' ' << c.changeLaneCar << ' ' <<c.willCollide<<')' << endl;;
}
bool operator <(const car& lhs, const car& rhs)
{
	return lhs.pos < rhs.pos || lhs.pos == rhs.pos && lhs.lane < rhs.lane;
};

long double eps = 1e-7;

int N;
vector<car> v;
bool exist(long double pos, char lane, int except = -1)
{
	for(int i = 0; i < N; i ++)
	{
		if (i == except)
			continue;
		if (v[i].lane == lane && 
			v[i].pos > pos-5 && 
			v[i].pos < pos+5)
		{
			return true;
		}
	}
	return false;
}

void push_to_right()
{
	for(int i = 0; i < N; i++)
	{
		if (v[i].lane == 'L')
		{
			if (!exist(v[i].pos, 'R', i))
			{
				v[i].lane = 'R';
			}
		}
	}
}

event next_event()
{
	event e;
	e.time = -1;
	e.changeLaneCar = -1;
	e.willCollide = false;
	for(int i = 0; i < N; i++)
	{
		for(int j = i+1; j < N; j ++)
		{
			car* a = &v[i];
			car* b = &v[j];
			int aidx = i;
			int bidx = j;
			if (a->speed == b->speed)
			{
				// ignore
				continue;
			}
			if (a->speed > b->speed)
			{
				swap(a,b);
				swap(aidx, bidx);
			}

			// fast: b
			if (a->lane == b->lane)
			{
				if (b->pos >= a->pos+5)
					continue;
				if (b->pos <= a->pos-5)
				{
					long double t = (a->pos-5-b->pos) / (b->speed-a->speed);
					#ifdef DEBUG
					cout <<"C" << t << ' ' << aidx << ' ' << bidx << endl;
					#endif
					if (e.time < 0 || e.time > t)
					{
						e.time = t;
						e.changeLaneCar = bidx;
						e.willCollide = true;
					}
				}
				else
				{
					// ?!
					cout << "KIN" << aidx << ' ' << bidx << ' ' << b->pos - a->pos << endl;
				}
			}
			else
			{
				if (b->pos > a->pos+5 || b->pos < a->pos-5)
					continue;
				if (b->pos > a->pos+5)
					continue;
				long double t = (a->pos+5 - b->pos)/(b->speed - a->speed);
					#ifdef DEBUG
					cout <<"!" << t << ' ' << aidx << ' ' << bidx << endl;
					#endif
				if (t>0)
				if (e.time < 0 || e.time > t)
				{
					e.time = t;
					e.willCollide = false;
					if (a->lane == 'L')
						e.changeLaneCar = aidx;
					else
						e.changeLaneCar = bidx;
				}
			}
		}
	}
	return e;
}

int main()
{
	cin.sync_with_stdio(false);
	cout.sync_with_stdio(false);
	int tn;
	cin >> tn;
	for(int loop = 0 ; loop < tn; loop++)
	{
		cout << "Case #" << loop+1<<": ";
		cin >> N;

		v.clear();
		//algorithm: prefer right
		for(int i = 0; i < N; i ++)
		{
			car c;
			std::string l;
			cin >> l >> c.speed >> c.pos;
			c.lane = l[0];
			v.push_back(c);
		}
		sort(v.begin(), v.end());
		push_to_right();
					#ifdef DEBUG
		for(int i = 0; i < N; i ++)
			cout << v[i] << endl;
		cout << endl;
#endif
		long double currentTime = 0;
		bool forever = false;
		while(1)
		{
			event e = next_event();
#ifdef DEBUG
			cout << currentTime<<endl;
			cout << e;
#endif
			if (e.time < 0)
			{
				forever = true;
				break;
			}
			for(int i = 0; i < N;i++)
			{
				v[i].pos += v[i].speed*e.time;
			}
			car& c = v[e.changeLaneCar];
			char anotherLane = 'L';
			if (c.lane == 'L')
				anotherLane = 'R';
			currentTime += e.time;
#ifdef DEBUG
			for(int i = 0; i < N; i ++)
				cout << v[i] << endl;
			cout << endl;
			cout << anotherLane << endl;
#endif
			if (exist(c.pos+eps, anotherLane, e.changeLaneCar))
			{
				if (e.willCollide)
				{
#ifdef DEBUG
					cout << "by collide" << endl;
#endif
					break;
				}
			}
			else
			{
				c.lane = anotherLane;
			}
		}
		if (forever)
		{
			cout << "Possible" << endl;
		}
		else
		{
			cout << currentTime << endl;
		}
	}
	return 0;
}

