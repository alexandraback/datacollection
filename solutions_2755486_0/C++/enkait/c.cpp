#include <cstdio>
#include <iostream>
#include <cassert>
#include <queue>
#include <string>

using namespace std;

const int INF = 1000000000;

class Node {
    public:
    int b, e;
    Node *left, *right;
    int val, M;
    Node(int _b = -INF, int _e = INF) {
        b = _b; e = _e; 
        left = right = NULL;
        val = 0;
        M = 0;
    }
    void createchildren() {
        if (b == e) return;
        if (e - b == 1) {
            left = new Node(b, b);
            right = new Node(e, e);
        } else {
            left = new Node(b, (b+e)/2);
            right = new Node((b+e)/2 + 1, e);
        }
    }
    void calcmin() {
        if (left == NULL) {
            M = val;
            return;
        }
        M = max(val, min(left->M, right->M));
    }
    void insert(int low, int high, int value) {
        assert(low >= -INF and high <= INF);
        if (left == NULL) createchildren();
        if (low <= b and high >= e) {
            val = max(value, val);
            calcmin();
            return;
        }
        if (low <= left->e) {
            left->insert(low, high, value);
        }
        if (high >= right->b) {
            right->insert(low, high, value);
        }
        calcmin();
    }
    int getmin(int low, int high) {
        assert(low >= -INF and high <= INF);
        if (left == NULL) createchildren();
        if (low <= b and high >= e) {
            return M;
        }
        int res = INF;
        if (low <= left->e) {
            res = min(left->getmin(low, high), res);
        }
        if (high >= right->b) {
            res = min(right->getmin(low, high), res);
        }
        res = max(res, val);
        return res;
    }
    ~Node() {
        if (left != NULL) delete left;
        if (right != NULL) delete right;
    }
};

class Attack {
    public:
        int day, left, right, str;
        Attack(int _day, int _left, int _right, int _str) {
            day = _day;
            left = _left;
            right = _right;
            str = _str;
        }
        bool operator<(const Attack & alt) const {
            return day > alt.day;
        }
};

ostream & operator<<(ostream & out, const Attack & att) {
    out << "Attack: " << att.day << " [" << att.left << "," << att.right << "]: " << att.str;
    return out;
}

void solve(int cas) {
    int tribes;
    cin >> tribes;
    priority_queue <Attack> Q;
    for(int tribe = 0;tribe < tribes;tribe++) {
        int firstday, numatt, left, right, str, deltaday, deltapos, deltastr;
        cin >> firstday >> numatt >> left >> right >> str >> deltaday >> deltapos >> deltastr;
        for(int att = 0;att < numatt;att++) {
            Q.push(Attack(firstday + att * deltaday, left + att * deltapos, right + att * deltapos - 1, str + att * deltastr));
        }
    }
    Node *tree = new Node();
    int curday = -1;
    int result = 0;
    while(!Q.empty()) {
        vector <Attack> attacks;
        while(!Q.empty()) {
            Attack att = Q.top();
            if (att.day == curday) {
                attacks.push_back(att);
                int wall = tree->getmin(att.left, att.right);
                if (wall < att.str) {
                    result++;
                }
                Q.pop();
            } else {
                curday = att.day;
                break;
            }
        }
        for(int i = 0;i<attacks.size();i++) {
            Attack &att = attacks[i];
            tree->insert(att.left, att.right, att.str);
        }
    }
    cout << "Case #" << cas << ": " << result << endl;
    delete tree;
}

int main() {
    int T;
    cin >> T;
    for(int i = 1;i<=T;i++) solve(i);
    return 0;
}

