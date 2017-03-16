#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <vector>
#include <utility>
#include <queue>
#include <map>
#include <set>
using namespace std;

typedef long long LL;
typedef unsigned int UINT32;

vector<pair<int,int> > getMirrors(int r, int c, int H, int W)
{
    vector<pair<int,int> > q;
    q.push_back(make_pair(-r,c));
    q.push_back(make_pair(2*H-r,c));
    q.push_back(make_pair(r,-c));
    q.push_back(make_pair(r,2*W-c));
    return q;
}

int dist2(int x1, int y1, int x2, int y2)
{
    return (x1 - x2) * (x1 - x2) + (y1-y2)*(y1-y2);
}

string calc()
{
    int H, W, D;
    cin >> H >> W >> D;
    vector<string> grid(H);
    int r, c;
    for (int i = 0; i < H; ++i) {
        cin >> grid[i];
        for (int j = 0; j < W; ++j) {
            if (grid[i][j] == 'X') {
                r = i;
                c = j;
            }
        }
    }

    r = 2*r - 1;
    c = 2*c - 1;
    H = 2*(H - 1) - 2;
    W = 2*(W - 1) - 2;

    D *= 2;

    set<pair<int,int> > visited;
    queue<pair<int,int> > q;

    vector<pair<int,int> > mirrors = getMirrors(r, c, H, W);
    for (int i = 0; i < 4; ++i) {
        pair<int, int> m = mirrors[i];
        if (dist2(m.first, m.second, r, c) <= D*D) {
            visited.insert(m);
            q.push(m);
        }
    }

    visited.insert(make_pair(r,c));

    //cout << "r/c: " << r << ' ' << c << endl;
    //cout << "H/W: " << H << ' ' << W << endl;

    vector<pair<int,int> > candidates;

    while (!q.empty()) {
        pair<int, int> cur = q.front(); q.pop();
        candidates.push_back(cur);

        int r1 = cur.first - r;
        int c1 = cur.second - c;

        mirrors = getMirrors(cur.first, cur.second, H, W);
        for (int i = 0; i < 4; ++i) {
            pair<int, int> m = mirrors[i];

            int r2 = m.first - r;
            int c2 = m.second - c;

            if (r1*c2 - c1*r2 == 0) continue;

            if (!visited.count(m) && dist2(m.first, m.second, r, c) <= D*D) {
                visited.insert(m);
                q.push(m);
            }
        }
    }

    /*
    for (int i = 0; i < candidates.size(); ++i) {
        cout << candidates[i].first << ' ' << candidates[i].second << endl;
    }
    */

    sort(candidates.begin(), candidates.end());
    for (int i = candidates.size() - 1; i >= 0; --i) {
        int r1 = candidates[i].first - r;
        int c1 = candidates[i].second - c;
        //for (int j = i -1; j>=0; --j) {
        for (int j = 0; j < candidates.size(); ++j) if (j != i) {
            int r2 = candidates[j].first - r;
            int c2 = candidates[j].second - c;
            if (r1*c2 - c1*r2 != 0) continue;

            int r3 = candidates[j].first - candidates[i].first;
            int c3 = candidates[j].second - candidates[i].second;
            if (r1*r1 + c1*c1 >= r2*r2 + c2*c2 && r3*r3+c3*c3 <= r1*r1+c1*c1) {
                candidates.erase(candidates.begin() + i);
                //cout << "erase" << endl;
                break;
            }
        }
    }

    for (int i = 0; i < candidates.size(); ++i) {
        //cout << candidates[i].first << ' ' << candidates[i].second << endl;
    }

    stringstream S;
    S << candidates.size();
    return S.str();
}

int main(void)
{
	int N;
	cin >> N;

    // NOTE: if using getline() to read the input, the following two lines should be
    // added to read the line sepeartor in the first line. 
    //string line;
    //getline(cin, line);
	for (int i=1; i<=N; ++i) {
		cout << "Case #" << i << ": " << calc() << endl;
	}

	return 0;
}
