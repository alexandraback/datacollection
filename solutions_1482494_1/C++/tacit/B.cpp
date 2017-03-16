#include <iostream>
#include <algorithm>
#include <fstream>
#include <stdio.h>
using namespace std;

struct level
{
    int a,b;
    int now;
};

level game[1100];

int main()
{
    ifstream fin;
    fin.open("B-large.in");
    cin.rdbuf(fin.rdbuf());

    int T,n;
    cin >> T;
    for (int test=1; test<=T; ++test)
    {
        cin >> n;
        for (int i=0; i<n; ++i)
        {
            cin >> game[i].a >> game[i].b;
            game[i].now = 0;
        }
        int s = 0;
        int step = 0;
        while (s<2*n)
        {
            while (true)
            {
                bool p = false;
                for (int i=0; i<n; ++i)
                    if (s>=game[i].b && game[i].now < 2)
                    {
                        p = true;
                        s+=2-game[i].now;
                        game[i].now = 2;
                        step++;
                        //printf("LEVEL %d:%d\n", i+1, game[i].now);
                    }
                if (!p) break;
            }
            int max = 0, maxk = -1;
            for (int i=0; i<n; ++i)
                if (game[i].now == 0 && s>=game[i].a && game[i].b>max)
                {
                    max = game[i].b;
                    maxk = i;
                }
            if (maxk == -1)
                break;
            game[maxk].now = 1;
            s += 1;
            step++;
            //printf("LEVEL %d:%d\n", maxk+1, game[maxk].now);
        }
        printf("Case #%d: ", test);
        if (s<2*n)
            printf("Too Bad\n");
        else
            printf("%d\n", step);
    }
}
