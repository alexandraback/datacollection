#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <climits>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

void printPancakes(bool *pancakes, int n)
{
    for(int i = 0; i < n; i++)
    {
        cout << pancakes[i];
    }
}

void flip(bool *pancakes, int x)
{
    vector<bool> stk;
    for(int i = 0; i <= x; i++)
    {
        stk.push_back(pancakes[i]);
    }
    for(int i = 0; i <= x; i++)
    {
        pancakes[i] = !stk.back();
        stk.pop_back();
    }
}

int main()
{
    int T;
    scanf("%d\n", &T);

    for(int t = 1; t <= T; t++)
    {
        char in[103];
        scanf("%s", in);

        int n = strlen(in);
        bool pancakes[100];
        memset(pancakes,false,sizeof(bool));
        for(int i = 0; i < n; i++)
        {
            pancakes[i] = (in[i]=='+');
        }
        
        /*
        cout << " : ";
        printPancakes(pancakes,n);
        cout << endl;
        */

        int flips = 0;
        for(int i = n-1; i > 0; i--)
        {
            if(pancakes[i]) continue;

            if(pancakes[0])
            {
                int j = 0;
                while(pancakes[j+1]) j++;
                flip(pancakes,j);
                flips++;
                /*
                cout << j << ": ";
                printPancakes(pancakes,n);
                cout << endl;
                */
            }

            flip(pancakes, i);
            flips++;
            /*
            cout << i << ": ";
            printPancakes(pancakes,n);
            cout << endl;
            */
        }

        if(!pancakes[0]) 
        {
            pancakes[0] = !pancakes[0];
            flips++;
            /*
            cout << "0: ";
            printPancakes(pancakes, n);
            cout << endl;
            */
        }

        printf("Case #%d: %d\n", t, flips);
    }
}
