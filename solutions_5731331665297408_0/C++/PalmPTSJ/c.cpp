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
int n;
int edge[10][10];
int cEdge[10][10];
vector<string> okList;
string travDetail = "";
string debugDetail = "";
bool travUse[10];
string arr[10];
stack<int> goList;
bool go(int from,int ind)
{
    if(travDetail.compare(debugDetail) == 0)printf("GO %d -> [%d]=%d\n",from,ind,travDetail[ind]);
    if(ind >= n) return true;
    // if there is exists path
    if(cEdge[from][travDetail[ind]] == 1) {
        if(travDetail.compare(debugDetail) == 0) printf("GO NORMAL\n");
        // go to this edge and continue
        cEdge[from][travDetail[ind]] = 0;
        cEdge[travDetail[ind]][from] = 0;
        goList.push(from);
        return go(travDetail[ind],ind+1);
    }
    else {
        // if stack empty
        if(goList.empty()) {
            if(travDetail.compare(debugDetail) == 0) printf("STACK EMP\n");
            return false;
        }
        else {
            if(travDetail.compare(debugDetail) == 0) printf("BACK STACK\n");
            // go back first
            int toRet = goList.top();
            goList.pop();
            return go(toRet,ind);
        }
    }
}
void check()
{
    // check , debug
    /*for(int i = 0;i < n;i++) {
        printf("%d",travDetail[i]);
    }
    printf("\n");*/
    // go from now -> next
    //goList.push(travDetail[0]);
    bool isPass = go(travDetail[0],1);
    if(isPass) {
        /*for(int i = 0;i < n;i++) {
            printf("%d",travDetail[i]);
        }
        printf("\n");*/
        // form string
        string toPush = "";
        for(int i = 0;i < n;i++) {
            toPush.append(arr[travDetail[i]]);
        }
        okList.push_back(toPush);
        //printf(" PASS\n");
    }
    else {
    }
    while(!goList.empty()) goList.pop();
}
void perm()
{
    if(travDetail.size() >= n) {
        // go , copy edge
        FOR(i,10) FOR(j,10) cEdge[i][j] = edge[i][j];
        check();
    }
    else {
        for(int i = 0;i < n;i++) {
            if(travUse[i] == false) {
                travUse[i] = true;
                travDetail.push_back(i);
                perm();
                travDetail = travDetail.substr(0,travDetail.size()-1);
                travUse[i] = false;
            }
        }
    }
}
void solve()
{
    // START HERE <-----------------------------------------
    n = getInt();
    int m = getInt();
    // get n
    /*debugDetail.push_back(5);
    debugDetail.push_back(0);
    debugDetail.push_back(2);
    debugDetail.push_back(1);
    debugDetail.push_back(3);
    debugDetail.push_back(4);*/
    FOR(i,10) FOR(j,10) edge[i][j] = 0;
    FOR(i,10) travUse[i] = false;
    travDetail = "";
    FOR(i,n) cin>>arr[i];
    FOR(i,m) {
        int a = getInt();
        int b = getInt();
        edge[a-1][b-1] = 1;
        edge[b-1][a-1] = 1;
    }
    // check !!!
    perm();
    // find the answer
    while(okList.size() > 1)
    {
        if(okList[0].compare(okList[1]) < 0) {
            // keep [0]
            okList.erase(okList.begin() + 1);
        }
        else {
            okList.erase(okList.begin());
        }
    }
    cout << okList[0] << endl;
    okList.clear();
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
