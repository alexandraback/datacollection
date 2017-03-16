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
    double cost = getDouble();
    double farm = getDouble();
    double finish = getDouble();
    double rate = 2;
    double ans = 0;
    while(true) {
        if(finish <= cost) { // go directly to finish
            ans += finish/rate;
            break;
        }
        else {
            if((cost/rate + finish/(rate+farm)) < (finish/rate)) {
                ans += cost/rate;
                rate += farm;
            }
            else {
                ans += finish/rate;
                break;
            }
        }
    }
    printf("%f",ans);
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
            printf("\n");
        }
    } else {
        solve();
    }
}
