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


double ncr[2000][2000];
void init_ncr(void)
{
    ncr[0][0] = 1;
    for(int n=1;n<1999;n++){
        for(int r=0;r<=n;r++){
            if(r==0){
                ncr[n][r] = (ncr[n-1][r])/2;
                
            }else{
                ncr[n][r] = (ncr[n-1][r-1] + ncr[n-1][r])/2;
            }
        }
    }

}
double get_ncr_or_more(int n, int r)
{
    double result = 0;
    for(int r2=n;r2>=r;r2--){
        result += ncr[n][r2];
    }
    return result;
    
}
double calc(int N, int X, int Y)
{
    int total = 1;
    int num = 1;
    int layer = 0;
    while(true){
        num = num + 4;
        layer ++ ;
        if(total + num > N){
            break;
        }
        total += num;
    }
    int left = N - total;
    // printf("N=%d, X=%d, Y=%d\n", N, X, Y);
    // printf("total=%d, left=%d, X+Y=%d, layer=%d\n", total, left, X+Y, layer);
    if(X<0){
        X = - X;
    }
    if(X+Y>layer*2){
        return 0;
    }else if(X+Y<layer*2){
        return 1;
    }
    if(left == layer*4+1){
        return 1;
    }
    if(X==0){
        return 0;
    }
    
    int num2 = (layer*2+1) - X;
    // printf("left=%d, num2=%d, layer*2+num2=%d\n", left, num2, layer*2-num2);
    if(num2>left){
        return 0;
    }
    if(layer*2+num2<=left){
        return 1;
    }
    
    double ret = get_ncr_or_more(left, num2);
    return ret;

}
void testcase(int t)
{
	string result_str = "OK";
    int N, X, Y;
    cin >> N >> X >> Y;
    double result = calc(N,X,Y);
    printf("Case #%d: %lf\n", (t+1), result);
    // cout << "Case #" << (t+1) << ": " << result << endl;
}

int main(int argc, char *argv[]) {
	int T;
	// ios::sync_with_stdio(false);
    init_ncr();
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

