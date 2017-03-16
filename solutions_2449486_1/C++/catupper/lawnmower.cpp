#include<iostream>
#include<algorithm>
#include<string>
using namespace std;


int num[105][105];
int imax[105], jmax[105], t;
string solve(){
    int n, m;
    fill(imax, imax + 105, -1);
    fill(jmax, jmax + 105, -1);
    cin >> n >> m;
    for(int i = 0;i < n;i++){
	for(int j = 0;j < m;j++){
	    cin >> num[i][j];
	    imax[i] = max(imax[i], num[i][j]);
	    jmax[j] = max(jmax[j], num[i][j]);
	}
    }
    for(int i = 0;i < n;i++){
	for(int j = 0;j < m;j++){
	    if(num[i][j] != min(imax[i], jmax[j]))
		return "NO";
	}
    }
    return "YES";
}

int main(){
    cin >> t;
    for(int i = 1;i <= t;i++){
	cout << "Case #" << i << ": " << solve() << endl;
    }
    return 0;
}
