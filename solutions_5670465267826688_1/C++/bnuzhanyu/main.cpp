#include <iostream>
#include <stdio.h>
#include <string>
#include <queue>
using namespace std;


void useFile(string fname)
{
    if(fname == "std") return;
    freopen((fname+".in").c_str(), "r", stdin);
    freopen((fname+".out").c_str(), "w", stdout);
}


const int MAXN = 1001;
int P[MAXN];


int toNum(char x)
{
    return x - 'i' + 2;
}

int res[5][5] = {
    0, 0, 0, 0, 0,
    0, 1, 2, 3, 4,
    0, 2, -1, 4, -3,
    0, 3, -4, -1, 2,
    0, 4, 3, -2, -1
};


int multiply(int a, int b)
{
    int s1 = a > 0 ? 1 : -1;
    int s2 = b > 0 ? 1 : -1;
    a *= s1, b *= s2;
    return s1 * s2 * res[a][b];
}

bool findSolution(const string & str, int& start, long long X, int ans)
{
    int l = str.size() ;
    int mul = 1;
    for(int i=0 ; i<l * 4 && start < l * X; i++)
    {
        int pos = start % l;
        start++;
        mul = multiply(mul, toNum(str[pos]));

        if( mul == ans ) return true;
    }
    return false;
}

int main()
{
    useFile("C2");
    int T;
    string str;
    cin >> T;
    for(int ca=1; ca<=T; ca++)
    {
        long long X, L;
        cin >> L >> X;
        cin >> str;
        int mul = 1;
        for(int i=0; i<L; i++)
        {
            int cur = toNum(str[i]);
            mul = multiply(mul , cur);
            //cout << "mul =  " << mul << endl;
        }

        int str_res = mul;
        mul = 1;
        for(int i=0; i<X%4; i++){
            mul = multiply(mul, str_res);
        }
        //cout << "mul: " << mul << endl;
        bool ans = false;
        if( mul == -1) {
            int st = 0;
            ans = findSolution(str, st, X, 2);
            ans = ans && findSolution(str, st, X, 3);
        }

        cout << "Case #" << ca << ": " << (ans?"YES":"NO") << endl;

    }

    return 0;
}
