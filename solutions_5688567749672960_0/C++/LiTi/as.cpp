//In the name of Allah    
#include <bits/stdc++.h>    
using namespace std;    

#define sz(x) ((int)(x).size())    
typedef long long ll;    
int rev( int num ) { 
    int res= 0; 
    while( num ) { 
	res = res * 10 + num % 10; 
	num /= 10; 
    }
    return res;
}

const int maxN = 100*10000 + 10;
int check[maxN];
int solve() { 
    int n;
    cin >> n; 
    return check[n];
}

vector<int> que;
int main() { 
    que.push_back( 1 ) ; 
    check[1] = 1;
    for( int i = 0 ; i < sz(que) ; i++ ) {
	if( que[i] + 1 != maxN && !check[que[i] + 1] ) {
	    que.push_back( que[i] + 1 ) ; 
	    check[que[i]+1] = check[que[i]]+1;
	}
	if( rev(que[i]) < maxN && !check[rev(que[i])] ) {
	    que.push_back( rev(que[i]) ) ; 
	    check[rev(que[i])] = check[que[i]]+1;
	}
    }

    int t;
    cin >> t;
    for( int i = 1 ; i<= t ; i++ ) 
	cout << "Case #" << i << ": " << solve() << endl;
}
