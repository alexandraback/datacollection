#include<iostream>
#include<fstream>
#include<string>
#include<algorithm>
using namespace std;

const int MAXN = 1000;

int n;
int A[MAXN];
int acSum[MAXN];
int currentS1;
int currentS2;
int status[MAXN];
bool found;

void find(int pos) {
    if (pos == n) {
        if (currentS1 != currentS2) return;
        found = true;        
        for (int i = 0; i < n; i++) {
            if (status[i] == 1) {
                cout << A[i] << " ";
            }
        }
        cout << endl;
        for (int i = 0; i < n; i++) {
            if (status[i] == 2) {
                cout << A[i] << " ";
            }
        }
        cout << endl;
        return;
    } 
    status[pos] = 1;
    currentS1 += A[pos];
   /* if (currentS2 + acSum[pos+1] >= currentS1)*/ find(pos+1);
    if (found) return;
    currentS1 -= A[pos];
    status[pos] = 2;
    currentS2 += A[pos];
    /*if (currentS1 + acSum[pos+1] >= currentS2)*/ find(pos+1);
    if (found) return;
    currentS2 -= A[pos];
    status[pos] = 0;
    find(pos+1);
    if (found) return;
}

int main() {
    freopen("C-small-attempt2.in","r",stdin);
    freopen("C-small-attempt2.out","w",stdout);
    int ntests;
    cin >> ntests;
    for (int test = 1; test <= ntests; test++) {      
        cout << "Case #" << test << ":" << endl;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> A[i];
        }
        sort(A,A+n);
        acSum[n] = 0;
        currentS1 = 0;
        currentS2 = 0;
        for (int i = 0; i < n; i++) status[i] = 0;
        for (int i = n-1; i>=0; i--) {
            acSum[i] = acSum[i+1] + A[i];
        }
        found = false;
        find(0);       
        if (!found) cout << "Impossible" << endl;
    }

}