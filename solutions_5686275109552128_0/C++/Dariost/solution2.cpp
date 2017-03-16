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
    freopen("B-small-attempt3.in", "r", stdin);
    freopen("B-small-attempt3.out", "w", stdout);
    int n_casi;
    cin >> n_casi;
    for(int caso = 1; caso <= n_casi; caso++)
    {
        size_t n_diners;
        cin >> n_diners;
        vector<int> pancakes;
        for(size_t i = 0; i < n_diners; i++)
        {
            int tmp;
            cin >> tmp;
            pancakes.push_back(tmp);
        }
        int turn = 1;
        int max_pile = *max_element(pancakes.begin(), pancakes.end());
        int act_best = max_pile;
        while(turn < max_pile)
        {
            int add_turns = 0;
            for(size_t i = 0; i < pancakes.size(); i++)
            {
                if(pancakes[i] > turn)
                {
                    add_turns += (pancakes[i] / turn) - 1;
                    if(pancakes[i] % turn != 0)
                        add_turns++;
                }
            }
            act_best = min(act_best, add_turns + turn);
            turn++;
        }
        cout << "Case #" << caso << ": " << act_best << endl;
        cerr << "Case #" << caso << ": " << act_best << endl;
    }
    return EXIT_SUCCESS;
}
