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

/// 1=1 2=i 3=j 4=k
int multTable[5][5] = {
{0,0,0,0,0},
{0,1,2,3,4},
{0,2,-1,4,-3},
{0,3,-4,-1,2},
{0,4,3,-2,-1},
};

int qmult(int a,int b) {
    if((a < 0) ^ (b < 0)) {
        // minus
        return -(multTable[abs(a)][abs(b)]);
    }
    return (multTable[abs(a)][abs(b)]);
}

void solve()
{
    // START HERE <-----------------------------------------
    int L = getInt();
    int X = getInt();
    string str;
    cin >> str;
    // replace str
    for(int j = 0;j < L;j++) {
        if(str[j] == 'i') str[j] = '2';
        if(str[j] == 'j') str[j] = '3';
        if(str[j] == 'k') str[j] = '4';
    }
    // loop 8 times to see i , k
    int phase = 0;
    bool yes = false;
    int now = 1;
    for(int i = 0;i < min(X,9);i++) {
        for(int j = 0;j < L;j++) {
            now = qmult(now,str[j]-'0');
            //printf("%d = %d (PH %d)\n",j,now,phase);
            if(phase == 0 && now == 2) {
                phase = 1; // see i
            }
            else if(phase == 1 && now == 4) {
                phase = 2; // see k after i
                break;
            }
        }
        if(phase == 2) break;
    }
    if(phase == 2) {
        //printf("PHASE PASSED\n");
        // if all of this mult = 1
        now = 1;
        for(int j = 0;j < L;j++) {
            now = qmult(now,str[j]-'0');
        }
        //printf("ALL %d\n",now);
        if(now > 2) now = 2;
        else if(now < -2) now = -2;
        // 1 -1 , 2 -2
        if(X%4==1 || X%4==3) {
            if(now == -1) yes = true;
        }
        if(X%4 == 2) {
            if(now == 2 || now == -2) yes = true;
        }
    }
    if(yes) printf("YES\n");
    else printf("NO\n");
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
