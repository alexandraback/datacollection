using namespace std;

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <string.h>
#include <string>
#include <sstream>
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
#define forNF(I,F,C) for(int32_t I=(F); I<int32_t(C); ++I)
#define forN(I,C) forNF(I,0,C)
#define vi vector<int>
#define pb push_back
#define sumMod(a,b) a=(a+b)%1000003
#define mulMod(a,b) a=(a*b)%1000003
#define toZero(a) forN(kk,sizeof(a)) ((char*)a)[kk]=0
//#define local



double solve(int a, int b ,double* mistake)
{
    double res = b+2;
    forN(i,a+1)
    {
        double tot=1;
        forN(j,i)
        {
            tot*= mistake[j];
        }
        res = min(res , tot * ((b-i) + (a-i) + 1) + (1-tot)*( (b-i) + (a-i) + 1 + b + 1 ));
    }
    return res;
}
double mistake[100000];
int main()
{

    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    long long nrT;
    //string st;
    //cin >> st;
    cin >> nrT;

    forN(test,nrT)
    {
        cout << "Case #"<<test+1<<": ";

        int a,b;

        cin >> a >> b;
        forN(i,a)
        cin >> mistake[i];

        printf("%.6f\n",solve(a,b,mistake));
    }
    return 0;
}
