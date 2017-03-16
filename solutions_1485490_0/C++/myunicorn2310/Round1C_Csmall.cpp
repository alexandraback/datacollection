#include<iostream>
#include<fstream>
#include<string>
#include<algorithm>
using namespace std;

const int MAXN = 102;
int n,m;
long long boxOriginNumber[MAXN];
int boxOriginType[MAXN];
int boxMaxType;
long long toyOriginNumber[MAXN];
long long oldToyNumber[MAXN];
int toyOriginType[MAXN];
int toyMaxType;
long long boxExpand[MAXN][MAXN*MAXN*10];
long long toyExpand[MAXN][MAXN*MAXN*10];
int nBoxExpand[MAXN];
int nToyExpand[MAXN];
int lastBoxType[MAXN];
int lastToyType[MAXN];
int status[3];
long long best;
long long total;

void backtrack(int startAtBox, int startAtToy) {  
    if (startAtBox == n || startAtToy == m) {
        if (total > best) best = total;
        return;
    }
    int currentBoxType = boxOriginType[startAtBox];
    long long currentBoxes = boxOriginNumber[startAtBox];
    int toyType = toyOriginType[startAtToy];        
    long long toyNumber = toyOriginNumber[startAtToy];    
    if (toyType == currentBoxType) {
        if (toyNumber > currentBoxes) {
            toyOriginNumber[startAtToy] -= currentBoxes;
            total += currentBoxes;
            backtrack(startAtBox+1, startAtToy);
            toyOriginNumber[startAtToy] += currentBoxes;
            total -= currentBoxes;                
        } else {            
            boxOriginNumber[startAtBox] -= toyNumber;
            total += toyNumber;
            backtrack(startAtBox, startAtToy+1);
            boxOriginNumber[startAtBox] += toyNumber;
            total -= toyNumber;
        }
    } else {
        backtrack(startAtBox+1, startAtToy);
        backtrack(startAtBox, startAtToy+1);
    }
}

int main() {
    freopen("C-small-attempt0.in","r",stdin);
    freopen("C-small-attempt0.out","w",stdout);
    int ntests;
    cin >> ntests;
    for (int test = 1; test <= ntests; test++) {      
        cin >> n >> m;
        boxMaxType = 0;
        toyMaxType = 0;
        best = 0;
        for (int i = 0; i < n; i++) {
            cin >> boxOriginNumber[i] >> boxOriginType[i];            
            nBoxExpand[i] = 0;
            if (boxOriginType[i] > boxMaxType) boxMaxType = boxOriginType[i];            
        }
        for (int i = 0; i < m; i++) {
            cin >> toyOriginNumber[i] >> toyOriginType[i];
            nToyExpand[i] = 0;
            if (toyOriginType[i] > toyMaxType) toyMaxType = toyOriginType[i];
        }
        total = 0;
        backtrack(0,0);
        printf("Case #%d: ",test);
        cout << best << endl;
    }
}