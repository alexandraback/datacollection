#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
#include <climits>
#include <queue>
#include <bitset>
#include <map>
using namespace std;


pair<char,int> add( char c1, char c2)
{
    if ( c1=='1')
        return {c2, 1};

    if ( c1=='i')
    {
        switch (c2)
        {
            case 'i':
                return {'1',-1};
            case 'j':
                return {'k',1};
            case 'k':
                return {'j', -1};
        }

        throw "1";
    }

    if ( c1=='j')
    {
         switch (c2)
        {
            case 'i':
                return {'k',-1};
            case 'j':
                return {'1',-1};
            case 'k':
                return {'i', 1};
        }

        throw "2";

    }


    if ( c1=='k')
    {
         switch (c2)
        {
            case 'i':
                return {'j',1};
            case 'j':
                return {'i',-1};
            case 'k':
                return {'1', -1};
        }

        throw "3";

    }

    throw "4";

}

template <typename It>
pair<char,int> accum(It left, It right, char c='1', int sgn=1)
{
    for (auto it =left; it != right; ++it)
    {
        auto res = add(c,*it);
        c = res.first;
        sgn *= res.second;
    }

    return {c,sgn};
}


int64_t get( const string& s, int64_t  left, int64_t right, char t, char c)
{
    if (left==right)
        return -1;

    int sgn = 1;
    for (auto i =left; i < right; ++i)
    {
        auto res = add(c, s[i]);
        c = res.first;
        sgn *= res.second;
        if (sgn > 0 && c == t)
            return i;
    }

    return -1;
}


map<int,int> get_period(const string& s)
{
    string start = "1ijk";
    map<int, int> table;
    for (char c : start)
        for (int64_t sgn : {-1,1})
        {
            auto res = accum(s.begin(), s.end(), c, sgn);
            int val = c*10 + sgn;
            int res_val = res.first*10 + res.second;
            table[val] = res_val;
        }

        return table;
}


bool get_final( int64_t tail_size, char c, int sgn, map<int,int>& table )
{
    int val = c*10 + sgn;
    map<int,int64_t> seen;
    seen[val] = -1;

    int64_t pos = 0;
    while ( tail_size)
    {
        val = table[val];
        if (seen.count(val) )
        {
            int64_t period = pos - seen[val];
            tail_size = (tail_size-1) % period;
            break;

        }
        seen[val] = pos;
        pos++;
        tail_size--;
    }


    while(tail_size)
    {
         val = table[val];
         tail_size--;
    }

    c = val/10;
    sgn = val%10 == 1 ? 1:-1;
    return (sgn > 0 && c == 'k');
}


bool solve( string& s, int64_t x)
{
    const int64_t HS = 100;
    const int64_t head_size = min( HS, x);
    const int64_t tail_size = x - head_size;
    string head;
    for (int64_t i=0; i < head_size; i++)
        head += s;


    int64_t l = get(head, 0, head.size(), 'i', '1');
    if (l < 0)
        return false;

//     cout << "l=" << l <<endl;
    int64_t r = get( head, l+1, head.size(), 'j', '1');
    if (r < 0)
        return false;
//         cout << "r=" << r <<endl;

    auto res = accum( head.begin()+r+1, head.end(), '1');

    auto table = get_period(s);
    return get_final(tail_size, res.first, res.second, table);


}



int main()
{
    int t;
    cin >> t;
    for (int cs=1; cs <=t; cs++)
    {
        int64_t l,x;
        cin >> l >> x;
        string s;
        cin >> s;
        //cout << l << x << s << endl;

        bool b2 = solve(s,x);
        cout << "Case #" << cs << ": ";
        string out = b2 ? ("YES") : ("NO");

        cout << out;
        cout << endl ;

    }
}