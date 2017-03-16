#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cstdio>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <utility>
#include <vector>

using namespace std;

#define REP(i,n) for(int (i)=0;(i)<(int)(n);(i)++)
#define RANGE(i,b,e) for(int (i)=(b);(i)<(int)(e);(i)++)
#define CRANGE(i,b,e) for(int (i)=(b);(i)<=(int)(e);(i)++)
#define RRANGE(i,b,e) for(int (i)=(b);(i)>=(int)(e);(i)--)
#define foreach(c,itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)
#define PI 3.1415926535897932384626433832795
#define INF 0x7FFFFFFF

int T;
int N;
vector<double> nao, ken;

int play_dw()
{
    vector<double> n = nao, k = ken;
    int score = 0;
    for (int i = 0;i < N;i++) {
        double min_n = n[0];
        //double max_n = n[n.size() - 1];
        double min_k = k[0];
        //double max_k = k[k.size() - 1];

        if (min_n > min_k) {
            score++;
            n.erase(n.begin());
            k.erase(k.begin());
        } else {
            n.erase(n.begin());
            k.erase(k.end() - 1);
        }
    }
    return score;
}

int play_w()
{
    vector<double> n = nao, k = ken;
    int score = 0;
    for (int i = 0;i < N;i++) {
        double min_n = n[0];
        bool kwin = false;
        for (int j = 0;j < k.size();j++) {
            if (k[j] > min_n) {
                k.erase(k.begin() + j);
                kwin = true;
                break;
            }
        }
        if (!kwin) {
            k.erase(k.begin());
            score++;
        }
        n.erase(n.begin());
    }
    return score;
}

int main(int argc, char **argv)
{
    cin >> T;
    for (int t = 0;t < T;t++) {
        N = 0;
        nao.clear();
        ken.clear();

        cin >> N;
        REP(i, N) {
            double d;
            cin >> d;
            nao.push_back(d);
        }
        sort(nao.begin(), nao.end());
        REP(i, N) {
            double d;
            cin >> d;
            ken.push_back(d);
        }
        sort(ken.begin(), ken.end());

        int dw = play_dw();
        int w = play_w();

        cout << "Case #" << t + 1 << ": ";
        cout << dw << " " << w;
        cout << endl;
    }

    return 0;
}
