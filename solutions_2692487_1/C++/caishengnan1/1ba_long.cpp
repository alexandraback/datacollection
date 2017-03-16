#include <math.h>
#include <vector>
#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

long long step(long long s, long long d)
{
    long long cnt = 0;
    while (s < d)
    {
        s = s + s-1;
        cnt++;
    }
    return cnt;
}

long long maxv(long long s, long long step)
{
    for (long long i = 0; i < step; i++)
    {
        s = s + s-1;
    }
    return s;
}

long long alg(vector<long long> ele, long long s)
{
    if (ele.size() == 0)
        return 0;

    vector<long long> nex(ele.begin()+1, ele.end());

    long long dif = s - ele[0];
    if (dif > 0)
        return alg(nex, s+ele[0]);
    // drop
    long long r2 = 1 + alg(nex, s);

    if (s == 1)
        return r2;

    // add
    long long st = step(s, ele[0]+1);
    long long r1 = st + alg(nex, maxv(s, st)+ele[0]);

    return min(r1, r2);
}

int main(int argc, char** argv)
{
    long long T;
    cin >> T;

    for (long long i = 0 ; i < T; i++)
    {
        long long A, N;
        cin >> A >> N;
        vector<long long> motes;
        for (long long j = 0; j < N; j++)
        {
            long long tmp;
            cin >> tmp;
            motes.push_back(tmp);
            // debug
            //cout << motes[motes.size()-1] << endl;
        }

        sort(motes.begin(), motes.end());

        // main algorithm
        long long res = alg(motes, A);

        cout << "Case #" << i+1 << ": ";
        cout << res << endl;
    }

    return 0;
}

