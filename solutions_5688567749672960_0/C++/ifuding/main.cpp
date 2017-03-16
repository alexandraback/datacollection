#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<vector>
#include<queue>
#include<map>
#include<algorithm>
using namespace std;
#define maxN 1337735
#define INF 0X7F7F7F7F

int N;

class node {
public:
  long long val;
  int minStep;
  node* next;
  node():next(NULL) {}
  node(long long v, int s): val(s),minStep(s),next(NULL) {}
};

class HashList {
public:
  node** _list;
  HashList() {
    _list = new node*[maxN];
  }
  ~HashList() {
    delete[] _list;
  }
  int insertHash(long long val, int step) {
    int slot = val%maxN;
    node* tmpNode;
    for(tmpNode = _list[slot];tmpNode != NULL;tmpNode = tmpNode->next) {
        if(tmpNode->val == val) {
            return -1;
        }
    }
    node* newNode = new node(val, step);
    newNode->next = _list[slot];
    _list[slot] = newNode;
    return 1;
  }
};

struct qNode {
  long long val;
  int step;
  qNode(){}
  qNode(long long v, int s): val(v),step(s){}
  friend bool operator< (qNode a, qNode b) {
    return abs(a.val-N) > abs(b.val-N);
  }
};

long long inverse(long long x) {
  long long ans = 0;
  while(x) {
    ans *= 10;
    ans += x%10;
    x /= 10;
  }
  return ans;
}

int BFS() {
    priority_queue<qNode> q;
    qNode now,next;
    now= qNode(1, 1);
    HashList hashList;
    int tmp[2];
    q.push(now);
    hashList.insertHash(1, 1);
    int minCost = N;
    while(!q.empty()) {
        now = q.top();
        q.pop();
//        if(now.val <= N) {
//            minCost = min(minCost, N-now.val+now.step);
//        }
        if(now.val == N) {
            return now.step;
        }
        tmp[0] = now.val+1;
        tmp[1] = inverse(now.val);
        //int j = 2;
        int j = tmp[1] <= N ? 2 : 1;
        for(int i = 0;i < j;i++) {
          if(hashList.insertHash(tmp[i], now.step+1)) {
            next = qNode(tmp[i], now.step+1);
            q.push(next);
          }
        }
    }
    return 1;
}

int solve() {
  return BFS();
}

int main() {
    freopen("A-small-attempt1.in","r",stdin);
    //freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int T;
    scanf("%d",&T);
    for(int t = 1;t <= T;t++) {
        cout<<"Case #"<<t<<": ";
        scanf("%lld",&N);;
        cout<<solve()<<endl;
    }
    return 0;
}


