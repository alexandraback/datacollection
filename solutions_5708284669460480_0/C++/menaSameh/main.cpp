/*ICPC Infinite monkey theorem*/

#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
#include <iomanip>
using namespace std;

int fail[15];
double A[30];
double mem[101][101][101];

int a , b , c , len , mostFine;

string s, key;

double rec(int index , int matched , int fine)
{
    mostFine = max(fine , mostFine);
    if(index == c)
        return fine;

    double &ans = mem[index][matched][fine];
    if(ans != -1)
        return ans;

    ans = 0;
    for(int i = 0;i < 26;++i)
    {
        if(A[i] != 0)
        {
            int k = matched;
            while(k > 0 && i != s[k] - 'A')
                k = fail[k - 1];

            if(i == s[k] - 'A')
                ++k;

            ans += A[i] * rec(index + 1 , k , fine + (k == s.size()));
        }
    }
    return ans;
}

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    int T , cas = 0;
    cin >> T;
    while(T--)
    {
        mostFine = 0;
        cin >> a >> b >> c;
        ++cas;
        for(int i = 0;i < 26;++i)
            A[i] = 0;

        cin >> key;
        for(int i = 0;i < key.size();++i)
            A[key[i] - 'A'] += 1.0 / key.size();

        cin >> s;
        len = s.size();

        int matched = 0;
        for(int i = 1;i < len;++i)
        {
            while(matched > 0 && s[i] != s[matched])
                matched = fail[matched - 1];

            if(s[i] == s[matched])
                ++matched;

            fail[i] = matched;
        }
        for(int i = 0;i < 101;++i)
            for(int j = 0;j < 101;++j)
                for(int k = 0;k < 101;++k)
                    mem[i][j][k] = -1;

        double asd = rec(0 , 0 , 0);
        cout <<"Case #" << cas<< ": " <<std::setprecision(9) <<   mostFine*1.0  - asd<< endl;
//        printf("%d: %6lf  %6lf\n" , cas , mostFine * 1.0 ,  asd);
    }
    return 0;
}
