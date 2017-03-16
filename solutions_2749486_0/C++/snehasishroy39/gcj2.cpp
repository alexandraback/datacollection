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

long long mul[100005];
long long a[100005];
long long mul1[100005];
long long op[100005][3];
string str;
int klm = 1;

void west_m_jao(int xgf)
{
    int cntt = 0;
    while(1)
    {
        if(cntt - klm >= xgf)
        {
            str += 'W';
            cntt-= klm;
            klm++;
        }
        else
            break;
    }
    while(1)
    {
        if(cntt - 1 >= xgf)
        {
            str += "EW";
            cntt--;
            klm+=2;
        }
        else
            break;
    }
}

void east_m_jao(int xgf)
{
    int cntt = 0;
    while(1)
    {
        if(cntt + klm <= xgf)
        {
            str += 'E';
            cntt+= klm;
            klm++;
        }
        else
            break;
    }
    while(1)
    {
        if(cntt + 1 <= xgf)
        {
            str += "WE";
            cntt++;
            klm+=2;
        }
        else
            break;
    }
}

void north_m_jao(int xgf)
{
    int cntt = 0;
    while(1)
    {
        if(cntt + klm <= xgf)
        {
            str += 'N';
            cntt+= klm;
            klm++;
        }
        else
            break;
    }
    while(1)
    {
        if(cntt + 1 <= xgf)
        {
            str += "SN";
            cntt++;
            klm+=2;
        }
        else
            break;
    }
}

void south_m_jao(int xgf)
{
    int cntt = 0;
    while(1)
    {
        if(cntt - klm >= xgf)
        {
            str += 'S';
            cntt-= klm;
            klm++;
        }
        else
            break;
    }
    while(1)
    {
        if(cntt - 1 >= xgf)
        {
            str += "NS";
            cntt--;
            klm+=2;
        }
        else
            break;
    }
}


int main()
{
    int tot11, snehasish, pooh;
    cin >> tot11;
    int cases = 1;
    while(tot11--)
    {
        klm = 1;
        str.clear();
        cin >> snehasish >> pooh;
        if(snehasish < 0)
            west_m_jao(snehasish);
        else
            east_m_jao(snehasish);
        if(pooh < 0)
            south_m_jao(pooh);
        else
            north_m_jao(pooh);
        cout << "Case #" << cases++ << ": " << str << endl;
    }
}


