#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <cstring>
#include <cmath>
#include <queue>
#include <map>
#include <vector>
#include <stack>
#include <set>
#include <fstream>
#include <iomanip>
#define pb push_back
#define mp make_pair
#define M 10000
#define limit 150000
#define Inf 1e9+1
#define accr 1e-6
#define PI 3.141592653589793238462643383279502884197
#define ll (long long)
#define ld long double
#define ff first.first
#define fs first.second
#define Mod 1000000007
#define sec second
using namespace std;
int main()
{
    int i,j,k,t;
    int r,c,w,ans,ans1,ans2,Case;
    freopen("Input_2.in","r",stdin);
    freopen("Output_2.txt","w",stdout);
    cin>>t;
    Case=0;
    while(t--)
    {
        Case++;
        cin>>r>>c>>w;
        ans1=(c/w)*r;
        ans=ans1+w-1;
        if(c%w!=0) ans++;
        cout<<"Case #"<<Case<<": "<<ans<<endl;
    }
    return 0;
}
