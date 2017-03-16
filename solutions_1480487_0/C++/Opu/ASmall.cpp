#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cctype>
#include <cstdlib>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <list>
#include <bitset>
#include <numeric>
#include <algorithm>
#include <functional>
using namespace std;

#define PI 2*acos(0.0)
#define FOR(i,n) for(int i = 0;i<n;++i)
#define setbit(a,b) a|=(1<<b)
#define S1(a) scanf("%d",&a)
#define S2(a,b) scanf("%d %d",&a,&b)
#define S3(a,b,c) scanf("%d %d %d",&a,&b,&c)
#define C1(a) __builtin_popcount(a)
#define gcd(a,b) __gcd(a,b)
#define ALL(a) (a.begin(),a.end())

typedef long long LL;
typedef vector<int> vi;
const int INF = (1LL<<31)-1;

const double eps = (1e-12);

int main(){

    freopen("A-small-attempt0.in","r",stdin);
    freopen("A-Small_output.txt","w",stdout);

    int t;
    S1(t);

    for(int ca = 1;ca<=t;++ca){

        int n;
        S1(n);

        int A[205];
        double sum = 0.;
        for(int i = 0;i<n;++i){
            S1(A[i]);
            sum += A[i];
        }

        vector<double>v;
        for(int i = 0;i<n;++i){

            double low = 0,high = 1.0,mid,res=100.000000;

            while( fabs(low-high) > eps ){

                mid = (low+high)/2.;

                double r = 1.0-mid;

                double S = A[i]+sum*mid;

                vector< double > rest;
                for(int j = 0;j<n;++j)if(i!=j)
                    rest.push_back(A[j]);
                sort(rest.begin(),rest.end());

                bool done = false;
                for(int j = 0;j<rest.size();++j){
                    if( rest[j] < S ){
                        double p = (S-rest[j])/sum + (1e-10);
                        if(p>r){
                            done = true;
                            break;
                        }
                        r -= p;
                    }
                }
                if(done){
                    high = mid;
                    res = mid*100.0;
                }
                else
                    low = mid;

            }

            v.push_back(res);

        }
        printf("Case #%d:",ca);
        for(int i = 0;i<v.size();++i)
            printf(" %.10lf",v[i]);
        puts("");

    }
    return 0;

}
