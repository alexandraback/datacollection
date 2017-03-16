#include <iostream>
#include <queue>
#include <utility>
#include <algorithm>

using namespace std;

struct Node
{
    int day;
    int str;
    int w, e;

    Node(int d, int s, int we, int ea): day(d), str(s), w(we), e(ea) {}
    bool operator< (const Node& rhs) const
    {
        return day > rhs.day;
    }
};

int main()
{
    int T;
    cin >> T;
    for (int C = 1; C <= T; C++)
    {
        priority_queue<Node> pq;
        int N;
        cin >> N;
        for (int i = 0; i < N; i++)
        {
            int d, n, w, e, s, d_d, d_p, d_s;
            cin >> d >> n >> w >> e >> s >> d_d >> d_p >> d_s;
            for (int j = 0; j < n; j++)
            {
                pq.push(Node(d, s, w, e));
                d += d_d;
                w += d_p;
                e += d_p;
                s += d_s;
            }
        }
        int he[10000] = {0};
        int last = -1;
        int ans = 0;
        queue<pair<int, int> > toRaise;
        while (!pq.empty())
        {
            if (last != pq.top().day)
            {
                last = pq.top().day;
                while (!toRaise.empty())
                {
                    he[toRaise.front().first] = max(he[toRaise.front().first],
                            toRaise.front().second);
                    toRaise.pop();
                }
            }

            int str = pq.top().str;
            int w = pq.top().w;
            int e = pq.top().e;
            w += 5000;
            e += 5000;
            pq.pop();
            bool success = false;
            for (int i = w; i < e; i++)
            {
                if (he[i] < str)
                {
                    success = true;
                    toRaise.push(make_pair(i, str));
                }
            }
            if (success)
            {
                ans++;
            }
        }
        cout << "Case #" << C << ": " << ans << '\n';
    }
    return 0;
}

