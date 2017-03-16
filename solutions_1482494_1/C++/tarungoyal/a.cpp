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
#include <set>
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
        int n;
        set<ii> s;
        fscanf(fi,"%d",&n);
        ii *a = new ii[n];
        ii *b = new ii[n];
        int *c = new int[n];
        int *b1 = new int[n];
        for(int i=0;i<n;i++)
        {
            fscanf(fi,"%d%d",&(a[i].first),&(b[i].first));
            c[i]=0;
            a[i].second=i;b[i].second = i;
            b1[i] = b[i].first;
        }
        sort(a,a+n);
        sort(b,b+n);
        int strs = 0;
        int x = n+n;
        int j=0,k=0;
        int cnt=0;
        while(a[j].first<=0) 
        {
            //cout<<"blah";
            s.insert(ii(b1[a[j].second],a[j].second));
            j++;
        }
        while(k<n)
        {
            //cout<<"blah";

            bool chk = 0;
            if(b[k].first<=strs)
            {
                strs+=2-c[b[k].second];
                c[b[k].second]=2;
                k++;
                cnt++;
                chk=1;
            }
            else if(!s.empty())
            {
                while(!s.empty()&&chk==0)
                {
                set<ii>::iterator it = s.end();
                it--;
                int k = it->second;
                s.erase(it);
                if(c[k]==0)
                {
                    strs+=1;
                    c[k]=1;
                    cnt++;
                }
                chk=1;
                }
            }
            while(a[j].first<=strs&&j<n)
            {
                if(c[a[j].second]==0) s.insert(ii(b1[a[j].second],a[j].second));
                j++;
            }
            if(!chk) break;
        }
        if(strs!=x) fprintf(fo,"Case #%d: Too Bad\n",i);
        else fprintf(fo,"Case #%d: %d\n",i,cnt);
    }
    return 0;
}
