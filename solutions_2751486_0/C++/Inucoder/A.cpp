#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <utility>
#include <stack>
#include <queue>
#include <cctype>
#include <vector>
#include <set>
#include <map>
#include <cassert>
using namespace std;

#define pb push_back

typedef long long ll;
typedef unsigned long long ull;

bool isConsonant(char c){
    return c != 'a' && c != 'e' && c != 'i' && c != 'o' && c != 'u';

}

ull solve(string name, int n){

    ull ans = 0;

    int L = name.size();
    for (int i = 0; i < L; i++){
        for (int j = 0; j < L; j++){
            //if (j - i < n) continue;

            int count = 0;

            for (int k = i; k <= j; k++){
                if (isConsonant(name[k])){
                    count++;
                    if (count == n ){
                        ans++;
                        break;
                    }

                }
                else{
                    count = 0;
                }
            }

        }
    }

    return ans;

}

int main(){

    ifstream in("A-small-attempt0.in");
    ofstream out("A-small-attempt0.out");

    int T;

    in >> T;

    for (int t = 1; t <= T; t++){

        //input

        string name;
        int n;

        in >> name >> n;

        //output
        cout << "Case #" << t << ": " << solve(name, n) << endl;
        out << "Case #" << t << ": " << solve(name, n) << endl;
    }

    in.close();
    out.close();
}
