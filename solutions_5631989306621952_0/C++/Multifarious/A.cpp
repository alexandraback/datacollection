
#include <cstdlib>
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <map>
#include <algorithm>
#include <cstdio>
#include <sstream>
#include <stack>
#include <cmath>
#include <string.h>
#include <queue>
#include <set>
using namespace std;
 
typedef vector < string > vs;
typedef vector <int> vi;
#define FOREACH(it,c) for(typeof((c).begin()) it=(c).begin();it!=(c).end();++it)
#define deb(x) cout << #x << ": " << x << endl;
#define debv(x) for(int i = 0; i < (x).size(); i++) cout << x[i] << ' '; cout << endl;

string game = "";
int NG;

string gsolve(int pos)
{
    if(pos == 0)
        return "";
    char lg = game[0];
    int fpos = 0;
    for(int idx = 0; idx < pos; idx++)
    {
        if(lg < game[idx])
        {
            lg = game[idx];
            fpos = idx;
        }
    }
    string all_lg = "";
    for(int idx = 0; idx < pos; idx++)
    {
        if(lg == game[idx])
        {
            all_lg += lg;
        }
    }
    string before = gsolve(fpos);
    string after = "";
    for(int idx = fpos; idx < pos; idx++)
    {
        if(lg != game[idx])
        {
            after += game[idx];
        }
    }
    string ret = all_lg + before + after;

    return ret;
}


int main()
{
    int T;
	cin >> T;

	for(int tcase = 1; tcase <= T; tcase++)
	{
        game = "";
        cin >> game;
        NG = game.size();

        string ret = gsolve(NG);

        cout << "Case #" << tcase << ": " << ret << endl;
	}
	return 0;
}