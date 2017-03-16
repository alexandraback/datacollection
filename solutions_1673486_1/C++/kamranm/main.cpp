#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <fstream>
#include <set>
#include <map>
#include <cmath>
#pragma comment(linker,"/STACK:16777216")
#define inf 1000000000
#define MP make_pair
#define PI acos(-1.0)
#define eps 1e-9
using namespace std;
typedef long long i64;
typedef unsigned long long u64;
double P[200200];
int T,A,B;

int main()
{

    ifstream cin("A-large.in");
    ofstream cout("output.txt");

    double res,alt;
    cin>>T;

    for(int ts=1;ts<=T;ts++){
        cin>>A>>B;

        alt=1.0;

        for(int i=1;i<=A;i++){cin>>P[i];alt*=P[i];}

        res=1.0*B+2.0;
        res=min(res,alt*(B-A+1)+(1.0-alt)*(B-A+1+B+1));

        alt=1.0;
        for(int i=1;i<=A;i++){
            alt*=P[i];
            res=min(res,alt*(A-i+B-i+1)+(1.0-alt)*(A-i+B-i+1+B+1));
        }

        cout.setf(ios::fixed);
        cout.precision(15);
        cout.setf(ios::showpoint);
        cout<<"Case #"<<ts<<": "<<res<<endl;
    }

    cin.close(); cout.close();

    return 0;
}
