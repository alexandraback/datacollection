//
//  main.cpp
//  2
//
//  Created by Wanjia He on 4/15/16.
//  Copyright © 2016 Wanjia He. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(int argc, const char * argv[]) {
    ifstream fin("2.in"); ofstream fout("2.out");
    int l, t, i, j, n, min, count, ans, finished, b, c;
    int rac[55][3], re[100];
    int a[105][55];
    bool used[105];
    fin >> t;
    for (l=1; l<=t; l++){
        fin >> n;
        ans = 0;
        finished = 1;
        for (i=1; i<=2*n-1; i++){
            used[i] = false;
            for (j=1; j<=n; j++)
                fin >> a[i][j];
        }
        for (i=1; i<=n; i++){
            min = 10000;
            for (j=1; j<=2*n-1; j++)
                if (a[j][i] < min && used[j] == false)
                    min = a[j][i];
            count = 0;
            for (j=1; j<=2*n-1; j++)
                if (a[j][i] == min){
                    count++;
                    rac[i][count] = j;
                    used[j] = true;
                }
            if (count == 1) ans = i;
            re[ans] = a[rac[ans][1]][ans];
            for (j=1; j<=n; j++){
                if (j==ans) continue;
                b = a[rac[j][1]][ans];
                c = a[rac[j][2]][ans];
                if (b == a[rac[ans][1]][j]){
                    re[j] = c;
                }else{
                    re[j] = b;
                }
            }
        }
       /* for (j=1; j<=n; j++){
            if (ans != j)
                cout << j << "     " << rac[j][1] << "     " << rac[j][2] << endl;
            if (ans == j)
                cout << j << "     " << rac[j][1] << endl;
        }*/
        fout << "Case #" << l << ":";
        for (i=1; i<=n; i++)
            fout << " " << re[i];
        fout << endl;
    }
    fin.close(); fout.close();
    return 0;
}
