#include <set>
#include <iostream>

using namespace std;

int main()
{
    int T;
    cin >> T;
    for(int no=1; no<=T; ++no) {
        long long int ans = 0;
        int A, B;
        cin >> A >> B;
        for(int n=A; n<=B; ++n) {
            set<int> s;
            int a = 1;
            while(a<n) a*=10;
            for(int i=10;i<n;i*=10) {
                int front = n / i;
                int back = n % i;
                if(back<i/10) continue;
                if(front<a/i/10) continue;
                int m = back * (a/i) + front;
                if(A<=m && m<=B && n<m && s.find(m)==s.end()) {
                    s.insert(m);
                    ++ans;
                    //cout << "(" << n << ", " << m << ")" << endl;
                }
            }
        }
        cout << "Case #" << no << ": " << ans << endl;
    }
    return 0;
}
