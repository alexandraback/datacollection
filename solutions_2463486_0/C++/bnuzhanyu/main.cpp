#include <iostream>
#include <map>
#include <algorithm>
#include <cstdio>
#include <string>
#include <vector>
#include <iomanip>
#include <sstream>
#include <fstream>
using namespace std;




//#define fin cin
//#define fout cout
typedef long long ll;
ll array[]={
1,4,9,121,484,10201,12321,14641,40804,44944,
1002001,1234321,4008004,100020001,102030201,104060401,
121242121,123454321,125686521,400080004,404090404,10000200001,
10221412201,12102420121,12345654321,40000800004,1000002000001,
1002003002001,1004006004001,1020304030201,1022325232201,
1024348434201,1210024200121,1212225222121,1214428244121,
1232346432321,1234567654321,4000008000004,4004009004004
};

bool ispalindrome(ll n)
{
    ll s = 0;
    ll tmpn = n;
    while(n){
        s = s*10 + n%10;
        n/=10;
    }
    return s==tmpn;

}

int main()
{

    fstream fin("C.in");
    fstream fout("C.out", ios_base::out);
    int T;
    int maxN = sizeof(array)/sizeof(ll);
    fin>>T;
    ll x, y;
    for(int ca=1; ca<=T; ++ca){
        fin>>x>>y;
        fout<<"Case #"<< ca << ": ";
        fout << upper_bound(array, array+maxN, y)
                - lower_bound(array, array+maxN, x) << endl;
    }
    return 0;
}
