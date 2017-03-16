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

vector<vector<int> > adjs;
int matched[3000];
int visited[3000] = {0, };

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

bool augment_path(int i)
{
    visited[i] = 1;

    REP(j, adjs[i].size()) {
        int next = adjs[i][j];
        if (visited[next]) continue;

        if (matched[next] == -1) {
            matched[i] = next;
            matched[next] = i;
            return true;
        }

        if (matched[next] != i) {
            visited[next] = 1;
            if (augment_path(matched[next])) {
                matched[i] = next;
                matched[next] = i;
                return true;
            }
        }
    }
    return false;
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

    adjs.resize(3000);
    for(int i = 0; i < adjs.size(); ++i) {
        adjs[i].clear();
        matched[i] = -1;
    }

    REP(i, n) {
        string ss, ee;
        cin >> ss >> ee;
        if (!first[ss]) first[ss] = (++ns);
        if (!second[ee]) second[ee] = (++ne);

        topics.pb(Topic(first[ss], second[ee]));

        int findex = first[ss];
        int sindex = second[ee];

        adjs[findex].pb(sindex+1500);
        adjs[sindex+1500].pb(findex);

        Topic topic = topics[topics.size()-1];
        //cout << topic.s << " " << topic.e << endl;
    }

    //REP(i, 2000) { eee[i] = sss[i] = 0;}

    //res = -1;
    //go(0, 0);

    //cout << res << endl;

    int matching = 0;
    for(int i = 1; i <= ns; ++i) {
        REP(j, 3000) visited[j] = 0;
       if (augment_path(i)) ++matching;
    }

    // for (int i = 1; i <= ns; ++i) {
    //     cout << matched[i] << endl;
    // }
    // cout << matching << endl;
    cout << topics.size() - (ns + ne - matching) << endl;

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
