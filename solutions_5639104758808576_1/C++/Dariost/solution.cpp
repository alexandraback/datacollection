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

int main(int argc, char* argv[])
{
    (void)argc; (void)argv;
    freopen("A-large.in", "r", stdin);
    freopen("A-large.out", "w", stdout);
    int n_casi;
    cin >> n_casi;
    for(int caso = 1; caso <= n_casi; caso++)
    {
        int max_shy;
        cin >> max_shy;
        string shys;
        cin >> shys;
        vector<int> shy_values;
        for(size_t i = 0; i < shys.size(); i++)
            shy_values.push_back(shys[i] - '0');
        assert(max_shy + 1 == shys.size());
        int act_count = 0;
        int agg_count = 0;
        act_count = shy_values[0];
        for(size_t i = 1; i < shy_values.size(); i++)
        {
            if(act_count >= i)
                act_count += shy_values[i];
            else
            {
                agg_count += i - act_count;
                act_count = i + shy_values[i];
            }
        }
        cout << "Case #" << caso << ": " << agg_count << endl;
    }
    return EXIT_SUCCESS;
}
