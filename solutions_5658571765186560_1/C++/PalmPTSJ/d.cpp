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

struct point {
    int x;
    int y;
    int T;
};
int X,R,C;
void solve()
{
    // START HERE <-----------------------------------------
    cin >> X >> R >> C;
    int tR = R;
    int tC = C;
    R = min(tR,tC);
    C = max(tR,tC);
    if(X>=7) {
        // hard locked , can't
        printf("RICHARD\n");
    }
    else {
        if(R*C % X != 0) {
            printf("RICHARD\n"); // can't
        }
        else if(R>=X&&C>=X) {
            // can be placed !
            printf("GABRIEL\n");
        }
        else {
            if(X == 6) {
                if(R<=3) printf("RICHARD\n"); /// can't
                if(R==4) printf("GABRIEL\n"); /// can
                if(R==5) printf("GABRIEL\n"); /// can
            }
            else if(X==5) {
                if(R<=2) printf("RICHARD\n"); /// can't
                if(R==3 && C==5) printf("RICHARD\n"); /// can't , special block on the way
                if(R==3 && C>5) printf("GABRIEL\n"); /// can
                if(R==4) printf("GABRIEL\n"); /// can
            }
            else if(X==4) {
                if(R==1) printf("RICHARD\n"); /// can't
                if(R==2) printf("RICHARD\n"); /// can't , S block
                if(R==3) printf("GABRIEL\n"); /// can
            }
            else if(X==3) {
                if(R==1) printf("RICHARD\n"); /// can't
                if(R==2) printf("GABRIEL\n"); /// can
            }
            else if(X==2) {
                if(R==1) printf("GABRIEL\n"); /// can
            }
            else printf("GABRIEL\n"); /// can
        }
    }
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
