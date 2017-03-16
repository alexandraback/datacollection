#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <sstream>

#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define decltype(X) __typeof(X)
#define REP(i, n) for(int i=0; i<(int)n; i++)
#define FOR(it, c) for(decltype((c).begin()) it = (c).begin(); it!=(c).end(); it++)
#define ALL(c) (c).begin(), (c).end()

using namespace std;

bool check(unsigned long long r, unsigned long long t, unsigned long long n)
{
    unsigned long long a = r * 2 + 1;
#if 0
    unsigned long long tmp1 =2 * a;
    unsigned long long tmp2 =4 * (n-1);
    unsigned long long tmp3 =tmp1 + tmp2;
    unsigned long long tmp4 = n * tmp3;
    unsigned long long tmp5 = tmp4/2;
    // printf("tmp1=%llu, tmp2=%llu, tmp3=%llu, tmp4=%llu, tmp5=%llu\n", tmp1, tmp2, tmp3, tmp4, tmp5);
#endif
    
    
    unsigned long long area = (n * (2 * a + 4 * (n-1))) / 2;
    // printf("r=%llu, t=%llu, n=%llu, a = %llu, area=%llu\n", r, t, n, a, area);
    if(area <= t){
        return true;
    }else{
        return false;
    }
}
void testcase(int tcase)
{
	string result_str = "OK";
    unsigned long long r, t;
    cin >> r >> t;
    
    unsigned long long left = 1, right = min((unsigned long long)1000000000, t / r + 1);
    while(left < right){
        unsigned long long mid = (left+right)/2;
        if(check(r, t, mid) == true){
            left = mid + 1;
        }else{
            right = mid;
        }
    }
    unsigned long long result = right-1;
    
	cout << "Case #" << (tcase+1) << ": " << result << endl;
}

int main(int argc, char *argv[]) {
	int T;
	// ios::sync_with_stdio(false);
    // sleep(10000);
    if(argc >= 2){
        int fd = open(argv[1], O_RDONLY);
        if(fd == -1){
            fprintf(stderr, "failed to open [%s]\n", argv[1]);
            exit(1);
        }
        int ret = dup2(fd, 0);
        if(ret == -1){
            fprintf(stderr, "failed to dup2[%s]\n", argv[1]);
            exit(1);
        }
    }
	cin >> T;
	for(int t=0;t<T;t++){
		testcase(t);
	}
	return 0;
}

