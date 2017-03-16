#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

int qq[2000];

int main()
{
    freopen("B-small-attempt2.in", "r", stdin);
    freopen("out.txt", "w", stdout);
    int t;
    cin >> t;
    for (int ttt=1;ttt<=t;ttt++) {
        int d;
        cin >> d;
        int minn=2000;
        for (int i=1;i<=d;i++) {
            cin >> qq[i];
        }


        for (int i=1;i<=1000;i++) {
            priority_queue<int> q;
            for (int j=1;j<=d;j++) q.push(qq[j]);
            int time=0;
            while (q.top()>i) {
                if (q.top()<=2*i) {
                    int x=q.top();
                    q.pop();
                    int y=x/2;
                    q.push(y);
                    q.push(x-y);
                    time++;
                }
                else {
                    if (q.top()>2*i && q.top()<=3*i) {
                        int x=q.top();
                        q.pop();
                        int y=x/3;
                        q.push(y);
                        q.push(y);
                        q.push(x-2*y);
                        time+=2;
                    }
                    else if (q.top()>3*i) {
                        int x=q.top();
                        q.pop();
                        int y=x/2;
                        q.push(y);
                        q.push(x-y);
                        time++;
                    }
                }
                if (time>1200) break;
            }
            if (time<=1200) {
                minn=min(minn, time+q.top());
            }
        }


        cout << "Case #" << ttt<< ": " << minn<<endl;
    }
    return 0;
}
