#include<bits/stdc++.h>
#define endl '\n'
#define pb push_back
#define pii pair<int, int>
#define mp make_pair
#define ll long long
#define ld long double
#include<random>
using namespace std;

const int MAX = 50;
int ncases, n, m;
bool mat[MAX][MAX];

void printMat(int caseNumber, bool possible){
	if(possible){
		cout << "Case #" << caseNumber << ": POSSIBLE\n";
		for(int i=0;i<n;++i){
			for(int j=0;j<n;++j)
				cout << mat[i][j];
			cout << endl;
		}
	}
	else{
		cout << "Case #" << caseNumber << ": IMPOSSIBLE\n";
	}
}

void resetMat(){
	for(int i=0;i<n;++i)
		for(int j=0;j<n;++j)
			mat[i][j] = 0;
}

ll getPathsAux(int u){
	if(u == n-1)
		return 1;
	
	ll sum = 0;
	for(int i=0;i<n;++i)
		if(mat[u][i])
			sum += getPathsAux(i);
	return sum;
}
ll getPaths(){return getPathsAux(0);}

int main(){
	ios_base::sync_with_stdio(0);
	cin >> ncases;
	
	for(int test=1;test<=ncases;++test){
		cin >> n >> m;
		resetMat();
		
		default_random_engine gen;
		uniform_int_distribution<int> d1(0,n-2);
		int res = 0;
		int counter = 0, stopat = 10000;
		while(res != m && counter < stopat){
			int i = d1(gen);
			uniform_int_distribution<int> d2(i+1,n-1);
			int j = d2(gen);
// 			cout << i << " " << j << endl;
			if(res > m)
				mat[i][j] = false;
			else if(res < m)
				mat[i][j] = true;
			res = getPaths();
			
			if(res == m){
				printMat(test, true);
// 				cout << "in " << counter << endl;
				break;
			}
			
// 			cout << res << endl;
			counter++;
		}
		if(counter == stopat){
			printMat(test, false);
		}
		
// 		bool stop = false;
// 		for(int i=0;i<n-1;++i){
// 			for(int j=i+1;j<n;++j){
// 				mat[i][j] = true;
// 				ll paths = getPaths();
// 				if(paths == m){
// 					printMat(test, true);
// 					stop = true;
// 					break;
// 				}
// 				else if(paths > m)
// 					mat[i][j] = false;
// 			}
// 			if(stop)
// 				break;
// 		}
// 		if(!stop){
// 			printMat(test, false);
// 		}
	}
	return 0;
}