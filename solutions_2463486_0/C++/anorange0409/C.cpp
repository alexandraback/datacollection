#include <iostream>
#include <cstdio>
using namespace std;

const int N = 205;
long long p[39] = {1,4,9,121,484,10201,12321,14641,40804,44944,1002001,1234321,4008004,100020001,102030201,104060401,121242121,123454321,125686521,400080004,404090404,10000200001,10221412201,12102420121,12345654321,40000800004,1000002000001,1002003002001,1004006004001,1020304030201,1022325232201,1024348434201,1210024200121,1212225222121,1214428244121,1232346432321,1234567654321,4000008000004,4004009004004};

int main(){
    freopen("C-small-attempt0.in", "r", stdin);
    freopen("C-small-attempt0.out", "w", stdout);
    int testcase;
    cin >> testcase;
    for (int t = 1; t <= testcase; t++){
        printf("Case #%d: ", t);
        long long A, B;
        int sum = 0;
        cin >> A >> B;
        for (int i = 0; i < 39; i++)
            if (p[i] >= A && p[i] <= B)
                sum ++;
        cout << sum << endl;
    }
}
