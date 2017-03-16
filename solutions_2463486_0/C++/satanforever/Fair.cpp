#include <stdlib.h>
#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <string.h>
#include <algorithm>
#include <math.h>
#include <complex>
using namespace std;

#define read(c) scanf("%d",&(c))
#define FOR(i,n) for (int i=0;i<(n);i++)
#define FR(i,a,b) for (int i=(a);i<(b);i++)
#define fillzero(d) memset(d,0,sizeof(d))
#define fillmax(d) memset(d,63,sizeof(d))
#define dumps(x) cerr<<(__LINE__)<< ':'<<#x<<" = "<<(x)<<endl
#define dump(x) cerr<<(__LINE__)<< ':'<<#x<<" = "<<(x)<<"	"
#define shit cerr<<"Line:"<<(__LINE__)<<endl;
#define fileread freopen("/Users/satanforever/Downloads/C-small-attempt0.in.txt","r",stdin)
#define filewrite freopen("/Users/satanforever/Documents/codeJam/C-large.out","w",stdout)
#define closeread fclose(stdin)
#define closewrite fclose(stdout)
#define MAXINT 0x7fffffff

bool pali(long long n) {
    char str[30];
    sprintf(str, "%lld", n);
    int len = strlen(str);
    //cout << str <<"   "<<len<< endl; 
    for (int i = 0; i < len/2; i++)
        if (str[i] != str[len-i-1])
            return false;
    return true;
}
int main() {
//fileread;
//filewrite;
long long N = 1000;
int count[N];
count[0] = 0;
for (int i = 1; i <= N; i++) {
    count[i] = count[i-1];
    if (pali(i) & pali((long long)i*i)) {
        count[i]++; 
       // cout << "count:" << count[i] <<endl;
    }
}
int T;
long double A, B;
cin >> T;
for(int i = 1; i <= T; i++) {
    cin >> A >> B;
    cout << "Case #" << i << ": " << count[(int)floor(sqrt(B))] - count[(int)floor(sqrt(A-1))] << endl;
}
//closeread;
//closewrite;
  	return 0;
}
