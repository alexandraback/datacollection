/* 
 * File:   main.cpp
 * Author: Tarun
 *
 * Created on April 28, 2012, 6:41 AM
 */

#include <cstdlib>
#include<cstdio>
#include<iostream>
#include<math.h>
#include<vector>
#include<map>
#include<string.h>
#include<queue>
#include<algorithm>
#include<string.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef unsigned long long ulint;
typedef long long lint;
#define sz(a) int((a).size())
#define pb push_back
#define all(c) (c).begin(),(c).end()
#define tr(c,i) for(typeof((c).begin() i = (c).begin(); i != (c).end(); i++)
#define present(c,x) ((c).find(x) != (c).end())
#define cpresent(c,x) (find(all(c),x) != (c).end())

int main() {
    int t;
    FILE *fi = new FILE;
    fi = fopen("input.txt","r");
    FILE *fo = new FILE;
    fo = fopen("output.txt","w+");
    //fi = stdin;
    //fo = stdout;
    fscanf(fi,"%d",&t);
    for(int i=1;i<=t;i++)
    {
        int a,b;
        fscanf(fi,"%d%d",&a,&b);
        /*double **e = new double* [a+1];
        for (int i=1;i<=a;i++) e[i] = new double[a+1];*/
        double *p = new double[a+1];
        for(int i=1;i<=a;i++) fscanf(fi,"%lf",&p[i]);
        double x = 1;
        double mn = b+1;
        for(int i=1;i<=a;i++)
        {
            x*=p[i];
            double y = x*(b-i)+(1-x)*(b-i+1+b)+a-i;
            mn = min(mn,y);
        }
        fprintf(fo,"Case #%d: %.6lf\n",i,mn+1);
    }
    return 0;
}
