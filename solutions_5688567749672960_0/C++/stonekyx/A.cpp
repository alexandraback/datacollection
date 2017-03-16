#include <iostream>
#include <set>
#include <cstring>
#include <queue>

using namespace std;

struct Node {
    int id, dist;
    Node(int id, int dist) : id(id), dist(dist) {}
    bool operator<(const Node &o) const {
        return dist < o.dist;
    }
};

int reverse(int x)
{
    int ans = 0;
    while(x) {
        ans = ans * 10 + x%10;
        x/=10;
    }
    return ans;
}

int bfs(int src, int dst)
{
    queue<Node> qu;
    qu.push(Node(src, 1));
    set<int> visit;
    while(!qu.empty()) {
        Node top = qu.front();
        qu.pop();
        if(top.id == dst) {
            return top.dist;
        }
        if(visit.find(top.id+1) == visit.end()) {
            visit.insert(top.id+1);
            qu.push(Node(top.id+1, top.dist+1));
        }
        int rev = reverse(top.id);
        if(visit.find(rev) == visit.end()) {
            visit.insert(rev);
            qu.push(Node(rev, top.dist+1));
        }
    }
    return -1;
}

int main()
{
    int T, Tcnt=1;
    cin>>T;
    for(; T; T--,Tcnt++) {
        int N;
        cin>>N;
        cout<<"Case #"<<Tcnt<<": "<<bfs(1, N)<<endl;
    }
    return 0;
}

