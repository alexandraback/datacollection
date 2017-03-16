#include <string>
#include <vector>
#include <cstdlib>
#include <fstream>
//#include <iostream>
using namespace std;

ifstream cin("A-large.in");
ofstream cout("output.txt");

bool check(long long P, long long Q, int generations){
    if(generations > 40) return false;
    long long N = 2 * P - Q;
    if(N == 0) return true;
    while(N < Q){
        generations++;
        N *= 2;
    }
    N /= 2;
    return check(N, Q, generations);
}

int main(){
    int T;
    cin >> T;
    for(int t = 1; t <= T; t++){
        string s, num, den;
        cin >> s;
        num = s.substr(0, s.find_first_of('/'));
        den = s.substr(s.find_first_of('/') + 1);
        long long P, Q;
        P = atoll(num.c_str());
        Q = atoll(den.c_str());
        int generations = 0;
        while(P < Q){
            generations++;
            P *= 2;
        }
        P /= 2;
        cout << "Case #" << t << ": ";
        if(check(P, Q, generations))
            cout << generations << endl;
        else
            cout << "impossible\n";
    }
    return 0;
}