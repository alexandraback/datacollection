#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;

int t,n;
int a[1001],b[1001];
int dp[2002];
int seen[1001];

struct level {
    int one,two,num;
};

struct Comp1 {
    bool operator()(const level &l,const level &r) {
        return l.one != r.one ? l.one < r.one : l.two > r.two;
    }
};

struct Comp2 {
    bool operator()(const level &l,const level &r) {
        return l.two != r.two ? l.two < r.two : l.one < r.one;
    }
};

int main() {
    cin>>t;
    for(int tc=1; tc<=t; ++tc) {
        cin>>n;

        vector<level> l1,l2;
        for(int i=0; i<n; ++i) {
            cin>>a[i]>>b[i];
            l1.push_back((level){a[i],b[i],i});
            l2.push_back((level){a[i],b[i],i});
        }

        memset(seen, 0, sizeof(seen));
        sort(l1.begin(), l1.end(), Comp1());
        sort(l2.begin(), l2.end(), Comp2());

        bool ok = true;
        int p = 0, ans = 0;
        int ptr1 = 0,ptr2 = 0;
        priority_queue<int, vector<int>, greater<int> > one;
        while(true) {
            if(p == n*2) break;
            bool upd = false;

                while(!one.empty()) {
                    if(p >= one.top()) {
                        //cout<<"poped"<<endl;
                        p++; ans++;
                        one.pop();
                        upd = true;
                    }else break;
                }

            for(int i=0; i<n; ++i) {
                if(seen[i] == 0 && p >= b[i]) {
                    p += 2;
                    ans++;
                    upd = true;
                    seen[i] = 2;

                    //cout<<"double "<<i<<endl;
                }
            }

                while(!one.empty()) {
                    if(p >= one.top()) {
                        //cout<<"poped"<<endl;
                        p++; ans++;
                        one.pop();
                        upd = true;
                    }else break;
                }

            if(upd) continue;

            int idx = -1,m = -1;
            for(int i=0; i<n; ++i) {
                if(seen[i] == 0 && a[i] <= p) {
                    if(b[i] > m) {
                        m = b[i];
                        idx = i;
                    }
                }
            }

            if(idx == -1) {
                while(!one.empty()) {
                    if(p >= one.top()) {
                        //cout<<"poped"<<endl;
                        p++; ans++;
                        one.pop();
                        upd = true;
                    }else break;
                }
                if(!upd) {
                    ok = false;
                    break;
                }
                continue;
            }

            //cout<<"one "<<idx<<endl;
            p++; ans++; upd = true;
            seen[idx] = 2;
            one.push(b[idx]);

                while(!one.empty()) {
                    if(p >= one.top()) {
                        //cout<<"poped"<<endl;
                        p++; ans++;
                        one.pop();
                        upd = true;
                    }else break;
                }

        }

        if(ok) cout<<"Case #"<<tc<<": "<<ans<<endl;
        else cout<<"Case #"<<tc<<": Too Bad"<<endl;
    }
}
