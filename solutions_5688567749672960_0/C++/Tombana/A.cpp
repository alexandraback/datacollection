#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

const int MAXN = 1000000;

long long steps[MAXN+1];
long long parent[MAXN+1];

long long reverse(long long N)
{
    long long ans = 0;
    while (N)
    {
        ans *= 10;
        ans += N%10;
        N /= 10;
    }
    return ans;
}

struct derp
{
    long long steps;
    long long number;
    long long parent;

    derp(int s, int n, int p) : steps(s), number(n), parent(p) {};

    const bool operator<(const derp& rhs) const
    {
        return steps > rhs.steps;
    }
};

void dijkstra()
{
    memset(steps, 0, sizeof(steps));
    memset(parent, 0, sizeof(parent));
    priority_queue<derp> q;
    q.push(derp(1, 1, 0));

    while (!q.empty())
    {
        derp d = q.top(); q.pop();

        if (d.number > MAXN) continue;

        if (steps[d.number]) continue;
        steps[d.number] = d.steps;
        parent[d.number] = d.parent;

        long long next1 = reverse(d.number);
        long long next2 = d.number+1;
        q.push(derp(d.steps+1, next1, d.number));
        q.push(derp(d.steps+1, next2, d.number));
    }
    return;
}

int main()
{
    dijkstra();

    //for (int i = MAXN-50; i <= MAXN; i++)
    //{
    //    cout << i << " <-- ";
    //    for (int j = i; j >= 1; j = parent[j])
    //    {
    //        if (parent[j] == j-1) continue;
    //        cout << j << " <-x- " << parent[j] << " <-- ";
    //    }
    //    //cout << parent[i] << " --> " << i << " : " << steps[i] << endl;
    //    cout << endl;
    //}
    //return 0;

    int T;
    cin >> T;
    for (int run = 1; run <= T; ++run)
    {
        long long N;
        cin >> N;
        cout << "Case #" << run << ": " << steps[N] << endl;
    }
}
