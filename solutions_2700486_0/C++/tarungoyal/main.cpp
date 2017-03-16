/* 
 * File:   main.cpp
 * Author: Tarun
 *
 * Created on May 4, 2013, 10:40 PM
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
    int *precomp = new int[100];
    for(int i=1;i<=100;i++)
    {
        precomp[i-1] = 2*i*i-i;
    }
    FILE *fin = fopen("input.txt","r");
    FILE *fout = fopen("output.txt","w");
    fscanf(fin,"%d", &t);
    for(int I = 1; I<=t;I++) {
        int n,x,y;
        fscanf(fin,"%d%d%d",&n,&x,&y);
        if(x<0) x = 0-x;
        fprintf(fout,"Case #%d: ",I);
        int z = x+y;
        int full = 0;
        int fullInd = 0;
        for(int i = 0;i<1000;i++)
        {
            if(precomp[i]>n) {full = precomp[i-1];fullInd = i*2-2;break;}
        }
        cout<<I<<" "<<n<<" "<<full<<" "<<fullInd<<endl;
        if(z<=fullInd) fprintf(fout,"1.0\n");
        else if(z>fullInd+2) fprintf(fout,"0.0\n");
        else
        {
            n = n-full;
            z = y+1;
            int rem2 = n;
            double res = 0;
            if(z>n) fprintf(fout,"0.0\n");
            else {
                if(x==0) fprintf(fout,"0.0\n",res);
                else if(n-fullInd-2>=z) fprintf(fout,"1.0\n",res);
                else
                {
                res = 1;
                double x = 1;
                for(int i=1;i<z;i++)
                {
                    x = x*(n-i+1)/i;
                    res+= x;
                }
                for(int i=0;i<n;i++) res/=2;
                res = 1-res;
                fprintf(fout,"%lf\n",res);
                }
            }
        }
    }
    fclose(fin);
    fclose(fout);
    return 0;
}
