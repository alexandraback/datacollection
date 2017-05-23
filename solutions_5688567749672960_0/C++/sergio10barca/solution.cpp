#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <set>
#include <stack>
#include <deque>
#include <queue>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <cstring>
#include <iomanip>
#include <climits>
#include <cfloat>
#include <cstdio>
#define x first
#define y second
#define IN(x, n) (0 <= (x) && (x) < n)
#define MAX 1000010
#define MOD 1000000007
using namespace std;

typedef long long int entero;
typedef pair<int, int> Point;

int used[MAX];

long long int itoap(long long int n){
    char s[20];
//    printf("original %lld\n", n);
    sprintf(s, "%lld", n);
    reverse(s, s+strlen(s));
    sscanf(s, "%lld", &n);
//    printf("reversa %lld\n", n);
    return n;
}

long long int solve(long long int n){
    queue<Point> q;
    memset(used, 1, sizeof(used));
    q.push(make_pair(1, 1));
    if(n == 1)
        return 1;
    used[1] = false;
    while(!q.empty()){
        Point p = q.front();
        q.pop();
        long long c = p.first;
//        cout << p.first << " + " <<p.second<<endl;
        if(c+1 == n){
            while(!q.empty())
                q.pop();
            return p.second+1;
        }
        if(c+1 <= n && used[c+1]){
            q.push(make_pair(c+1, p.second+1));
            used[c+1] = false;
        }
        c = itoap(p.first);
        if(c == n){
            while(!q.empty())
                q.pop();
            return p.second+1;
        }
        if(c != p.first && c <= n && used[c]){
            q.push(make_pair(c, p.second+1));
            used[c] = false;
        }
    }
}


int main(){
	int casos;
	long long int n;
	cin >> casos;
	for(int i = 1; i <= casos; i++){
        cin >> n;
        cout << "Case #"<<i<<": "<<solve(n) << endl;
	}
	return 0;
}
