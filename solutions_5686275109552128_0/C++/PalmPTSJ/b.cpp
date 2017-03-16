// Version 2.1
#define TESTCASE true
#define DEBUG false

#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <vector>
#include <math.h>
#include <queue>
#include <algorithm>
#include <string.h>
#include <stack>
#define FOR(s,t) for(int s = 0;s < t;s++)
#define PI pair<int,int>
typedef long long ll;

using namespace std;
void print(int i) { printf("%d ",i); }
void print(double i) { printf("%f ",i); }
int getInt() {
    int a;
    scanf("%d",&a);
    return a;
}
void getInt(int& a) {
    scanf("%d",&a);
}
double getDouble() {
    double a;
    scanf("%lf",&a);
    return a;
}
void getDouble(double& a) {
    scanf("%lf",&a);
}
void getArray(int *arr,int size) { for(int i = 0;i < size;i++) getInt(arr[i]); }
void getArray(int **arr,int N,int M) { for(int i = 0;i < N;i++) for(int j = 0;j < M;j++) getInt(arr[i][j]);}
void getArray(double *arr,int size) { for(int i = 0;i < size;i++) getDouble(arr[i]); }
void getArray(double **arr,int N,int M) { for(int i = 0;i < N;i++) for(int j = 0;j < M;j++) getDouble(arr[i][j]); }

template<class t> bool sortMaxToMin(const t&a,const t&b) { return a>b; }

template<class t> void sortUp(t* arr,int n) { sort(arr,&arr[n]); }
template<class t> void sortDown(t* arr,int n) { sort(arr,&arr[n],sortMaxToMin<t>); }

template<class t> t* array(int N) { return (t*)calloc(sizeof(t),N); }
template<class t> t** array(int N,int M) {
    t** toRet = (t**)calloc(sizeof(t*),N);
    for(int i = 0;i < N;i++) toRet[i] = (t*)calloc(sizeof(t),M);
    return toRet;
}
template<class t> void freeMatr(t** matr,int N,int M) {
    for(int i = 0;i < N;i++) free(matr[i]);
    free(matr);
}

void printArray(int* arr,int n) { for(int i = 0;i < n;i++) printf("%d ",arr[i]);}

bool same(const string& a,const string& b) { return a.compare(b)==0;}

void solve()
{
    // START HERE <-----------------------------------------
    int D = getInt();
    vector<int> V;
    int mxAns = 0;
    for(int i = 0;i < D;i++) {
        int t = getInt();
        V.push_back(t);
        mxAns = max(mxAns,t);
    }
    int ans = mxAns;
    for(int k = mxAns-1;k > 0;k--) {
        // make everything <= k
        int splitTime = 0;
        for(int j = 0;j < D;j++) {
            if(V[j] > k) {
                // split with binary search
                int L,R,mid;
                L = 2;
                R = V[j]; // into ... sections
                mid = (L+R)/2;
                int bestSplit = V[j];
                while(L<=R) {
                    //printf("TESTING %d-%d-%d for %d k=%d\n",L,mid,R,V[j],k);
                    // if pass
                    if(((V[j]%mid==0)?(V[j]/mid):((V[j]/mid) + 1)) <= k) {
                        bestSplit = min(bestSplit,mid);
                        R = mid-1;
                    }
                    else {
                        L = mid+1;
                    }
                    mid = (L+R)/2;
                }
                splitTime += bestSplit-1;
            }
        }
        //printf("%d+%d\n",splitTime,k);
        ans = min(ans,splitTime+k);
    }
    printf("%d\n",ans);

}

int main()
{
    if(TESTCASE) {
        int t,tt;
        scanf("%d",&tt);
        for(t=0;t < tt;t++)
        {
            printf("Case #%d: ",t+1);
            solve();
        }
    } else {
        solve();
    }
}
