#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <string>
#include <string.h>
#include <math.h>

using namespace std;

vector<string> dict;
vector<int> dictl;
string s;
int best;
int sz;

int mem[4096][4096];
char used[4096][4096];
int ucnt;

int go(int p, int last)
{
    if (p>=sz)
    {
        return 0;
    }
    if (last>=0)
    {
        if (used[p][last]==ucnt)
        {
            return mem[p][last];
        }
    }
    int minchange = 1<<16;
    for (int i=0;i<dict.size();i++)
    {
        if (dictl[i]+p<=sz)
        {
            bool bok = true;
            int lst = last;
            int change = 0;
            for (int j=0;j<dictl[i];j++)
            {
                if (dict[i][j]!=s[p+j])
                {
                    if (p+j-lst<5)
                    {
                        bok = false;
                        break;
                    } else
                    {
                        lst = p+j;
                        change++;
                    }
                }
            }
            if (bok)
            {
                int m = change + go(p+dictl[i], lst);
                minchange = min(minchange, m);
            }
        }
    }
    if (last>=0)
    {
        used[p][last] = ucnt;
        mem[p][last] = minchange;
    }
    return minchange;
}

void solve()
{
    ucnt = 1;
    memset(used,0,sizeof(used));
    char buf[8192];
    int T;
    cin >> T;
    cin.getline(buf, 8192);
    for (int t=0;t<T;t++)
    {
        ucnt++;
        cin.getline(buf, 8192);
        s = buf;
        sz = s.length();
//        cerr << s << " = " << sz << endl;
        int ans = go(0, -100);
        cout << "Case #" << t+1 << ": " << ans << endl;
    }

}

int main(int argc,char *argv[])
{
    char buf[1<<16];
    ifstream fi("garbled_email_dictionary.txt");
    dict.resize(521196);
    dictl.resize(521196);
    for (int i=0;i<521196;i++)
    {
        fi.getline(buf, 65536);
        dict[i] = buf;
        dictl[i] = dict[i].length();
    }
    fi.close();
  solve();

  return 0;
}
