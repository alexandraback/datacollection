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
#include <sstream>
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
        int b;
        long long m;
        fin>>b;
        fin>>m;
        long long f[100] = {0};
        int a[60][60] = {0};
        m--;
        a[1][b] = 1;
        f[1] = 1;
        int k = 2;
        while ((m>0)&&(k<b))
        {
            a[k][b] = 1;
            for (int i=k-1;i>=1;i--)
            if (m-f[i]>=0)
            {

                m-=f[i];
                f[k]+=f[i];
                a[i][k] = 1;
            }


            k++;
        }

        fout<<"Case #"<<step+1<<": ";
        if (m>0) fout<<"IMPOSSIBLE"<<endl;
        else
        {


            fout<<"POSSIBLE"<<endl;
            for (int i=1;i<=b;i++)
            {
                for (int j=1;j<=b;j++)
                    fout<<a[i][j];
                    fout<<endl;
            }

        }



    }

    fin.close();
    fout.close();
    return 0;
}

