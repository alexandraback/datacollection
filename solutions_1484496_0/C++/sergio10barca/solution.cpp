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
#define MAX 2010
#define MOD 1000000007
#define EPS 0.0001
#define INF 9223372036854775807LL
using namespace std;

typedef long long int entero;
typedef pair<int, int> Point;

pair<bool, bool> u[MAX];

long long int sumaa, sumab, v[MAX];

string to_base3(int i, int N){
	string s = "";
	do{
		s+=(char)((i%3)+'0');
		i/=3;
	}while(i>0);
	while(s.size() < N)
		s+="0";
	return s;
}

int main(){
    int j, k, N, T, r, q;
    long long int i, lim;
    string s;
    vector<int> a, b;
    cin >> T;
    for(k = 1; k <= T; k++){
        cin >> N;
        for(i = 0; i < N; i++)
			cin >> v[i];
		lim = (long long int)pow(3.0, N);
//		cout << N << " " << lim << endl;
		for(i = 1; i < lim; i++){
			sumaa = sumab = 0;			
			s = to_base3(i, N);
//			cout << s << endl;
			for(j = 0; j < N; j++){
				switch(s[j]){				
					case '1':{
						sumaa+=v[j];
						a.push_back(j);
						break;
					}		
					case '2':{
						sumab+=v[j];
						b.push_back(j);
						break;
					}
					default:{
						break;
					}
				}
			}
//			cout << sumaa << " " << sumab << endl;
			if(sumaa == sumab)
				break;
			a.clear(), b.clear();
		}
		printf("Case #%d:\n", k);
		printf("%d", v[a[0]]);
		for(i = 1; i < a.size(); i++)
			printf(" %d", v[a[i]]);
		printf("\n");
		printf("%d", v[b[0]]);
		for(i = 1; i < b.size(); i++)
			printf(" %d", v[b[i]]);
		printf("\n");
		a.clear(), b.clear();
    }
    return 0;
}
