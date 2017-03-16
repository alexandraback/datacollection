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

int* mem[101];
char *used[101];
char ucnt;

int go(int A, int from)
{
    int AA = A;
    if (AA>1000000) AA=1000001;
    if (used[from][AA]==ucnt)
    {
        return mem[from][AA];
    }

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

            used[from][AA] = ucnt;
            mem[from][AA] = ans+add;
            return ans+add;
        }
    }
    used[from][AA] = ucnt;
    mem[from][AA] = ans;
    return ans;
}

void solve()
{
    for (int i=0;i<101;i++)
    {
        mem[i] = new int[1000010];
        used[i] = new char[1000010];
        memset(used[i], 0, 1000010);
    }
    ucnt = 1;
    int T;
    cin >> T;
    for (int t=0;t<T;t++)
    {
        ucnt++;
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
