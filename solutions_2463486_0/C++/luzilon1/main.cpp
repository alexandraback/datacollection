#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>

using namespace std;

long long a[] = {0, 1, 4, 9, 121, 484, 10201, 12321, 14641, 40804, 44944, 1002001, 1234321, 4008004, 100020001, 102030201, 104060401, 121242121, 123454321, 125686521, 400080004, 404090404, 10000200001L, 10221412201L, 12102420121L, 12345654321L, 40000800004L, 1000002000001L, 1002003002001L, 1004006004001L, 1020304030201L, 1022325232201L, 1024348434201L, 1210024200121L, 1212225222121L, 1214428244121L, 1232346432321L, 1234567654321L, 4000008000004L, 4004009004004L};

int f(long long A, long long B) {
    int ans = 0;
    for(int i = 0; i < 40; i++) {
        if(a[i] >= A && a[i] <= B)
            ans++;
    }
    return ans;
}
int main()
{
    string filename = "C-small-attempt0";
    freopen("C-small-attempt0.in", "r", stdin);
    freopen("C-small-attempt0.out", "w", stdout);
    int T;
    scanf("%d", &T);
    for(int i = 0; i < T; i++) {
        long long A, B;
        cin >> A >> B;
        cout << "Case #" << i+1 << ": " << f(A, B) << endl;
    }
 //   for(int i = 0; i < 40; i++) cout << a[i] << endl;
    return 0;
}
