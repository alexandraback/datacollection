#include "stdafx.h"
#include <cmath>
#include <cstdio>
#include <fstream>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <set>
using namespace std;



int main(){
    int file = 1;
    ifstream fin;
    fin.open("F:/C-small-1-attempt0.in");
    ofstream fout;
    fout.open("F:/output1.txt");

    int T;
    if (file)fin >> T;
    else
        cin >> T;
    for (int i = 0; i < T; ++i){
        int n,ans=0;
        if (file)fin >>n;
        else
            cin >> n;

        int d1, d2, h, m1, m2;
        if (n == 2)
        {
            fin >> d1 >> h >> m1;
            fin >> d2 >> h >> m2;
            double t1 = (360 - d1) / 360.0 * m1;
            double t2 = (360 - d2) / 360.0 * m2;
            if (t1 < t2)
            {             
                swap(d1, d2);
                swap(t1, t2);
                swap(m1, m2);
            }
            if ((t1 - t2) * 360 / m2 >= 360)
                ans++;
        }
        else
        {
            fin >> d1 >> h >> m1;
        }
        

        if (file)
            fout << "Case #" << i + 1 << ": " << ans << endl;
        else
            cout << "Case #" << i + 1 << ": " << ans << endl;
    }
    fin.close();
    fout.close();

    return 0;

}