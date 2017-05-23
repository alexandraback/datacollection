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
#define MAX 2000010
#define MOD 1000000007
#define INF 9223372036854775807LL
using namespace std;

typedef long long int entero;
typedef pair<int, int> Point;
int prod[8];
set<int> v[MAX];
set<int>::iterator it;

void genera(int n){
    int a, i = 0, j, k, nuevo, m = n;
    char s[10], t[10];
    do{
        s[i++] = (n%10)+'0';
        n/=10;
    }while(n > 0);
    reverse(s, s+i);
    for(j = 1; j < i; j++){
        for(k = 0; k < j; k++)
            t[k] = s[i-j+k];
        for(a = 0; k < i; k++, a++)
            t[k] = s[a];
        t[i] = '\0';
        if(t[0]!= '0'){
            nuevo = atoi(t);
            if(nuevo != m)
                v[m].insert(nuevo);
        }
    }
    return;
}

int rec(int n, int m){
    int i, cont = 0;
    for(i = n; i <= m; i++)
        for(it = v[i].begin(); it != v[i].end(); it++){
            if(i <= (*it) && n <= (*it) && (*it)<=m )
                cont++;
        }
    return cont;
}

int main(){
    int i, j, k, A, B, T;
    prod[0] = 10;
    for(i = 1; i < 8; i++)
        prod[i] = 10*prod[i-1];
    for(i = 10; i < MAX; i++)
        genera(i);
/*    for(i = 0; i < 100; i++){
        cout << i << " ";
        for(it = v[i].begin(); it != v[i].end(); it++)
            cout << (*it) << " ";    
        cout << endl;
    }//*/
    cin >> T;
    for(k = 1; k <= T; k++){
        cin >> A >> B;
        cout << "Case #"<<k<<": " << rec(A, B)<<endl;
    }
    for(i = 0; i < MAX; i++)
        v[i].clear();
    return 0;
}
