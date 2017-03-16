
#define OSW2
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <utility>
using namespace std;



int main() {
    #ifdef OSW
    freopen("C:\\Users\\Oswww\\Desktop\\in.txt", "r", stdin);
    #endif // OSW
    #ifdef OSW2
    freopen("E:\\ACM\\Google Code Jam 2014\\dd.in", "r", stdin);
    freopen("E:\\ACM\\Google Code Jam 2014\\outD.txt", "w", stdout);
    #endif // OSW
    ios::sync_with_stdio(false);

    int T;
    cin >> T;
    int t=0;
    while (T-(t++)) {
        cout << "Case #" << t << ":";
        int n;
        cin >> n;
        pair<double, int> arr[2222];

        for (int k=0; k!=2; ++k)
        for (int i=0; i!=n; ++i) {
            auto& pp = arr[k*n+i];
            cin >> pp.first;
            pp.second = k+1;
        }

        sort(arr, arr+2*n);

        int x1=1, x2=2;


        for (int k=0; k!=2; ++k) {
            int cnt=0, sum = 0;
            for (int i=2*n-1; i>=0; --i) {
                //cout << '<' << arr[i].first << ',' << arr[i].second << "> ";
                if (arr[i].second==x1) ++cnt;
                else if (arr[i].second==x2 && cnt>0) --cnt, ++sum;
            }
            if (k==0) cout << " " << sum;
            else  cout << " " << n-sum;
            swap(x1,x2);
        }
        cout << endl;



    }
}


