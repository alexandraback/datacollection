#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

long long int numbers[] = { 1LL,4LL,9LL,121LL,484LL,10201LL,12321LL,
                            14641LL,40804LL,44944LL,1002001LL,1234321LL,
                            4008004LL,100020001LL,102030201LL,104060401LL,
                            121242121LL,123454321LL,125686521LL,400080004LL,
                            404090404LL,10000200001LL,10221412201LL,
                            12102420121LL,12345654321LL,40000800004LL,
                            1000002000001LL,1002003002001LL,1004006004001LL,
                            1020304030201LL,1022325232201LL,1024348434201LL,
                            1210024200121LL,1212225222121LL,1214428244121LL,
                            1232346432321LL,1234567654321LL,4000008000004LL,
                            4004009004004LL
                        };

int main()	{
    int T, I, lb, ub;
    long long int A, B;

	freopen("C-large-1.in", "r", stdin);
	freopen("C-large.txt", "w", stdout);

	cin >> T;
	for(I=1; I<=T; I++) {
        cin >> A >> B;
        lb = lower_bound(numbers, numbers + 39, A) - numbers;
        ub = upper_bound(numbers, numbers + 39, B) - numbers;
        cout << "Case #" << I << ": " << (ub - lb) << "\n";
	}

	return 0;
}
