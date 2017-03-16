#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <vector>
#include <utility>
#include <queue>
#include <map>
using namespace std;

typedef long long LL;
typedef unsigned int UINT32;

void combine(vector<pair<LL, int> > &toyes) {
    int n = toyes.size();
    for (int i = n-1; i>=1; --i) {
        if (toyes[i-1].second == toyes[i].second) {
            toyes[i-1].first += toyes[i].first;
            toyes.erase(toyes.begin()+i);
        }
    }
}

LL calc(vector<pair<LL, int> > &boxes, vector<pair<LL, int> > toyes)
{
    int N = boxes.size();
    int M = toyes.size();
    if (N == 0 || M == 0) {
        return 0;
    }

    pair<LL, int> &box = boxes[0];
    pair<LL, int> &toy = toyes[0];
    vector<pair<LL, int> > nboxes = boxes;
    vector<pair<LL, int> > ntoyes = toyes;
    if (box.second == toy.second) {
        LL t;
        if (box.first > toy.first) {
            nboxes[0].first = box.first - toy.first;
            ntoyes.erase(ntoyes.begin());
            t = toy.first;
        } else if (box.first < toy.first) {
            nboxes.erase(nboxes.begin());
            ntoyes[0].first = toy.first - box.first;
            t = box.first;
        } else {
            nboxes.erase(nboxes.begin());
            ntoyes.erase(ntoyes.begin());
            t = toy.first;
        }

        return t + calc(nboxes, ntoyes);
    }

    nboxes.erase(nboxes.begin());
    LL ans = calc(nboxes, ntoyes);

    nboxes.insert(nboxes.begin(), boxes[0]);
    ntoyes.erase(ntoyes.begin());
    LL t = calc(nboxes, ntoyes);
    if (t > ans) ans = t;

    return ans;



    /*
    int i, j, k;
    LL ans = 0;
    for (i = 0; i < N; ++i) {
        pair<LL, int> &box = boxes[i];
        for (j = 0; j < M; ++j) {
            pair<LL, int> &toy = toyes[j];
            if (box.second != toy.second) continue;

            LL t = toy.first;

            vector<pair<LL, int> > nboxes;
            vector<pair<LL, int> > ntoyes;
            if (box.first > toy.first) {
                nboxes.push_back(make_pair(box.first - toy.first, box.second));
            } 
            
            if (box.first < toy.first) {
                nboxes.push_back(make_pair(toy.first - box.first, box.second));
                t = box.first;
            }

            for (k = i+1; k < N; ++k) {
                nboxes.push_back(boxes[k]);
            }
            for (k = j+1; k < M; ++k) {
                ntoyes.push_back(toyes[k]);
            }

            t += calc(nboxes, ntoyes);
            if (t > ans) ans = t;
        }
    }

    return ans;
    */
}

string calc()
{
    int N, M;
    cin >> N >> M;

    vector<pair<LL, int> > boxes(N);
    vector<pair<LL, int> > toyes;

    vector<int> types(101, 0);

    int i;
    for (i = 0; i < N; ++i) {
        cin >> boxes[i].first >> boxes[i].second;
        types[boxes[i].second] = 1;
    }
    for (i = 0; i < M; ++i) {
        LL n;
        int t;
        cin >> n >> t;
        if (types[t]) {
            toyes.push_back(make_pair(n, t));
        }
    }

    vector<int> types2(101, 0);
    for (i = 0; i < toyes.size(); ++i) {
        types2[toyes[i].second] = 1;
    }

    for (i = N-1; i >= 0; --i) {
        if (types2[boxes[i].second] == 0) {
            boxes.erase(boxes.begin() + i);
        }
    }

    combine(boxes);
    combine(toyes);

    stringstream S;
    LL ans = calc(boxes, toyes);
    S << ans;

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
