#include <cstdio>
#include <algorithm>
#include <vector>

typedef long long ll;

using namespace std;

struct Hiker {
	Hiker() : deg(0), time(0) {}
	Hiker(ll deg, ll time) : deg(deg), time(time) {}
	ll deg;
	ll time;
};

bool operator<(const Hiker & h1, const Hiker & h2) {
	if (h1.time != h2.time)
		return h1.time < h2.time;
	return h1.deg < h2.deg;
}

int main() {
	int iC=0, nC;
	scanf("%d", &nC);
	for (iC=1; iC<=nC; iC++) {
		int n;
		scanf("%d", &n);
		vector<Hiker> hikers;

		for (int i=0; i<n; i++) {
			ll d, h, t;
			scanf("%I64d %I64d %I64d", &d, &h, &t);
			for (int i=0; i<h; i++)
				hikers.push_back(Hiker(d, t+i));
		}

		sort(hikers.begin(), hikers.end());

		ll c = 0;
		if (false and hikers.size() == 2) {

			// All units are in 1/360s.
			ll myTime = 360LL*hikers[0].time + (360-hikers[0].deg)*hikers[0].time;
			// The deer will finish just in ahead of the quickest hiker

			// Now we check if we collide with the slowest
			if ((360-hikers[1].deg)*hikers[1].time >= myTime)
				c++;
		}
		else {
			
			c = hikers.size(); // If the deer is faster than all of them
			for (int i=0; i<(int) hikers.size(); i++) {
				ll tc = 0;

				// All units are in 1/360s.
				ll myTime = 360LL*hikers[i].time + (360-hikers[i].deg)*hikers[i].time;

				for (int j=0; j<i; j++)
					tc += (myTime - hikers[j].time*(360-hikers[j].deg)-1) / (360*hikers[j].time);

				for (int j=i+1; j<(int)hikers.size(); j++)
					if ((360-hikers[j].deg)*hikers[j].time >= myTime)
						tc++;

				//printf("%I64d %I64d\n", myTime, tc);

				c = min(c, tc);

				// In the previous we are assuming that we are just a tiny bit faster than hiker i,
				//so if there are some of the slower that end at the same time, we hit them
				// Now we try to be a bit slower than hiker i, so we always hit him, but may not here
				//the slower ones
				for (int j=i+1; j<(int)hikers.size(); j++)
					if ((360-hikers[j].deg)*hikers[j].time == myTime)
						tc--;

				for (int j=0; j<=i; j++)
					if ((myTime - hikers[j].time*(360-hikers[j].deg)) % (360*hikers[j].time) == 0)
						tc++;

				c = min(c, tc);
			}
		}

		bool allSame = false;
		{
			allSame = true;
			ll t = hikers[0].time;
			for (int i=0; i< (int)hikers.size(); i++)
				if (hikers[i].time != t)
					allSame = false;
		}

		if (false and allSame)
			c = 0;

		printf("Case #%d: %I64d\n", iC, c);
	}
	return 0;
}