/*
 * =====================================================================================
 *
 *         Author:  KissBuaa.DS(AC)
 *        Company:  BUAA-ACMICPC-Group
 *
 * =====================================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include <stdbool.h>
#include <math.h>
#define LL long long
#define CLR(x) memset(x,0,sizeof(x))
#define typec double
#define sqr(x) ((x)*(x))
#define abs(x) ((x)<0?(-(x)):(x))
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
#define PI acos(-1.0)
#define lowbit(x) ((x)&(-(x)))
#define lson l , m , rt << 1
#define rson m + 1 , r , rt << 1 | 1
#define inf 100000000
//For C++
#include <cctype>
#include <ctime>
#include <climits>
#include <algorithm>
#include <functional>
#include <numeric>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <bitset>
#include <list>
#include <iostream>
#include <sstream>
#include <fstream>
#include <iomanip>
using namespace std;
const double eps=1e-10;
int dblcmp(typec d) {
    if (fabs(d)<eps)
       return 0;
    return (d>0)?1:-1;
}
int n,m,T;
const int N=2000;
double a[N],sum;
bool b[N];
int main(){
    freopen("A-small-attempt6.in","r",stdin);
    freopen("A.out","w",stdout);
    cin>>T;
    for (int icase=1;icase<=T;++icase){
        cin>>n;
        sum=0.0;
        for (int i=0;i<n;++i) {
            cin>>a[i];
            sum+=a[i];
        }
        CLR(b);
        int m=0,nn,nnn;
        nn=0;      
        double ss=0.0;
        for (int i=0;i<n;++i){
           if (dblcmp(a[i]-2.0*sum/(double)n)>0) {
              b[i]=true;
              ss+=a[i];
           }
           else ++nn;
        }
        printf("Case #%d:",icase);
        double s=(2.0*sum-ss)/(double)nn;
        for (int i=0;i<n;++i)
            if (b[i]) printf(" 0.000000");
            else printf(" %.6lf",100.0*(s-a[i])/sum);
        printf("\n");
    }
} 
