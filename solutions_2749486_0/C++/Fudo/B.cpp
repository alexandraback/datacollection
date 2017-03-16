#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>
#include <map>
#include <set>
#include <list>

using namespace std;

struct state_Pos
{
    long long x,y;
    char d;
    state_Pos *prev;
};

//int max_num = 2*200;
long long mo[8] = {1,0,0,1,-1,0,0,-1};
char dir[5] = "ENWS";

struct GCase
{
    long long x;
    long long y;
    vector<char> sol;

    vector<state_Pos*> states;
    //state_Pos* endPos;
    void solve()
    {
        if (x < 0)
            for (int i = 0; i < abs(x); ++i)
            {
                sol.push_back(0);
                sol.push_back(2);
            }
        else
            for (int i = 0; i < abs(x); ++i)
            {
                sol.push_back(2);
                sol.push_back(0);
            }
        if (y < 0)
            for (int i = 0; i < abs(y); ++i)
            {
                sol.push_back(1);
                sol.push_back(3);
            }
        else
            for (int i = 0; i < abs(y); ++i)
            {
                sol.push_back(3);
                sol.push_back(1);
            }
        //state_Pos* st = new state_Pos;
        //st->x = st->y = 0;
        //st->prev = NULL;
        //states.push_back(st);
        //for (int i = 1; i < 501; ++i)
        //{
        //    cerr << i << endl;
        //    vector<state_Pos*> newStates;
        //    for (int k = 0; k < states.size(); ++k)
        //    {
        //        state_Pos* cur = states[k];
        //        for (int j = 0; j < 4; ++j)
        //        {
        //            state_Pos *a = new state_Pos;
        //            a->d = j;
        //            a->x = cur->x + mo[j*2] * i;
        //            a->y = cur->y + mo[j*2+1] * i;
        //            a->prev = cur;
        //            if (a->x == x && a->y == y)
        //            {
        //                endPos = a;
        //                return;
        //            }
        //            newStates.push_back(a);
        //        }
        //    }
        //    states.assign(newStates.begin(), newStates.end());
        //}
        //for (int i = 1; i < 501; ++i)
    }

    void collect()
    {
        //state_Pos *cur = endPos;
        //while (cur)
        //{
        //    if (cur->prev == NULL)
        //        break;
        //    sol.push_back(cur->d);
        //    cur = cur->prev;
        //}
        //for (int i = 0; i < sol.size(); ++i)
        //    cout << dir[sol[sol.size() - i - 1]];
        for (int i = 0; i < sol.size(); ++i)
            cout << dir[sol[i]];
    }
};

int g_nCases = 0;
vector<GCase*> g_cases;

void read_input()
{
    cin >> g_nCases;
    for (int i = 0; i < g_nCases; ++i)
    {
        GCase* gc = new GCase;
        // do sth
        cin >> gc->x;
        cin >> gc->y;
        g_cases.push_back(gc);
    }
}

int main(int argc, char**argv)
{
    read_input();

    for (int i = 0; i < g_nCases; ++i)
    {
        g_cases[i]->solve();
        cout << "Case #" << i+1 << ": ";
        g_cases[i]->collect();
        cout << endl;
    }
    return 0;
}