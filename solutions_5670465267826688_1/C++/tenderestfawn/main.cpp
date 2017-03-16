#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
#include <fstream>

using namespace std;
typedef long long ll;

int table[5][5] = {{0,0,0,0,0},
    {0,1,2,3,4},
    {0,2,-1,4,-3},
    {0,3,-4,-1,2},
    {0,4,3,-2,-1}
};

int T;
long long L, X;


long long mult(long long a, long long b){
    return a * b > 0 ? table[abs(a)][abs(b)] : -1*table[abs(a)][abs(b)];
}

int charToNum(char c){
    if (c == '1')
        return 1;
    if (c == 'i')
        return 2;
    if (c == 'j')
        return 3;
    if (c == 'k')
        return 4;
    return -1;
}

int main(){
    ifstream ins("C-large.in");
    ofstream ofs("C-large1.txt");
    ins >> T;
    for (int cse = 1; cse <= T; cse++){
        
        string s = "";
        string ans;

        ins >> L >> X >> s;
        int smallX = (X-1) %4;
        
        ll prod = 1;
        for (int i = 0; i < s.size(); i++){
            prod = mult(prod, charToNum(s[i]));
        }
        ll overallProd = prod;
        for (int i = 0; i < smallX; i++){
            overallProd = mult(overallProd, prod);
        }
        if (overallProd != -1){
            ans = "NO";
        }
        
        
        ll leftInd = 0, leftProd = 1;
        long long minX = X < 20 ? X : 20;
        for (; leftInd < minX * s.size(); leftInd++){
            leftProd = mult(leftProd, charToNum(s[leftInd%s.size()]) );
            if (leftProd == 2)
                break;
        }
        if (leftInd == minX * s.size())
            ans = "NO";
        
        long long rightInd = minX * s.size()-1, rightProd = 1;
        long long r = 0;
        for (; rightInd >= 0; rightInd--){
            rightProd = mult(charToNum(s[rightInd%s.size()]), rightProd);
            if (rightProd == 4)
                break;
            r++;
        }
        
        long long end = ll(L*X) - r - 1;
        
        if (rightInd < 0 || leftInd >= end)
            ans = "NO";
        else if (ans != "NO")
            ans = "YES";

        
        ofs << "Case #" << cse << ": " <<ans << endl;
    }
    
}


