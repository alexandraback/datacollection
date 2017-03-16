#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <string>
#include <string.h>
#include <math.h>

using namespace std;

vector<int> dt;
int N;

int go(int A, int from)
{
    int ans = 0;
    for (int i=from;i<N;i++)
    {
        if (dt[i]<A)
        {
            A += dt[i];
        } else
        {
            int add = N-i;
            int c;
            if (A+A-1!=A)
            {
                c = 1 + go(A+A-1, i);
                add = min(add, c);
            }
            c = 1 + go(A, i+1);
            add = min(add, c);
            return ans+add;
        }
    }
    return ans;
}

void solve()
{
    int T;
    cin >> T;
    for (int t=0;t<T;t++)
    {
        int A;
        cin >> A >> N;
        dt.clear();
        dt.resize(N);
        for (int i=0;i<N;i++)
            cin >> dt[i];
        sort(dt.begin(),dt.end());
        int ans = go(A, 0);
        cout << "Case #" << t+1 << ": " << ans << endl;
    }

}

int main(int argc,char *argv[])
{
  solve();

  return 0;
}
