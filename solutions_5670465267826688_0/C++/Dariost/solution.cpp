#include <bits/stdc++.h>

using namespace std;

#define sym_one (0)
#define sym_i (1)
#define sym_j (2)
#define sym_k (3)
#define sign_neg (1)
#define sign_pos (0)

typedef pair<int, int> ii;

ii multiply(ii a, ii b)
{
    ii res;
    res.first = a.first ^ b.first;
    if(a.second == sym_one)
    {
        res.second = b.second;
    }
    else if(b.second == sym_one)
    {
        res.second = a.second;
    }
    else if(a.second == b.second)
    {
        res.second = sym_one;
        res.first = !res.first;
    }
    else if(a.second == sym_i)
    {
        if(b.second == sym_j)
        {
            res.second = sym_k;
        }
        else
        {
            res.second = sym_j;
            res.first = !res.first;
        }
    }
    else if(a.second == sym_j)
    {
        if(b.second == sym_k)
        {
            res.second = sym_i;
        }
        else
        {
            res.second = sym_k;
            res.first = !res.first;
        }
    }
    else if(a.second == sym_k)
    {
        if(b.second == sym_i)
        {
            res.second = sym_j;
        }
        else
        {
            res.second = sym_i;
            res.first = !res.first;
        }
    }
    return res;
}

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

int symbol_of(char c)
{
    if(c == 'i')
        return sym_i;
    else if(c == 'j')
        return sym_j;
    else if(c == 'k')
        return sym_k;
    else
        return sym_one;
}

bool find_k(int start, string& s)
{
    ii act_num;
    act_num.first = sign_pos;
    act_num.second = sym_one;
    for(size_t i = start; i < s.size(); i++)
    {
        act_num = multiply(act_num, make_pair(sign_pos, symbol_of(s[i])));
    }
    if(act_num.first == sign_pos && act_num.second == sym_k)
        return true;
    else
        return false;
}

bool find_j(int start, string& s)
{
    ii act_num;
    act_num.first = sign_pos;
    act_num.second = sym_one;
    for(size_t i = start; i < s.size(); i++)
    {
        act_num = multiply(act_num, make_pair(sign_pos, symbol_of(s[i])));
        if(act_num.first == sign_pos && act_num.second == sym_j)
        {
            bool ret = find_k(i + 1, s);
            if(ret)
                return true;
        }
    }
    return false;
}

bool find_i(string& s)
{
    ii act_num;
    act_num.first = sign_pos;
    act_num.second = sym_one;
    for(size_t i = 0; i < s.size(); i++)
    {
        act_num = multiply(act_num, make_pair(sign_pos, symbol_of(s[i])));
        if(act_num.first == sign_pos && act_num.second == sym_i)
        {
            bool ret = find_j(i + 1, s);
            if(ret)
                return true;
        }
    }
    return false;
}

int main(int argc, char* argv[])
{
    (void)argc; (void)argv;
    freopen("C-small-attempt1.in", "r", stdin);
    freopen("C-small-attempt1.out", "w", stdout);
    int n_casi;
    cin >> n_casi;
    bool* risposta = (bool*)calloc(n_casi+1, sizeof(bool));
    int* lens = (int*)calloc(n_casi+1, sizeof(int));
    int* reps = (int*)calloc(n_casi+1, sizeof(int));
    string* s_origs = new string[n_casi+1];
    assert(risposta && lens && reps && s_origs);
    for(int caso = 1; caso <= n_casi; caso++)
    {
        cin >> lens[caso];
        cin >> reps[caso];
        cin >> s_origs[caso];
    }
    #pragma omp parallel for schedule(dynamic)
    for(int caso = 1; caso <= n_casi; caso++)
    {
        int len = lens[caso], rep = reps[caso];
        string s_orig;
        s_orig = s_origs[caso];
        string s;
        for(int i = 0; i < rep; i++)
            s += s_orig;
        bool found = false;
        found = find_i(s);
        risposta[caso] = found;
        cerr << "Case #" << caso << ": " << ((found) ? ("YES") : ("NO")) << endl;
    }
    for(int caso = 1; caso <= n_casi; caso++)
    {
        cout << "Case #" << caso << ": " << ((risposta[caso]) ? ("YES") : ("NO")) << endl;
    }
    return EXIT_SUCCESS;
}
