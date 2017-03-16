#include <stdexcept>
#include <cassert>
#include <iostream>
#include <sstream>
#include <fstream>
#include <algorithm>
#include <iterator>
#include <vector>
#include <stack>
#include <list>
#include <map>
#include <queue>
#include <cmath>
#include <climits>
#include <ctime>
#include <cstring>
#include <string>
#include <cstdlib>
#include <cstdio>
#include <utility>
#include <set>
using namespace std;


long long solve_large(long long r, long long t){
    long long ret = 0;
    long long i = 0;
    long long j = (long long)sqrt(t);
    long long r2 = 2 * r + 1;
    long long k = i+(j-i)/2, tmp;
    while(i<=j){
        k = i+(j-i)/2;
        tmp = k * r2+ 2 * k * k;
        if(tmp > t)
            j = k-1;
        else if(tmp < t)
            i = k+1;
        else
            return k;
    }
    return j;
}

long long solve_small(long long r, long long t){
    long long r2 = 2 * r + 1;
    long long i = 1;
    while(t>=0){
        t = t - (r2 + (i-1)*4);
        i++;
    }
    return i-2;
}

long long solve(long long r, long long t){
    if(t/r < 100000){    
        return solve_small(r,t);    
    }else{
        return solve_large(r,t);
    }
}

int main(){
    string iName = "./data1.dat";
    string oName = "./ret.dat";
    ifstream fin(iName.c_str());
    ofstream fout(oName.c_str());
    int nTest;
    fin>>nTest;
    for(int i = 0; i < nTest; i++){
        cout << "TESTCASE #" << (i+1) << endl;
        long long r, t;
        fin >> r >> t;
        long long ret = solve(r,t);

        fout << "Case #" << (i+1) << ": " << ret << endl;
    }
    fin.close();
    fout.close();
}
