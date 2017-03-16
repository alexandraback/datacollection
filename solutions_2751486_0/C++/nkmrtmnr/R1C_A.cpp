#include <cstdio>
#include <vector>
#include <deque>
#include <queue>
#include <map>
#include <algorithm>
#include <functional>
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <string.h>
#include <math.h>
#include <sstream>

using namespace std;

int main(int argc, const char **argv)
{
    ifstream fin(argv[1]);
    ofstream fout("out.txt");
    int T;
    fin >> T;

    for (int tc = 0; tc < T; tc++)
    {
        vector<int> mem(100, 1);
    
        string s;
        int n;
        fin >> s;
        fin >> n;
        int ret = 0;

        for (int i = 0; i < s.length(); i++)
        {
            int c = s[i];
            if (c == 'a'
                || c == 'i'
                || c == 'u'
                || c == 'e'
                || c == 'o')
            {
                mem[i] = 0;
            }
        }

        for (int i = 0; i < s.length(); i++)
        {
            for (int k = s.length(); k > 0; k--)
            {
                int tmp = 0;
                for (int j = i; j < k; j++)
                {
                    if (mem[j] == 0)
                    {
                        tmp = 0;
                    }
                    else
                    {
                        tmp++;
                        if (tmp == n)
                        {
                            ret++;
                            break;
                        }
                    }
                }
            }
        }

        fout << "Case #" << tc+1 << ": " << ret << endl;
    }

    return (0);
}
