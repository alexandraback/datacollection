#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

struct activity {
    int time;
    long long value;
};

bool operator<(activity a, activity b) {
    return a.value > b.value;
}

activity activities[10000];

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        long long E, R, N;
        cin >> E >> R >> N;
        for (int i = 0; i < N; i++) {
            cin >> activities[i].value;
            activities[i].time = i;
        }
        sort(activities, activities+N);
        set<int> alreadyUsed;
        long long answer = 0;
        for (int i = 0; i < N; i++) {
            set<int>::iterator after = alreadyUsed.upper_bound(activities[i].time);
            long long availBefore = E, neededAfter = 0;
            if (after != alreadyUsed.begin()) {
                set<int>::iterator before = after;
                before--;
                availBefore = min(availBefore, (activities[i].time - *before) * R);
            }
            if (after != alreadyUsed.end()) {
                neededAfter = max(neededAfter, E - (*after - activities[i].time) * R);
            }
            answer += max(availBefore-neededAfter, 0LL) * activities[i].value;
            alreadyUsed.insert(activities[i].time);
        }
        cout << "Case #" << t << ": " << answer << endl;
    }
    return 0;
}
