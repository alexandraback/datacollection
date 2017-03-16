#include <iostream>
#include <vector>
#include <cassert>
#include <cmath>
#include <ctime>
#include <cstdio>
#include <queue>
#include <set>
#include <map>
#include <fstream>
#include <cstdlib>
#include <string>
#include <cstring>
#include <algorithm>
#include <numeric>

#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define fornn(i, a, b) for (int i = (int)(a); i < (int)(b); ++i)
#define fore(i, a, b) for (int i = (int)(a); i <= (int)(b); ++i)

using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<int>::iterator vi_it;
typedef vector<vi> vvi;

typedef long long i64;
typedef pair<i64, i64> pi64;
typedef vector<i64> vi64;
typedef vector<vi64> vvi64;
int t;
string a;

string cal() {
	int n = a.length();
	char s[2*n];
	int left = n, right = n + 1;
	s[left] = a[0];
	for (int i = 1; i < n; ++i) {
		if (a[i] >= s[left]) {
			s[--left] = a[i];
		} else {
			s[right++] = a[i];
		}
	}
	return string(s + left, right - left);
}


int main(int argc, char* argv[]){
    cin>>t;
    for(int i=0;i<t;i++){
        cin>>a;
        cout<<"Case #"<<i+1<<": "<<cal()<<endl;
    }
    return 0;
}
