#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define fr first
#define sc second

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<string> vs;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main()
{
    ios::sync_with_stdio(false);

    ifstream fin ("pancakes.in");
    ofstream fout ("pancakes.out");

    int t;
    fin >> t;

    int d;
    priority_queue<int> pancakes;
    int totaltime;
    int besttime;
    int tmp, u;
    for (int test = 0; test < t; test++) {
        cout << "TEST " << test << endl;
        fin >> d;
        pancakes = priority_queue<int>();
        for (int i = 0; i < d; i++) {
            fin >> tmp;
            pancakes.push(tmp);
        }
        //END INPUT

        totaltime=0;
        besttime = 1000000;

        //KEEP CHOPPING IN HALF, KEEPING TRACK OF BESTTIME SO FAR:
        while(true) {
            //UPDATE BEST TIME
            u = pancakes.top();
            pancakes.pop();

            //UPDATE
            if (u+totaltime < besttime) {
                besttime = u+totaltime;
            }

            if (u%2 == 0) {
                pancakes.push(u/2);
                pancakes.push(u/2);
            } else {
                pancakes.push((u-1)/2);
                pancakes.push((u+1)/2);
            }
            totaltime++;

            if (u <= 1) {
                //WE SHOULD HAVE REACHED OPTIMAL TIME
                break;
            }
        }

        fout << "Case #" << (test+1) << ": " << besttime << "\n";
    }

    return 0;
}
