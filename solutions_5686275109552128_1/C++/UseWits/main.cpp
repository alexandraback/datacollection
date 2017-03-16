#include <iostream>
#include <vector>

using namespace std;

int run() {
    int n;
    cin >> n;
    vector<int> p(n);
    for(int i=0; i<n; i++)
        cin >> p[i];
    int bestT=1000000000;
    for(int m = 1; m <= 1001; m++) {
        int maxMoves=0;
        int maxCakes=0;
        for(int i=0; i<n; i++) {
            if(p[i] > m){
                maxCakes = m;
                maxMoves += (p[i]-1)/m;
            }else if(p[i] > maxCakes) maxCakes=p[i];
        }
        int t = maxMoves+maxCakes;
        if(t < bestT) bestT=t;
    }
    return bestT;
}

int main() {
    int ncases;
    cin >> ncases;
    for(int i=0; i<ncases; i++)
        cout << "Case #"<<(i+1) << ": " <<run()<<"\n";
}
