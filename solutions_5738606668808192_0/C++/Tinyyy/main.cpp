#include <cstdio>
#include <cmath>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <stack>
#include <map>
#include <queue>
#include <string>
#include <list>
#include <set>
#include <unordered_map>
#include <cstring>
#include <ctime>
#include <bitset>
#include <cassert>
using namespace std;

#define INF 2100000000

bool isprime[70000];
vector<int> primes;

void printnum(long long n) {
    string s;
    while (n != 0) {
        if (n % 2) s += '1';
        else s += '0';
        n >>= 1;
    }
    reverse(s.begin(), s.end());
    cout << s;
}

int main() {
    freopen("/Users/tianyi/Desktop/input.txt", "r", stdin);
    freopen("/Users/tianyi/Desktop/output.txt", "w", stdout);
    int tc; scanf("%d", &tc);
    int n, j; scanf("%d%d", &n, &j);
    printf("Case #1:\n");
    
    long long base = (1ll<<(n-1))+1;
    for (int p1 = 1; p1 <= n-2; p1 += 2) {
        for (int p2 = p1+2; p2 <= n-2; p2 += 2) {
            for (int q1 = 2; q1 <= n-2; q1 += 2) {
                for (int q2 = q1+2; q2 <= n-2; q2 += 2) {
//                    printf("%d %d %d %d\n", p1, p2, q1, q2);
                    long long newnum = base;
                    newnum |= (1<<p1);
                    newnum |= (1<<p2);
                    newnum |= (1<<q1);
                    newnum |= (1<<q2);
                    //                        printf("num = %lld\n", newnum);
                    printnum(newnum);
                    for (int i = 2; i <= 10; i++) printf(" %d", i+1);
                    printf("\n");
                    j--;
                    if (j == 0) exit(0);
                }
            }
        }
    }
    
    return 0;
}