#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

int solve(const vector<int> &ts, int S, int p)
{
    int ans = 0;
    for (int i = 0; i < ts.size(); ++i)
    {
        int q = ts[i] / 3;
        int r = ts[i] % 3;

        bool not_surprising = false;
        bool surprising = false;
        switch (r)
        {
        case 0:
            if (q >= p) not_surprising = true;
            else if (q > 0 && q + 1 >= p) surprising = true;
            break;
        case 1:
            if (q + 1 >= p) not_surprising = true;
            break;
        case 2:
            if (q + 1 >= p) not_surprising = true;
            else if (q + 2 >= p) surprising = true;
            break;
        default:
            assert(false);
        }

        if (not_surprising)
        {
            ++ans;
        }
        else if (surprising && S > 0)
        {
            ++ans;
            --S;
        }
    }

    return ans;
}

int main()
{
    int T;
    cin>>T;

    for (int i = 0; i < T; ++i)
    {
        int N, S, p;
        cin>>N>>S>>p;

        vector<int> ts(N);
        for (int j = 0; j < N; ++j)
        {
            cin>>ts[j];
        }

        cout<<"Case #"<<i + 1<<": "<<solve(ts, S, p)<<endl;
    }

    return 0;
}
