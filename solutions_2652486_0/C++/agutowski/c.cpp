#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;
int T, N, M, K, R, t[10], c[10], m[10];
long long p;
vector<int> res;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    cout << "Case #1:\n";
    cin >> R >> N >> M >> K;
    while (R--) {
        for (int i=2; i<=8; i++) t[i]=false, m[i]=0;
        for (int i=0; i<K; i++) {
            cin >> p;
            c[2] = c[3] = c[5] = c[7] = 0;
            while (p%2 == 0) { c[2]++; p/=2; }
            while (p%3 == 0) { c[3]++; p/=3; }
            while (p%5 == 0) { c[5]++; p/=5; }
            while (p%7 == 0) { c[7]++; p/=7; }
            int sum=0;
            for (int j=2; j<=7; j++) {
                m[j]=max(m[j],c[j]);
                sum += m[j];
            }
            if (m[2] > 2*(N-sum+m[2]))
                t[8]=true;
            else if (m[2] > (N-sum+m[2]))
                t[4]=true;
            else if (m[2] != 0)
                t[2]=true;
        }
        res.clear();
        if (t[8]) res.push_back(8);
        if (m[3]) res.push_back(3);
        if (m[5]) res.push_back(5);
        if (m[7]) res.push_back(7);
        if (t[4]) res.push_back(4);
        if (t[2]) res.push_back(2);
        if (res.empty()) res.push_back(2);
        while (res.size() < N) res.push_back(res[rand()%res.size()]);
        while (res.size() > N) res.pop_back();
        for (int i=0; i<res.size(); i++) cout<<res[i];
        cout << "\n";
    }
    return 0;
}
