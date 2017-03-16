#pragma comment(linker, "/STACK:36777216")
#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <string>
#include <map>
#include <set>
#include <algorithm>
#include <queue>
#include <stack>
#include <ctime>

#define pb push_back
#define mp make_pair
#define sz size()
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
#define vint vector<int>
#define rep(i,n) for (int i=0; i<n; i++)
#define ll long long

using namespace std;

const int INF=~(1<<31);
const double EPS=1;
const double PI=3.141592653589793;

int main() {
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int T;
	cin>>T;
	int hhx[]={-1, 0, 1, 0};
	int hhy[]={0, 1, 0, -1};
	char dir[]={'W','N','E','S'};
	rep(t,T) {
		int x,y;
		cin>>x>>y;
		printf("Case #%d: ",t+1);
        map<pair<int,int>,string > ans;
        map<pair<int,int>,int> k;
		set<pair<int,int> >u;
        pair<int,int> now, to=mp(x,y);
        queue<pair<int,int> >q;
        int xn,yn,l;
        char p;
        q.push(mp(0,0));
        k[mp(0,0)] = 0;
        while(!q.empty()) {
            now = q.front();         
            q.pop();
            if(now == to) {
				cout<<ans[now]<<endl;
				break;
			}
			bool br=0;
            rep(i,4) {
                l=k[now]+1;
                xn=now.first+hhx[i]*l;
                yn=now.second+hhy[i]*l;
                if(u.count(mp(xn, yn))) {
					continue;
				}
                p = dir[i];
                ans[mp(xn,yn)] = ans[now] + p;
                q.push(mp(xn,yn));
                k[mp(xn,yn)] = l ;
                u.insert(mp(xn,yn));
                if(to == mp(xn,yn)) {
					cout<<ans[to]<<endl;
					br=1;
					break;
				}
            }
			if (br) break;
        }
	}
	return 0;
}