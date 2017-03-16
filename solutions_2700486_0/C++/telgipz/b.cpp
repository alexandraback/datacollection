#include <cstdio>
#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;

queue<pair<int, int> > q;
int main() {
    freopen("b.in", "r", stdin);
    freopen("b.out", "w", stdout);
    int t ,n, x, y;
    
    cin >> t;
    for (int test=1; test <= t; test ++ ) {
        cin >> n >>x >> y;
        double out;
        if (n == 0) {
            out = 0;
        }else {
            if (n >= 15) {
                if (x + y <= 4) {
                    out = 1;
                }else if(x + y == 6) {
                    while (!q.empty()) {
                        q.pop();
                    }
                    q.push(make_pair(0, 0));
                    n-= 15;
                    while (--n >= 0) {
                        int s = (int)q.size();
                        
                        for (int i=0; i<s; i++) {
                            pair<int, int> nl=q.front(), nr=q.front();
                            if (nl.first+1 <7) {
                                nl.first++;
                            }else nl.second++;
                            if (nr.second+1 <7) {
                                nr.second++;
                            }else nr.first++;
                            q.push(nr);
                            q.push(nl);
                            q.pop();
                        }
                    }
                    double a=0, b= q.size();
                    while (!q.empty()) {
                        //cout << "!"<<q.front().first << " "<< q.front().second << endl;
                        if (x>0) {
                            if(q.front().second>y) a++;
                        }else {
                            if(q.front().first>y) a++;
                        }
                        q.pop();
                    }
                    out=a/b;
                }else out = 0;
            }else if(n >= 6) {
                if (x + y <= 2) {
                    out = 1;
                }else if (x + y <= 4) {
                    
                    while (!q.empty()) {
                        q.pop();
                    }
                    q.push(make_pair(0, 0));
                    n-= 6;
                    while (--n>= 0) {
                        int s = (int)q.size();
                        for (int i=0; i<s; i++) {
                            pair<int, int> nl=q.front(), nr=q.front();
                            if (nl.first+1 < 5) {
                                nl.first++;
                            }else nl.second++;
                            if (nr.second+1 < 5) {
                                nr.second++;
                            }else nr.first++;
                            q.push(nr);
                            q.push(nl);
                            q.pop();
                        }
                    }
                    double a=0, b= q.size();
                    while (!q.empty()) {
                        if (x>0) {
                            if(q.front().second>y) a++;
                        }else {
                            if(q.front().first>y) a++;
                        }
                        q.pop();
                    }
                    out=a/b;
                    
                    
                }else out = 0;
            }else if(n >= 1) {
                if(x+y == 0) out =1;
                else if (x+y <= 2) {
                    
                    
                    
                    while (!q.empty()) {
                        q.pop();
                    }
                    q.push(make_pair(0, 0));
                    n-= 1;
                    while (--n>= 0) {
                        int s = (int)q.size();
                        for (int i=0; i<s; i++) {
                            pair<int, int> nl=q.front(), nr=q.front();
                            if (nl.first+1 < 3) {
                                nl.first++;
                            }else nl.second++;
                            if (nr.second+1 < 3) {
                                nr.second++;
                            }else nr.first++;
                            q.push(nr);
                            q.push(nl);
                            q.pop();
                        }
                    }
                    double a=0, b= q.size();
                    while (!q.empty()) {
                        //cout << "!"<<q.front().first << " "<< q.front().second << endl;
                        if (x>0) {
                            if(q.front().second>y) a++;
                        }else {
                            if(q.front().first>y) a++;
                        }
                        q.pop();
                    }
                    out=a/b;
                    
                    
                }else out =0;
            }else{
                if (x+y == 0) {
                    out = 1;
                }else out =0;
            }
            
        }
        cout << "Case #" << test << ": " << out << endl;
    }
    
    
    return 0;
}