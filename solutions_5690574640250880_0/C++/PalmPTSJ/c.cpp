// Version 2
#define TESTCASE 1
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <vector>
#include <math.h>
#include <queue>
#define FOR(s,t) for(int s = 0;s < t;s++)
#define PI pair<int,int>
typedef long long ll;

using namespace std;
void print(int i) { printf("%d ",i); }
void print(double i) { printf("%lf ",i); }
int getInt() {
    int a;
    scanf("%d",&a);
    return a;
}
double getDouble() {
    double a;
    scanf("%lf",&a);
    return a;
}

void getArray(int *arr,int size) { for(int i = 0;i < size;i++) arr[i] = getInt(); }
void getArray(double *arr,int size) { for(int i = 0;i < size;i++) arr[i] = getDouble(); }

int sortMinToMax(const void* a,const void* b){ return *((int*)a) - *((int*)b); }
int sortMaxToMin(const void* a,const void* b){ return *((int*)b) - *((int*)a); }
void sortArrayUp(int* arr,int n){ qsort(arr,n,sizeof(int),sortMinToMax); } /* Min -> Max */
void sortArrayDown(int* arr,int n){ qsort(arr,n,sizeof(int),sortMaxToMin); } /* Max -> Min */

template<class t>
t* array(int N) { return (t*)calloc(sizeof(t),N); }
void solve()
{
    // START HERE <-----------------------------------------
    int r,c,m;
    scanf("%d %d %d",&r,&c,&m);
    bool swap = false;
    if(c>r) {
        // swap
        int tmp = c;
        c = r;
        r = tmp;
        swap = true;
    }
    char arr[r][c];
    bool visit[r][c];
    for(int i = 0;i < r;i++) for(int j = 0;j < c;j++) {arr[i][j] = '.'; visit[i][j] = false;}
    if(r>3&&c>2&&m>0) {
        for(int i = 0;i < r-3;i++) {
            for(int j = 0;j < c-2;j++) {
                arr[i][j] = '*';
                m--;
                if(m <= 0) break;
            }
            if(m <= 0) break;
        }
    }
    if(r>=3&&c>=2&&m>0) {
        // go
        int quota3 = c-2;
        int quota2 = r-3;
        for(int i = 0;i < quota3;i++) {
            if(m == 1) {
                arr[r-3][i] = '*';
                m=0;
                break;
            }
            else if(m%2==0 && m>=6 && quota3-i>=2) {
                arr[r-3][i] = '*';
                arr[r-2][i] = '*';
                arr[r-1][i] = '*';
                arr[r-3][i+1] = '*';
                arr[r-2][i+1] = '*';
                arr[r-1][i+1] = '*';
                m-=6;
                i++;
            }
            else if(m%2==0) break;
            else if(m%2==1) {
                arr[r-3][i] = '*';
                arr[r-2][i] = '*';
                arr[r-1][i] = '*';
                m-=3;
            }
            if(m<=0) break;
        }
        // place all left in quota 2
        for(int j = 0;j < quota2;j++) {
            if(m==1) { // surely fail
                arr[j][c-1] = '*';
                m--;
            }
            else {
                arr[j][c-1] = '*';
                arr[j][c-2] = '*';
                m-=2;
            }
            if(m<=0)break;
        }
        // place thing in the last space
        if(m>0) {
            for(int i = 0;i < r;i++) {
                for(int j = 0;j < c;j++) {
                    if(arr[i][j] != '*') {
                        arr[i][j] = '*';
                        m--;
                    }
                    if(m<=0)break;
                }
                if(m<=0)break;
            }
        }
    }
    // special case ( always r>=c)
    if(m>0) {
        for(int i = 0;i < r;i++) {
            for(int j = 0;j < c;j++) {
                if(arr[i][j] != '*') {
                    arr[i][j] = '*';
                    m--;
                }
                if(m<=0)break;
            }
            if(m<=0)break;
        }
    }

    // check if possible or not
    queue<PI> Q;
    Q.push(PI(c-1,r-1));
    while(!Q.empty()) {
        //system("pause");
        PI pos = Q.front();
        Q.pop();
        int x = pos.first;
        int y = pos.second;
        if(visit[y][x] == true) continue;
        if(arr[y][x] == '*') {
            visit[y][x] = true;
            continue;
        }
        // if no mine around here
        bool haveMine = false;
        for(int i = -1;i<=1;i++) {
            for(int j = -1;j <= 1;j++) {
                if(x+i >= 0 && x+i < c && y+j >= 0 && y+j < r) {
                    if(arr[y+j][x+i] == '*') haveMine = true;
                }
            }
        }
        visit[y][x] = true;
        if(haveMine) continue;
        for(int i = -1;i<=1;i++) {
            for(int j = -1;j <= 1;j++) {
                //printf("%d %d\n",x+i,y+j);
                if(x+i >= 0 && x+i < c && y+j >= 0 && y+j < r) {
                    Q.push(PI(x+i,y+j));
                }
            }
        }
    }
    bool impossible = false;
    for(int i = 0;i < r;i++) {
        for(int j = 0;j < c;j++) {
            if(arr[i][j] == '.' && visit[i][j] == false) {
                impossible = true;
                break;
            }
        }
        if(impossible) break;
    }
    //impossible = false;
    printf("\n");
    if(impossible) printf("Impossible\n");
    else {
        for(int i = 0;i < (swap?c:r);i++) {
            for(int j = 0;j < (swap?r:c);j++) {
                if(swap) {
                    if(i==c-1&&j==r-1) printf("c");
                    else printf("%c",arr[j][i]);
                }
                else {
                    if(i==r-1&&j==c-1) printf("c");
                    else printf("%c",arr[i][j]);
                }
            }
            printf("\n");
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
            //printf("\n");
        }
    } else {
        solve();
    }
}
