#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>

#define inf 0x3f3f3f3f
#define Inf 0x3FFFFFFFFFFFFFFFLL
#define maxn 1010
using namespace std;
struct node1{
    int a, id;
    node1(int _a, int _id){ a = _a, id = _id;}
    node1(){}
    friend bool operator<(node1 x, node1 y){
        return x.a > y.a;
    }
}t1;
struct node2{
    int b, id;
    node2(int _b, int _id){ b = _b, id = _id;}
    node2(){}
    friend bool operator<(node2 x, node2 y){
        return x.b > y.b;
    }
}t2;
priority_queue<node1> q1;
priority_queue<node2> q2;
int used[maxn];

int main(){
    //freopen("B-small-attempt1.in", "r", stdin);
    //freopen("B-large.in", "r", stdin);
    //freopen("B-ans.txt", "w", stdout);
    int t, n;
    int a, b;
    scanf("%d", &t);
    for(int _ca=1;_ca<=t;_ca++){
        scanf("%d", &n);
        while(!q1.empty())q1.pop();
        while(!q2.empty())q2.pop();
        for(int i=1;i<=n;i++){
            scanf("%d%d", &a, &b);
            q1.push(node1(a, i));
            q2.push(node2(b, i));
        }
        memset(used, 0, sizeof(used));
        int s = 0, res = 0;
        bool flag = true;
        while(!q1.empty() || !q2.empty()){
            bool f1 = false, f2 = false;
            while(!q1.empty() && used[q1.top().id] >= 2) q1.pop();
            if(!q1.empty()){
                f1 = true;
                 t1 = q1.top(); q1.pop();
            }
            while(!q2.empty() && used[q2.top().id] >= 2) q2.pop();
            if(!q2.empty()){
                f2 = true;
                t2 = q2.top(); q2.pop();
            }
           //if(q1.empty() && q2.empty()) break;
           // cout << f1 << "," << f2 << endl;
        //    cout << t1.a << "," << t2.b << "->" << res << ":  " << s << endl;
            if(f2 && s >= t2.b){
                res++;
                s += 2 - used[t2.id];
                used[t2.id] += 2;
                q1.push(t1);
            }
            else if(f1 && s >= t1.a){
                res++;
                s ++;
                used[t1.id] ++;
                q2.push(t2);
                q1.push(t1);
            }
            else if(f1 || f2){
                flag = false;
                break;
            }
          //  for(int i=1;i<=n;i++) cout << used[i] << " "; cout << endl;
        }
        if(!flag) printf("Case #%d: Too Bad\n", _ca);
        else printf("Case #%d: %d\n", _ca, res);
    }
    return 0;
}
