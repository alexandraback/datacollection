
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

vs strsp(string a, string delim=" ")
{
    vs ret;
    string cr = "";
    for(int i = 0; i < a.size(); i++)
    {
       if(delim.find(a[i])==string::npos) cr += a[i];
       else { if(cr.size()) ret.push_back(cr); cr = ""; }
    }
    if(cr.size()) ret.push_back(cr);
    return ret;
}

int main()
{
    int T;
	cin >> T;

	for(int tcase = 1; tcase <= T; tcase++)
	{
        int GN;
        cin >> GN;
        int LN = 2*GN-1;

        int lines[LN][GN];
        int cnts[5000];
        memset(cnts,0,sizeof(cnts));
        for(int i = 0; i < LN; i++)
        {

            for(int j = 0; j < GN; j++)
            {
                cin >> lines[i][j]; // = std::stoi(tokens[j]);
                //deb(lines[i][j])
                cnts[lines[i][j]]++;
            }
        }
        
        vi fin;
        for(int i = 0; i < 2501; i++)
        {
            if((cnts[i] % 2) != 0)
            {
                fin.push_back(i);
            }
        }
        cout << "Case #" << tcase << ":";
        for(int i = 0; i < GN; i++)
        {
            cout << " " << fin[i];
        }
        cout << endl;
	}
	return 0;
}