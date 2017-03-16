#include <bits/stdc++.h>

using namespace std;

template<typename T>
ostream& operator << (ostream& o, vector<T>& v)
{
    o << "[";
    for(size_t i = 0; i < v.size(); i++)
    {
        o << v[i];
        if(i != v.size() - 1)
            o << ", ";
    }
    o << "]";
    return o;
}

typedef long double ld;

int main(int argc, char* argv[])
{
    (void)argc; (void)argv;
    freopen("C-small-1-attempt4.in", "r", stdin);
    freopen("C-small-1-attempt4.out", "w", stdout);
    int n_casi;
    cin >> n_casi;
    for(int caso = 1; caso <= n_casi; caso++)
    {
        long long int n;
        cin >> n;
        ld hik[2][2];
        long long int prog = 0;
        for(long long int i = 0; i < n; i++)
        {
            long long int start;
            cin >> start;
            long long int hn;
            cin >> hn;
            long long int lun;
            cin >> lun;
            if(hn == 1)
            {
                hik[prog][0] = start;
                hik[prog][1] = lun;
                prog++;
            }
            else
            {
                hik[prog][0] = start;
                hik[prog+1][0] = start;
                hik[prog][1] = lun;
                hik[prog+1][1] = lun + 1;
                prog += 2;
            }
        }
        assert(prog <= 2);
        if(prog <= 1 || hik[0][1] == hik[1][1])
        {
            cout << "Case #" << caso << ": " << 0 << endl;
            continue;
        }
        if(hik[0][0] > hik[1][0])
            swap(hik[0], hik[1]);
        if(hik[0][0] == hik[1][0] && hik[0][1] < hik[1][1])
            swap(hik[0], hik[1]);
        long double my_pos = 0.0, my_pos_prev = 1000000.0;
        while(fabs(my_pos - my_pos_prev) > 0.1)
        {
            ld time_spent = fmod(fabs(my_pos - hik[1][0]), 360.0) / 360.0 * hik[1][1];
            hik[1][0] = my_pos;
            hik[0][0] = hik[0][0] + (time_spent / hik[0][1] * 360.0);
            my_pos_prev = my_pos;
            my_pos = hik[0][0];

        }
        if(my_pos < 359.9999999999)
            cout << "Case #" << caso << ": " << 0 << endl;
        else
            cout << "Case #" << caso << ": " << 1 << endl;
        cerr << "Case #" << caso << endl;
    }
    return EXIT_SUCCESS;
}
