#include <math.h>
#include <vector>
#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

int step(int s, int d)
{
    int cnt = 0;
    while (s < d)
    {
        s = s + s-1;
        cnt++;
    }
    return cnt;
}

int maxv(int s, int step)
{
    for (int i = 0; i < step; i++)
    {
        s = s + s-1;
    }
    return s;
}

int alg(vector<int> ele, int s)
{
    if (ele.size() == 0)
        return 0;

    vector<int> nex(ele.begin()+1, ele.end());

    int dif = s - ele[0];
    if (dif > 0)
        return alg(nex, s+ele[0]);
    // drop
    int r2 = 1 + alg(nex, s);

    if (s == 1)
        return r2;

    // add
    int st = step(s, ele[0]+1);
    int r1 = st + alg(nex, maxv(s, st)+ele[0]);

    return min(r1, r2);
}

int main(int argc, char** argv)
{
    int T;
    cin >> T;

    for (int i = 0 ; i < T; i++)
    {
        int A, N;
        cin >> A >> N;
        vector<int> motes;
        for (int j = 0; j < N; j++)
        {
            int tmp;
            cin >> tmp;
            motes.push_back(tmp);
            // debug
            //cout << motes[motes.size()-1] << endl;
        }

        sort(motes.begin(), motes.end());

        // main algorithm
        int res = alg(motes, A);

        cout << "Case #" << i+1 << ": ";
        cout << res << endl;
    }

    return 0;
}

