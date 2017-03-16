#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <string>
#include <cstring>
#include <cmath>
#include <cstdio>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef long long ll;
#define pb push_back
#define sz(a) int((a).size())
#define all(c) (c).begin(), (c).end()
#define tr(c, i) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define present(c,x) ((c).find(x) != (c).end())
#define cpresent(c,x) (find(all(c),x) != (c).end())

double td[2000];
double dd[2000];

double calc(double dis, int n, double a)
{
    double rest = 0;
    double lastdis = 0;
    double lastsp = 0;
    if(n == 1) return sqrt(dis * 2 / a);
    if(dd[n - 1] > dis + 0.000001)
    {
        td[n - 1] = td[n - 2] + (dis - dd[n - 2]) / (dd[n - 1] - dd[n - 2]) * (td[n - 1] - td[n - 2]);
        dd[n - 1] = dis;
    }
    for(int i = 1; i < n; i++)
    {
        double th = td[i] - td[i - 1];
        double mydis = lastsp * th + 0.5 * a * th * th + lastdis;
        if(mydis > dd[i] + 0.000001)
        {
//            cout << "i " << i << " mydis " << mydis << " dd[i] " << dd[i] << endl;
            rest = td[i];
            lastdis = dd[i];
            lastsp = sqrt(2 * dd[i] / a) * a;
        }
        else
        {
 //           cout << "i " << i << " mydis " << mydis << " dis " << dis << endl;
            if(mydis > dis - 0.000001)
            {
                return sqrt(dis * 2 / a);
            }
            rest += th;
            lastdis = mydis;
            lastsp = lastsp + a * (td[i] - td[i - 1]);
        }
    }
    if(lastdis < dis)
    {
        rest += (-lastsp + sqrt(lastsp * lastsp + 2 * a * (dis - lastdis))) / a;
    }
    return rest;
}

void func()
{
    int N, A;
    double dis;
    cin >> dis;
    cin >> N;
    cin >> A;
    for(int i = 0; i < N; i++)
    {
        cin >> td[i] >> dd[i];
    }
    cout << endl;
    for(int i = 0; i < N; i++)
    {
        if(dd[i] > dis) 
        {
            N = i + 1;
            break;
        }
    }
    for(int i = 0; i < A; i++)
    {
        double a;
        cin >> a;
        printf("%.8lf\n",  calc(dis, N, a));
    }
}

int main()
{
    int t;
    cin >> t;
    for(int ti = 1; ti <= t; ti++)
    {
        cout << "Case #" << ti << ":";
        func();
    }
}
