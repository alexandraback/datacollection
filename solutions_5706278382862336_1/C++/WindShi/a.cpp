#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

long long A, B, n;
int test;
string str;

long long gcd(long long a, long long b){
     if (!b) return a;
     return gcd(b, a % b);
}

int main(){
    freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);
    n = 1LL << 40LL;
    scanf("%d", &test);
    for (int uu = 1; uu <= test; uu++)
    {
        printf("Case #%d: ", uu);
        cin >> str;
        for (int i = 0; i < str.size(); i++)
        if (str[i] == '/') 
        {
           A = 0; B = 0;
           for (int j = 0; j < i; j++) A = A * 10 + str[j] - '0';
           for (int j = i + 1; j < str.size(); j++) B = B * 10 + str[j] - '0';
           break;
        }
        long long GCD = gcd(A, B);
        A /= GCD; B /= GCD;
        if ((n % B))
        {
           printf("impossible\n");
           continue;
        }
        A *= n / B;
        long long status = n / 2;
        for (int i = 1; ; i++, status /= 2)
            if (A >= status) 
            {
               printf("%d\n", i);
               break;
            }
    }
} 
    
