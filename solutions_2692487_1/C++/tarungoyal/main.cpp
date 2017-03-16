/* 
 * File:   main.cpp
 * Author: Tarun
 *
 * Created on May 4, 2013, 9:36 PM
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
    FILE *fin = fopen("input.txt","r");
    FILE *fout = fopen("output.txt","w");
    fscanf(fin,"%d", &t);
    for(int I=1;I<=t;I++) {
        int sz,n;
        fscanf(fin,"%d%d",&sz,&n);
        int *a = new int[n+1];
        for(int i=0;i<n;i++)
        {
            fscanf(fin,"%d",&a[i]);
        }
        sort(a,a+n);
        int *count = new int[n+1];
        count[0] = 0;
        for(int i=0;i<n;i++)
        {
            count[i+1] = count[i];
            if(count[i+1]>n) continue;
            if(a[i]<sz)
            {
                sz+=a[i];
            }
            else
            {
                while(a[i]>=sz)
                {
                    sz+=sz-1;
                    count[i+1]++;
                    if(count[i+1]>n) break;
                }
                sz+=a[i];
            }
        }
        int max = n;
        for(int i=0;i<n;i++)
        {
            int discard = count[i]+n-i;
            if(max>discard) max = discard;
        }
        if(max>count[n]) max = count[n];
        fprintf(fout,"Case #%d: %d\n",I,max);
    }
    fclose(fin);
    fclose(fout);
    return 0;
}
