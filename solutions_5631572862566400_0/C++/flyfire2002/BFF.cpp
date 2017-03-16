#include <iostream>
#include <string>
#include <vector>
#include <cstring>
using namespace std;

struct linkTail {
    int a;
    int b;
    int len;
};

int main () {
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        int BFF[1001] = {0};
        bool visited[1001];
        int order[1001] = {0};
        int maxLen = 1;
        int N;
        cin >> N;

        for (int i = 1; i <= N; i++) {
            cin >> BFF[i];
        }
        vector<linkTail> link;
        for (int i = 1; i <= N; i++) {
            memset(visited, 0, 1001 * sizeof(bool));
            int newOrder = 0;
            int curr = i;
            while (!visited[curr]) {
                visited[curr] = true;
                order[curr] = newOrder++;
                curr = BFF[curr];
            }
            if (newOrder - order[curr] == 2) {
                struct linkTail lkt;
                lkt.a = curr;
                lkt.b = BFF[curr];
                lkt.len = newOrder;
                link.push_back(lkt);
                maxLen = (maxLen < newOrder) ? newOrder : maxLen;
            } else {
                maxLen = (maxLen < (newOrder - order[curr])) ? (newOrder - order[curr]) : maxLen;
            }
        }

        if(link.size() >= 2) {
            for (int i = 0; i < link.size() - 1; i++) {
                for (int j = i + 1; j < link.size(); j++) {
                    if (link[i].a == link[j].b
                        && link[i].b == link[j].a) {
                        maxLen = (maxLen < (link[i].len + link[j].len - 2)) ? (link[i].len + link[j].len - 2) : maxLen;
                    }
                }
            }
        }

        cout << "Case #" << t << ": " << maxLen << endl;
    }
    return 0;
}
