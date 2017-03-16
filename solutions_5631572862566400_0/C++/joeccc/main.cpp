#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class UsedStates {
public:
    long states[32];

    UsedStates() {
        for (int i = 0; i < 32; i++) {
            states[i] = 0;
        }
    }

    UsedStates(UsedStates *from) {
        for (int i = 0; i < 32; i++) {
            states[i] = from->states[i];
        }
    }

    bool isUsed(int num) {
        int bucket = num / 32;
        int pos = num % 32;
        return (states[bucket] & (1 << pos)) != 0;
    }

    void setUsed(int num) {
        int bucket = num / 32;
        int pos = num % 32;
        states[bucket] = states[bucket] | (1 << pos);
    }

};

class Node {
public:
    Node(int pos) {
        curPos = pos;
        lastPos = 0;
        head = pos;
        len = 1;
        used = new UsedStates();
        used->setUsed(curPos);
        dir = 'f';
        path = to_string(curPos);
    }

    Node(Node *old, int newPos, char newDir) {
        curPos = newPos;
        lastPos = old->curPos;
        head = old->head;
        len = old->len + 1;
        used = new UsedStates(old->used);
        used->setUsed(curPos);
        dir = newDir;
        if (newDir == 'f') {
            path = old->path + "->" + to_string(curPos);
        } else if (curPos != lastPos) {
            path = old->path + "<-" + to_string(curPos);
        } else {
            path = old->path;
        }

    }

    string path;
    int curPos;
    int lastPos;
    int head;
    int len;
    char dir;
    UsedStates *used;
};

int main() {
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        int n;
        cin >> n;

        int relf[1001];
        vector<int> relb[1001];

        for (int j = 1; j <= n; j++) {
            int bff;
            cin >> bff;
            relf[j] = bff;
            relb[bff].push_back(j);
        }

        queue<Node *> q;
        for (int j = 1; j <= n; j++) {
            q.push(new Node(j));
        }

        int maxLen = 0;
        string path = "";
        Node *now;
        while (!q.empty()) {
            now = q.front();
            q.pop();
//            cout << now->curPos << " " << now->len << " " << now->path << endl;

            if (now->dir == 'f') {
                if (!now->used->isUsed(relf[now->curPos])) {
                    Node *newNode = new Node(now, relf[now->curPos], 'f');
                    q.push(newNode);
                } else if (now->used->isUsed(relf[now->curPos]) && relf[now->curPos] == now->lastPos) {
                    Node *newNode = new Node(now, now->curPos, 'b');
                    newNode->len--;
                    q.push(newNode);
                } else if (now->used->isUsed(relf[now->curPos]) && relf[now->curPos] == now->head) {
                    if (now->len > maxLen) {
                        maxLen = now->len;
                        path = now->path;
                    }
                }
            } else {
                for (int f : relb[now->curPos]) {
                    if (!now->used->isUsed(f)) {
                        Node *newNode = new Node(now, f, 'b');
                        q.push(newNode);
                    }
                }
                if (now->len > maxLen) {
                    maxLen = now->len;
                    path = now->path;
                }
            }

        }

        cout << "Case #" << i << ": " << maxLen << endl;

    }
    return 0;
}