//
//  main.cpp
//  MagicTrick
//
//  Created by L on 14-4-12.
//  Copyright (c) 2014ๅนด L. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
using namespace std;

int main(int argc, const char * argv[])
{

    // insert code here...
    ifstream fin;
    ofstream fout;
    int case_count;
    fin.open("data.in",std::ofstream::in);
    fout.open("data.out",std::ofstream::out);
    fin>>case_count;

    for (int step=0;step<case_count;step++)
    {
        int x,n = 10;
        bool f[10] = {false};
        fin>>x;
        if (x == 0) {

            fout<<"Case #"<<step+1<<": INSOMNIA"<<endl;
            continue;

        }
        int incx = x,ans=0;
        while (n!=0)
        {

            ans++;

            int y = incx;
            //cout<<incx<<endl;
            while (y!=0)
            {
                if (!f[y%10]) {
                    n--;
                    f[y%10] = true;
                }
                y/=10;
            }
            incx +=x;

        }

        fout<<"Case #"<<step+1<<": "<<incx-x<<endl;
    }

    fin.close();
    fout.close();
    return 0;
}

