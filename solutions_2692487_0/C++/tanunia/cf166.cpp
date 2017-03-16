// cf166.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <stdlib.h>
#include <algorithm>
#include <vector>
#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	ifstream in;
	in.open("input.txt");
	ofstream out;
	out.open("output.txt");
    int T;
    in >> T;
    int a,n;
    vector<long long> v(102);
	long long sum, sum_now, res;
    for (int t = 0; t < T; ++ t){
        in >> a >> n;
        for (int i = 0; i < n; ++ i) in >> v[i];
        sort(v.begin(), v.begin()+n);
        res = a;
		sum = n;
		sum_now = 0;
        for (int i = 0; i < n; ++ i) {
			if (res != 1) {
				while (v[i] >= res){
					res += (res-1);
					sum_now ++;
				}
				res += v[i];
			}else{
				sum_now += 1;
			}
			sum_now += (n - i - 1);
			if (sum_now < sum) {
				sum = sum_now;
			}
			sum_now -= (n - i - 1);
        }
        out << "Case #" << t + 1 << ": " << sum << endl;   
    }      
	in.close();
	out.close();
    return 0;

}

