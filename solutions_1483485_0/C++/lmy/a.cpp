#include <cstdio>
#include <iostream>
#include <string>
#include <cstdlib>
#include <sstream>

using namespace std;

char map[26] = {'y', 'h', 'e', 's', 'o', 'c', 'v', 'x', 'd', 'u', 'i', 'g', 'l', 'b', 'k', 'r', 'z', 't', 'n', 'w', 'j', 'p', 'f', 'm', 'a', 'q'};

int main()
{
    FILE * pFile = freopen("A-small-attempt3.in", "r", stdin);
    FILE * pFile2 = freopen("A-small-attempt3.out", "w", stdout);

    int t;
    scanf("%d\n", &t);
    for (int no = 1; no <=t; no++)
    {
        string g;
        getline (cin, g);
        int n = g.size();
        for (int i = 0; i < n; i++)
        {
            if (g[i] == ' ') continue;
            g[i] = map[g[i] - 'a'];
        }
        printf("Case #%d: %s\n", no, g.c_str());
    }
}
