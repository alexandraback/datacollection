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
    freopen("D-small-attempt0.in", "r", stdin);
    freopen("D-small-attempt0.out", "w", stdout);
    int n_casi;
    cin >> n_casi;
    for(int caso = 1; caso <= n_casi; caso++)
    {
        int x, r, c;
        cin >> x;
        cin >> r;
        cin >> c;
        bool richard_win = true;
        if(x >= 7)
            richard_win = true;
        else if(x == 1)
            richard_win = false;
        else if(x == 2)
        {
            if((r*c)%2==0)
                richard_win = false;
            else
                richard_win = true;
        }
        else if(x == 3)
        {
            if((r*c)%3==0 && (r > 1 && c > 1))
                richard_win = false;
            else
                richard_win = true;
        }
        else if(x == 4)
        {
            if((r*c)%4==0 && (r > 2 && c > 2))
                richard_win = false;
            else
                richard_win = true;
        }
        cout << "Case #" << caso << ": " << ((richard_win) ? ("RICHARD") : ("GABRIEL")) << endl;
    }
    return EXIT_SUCCESS;
}
