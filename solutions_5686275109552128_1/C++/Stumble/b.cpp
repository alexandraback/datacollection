
#include <iostream>
#include <cstdio>
#include <queue>
#include <cstdlib>

using namespace std;

#define prq priority_queue

const int MAXN = 1111;
int diner;
int data[MAXN];
int smax;

// struct node {
//     int * val;
//     bool operator <(const node &c) const{
//         return (*val) < (*c.val);
//     }
//     node(int * val):val(val){};
// };

void init()
{
    smax = 0;
    cin >> diner;
    for (int i = 1; i <= diner; i++) {
        cin >> data[i];
        smax = max(smax,data[i]);
    }
}



// bool check(int bound)
// {
//     // int tdata[MAXN];
//     // for (int i = 1; i <= diner; i++) {
//     //     tdata[i] = data[i];
//     // }
//     prq<int> heap;
//     for (int i = 1; i <= diner; i++) {
//         heap.push(data[i]);
//     }

//     while(!heap.empty()) {
//         // int tops = heap.top());
//         // if (tops & 1) {
//         //     for (int i = 1; i <= diner; i++) {
//         //         tdata[i]--;
//         //     }

//         // }
//         if (heap.top() <= bound) {
//             return true;
//         }
//         bound --;
//         if(bound == 0) break;
//         int now = heap.top();
//         heap.push(bound);
//         heap.push(now - bound);
//         // if (now %2 == 0) {
//         //     heap.pop();
//         //     heap.push(now/2);
//         //     heap.push(now/2);
//         // } else {
//         // }
//     }
//     return false;
// }

int check(int bound)
{
    int ans = 0;
    for (int i = 1; i <= diner; i++) {
        if (data[i] > bound) {
            ans += ((data[i] - 1) / bound);
            // if (data[i] % bound) ans++;
        }
    }
    return ans;
}


int solve()
{
    int ans = 9999999;
    int wait_time = 1;
    while (wait_time <= smax) {
        ans = min(ans, wait_time + check(wait_time));
        wait_time ++;
    }
    return ans;
}


int main(int argc, char *argv[])
{
    int T;
    cin >> T;

    for (int tt = 1; tt <= T; tt++) {
        init();
        printf("Case #%d: %d\n",tt,solve());
    }

    return 0;
}



