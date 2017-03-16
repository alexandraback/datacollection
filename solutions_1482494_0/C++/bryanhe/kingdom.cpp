#include <iostream>
#include <stdlib.h>

#define MAX 2000

using namespace std;

int main(int argc, char *argv[])
{
    int T;
    cin >> T;

    int a[MAX];
    int b[MAX];
    int stars[MAX];

    for(int counter = 1; counter <= T; counter++)
    {
        int N;
        cin >> N;

        for(int c = 0; c < N; c++)
        {
            cin >> a[c] >> b[c];
            stars[c] = 0;
        }

        int current = 0;
        int steps = 0;

        bool done = false;
        while(!done)
        {
            done = true;
            bool hasTwo = true;
            while(hasTwo)
            {
                hasTwo = false;
                for(int c = 0; c < N; c++)
                {
                    if(stars[c] != 2 && current >= b[c])
                    {
                        hasTwo = true;
                        current += (2 - stars[c]);
                        stars[c] = 2;
                        steps++;
                        done = false;
                    }
                }
            }

            int index = -1;
            for(int c = 0; c < N; c++)
            {
                if(stars[c] == 0 && current >= a[c])
                {
                    if(index == -1)
                    {
                        index = c;
                    }
                    else if(b[c] > b[index])
                    {
                        index = c;
                    }
                }
            }
            if(index != -1)
            {
                current++;
                stars[index] = 1;
                steps++;
                done = false;
            }
        }

        bool canWin = true;
        for(int c = 0; c < N; c++)
        {
            if(stars[c] != 2)
            {
                canWin = false;
                break;
            }
        }
        cout << "Case #" << counter << ": ";
        if(canWin)
        {
            cout << steps;
        }
        else
        {
            cout << "Too Bad";
        }
        cout << "\n";
    }

    return 0;
}
