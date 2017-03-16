#include <vector>
#include <list>
#include <map>
#include <set>
#include <stack>
#include <algorithm>
#include <utility>
#include <sstream>
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

#define frl(a, b, c) for( a = b; a < c; a++)
#define fru(a, b, c) for( a = b; a <= c; a++)
#define frd(a, b, c) for( a = b; a >= c; a--)
#define mst(a, b) memset(a, b, sizeof(a))
#define si(a) scanf("%d", &a)
#define ss(a) scanf("%s", a)
#define sc(a) scanf("%c", &a)
#define pb(a) push_back(a)
#define mp make_pair

#define ssz(s) s.size()
#define bg(v) v.begin()
#define ed(v) v.end()

typedef pair<int, int> pair_int_int;
typedef pair<string, int> pair_string_int;
typedef pair<int, string> pair_int_string;
typedef pair<string, string> pair_string_string;

typedef set<int> set_int;
typedef set<string> set_str;

typedef vector<int> vector_int;
typedef vector<string> vector_string;
typedef vector<pair_int_int> vector_pair_int_int;
typedef vector<pair_string_string> vector_pair_string_string;
long long muli[100005];
long long a[100005];
long long muli1[100005];
long long op[100005][3];
string str;
int i = 1;

void go_west(int x)
{
    int c = 0;
    while(1)
    {
        if(c - i >= x)
        {
            str += 'W';
            c-= i;
            i++;
        }
        else
            break;
    }
    while(1)
    {
        if(c - 1 >= x)
        {
            str += "EW";
            c--;
            i+=2;
        }
        else
            break;
    }
}

void go_east(int x)
{
    int c = 0;
    while(1)
    {
        if(c + i <= x)
        {
            str += 'E';
            c+= i;
            i++;
        }
        else
            break;
    }
    while(1)
    {
        if(c + 1 <= x)
        {
            str += "WE";
            c++;
            i+=2;
        }
        else
            break;
    }
}

void go_north(int x)
{
    int c = 0;
    while(1)
    {
        if(c + i <= x)
        {
            str += 'N';
            c+= i;
            i++;
        }
        else
            break;
    }
    while(1)
    {
        if(c + 1 <= x)
        {
            str += "SN";
            c++;
            i+=2;
        }
        else
            break;
    }
}

void go_south(int x)
{
    int c = 0;
    while(1)
    {
        if(c - i >= x)
        {
            str += 'S';
            c-= i;
            i++;
        }
        else
            break;
    }
    while(1)
    {
        if(c - 1 >= x)
        {
            str += "NS";
            c--;
            i+=2;
        }
        else
            break;
    }
}


int main()
{
    int south[100];
    int t, x, y, curr_x, curr_y;
    cin >> t;
    int testi = 1;
    while(t--)
    {
        i = 1;
        str.clear();
        cin >> x >> y;
        if(x < 0)
            go_west(x);
        else
            go_east(x);
        if(y < 0)
            go_south(y);
        else
            go_north(y);
        cout << "Case #" << testi++ << ": " << str << endl;
    }
}
