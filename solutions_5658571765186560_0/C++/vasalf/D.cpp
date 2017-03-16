#include <iostream>
#include <cstdio>
#include <vector>
#include <string>

using namespace std;

vector<vector<vector<vector<string> > > > polyminoes = 
{{{}},
{{{"#"}}},

{{{"##"},

 {"#",
  "#"}}},

{{{"###"},

 {"#",
  "#",
  "#"}},

 {{"##",
   ".#"},

 {"##",
  "#"}, 

 {"#",
  "##"}, 

 {".#",
  "##"}}},

{{{"##",
   "##"}}, 
  
 {{"##", 
   "#",
   "#"}, 
  
 {"#",
  "#",
  "##"},
   
 {".#",
  ".#",
  "##"},
   
 {"#",
  "###"},
   
 {"###",
  "..#"},
   
 {"##",
  ".#",
  ".#"},
   
 {"###",
  "#"},

 {"..#",
  "###"}},

 {{"#",
  "##",
  "#"},
  
 {".#.",
  "###"},
  
 {".#",
  "##",
  ".#"},

 {"#",
  "##",
  "#"}},
  
 {{"#",
   "#",
   "#",
   "#"},
  
 {"####"}},

 {{"#",
   "##",
   ".#"},
  
 {".#",
  "##",
  "#"},

 {"##", 
  ".##"},
  
 {".##",
  "##"}}}
};

vector<string> cur;

bool good_index(int a, int b, int r, int c)
{
    return 0 <= a && a < r && 0 <= b && b < c;
}

bool fill(int a, int b, int r, int c, int fa, int fb, const vector<string>& figure)
{
    vector<string> ncur = cur;
    for (int i = 0; i < (int)figure.size(); i++)
    {
        for (int j = 0; j < (int)figure[i].size(); j++)
        {
            if (figure[i][j] == '#' && good_index(a + i - fa, b + j - fb, r, c))
            {
                if (cur[a + i - fa][b + j - fb] == '#')
                    return false;
                else
                    ncur[a + i  - fa][b + j - fb] = '#';
            }
            else if (!good_index(a + i - fa, b + j - fb, r, c))
                return false;
        }
    }
    cur = ncur;
    return true;
}

void unfill(int a, int b, int fa, int fb, const vector<string>& figure)
{
    /*cout << endl;
    cout << "### UNFILL ###" << endl;
    cout << a << " " << b << " " << fa << " " << fb << endl;
    cout << endl;
    for (string t : figure)
        cout << t << endl;
    cout << endl;
    for (string t : cur)
        cout << t << endl;
    cout << endl;*/
    for (int i = 0; i < (int)figure.size(); i++)
    {
        for (int j = 0; j < (int)figure[i].size(); j++)
        {
            if (figure[i][j] == '#')
                cur[a + i - fa][b + j - fb] = '.';
        }
    }
    /*for (string t : cur)
        cout << t << endl;
    cout << endl;
    cout << "### END ###" << endl;*/
}

bool can(int a, int b, int r, int c, int x)
{
    if (b == c)
        return can(a + 1, 0, r, c, x);
    if (a == r)
        return true;
    if (cur[a][b] == '#')
        return can(a, b + 1, r, c, x);
    for (auto cls : polyminoes[x])
    {
        for (auto figure : cls)
        {
            for (int i = 0; i < (int)figure.size(); i++)
            {
                for (int j = 0; j < (int)figure[i].size(); j++)
                {
                    if (figure[i][j] == '#')
                    {
                        if (fill(a, b, r, c, i, j, figure))
                        {
                            bool fl = can(a, b + 1, r, c, x);
                            unfill(a, b, i, j, figure);
                            if (fl)
                                return true;
                        }
                    }
                }
            }
        }
    }
    return false;
}

bool place_figure_and_try(int r, int c, int x, const vector<string>& figure)
{
    /*cout << endl;
    for (string t : cur)
        cout << t << endl;
    cout << endl;*/
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (fill(i, j, r, c, 0, 0, figure))
            {
                bool fl = can(0, 0, r, c, x);
                unfill(i, j, 0, 0, figure);
                if (fl)
                    return false; 
            }
        }
    }
    /*cout << endl;
    for (string t : cur)
        cout << t << endl;
    cout << endl;*/
    return true;
}

bool solve(int x, int r, int c)
{
    if ((r * c) % x != 0)
        return true;
    string s(c, '.');
    cur.clear();
    cur.assign(r, s);
    for (auto cls : polyminoes[x])
    {
        bool fl = true;
        for (auto figure: cls)
        {
            if (fl && !place_figure_and_try(r, c, x, figure))
            {
/*            cout << endl;
            for (string t: figure)
                cout << t << endl;
            cout << endl;*/
                fl = false;
            }
        }
        if (fl)
            return true;
    }
    return false;
}

int main()
{
    int t;
    cin >> t;
    for (int test = 1; test <= t; test++)
    {
        int x, r, c;
        cin >> x >> r >> c;
        cout << "Case #" << test << ": ";
        if (solve(x, r, c))
            cout << "RICHARD" << endl;
        else
            cout << "GABRIEL" << endl;
    }
    return 0;
}
