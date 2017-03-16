/*
Author: Vivek Dhiman
Email: vivek4dhiman@gmail.com
*/
#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

#define PB(x) push_back(x)
#define fp(i,f,t) for(int i=f; i<t; i++)
#define fm(i,f,t) for(int i=f; i>t; i--)
#define MP(x,y) make_pair(x,y)

using namespace std;

map<long long, long long> ans;
long long flipN(long long n){
    long long x = 0;
    while(n>0){
        x = x*10 + n%10;
        n/=10;
    }
    return x;
}

long long getMin(long long n){
    if(ans.count(n)) return ans[n];
    if(n%10 == 0){
        return 1+getMin(n-1);
    }
    long long fn = flipN(n);
    if( fn < n && n >=1){
        return 1+ min( getMin(n-1), getMin(fn));
    }else{
        return 1+getMin(n-1);
    }
}



int main() {
    for(long i=1; i<10; i++)
        ans[i] = i;
    for(long long i=10; i<=1000000; i++){
        ans[i] = getMin(i);
    }
    int total_tests=0;
    cin >> total_tests;
    for(int _case=1; _case<=total_tests; _case++){
        cout << "Case #"<< _case <<": " ;
        long long n;
        cin >> n;
        cout << ans[n] << endl;
    }
    return 0;
}

