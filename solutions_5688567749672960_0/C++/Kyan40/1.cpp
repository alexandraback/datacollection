#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("A-small-attempt0.in");
ofstream fout("output.txt");

int W(int x) {
    int ans = 0;
    while (x != 0) {
        ans ++;
        x /= 10;
    }
    return  ans;
}

long long mypow(int x){
    long long ans = 1;
    for (int i = 0; i < x; i++) {
        ans *= 10;
    }
    return ans;
}

bool isPow(long long x) {
    while (x > 9) {
        if (x % 10 != 0) return false;
        x /= 10;
    }
    if (x != 1) return false;
    return true;
}

long long go(long long s, long long e){
    int ws, we, ans = 0;
    ws = W(s); we = W(e);
    if (ws == we) {
        int tans = 0;
        ans += e % (mypow((we+1)/2)) - 1;
//        cout << "we " << we << endl;
        for (int i = we; i > (we+1)/ 2; -- i) {
            if (i != we) tans += (e/mypow(i-1)%10) * mypow(we-i);
            else tans += (e/mypow(i-1)%10) * mypow(we-i) -1;
//            cout << tans << endl;
        }
        ans += tans;
        if (tans != 0) ans ++;

    } else {
        ans = 2 + go(s, mypow(we-1)-1) + go(mypow(we-1)+1, e);
    }
//    cout << s << " " << e << " " << ans << endl;
    return ans;
}

int main(int argc, const char * argv[]) {
    long long n;
    int t;
    fin >> t;
    for (int ti = 1; ti <= t; ++ ti) {
        fin >> n;
        long long ans;
        if (n % 10 == 0) ans = go(1, n-1) + 2;
        else ans = go(1, n) + 1;
        fout << "Case #" << ti << ": " << ans << endl;
    }
}
