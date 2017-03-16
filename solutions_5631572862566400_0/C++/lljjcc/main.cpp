#include <algorithm>
#include <iostream>
#include <sstream>
#include <cstring>
#include <cstdlib>
#include <string>
#include <fstream>
#include <vector>
#include <cstdio>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <set>
using namespace std;
#define INF 0x3f3f3f3f
const int N=1015;
const int mod=1e9+7;

int f[N];
vector<int> s[N];

int dfs(int x,int sss) {
    vector<int>::iterator pos;
    sss++;
    if (s[x][0]==0) {
        return sss;
    }
    for (pos=s[x].begin(); pos!=s[x].end(); pos++) {
        sss=max(sss,dfs(*pos, sss));
    }
    return sss;
}

int main() {
    int t,n;
    ifstream ifile;
    ofstream ofile;
    ofile.open("/Users/lijiechen/Downloads/outt.txt",ios::out);
    ifile.open("/Users/lijiechen/Downloads/C-small-attempt0.in.txt",ios::out);
    ifile>>t;
    int kase=0;
    while (t--) {
        ifile>>n;
        kase++;
        int maxx=0;
        memset(f, 0, sizeof(f));
        memset(s, 0, sizeof(s));
        for (int i=1; i<=n; i++) {
            if (!s[i].empty()) {
                s[i].pop_back();
            }
        }
        for (int i=1; i<=n; i++) {
            ifile>>f[i];
            s[f[i]].push_back(i);
        }
        for (int i=1; i<=n; i++) {
            if (s[i].empty()) {
                s[i].push_back(0);
            }
        }
        ofile<<"Case #"<<kase<<": ";
        int next,sum,flag;
        for (int i=1; i<=n; i++) {
            next=f[i];
            flag=i;
            sum=1;
            while (sum<=n) {
                if (next==i) {
                    break;
                }
                sum++;
                if (f[next]==flag) {
                    flag-=10000;
                    break;
                }
                flag=next;
                next=f[next];
            }
            if (flag<0) {
                flag+=10000;
                vector<int>::iterator pos1;
                for (pos1=s[flag].begin(); pos1!=s[flag].end(); pos1++) {
                    if (*pos1==next) {
                        s[flag].erase(pos1);break;
                    }
                }
                vector<int>::iterator pos2;
                for (pos2=s[next].begin(); pos2!=s[next].end(); pos2++) {
                    if (*pos2==flag) {
                        s[next].erase(pos2);break;
                    }
                }
                if (sum==2) {
                    sum+=dfs(next, 0)+dfs(flag, 0)-2;
                } else {
                    sum+=dfs(next, 0)-1;
                }
                sum--;
            }
            if (sum<=n) {
                maxx=max(sum, maxx);
            }
        }
        ofile<<maxx<<endl;
    }
    return 0;
}