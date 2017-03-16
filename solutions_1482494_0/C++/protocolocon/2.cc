//  -*- mode: c++; coding: utf-8; c-file-style: "stroustrup"; -*-

#include <fstream>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <limits>
#include <set>

using namespace std;

int main(int narg, char **arg)
{
    int t;
    cin >> t;
    for(int it=0; it<t; it++)
    {
        cout << "Case #" << it+1 << ": ";

        int n;
        cin >> n;
        int a[n], b[n];
        for(int i=0; i<n; i++) cin >> a[i] >> b[i];
        int n_stars[n];
        memset(n_stars, 0, sizeof(n_stars));

        int current=0, counter=0;
        while(current< n*2)
        {
            // search one star left level and 2 star levels
            int old_current=current;
            for(int i=0; i<n; i++)
            {
                if(n_stars[i]==1 && current>=b[i])
                {
                    current++;
                    counter++;
                    n_stars[i]=2;
                }
                else if(n_stars[i]==0 && current>=b[i])
                {
                    current+=2;
                    counter++;
                    n_stars[i]=2;
                }
            }
            if(old_current!=current) continue;

            // search any level adding stars
            int greater=-1;
            for(int i=0; i<n; i++)
            {
                if(n_stars[i]==0 && current>=a[i])
                {
                    if(greater<0 || b[greater]<b[i]) greater=i;
                }
            }
            if(greater>=0)
            {
                current++;
                counter++;
                n_stars[greater]=1;
                continue;
            }

            cout << "Too Bad" << endl;
            break;
        }
        if(current==n*2) cout << counter << endl;
    }
    return 0;
}
