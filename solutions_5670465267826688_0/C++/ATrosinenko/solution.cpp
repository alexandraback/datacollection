#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <assert.h>

using namespace std;

const int MAXLX = 200000;
int mul[MAXLX + 10];

enum {e, E, i, I, j, J, k, K};
int mul_table[8][8];

int neg(int x)
{
    switch(x)
    {
        case e: return E;
        case E: return e;
        case i: return I;
        case I: return i;
        case j: return J;
        case J: return j;
        case k: return K;
        case K: return k;
        default: assert(0 /* neg() */);
    }
}

int from_letter(char ch)
{
    switch(ch)
    {
        case 'i': return i;
        case 'j': return j;
        case 'k': return k;
        default: assert(0 /* from_letter() */);
    }
}

char to_letter(int x)
{
    switch(x)
    {
        case e: return 'e';
        case E: return 'E';
        case i: return 'i';
        case I: return 'I';
        case j: return 'j';
        case J: return 'J';
        case k: return 'k';
        case K: return 'K';
        default: assert(0 /* to_letter() */);
    }
}

void put(int a, int b, int c)
{
    mul_table[a     ][b     ] =     c ;
    mul_table[neg(a)][b     ] = neg(c);
    mul_table[a     ][neg(b)] = neg(c);
    mul_table[neg(a)][neg(b)] =     c ;
}

void put_e(int x)
{
    put(e, x, x);
    put(x, e, x);
}

void init_mul_table()
{
    put_e(e);
    put_e(i);
    put_e(j);
    put_e(k);
    
    put(i, i, E);
    put(j, j, E);
    put(k, k, E);
    
    put(i, j, k);
    put(j, i, K);
    
    put(j, k, i);
    put(k, j, I);
    
    put(k, i, j);
    put(i, k, J);
}

int find(const string &line, int start, char x)
{
    for(int l = start; l < line.size(); ++l)
        if(mul[l] == x)
            return l + 1;
    return 0;
}

void solve(const int t)
{
    int L, X;
    string input_line, line;
    cin >> L >> X >> input_line;
    
    if(X > 20)
        X = (X - 12) % 4 + 12;
    for(int _i = 0; _i < X; ++_i)
        line += input_line;
    
    mul[0] = from_letter(line[0]);
    for(int _i = 1; _i < line.size(); ++_i)
        mul[_i] = mul_table[mul[_i - 1]][from_letter(line[_i])];
    
/*    for(int _i = 0; _i < line.size(); ++_i)
        cerr << to_letter(mul[_i]);
    cerr << "\n";
*/
    
    int start_j = find(line, 0, i);
    int start_k = find(line, start_j, mul_table[i][j]);
    
/*    cerr << start_j << " " << start_k << "\n"; */
    
    cout << "Case #" << t << ": ";
    if(start_j && start_k && mul[line.size() - 1] == mul_table[mul_table[i][j]][k])
        cout << "YES\n";
    else
        cout << "NO\n";
}

int main()
{
    int T;
    init_mul_table();
    cin >> T;
    for(int t = 1; t <= T; ++t)
    {
        cerr << "Solving #" << t << "\n";
        solve(t);
    }
    return 0;
}
