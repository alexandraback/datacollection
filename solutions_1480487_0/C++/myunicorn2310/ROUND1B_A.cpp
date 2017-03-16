#include<iostream>
#include<fstream>
#include<string>
#include<algorithm>
using namespace std;

const int MAXN = 150000;

int n;
int Point[MAXN];
int PointSort[MAXN];
double answer[MAXN];

int main() {
    freopen("A-small-attempt1.in","r",stdin);
    freopen("A-small-attempt1.out","w",stdout);
    int ntests;
    cin >> ntests;
    int maxP = 0;
    for (int test = 1; test <= ntests; test++) {
        cin >> n;
        int total = 0;
        for (int i = 0; i < n; i++) {
            cin >> Point[i];
            PointSort[i] = Point[i];
            total += Point[i];
        }
        sort(PointSort,PointSort+n);  
        int totalDiff;
        int endAt;
        int pointEndAt;
        for (int p = n-1; p>=0; p--) {            
            totalDiff = 0;
            for (int i = 0; i < p; i++) {                
                totalDiff += PointSort[p] - PointSort[i];
            }
            if (totalDiff <= total) {
                endAt = p;
                pointEndAt = PointSort[p];
                break;
            }
        }
        double temp = (totalDiff * 100.0) / total;
        double minP = (100.0 - temp) / (endAt + 1);        
        cout << "Case #" << test << ":";
        for (int i = 0; i <n; i++) {
            if (Point[i] > PointSort[endAt]) {
                answer[i] = 0.0;
            } else {
                double temp = ((PointSort[endAt] - Point[i]) * 100.0);
                temp = temp / total;
                answer[i] = minP + temp;            
            }
        }
        for (int i = 0; i < n; i++) {
            printf(" %0.6f", answer[i]);
        }
        cout << endl;
    }

}