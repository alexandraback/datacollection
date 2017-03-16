#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cctype>
#include <climits>
#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <sstream>
#include <initializer_list>

using namespace std;

class node {
public:
    long long step;
    long long num;

    node(int s, int n) {
        step = s;
        num = n;
    }
};

long long revnum(long long num) {
    long long res = 0;
    while (num) {
        res = res * 10 + num % 10;
        num /= 10;
    }

    return res;
}

int main(int argc, char *argv[])
{
    int T = 0;

    freopen("A-small.in", "r", stdin);
    
    cin >> T;

    for (int cas = 1; cas <= T; cas++) {
        long long N = 0;
        long long res = 1;
        cin >> N;

        unordered_set <long long> s;
        s.insert(1);
        
        queue <node> Q;
        Q.push(node(1, 1));

        node n = Q.front();
        Q.pop();
        while (n.num != N) {
            long long rev = revnum(n.num);

            if (s.find(rev) == s.end()) {
                s.insert(rev);
                Q.push(node(n.step + 1, rev));
            }
            
            long long next = n.num + 1;
            
            if (s.find(next) == s.end()) {
                s.insert(next);
                Q.push(node(n.step + 1, next));
            }
            if (rev == N || next == N) {
                res = n.step + 1;
                break;
            }

            n = Q.front();
            Q.pop();
        }

        cout << "Case #" << cas << ": " << res << endl;
        
    }

    return 0;
}
