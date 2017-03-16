#include <iostream>
#include <vector>

using namespace std;

bool getbit(int x, int pos)
{
    return (x & (1 << pos)) != 0;
}

vector<pair<int, int> > decompose(int ub)
{
    vector<pair<int, int> > dec;
    int base = 0;
    for (int pos = 30; pos >= 0; --pos)
    {
        if (!getbit(ub, pos))
            continue;
        dec.push_back(pair<int, int>(base, pos));
        base |= 1 << pos;
    }
    return dec;
}

int main()
{
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    for (int testcase = 1; testcase <= T; ++testcase)
    {
        int A, B, K;
        cin >> A >> B >> K;
        vector<pair<int, int> > Ad = decompose(A);
        vector<pair<int, int> > Bd = decompose(B);
        vector<pair<int, int> > Kd = decompose(K);
        long long ans = 0LL;
        for (auto itA = Ad.begin(); itA != Ad.end(); ++itA)
        {
            int Abase = itA->first;
            int Apos = itA->second;
            for (auto itB = Bd.begin(); itB != Bd.end(); ++itB)
            {
                int Bbase = itB->first;
                int Bpos = itB->second;
                for (auto itK = Kd.begin(); itK != Kd.end(); ++itK)
                {
                    int Kbase = itK->first;
                    int Kpos = itK->second;
                    long long count = 1LL;
                    for (int pos = 30; pos >= Kpos; --pos)
                    {
                        if (getbit(Kbase, pos))
                        {
                            if ((pos >= Apos && !getbit(Abase, pos)) ||
                                (pos >= Bpos && !getbit(Bbase, pos)))
                            {
                                count = 0;
                            }
                        }
                        else
                        {
                            if (pos < Apos && pos < Bpos)
                                count *= 3;
                            else if (pos < Apos)
                            {
                                if (!getbit(Bbase, pos))
                                    count *= 2;
                            }
                            else if (pos < Bpos)
                            {
                                if (!getbit(Abase, pos))
                                    count *= 2;
                            }
                            else
                            {
                                if (getbit(Abase, pos) && getbit(Bbase, pos))
                                    count = 0;
                            }
                        }
                    }
                    for (int pos = Kpos - 1; pos >= 0; --pos)
                    {
                        if (pos < Apos)
                            count *= 2;
                        if (pos < Bpos)
                            count *= 2;
                    }
                    ans += count;
                }
            }
        }
        cout << "Case #" << testcase << ": " << ans << "\n";
    }
    return 0;
}
