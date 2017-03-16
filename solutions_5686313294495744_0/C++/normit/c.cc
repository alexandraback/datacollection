#include <cstdio>
#include <iostream>
#include <map>
#include <vector>

#define mp make_pair
#define pb push_back

#define REP(i, n) for(int i = 0; i < (n); ++i)
#define REP2(i, s, n) for (int i = (s); i < (n); ++i)

#define MAX(a,b) ((a) > (b) ? (a) : (b))

using namespace std;
typedef long long ll;

struct Topic
{
    Topic(int _s, int _e) : s(_s), e(_e) {}
    int s, e;
};

vector<Topic> topics;
int sss[2000] = {0, };
int eee[2000] = {0, };
int ns = 0;
int ne = 0;

int res = 0;

void go(int index, int fake)
{
    int n = topics.size();
    if (index == n) {
        REP(i, ns) if (!sss[i+1]) return;
        REP(i, ne) if (!eee[i+1]) return;
        res = MAX(fake, res);
        return;
    }

    Topic topic = topics[index];
    if (sss[topic.s] > 0 && eee[topic.e] > 0) go(index+1, fake+1);
    else {
        go(index+1, fake+1);
        sss[topic.s]++;
        eee[topic.e]++;
        go(index+1, fake);
        sss[topic.s]--;
        eee[topic.e]--;
    }
}

void solve()
{
    int n;
    cin >> n;

    map<string, int> first;
    map<string, int> second;

    topics.clear();
    ns = 0;
    ne = 0;


    REP(i, n) {
        string ss, ee;
        cin >> ss >> ee;
        if (!first[ss]) first[ss] = (++ns);
        if (!second[ee]) second[ee] = (++ne);

        topics.pb(Topic(first[ss], second[ee]));

        Topic topic = topics[topics.size()-1];
        //cout << topic.s << " " << topic.e << endl;
    }

    REP(i, 2000) { eee[i] = sss[i] = 0;}

    res = -1;
    go(0, 0);

    cout << res << endl;

    //cout << topics.size() - MAX(ns, ne) << endl;
}

int main()
{
	int t;
	cin >> t;
	for(int i = 1; i <= t; ++i) {
		cout << "Case #" << i << ": ";
		solve();
	}

	return 0;
}
