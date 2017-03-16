#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <string.h>
#include <map>
#include <deque>
#include <queue>
#include <stack>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <vector>
#include <set>
#include <complex>
#include <list>
#include <bitset>

using namespace std;

#define pb push_back
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define sz size()
#define rep(i,m) for(int i=0;i<(int)(m);i++)
#define rep2(i,n,m) for(int i=n;i<(int)(m);i++)
#define For(it,c) for(__typeof(c.begin()) it=c.begin();it!=c.end();++it)
#define mem(a,b) memset(a,b,sizeof(a))
#define mp make_pair
#define dot(a,b) ((conj(a)*(b)).X)
#define X real()
#define Y imag()
#define vect(a,b) ((b)-(a))
#define cross(a,b) ((conj(a)*(b)).imag())
#define normalize(v) ((v)/length(v))
#define rotate(p,about,theta) ((p-about)*exp(point(0,theta))+about)
#define pointEqu(a,b) (comp(a.X,b.X)==0 && comp(a.Y,b.Y)==0)

typedef stringstream ss;
typedef pair<int, int> pii;
typedef vector<pii> vpii;
typedef vector<string> vs;
typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<vector<int> > vii;
typedef long long ll;
typedef long double ld;
typedef complex<double> point;
typedef pair<point, point> segment;
typedef pair<double, point> circle;
typedef vector<point> polygon;

const int oo = (int) 1e9;
const double PI = 2 * acos(0);
const double eps = 1e-9;

inline int comp(const double &a, const double &b) {
    if (fabs(a - b) < eps)
        return 0;
    return a > b ? 1 : -1;
}

int di[] = { 1, -1, 0, 0, 1, -1, 1, -1 };
int dj[] = { 0, 0, 1, -1, 1, -1, -1, 1 };
int diK[] = { -2, -2, -1, 1, 2, 2, 1, -1 };
int djK[] = { -1, 1, 2, 2, 1, -1, -2, -2 };

int I, J;

inline bool val(const int &i, const int &j) {
    if (i < 0 || j < 0 || i >= I || j >= J)
        return false;
    return true;
}

inline long long isprime(long long val)
{
    if (val % 2 == 0)
        return 2;
    for (int i = 3; i < sqrt(val) + 1; i+=2){
        if (val % i == 0)
            return i;
    }
    return -1;
}

inline vector<long long> jam(string& str)
{
    vector<long long> divs;
    
    if (str[0] != '1' || str[str.length() - 1] != '1')
        return vector<long long>();

    for (int i = 2; i <= 10; i++)
    {
        long long val = 0;
        for (int j = str.length() - 1; j >= 0; j--)
        {
            if (str[j] == '1')
            {
                val += powl(i, str.length() - j - 1);
            }
        }

        long long ret = isprime(val);
        if (ret == -1)
        {
            return vector<long long>();
        }
        divs.push_back(ret);
    }
    return divs;
}

int N;
int main(int argc, char *args[]) {
    if (argc == 2 && strcmp(args[1], "small") == 0) {
        freopen("small.in", "rt", stdin);
        freopen("small.out", "wt", stdout);
    }
    else if (argc == 2 && strcmp(args[1], "large") == 0) {
        freopen("large.in", "rt", stdin);
        freopen("large.out", "wt", stdout);
    }
    else {
        freopen("a.txt", "rt", stdin);
    }

    cin >> N;
    rep2(nn, 1, N + 1) {
        printf("Case #%d: ", nn);

        ///////////////////////////////////////////////////////////////
        int N, J;
        cin >> N >> J;
        cout << endl;

        unsigned short num = (1 << (N - 1)) + 1;

        int counter = 0;
        while (counter < J)
        {
            std::string s = std::bitset< 16 >(num).to_string();

            vector<long long> jamres = jam(s);
            if (jamres.size() > 0)
            {
                cout << s << " ";
                for (int i = 0; i < jamres.size(); i++)
                {
                    cout << jamres[i];
                    if (i != jamres.size() - 1)
                        cout << " ";
                }
                cout << endl;
                counter++;
            }
            num++;
            if (s.find_first_of('0') == string::npos)
                break;
        }
        ///////////////////////////////////////////////////////////////
        cout << endl;
        cin.get();
        cin.get();
    }

    return 0;
}