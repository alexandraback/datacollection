
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
        for(int i = 0; i < LN; i++)
        {

            for(int j = 0; j < GN; j++)
            {
                cin >> lines[i][j]; // = std::stoi(tokens[j]);
                //deb(lines[i][j])
            }
        }
        int grid[GN][GN];
        memset(grid,0,sizeof(grid));

        int ucol = -1;
        int marked[LN];
        memset(marked,0,sizeof(marked));
        int fillrow[GN];
        int fillcol[GN];
        for(int i = 0; i < GN; i++)
        {
            fillrow[i] = fillcol[i] = 0;
        }

        for(int i = 0; i < GN; i++)
        {
            int small = 1e6;
            int cnt = 0;
            for(int j = 0; j < LN; j++)
            {
                if(marked[j] > 0)
                    continue;
                if(lines[j][i] < small)
                {
                    small = lines[j][i];
                    cnt = 1;
                }
                else if(lines[j][i] == small)
                {
                    cnt++;
                }
            }
          
            if(cnt > 2)
            {
                deb("shit");
            }
            deb(cnt)
            for(int j = 0; j < LN; j++)
            {
                
                if(marked[j] > 0)
                    continue;
                if(lines[j][i] == small)
                {
                    marked[j] = 1;
                    for(int k = 0; k < GN; k++)
                    {
                        if(i == 0)
                        {
                            if(cnt == 2)
                            {
                                
                                grid[k][i] = lines[j][k];
                                fillcol[i] = 1; 
                            }
                            else
                            {
                                grid[i][k] = lines[j][k];
                                fillrow[i] = 1;
                            }
                        }
                        else
                        {
                            if((grid[0][i] == grid[i][0]) && (grid[i][i] > 0))
                            {
                                grid[k][i] = lines[j][k];
                                fillcol[i] = 1;
                            }
                            else if(grid[0][i] == lines[j][0])
                            {
                                grid[i][k] = lines[j][k];
                                fillrow[i] = 1;
                            }
                            else
                            {
                                grid[k][i] = lines[j][k];
                                fillcol[i] = 1;
                            }
                            
                            
                        }
                    }
                    cnt--;
                }
            }
           for(int i = 0; i < GN; i++)
            {
                for(int j = 0; j < GN; j++)
                {
                    cout << grid[i][j] << ' ';
                }
                cout << endl;
            } 
        }
        vi fin;
        for(int i = 0; i < GN; i++)
        {
            if(fillrow[i] == 0)
            {
                for(int j = 0; j < GN; j++)
                {
                    fin.push_back(grid[i][j]);
                }
            }
            if(fillcol[i] == 0)
            {
                for(int j = 0; j < GN; j++)
                {
                    fin.push_back(grid[j][i]);
                }
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