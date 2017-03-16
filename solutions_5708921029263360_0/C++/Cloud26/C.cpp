#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <vector>
#include <queue>
#include <map>
#include <set>
using namespace std;

#define eps 1e-9
#define PB push_back
#define LL long long
#define INF 0x3f3f3f3f

template<class T> void checkMax(T &a, T b)
{
    a = max(a, b);
}
template<class T> void checkMin(T &a, T b)
{
    a = min(a, b);
}
const int N = 15;
int A[N][N], B[N][N], C[N][N];
int get_count(int x, int y, int z)
{
    return A[x][y] + B[y][z] + C[z][x];
}
struct Node
{
    int x, y, z;
    Node(){}
    Node(int _x, int _y, int _z): x(_x), y(_y), z(_z) {}
    bool operator < (const Node &p) const
    {
        return get_count(x, y, z) < get_count(p.x, p.y, p.z);
    }
};
int main()
{
    int t, cas = 1;
    cin >> t;
    while(t--)
    {
        int J, P, S, K;
        cin >> J >> P >> S >> K;
        memset(A, 0, sizeof(A));
        memset(B, 0, sizeof(B));
        memset(C, 0, sizeof(C));
        vector<Node> all;
        for(int i = 1; i <= J; i++)
            for(int j = 1; j <= P; j++)
                for(int k = 1; k <= S; k++)
                    all.push_back(Node(i, j, k));
        vector< Node > ans;
        while(all.size() > 0)
        {
            int next = -1;
            for(int i = 0; i < all.size(); i++)
            {
                if(A[all[i].x][all[i].y] < K && B[all[i].y][all[i].z] < K && C[all[i].z][all[i].x] < K)
                {
                    A[all[i].x][all[i].y]++;
                    B[all[i].y][all[i].z]++;
                    C[all[i].z][all[i].x]++;
                    ans.push_back(all[i]);
                    next = i;
                    break;
                }
            }
            if(next == -1)  break;
            all.erase(all.begin(), all.begin() + next + 1);
            sort(all.begin(), all.end());
        }
        cout << "Case #" << cas++ << ": " << ans.size() << endl;
        for(int i = 0; i < ans.size(); i++)
            cout << ans[i].x << " " << ans[i].y << " " << ans[i].z << endl;
    }
    return 0;
}
