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
    string str;
    getline(fin,str);

    for (int step=0;step<case_count;step++)
    {
        getline(fin,str);
        int a[27] = {0};
        for (int i=0;i<str.length();i++)
        {
            a[str[i] - 'A']++;
        }
        int ans[10] = {0};
        int k = 0;
        ans[0] = a['Z' - 'A'];
        a['Z' - 'A'] -= ans[0];
        a['E' - 'A'] -= ans[0];
        a['R' - 'A'] -= ans[0];
        a['O' - 'A'] -= ans[0];
        ans[4] = a['U' - 'A'];
        a['F' - 'A'] -= ans[4];
        a['O' - 'A'] -= ans[4];
        a['U' - 'A'] -= ans[4];
        a['R' - 'A'] -= ans[4];
        ans[5] = a['F' - 'A'];
        a['F' - 'A'] -= ans[5];
        a['I' - 'A'] -= ans[5];
        a['V' - 'A'] -= ans[5];
        a['E' - 'A'] -= ans[5];
        ans[3] = a['R' - 'A'];
        a['T' - 'A'] -= ans[3];
        a['H' - 'A'] -= ans[3];
        a['R' - 'A'] -= ans[3];
        a['E' - 'A'] -= ans[3];
        a['E' - 'A'] -= ans[3];
        ans[7] = a['V' - 'A'];
        a['S' - 'A'] -= ans[7];
        a['E' - 'A'] -= ans[7];
        a['V' - 'A'] -= ans[7];
        a['E' - 'A'] -= ans[7];
        a['N' - 'A'] -= ans[7];

        ans[6] = a['S' - 'A'];
        a['S' - 'A']-= ans[6];
        a['I' - 'A']-= ans[6];
        a['X' - 'A']-= ans[6];

        ans[2] = a['W' - 'A'];
        a['T' - 'A']-= ans[2];
        a['W' - 'A']-= ans[2];
        a['O' - 'A']-= ans[2];

        ans[1] = a['O' - 'A'];
        a['O' - 'A']-= ans[1];
        a['N' - 'A']-= ans[1];
        a['E' - 'A']-= ans[1];

        ans[9] = a['N' - 'A'] / 2;
        a['N' - 'A'] -= ans[9];
        a['I' - 'A'] -= ans[9];
        a['N' - 'A'] -= ans[9];
        a['E' - 'A'] -= ans[9];

        ans[8] = a['E' - 'A'];



        fout<<"Case #"<<step+1<<": ";
        for (int i=0;i<=9;i++)
        {
            for (int j=0;j<ans[i];j++)
                fout<<i;
        }
        fout<<endl;
    }

    fin.close();
    fout.close();
    return 0;
}

