#include<fstream>
#include <iomanip>
using namespace std;
ifstream cin("A-large.in");
ofstream cout("A-large.out");

const int maxn = 200;
int T,n,m;
int a[maxn];
int ans;

void doit()
{
    double t,now;
    int ans1 = ans;
    now = double(ans*2)/n;
    int m = n;
    for (int i = 0; i < n; i++)
        if (a[i] >= now) {
            m--;
            ans1 -= a[i];
        }
    now = double(ans+ans1)/m;
    for (int i = 0; i < n; i++){
        t = 100*(now-a[i])/ans;
        if (t <0) t = 0;
        cout << fixed << setprecision(6) << t <<' ';
    }

}

int main() {
    cin >> T;
    for (int test = 1; test <= T; test++) {
        cout << "Case #" << test << ": ";
        cin >> n;
        ans = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            ans += a[i];
        }
        doit();
        cout << endl;
    }
    return 0;
}
