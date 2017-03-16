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
    fin.open("F:/A-large (1).in");
    ofstream fout;
    fout.open("F:/output1.txt");

    int T;
    if (file)fin >> T;
    else
        cin >> T;
    for (int i = 0; i < T; ++i){
        long long N;
        if (file)fin >> N;
        else   cin >> N;
        int count = 0, num = 0, base = 0;
        if (N % 10 == 0){
            N -= 1;
            count++;
        }
        if (N > 10){
            
            long long t = N;
            while (t >= 10){
                if (base<=1)
                    count += pow(10, base++) + 9;
                else{
                    base++;
                    count += pow(10, base / 2 + (base & 1)) + pow(10, base / 2) - 1;
                }
                t /= 10;
            }
            t = N;
            t /= pow(10, base / 2 +1);
            string s = to_string(t);
            reverse(s.begin(), s.end());
            if (stoi(s) != 1){
                count += stoi(s) + 1;
            }
            t = pow(10, base / 2 +1);
            count += N%t - (stoi(s) != 1);
        }
        else
            count += N;
        if (file)
            fout << "Case #" << i + 1 << ": " << count << endl;
        else
            cout << "Case #" << i + 1 << ": " << count << endl;
    }
    fin.close();
    fout.close();

    return 0;

}