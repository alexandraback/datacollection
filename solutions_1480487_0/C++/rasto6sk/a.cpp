#include<iostream>
#include<vector>
#include<map>
#include<string>
#include<sstream>
#include<cmath>
#include<algorithm>
#include<deque>
#include<set>
using namespace std;
#define ll long long
#define VI vector<ll>
#define VS vector<string>
#define PI pair<int,int>
#define MP make_pair
#define PB push_back

int main() {
    int T;
    cin >> T;
    cout.setf(ios::fixed, ios::floatfield); cout.precision(10);
    for (int t = 0; t < T; t++) {
        int n;
        cin>>n;
        VI a = VI(n,0);
        int sum = 0;
        for (int i = 0; i < n; i++) { cin>>a[i]; sum+=a[i]; }
        cout<<"Case #"<<t+1<<": ";
       for (int i = 0; i <n;i++) { 
        double low = 0;
        double up = 1;
        while (abs(up-low)>1e-9) {
            double cand = (low+up)/2;
            double r1 = a[i] + cand*sum;
            double prop = 0;
            for (int j = 0; j < n; j++) if (i!=j) {
                double points = r1 - a[j];
                if (points<0) points = 0;
                prop +=points;
            } 
            prop /=sum;
            if (prop+cand>1) up = cand;
            else low = cand;
        }
        if (i!=0) cout<<" ";
        cout<<(low+up)*50;
       }
        cout<<endl;
    }
}
