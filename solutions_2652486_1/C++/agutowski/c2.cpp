#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;
int T, N, M, K, R, t[10], c[10], m[10], sum;
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
            for (int j=2; j<8; j++) {
                c[j]=0;
                while (p%j == 0) { c[j]++; p/=j; }
            }
            sum=0;
            for (int j=2; j<8; j++) {
                m[j]=max(m[j],c[j]);
                sum += m[j];
            }
        }
        if (N-sum+m[2] != 0) {
            m[8] = m[2] / (2*(N-sum+m[2]));
            m[4] = m[2] / (N-sum+m[2]);
        }
        if (m[2] && m[3]) m[6]=1;
        res.clear();
        for (int i=3; i<=8; i++)
            while (m[i]--) res.push_back(i);
        if (m[2] != 0) res.push_back(2);
        if (res.empty()) res.push_back(2);
        for (int i=2; i<=8; i++) c[i]=0;
        for (int i=0; i<res.size(); i++) c[res[i]]++;
        while (res.size() < N) {
            int min=2;
            for (int i=3; i<=8; i++) if (c[i]<c[min]) min=i;
            res.push_back(min);
            c[min]++;
        }
        while (res.size() > N) res.pop_back();
        for (int i=0; i<res.size(); i++) cout<<res[i];
        cout << "\n";
    }
    return 0;
}
