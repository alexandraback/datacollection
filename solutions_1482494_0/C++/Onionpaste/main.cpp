/* 
 * File:   main.cpp
 * Author: Alex Ambrose
 *
 * Created on April 27, 2012, 7:12 PM
 */

#include <iostream>
#include <fstream>

using namespace std;

/*
 * 
 */
int main()
{
    ifstream input("B-small-attempt1.txt");
    ofstream output("Kingdom_Output.txt");
    int T;
    input >> T;
    for (int c = 1; c <= T; c++)
    {
        int n;
        input >> n;
        int a[n], b[n], s[n];
        for (int i = 0; i < n; i++)
        {
            input >> a[i];
            input >> b[i];
            s[i] = 0;
        }
        
        int stars = 0;
        int tries = 0;
        bool able = true;
        while(able)
        {
            for (int i = 0; i < n; i++)
            {
                if (stars >= b[i] && s[i] < 2)
                {
                    tries++;
                    stars += (2 - s[i]);
                    s[i] = 2;
                    break;
                }
                if (i == (n - 1))
                {
                    for (int j = 0; j < n; j++)
                    {
                        if (stars >= a[j] && s[j] == 0)
                        {
                            tries++;
                            stars += 1;
                            s[j] = 1;
                            break;
                        }
                        if (j == (n - 1))
                            able = false;
                    }
                }
            }
            if (stars == (2 * n))
                break;
        }
        if (able)
            output << "Case #" << c << ": " << tries << endl;
        else
            output << "Case #" << c << ": " << "Too Bad" << endl;
    }
    return 0;
}

