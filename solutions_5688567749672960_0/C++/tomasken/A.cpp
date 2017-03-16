#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
using namespace std;

#define foreach(u, o) \
    for (typeof((o).begin()) u = (o).begin(); u != (o).end(); ++u)
const int INF = 2147483647;
const double EPS = 1e-9;
const double pi = acos(-1);
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vii> vvii;
template <class T> T mod(T a, T b) { return (a % b + b) % b; }
template <class T> int size(const T &x) { return x.size(); }

int revs(int n){
    string s = to_string(n);
    reverse(s.begin(), s.end());
    return stoi(s);
}

int first(int n){
    int res = n;
    while(n){
        res = n;
        n /= 10;
    }
    return res;
}

int solve1(int N){
    int n = 1, cnt = 1;
    while(n != N){
        int rev = revs(n);
        printf("n: %d -- rev: %d\n", n, rev);
        cout << cnt << endl;
        if(rev > n && rev <= N){
            n = rev; cnt++;
        } else {
            n++; cnt++;
        }
    }
    return cnt;
}

int solve2(int N){
    int cnt = 1;
    while(N != 1){
        if(N % 10){
            int rev = revs(N);
            if(rev < N){
                N = rev;
            } else {
                N--;
            }
        } else {
            N--;
        }
        cnt++;
    }
    return cnt;
}

//int solve3(int N){
    //int cnt = 1;
    //while(N != 1){
        //if(N % 10){

        //}
    //}
//}

int solve4(int N){
    vi dist(N+1, -1);
    queue<int> Q;
    Q.push(1);
    dist[1] = 1;
    //printf("N: %d\n", N);
    while(!Q.empty()){
        int head = Q.front(); Q.pop();
        //printf("%d\n", head);
        int rev = revs(head);
        if(rev <= N && dist[rev] == -1){
            dist[rev] = dist[head] + 1;
            Q.push(rev);
        }
        if(head < N && dist[head+1] == -1){
            dist[head+1] = dist[head] + 1;
            Q.push(head+1);
        } else if(head == N){
            //return dist[head];
            break;
        }
    }
    return dist[N];
}


int main(){
    int T;
    cin >> T;
    for(int t = 0; t < T; ++t){
        int N;
        cin >> N;
        printf("Case #%d: %d\n", t+1, solve4(N));
    }
}
