#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

double solve(double C, double F, double X, double t, double r, double a);
void print(double result, int r);

int main()
{
    int n;
    double C;
    double F;
    double X;
    double t=0;
    double r=2;
    double a;
    double result;
    
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> C >> F >> X;
        result = solve(C,F,X,t,r,C/r);
        print(result, i+1);
    }

    return 0;
}

double solve(double C, double F, double X, double t, double r, double a)
{
    if(X<=C) return X/r;
    double t1 = (X-C)/r;
    double t2 = X/(r+F);
    if(t1<t2) return t+X/r;
    else return solve(C,F,X,t+a,r+F,C/(r+F));
}

void print(double result, int r)
{
    printf("Case #%d: %.7f\n", r, result);
}
