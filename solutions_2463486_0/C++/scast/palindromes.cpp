#include<cstdio>
#include<algorithm>
#include<cmath>
#include<vector>
using namespace std;
vector<long> p;
int t;
long a, b;
long pp[] = {0, 1, 4, 9, 121, 484, 10201, 12321, 14641, 40804, 44944, 1002001, 1234321, 4008004, 100020001, 102030201, 104060401, 121242121, 123454321, 125686521, 400080004, 404090404, 10000200001, 10221412201, 12102420121, 12345654321, 40000800004, 1000002000001, 1002003002001, 1004006004001, 1020304030201, 1022325232201, 1024348434201, 1210024200121, 1212225222121, 1214428244121, 1232346432321, 1234567654321, 4000008000004, 4004009004004};
int main() {
    // printf("%ld", sizeof(long));
    // for (int i=0; i<10; i++) {
    // 	p.push_back(i);
    // 	if (i > 0) p.push_back(i+10*i);
    // }
    // for (int i=1; i<10; i++)
    // 	for (int j=0; j<10; j++) {
    // 	    p.push_back(100*i+10*j+i);
    // 	    p.push_back(1000*i+100*j+10*j+i);
    // 	    for (int k=0; k<10; k++) {
    // 		p.push_back(10000*i+1000*j+100*k+10*j+i);
    // 		p.push_back(100000*i+10000*j+1000*k+100*k+10*j+i);
    // 		for (int l=0; l<10; l++) {
    // 		    p.push_back(1000000*i+100000*j+10000*k+1000*l+100*k+10*j+i);
    // 		}
    // 	    }
    // 	}
    // sort(p.begin(), p.end());
    // for (int i=0; i<p.size(); i++) {p[i] *= p[i];printf("%ld\n", p[i]); }
    // for (int i=0; i<p.size(); i++) printf("%ld\n", p[i]);
    // printf("%ld\n", p.size());
    scanf("%d", &t);

    for (int i=1; i<=t; i++) {
    	scanf("%ld%ld", &a, &b);
    	int pa = lower_bound(pp, pp+40, a)-pp,
	    pb = lower_bound(pp, pp+40, b)-pp;
	int sum = 0;
    	// printf("pa = %d, pb = %d\n", pa, pb);
	for (int i=pa; i<=pb; i++) {
	    if (a <= pp[i] && pp[i] <= b) sum++;
	    else break;
	}
	printf("Case #%d: %d\n", i, sum);
    	// printf("%ld", pb-pa);
    	// printf("sqrt(%ld)=%ld sqrt(%ld)=%ld\n", a, sqa, b, sqb);
    }
    return 0;
}

// 4004009004004