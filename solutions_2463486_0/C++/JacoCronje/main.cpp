#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <string>
#include <string.h>
#include <math.h>

using namespace std;

static const long long lst[] = {
1,
4,
9,
121,
484,
10201,
12321,
14641,
40804,
44944,
1002001,
1234321,
4008004,
100020001,
102030201,
104060401,
121242121,
123454321,
125686521,
400080004,
404090404,
10000200001,
10221412201,
12102420121,
12345654321,
40000800004,
1000002000001,
1002003002001,
1004006004001,
1020304030201,
1022325232201,
1024348434201,
1210024200121,
1212225222121,
1214428244121,
1232346432321,
1234567654321,
4000008000004,
4004009004004,
100000020000001,
100220141022001,
102012040210201,
102234363432201,
121000242000121,
121242363242121,
123212464212321,
123456787654321,
400000080000004,
-1};

bool palin(long long i)
{
    stringstream ss;
    ss << i;
    string s = ss.str();
    int n = s.length();
    for (int j=0;j<n;j++)
        if (s[j]!=s[n-1-j]) return false;
    return true;
}

void solve()
{
    int T;
    cin >> T;
    ofstream fo("dt.txt");
    fo << "static const long long lst[] = {" << endl;
    for (int t=0;t<T;t++)
    {
        long long A, B;
        cin >> A >> B;
        long long ans = 0;
        long long a = sqrt(A);
        long long b = sqrt(B);
        for (long long i=a;i<=b;i++)
        {
            long long ii = i*i;
            if (ii>B) break;
            if (ii<A) continue;
            if (palin(i) && palin(ii))
            {
                ans++;
                cout << ii << endl;
                fo << ii << "," << endl;
            }
        }
        cout << "Case #" << (t+1) << ": " << ans << endl;
    }
    fo << endl;
}

void solvelst()
{
    int T;
    cin >> T;
    for (int t=0;t<T;t++)
    {
        long long A, B;
        cin >> A >> B;
        long long ans = 0;
        for (int i=0;i<100;i++)
        {
            if (lst[i]==-1) break;
            if (lst[i]>=A && lst[i]<=B) ans++;
        }
        cout << "Case #" << (t+1) << ": " << ans << endl;
    }
}

int main(int argc,char *argv[])
{
  solvelst();

  return 0;
}
