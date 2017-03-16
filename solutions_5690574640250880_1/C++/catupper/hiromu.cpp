#include<iostream>
#include<algorithm>
#include<vector>
#include<map>

using namespace std;
typedef pair<int, int> P;
typedef pair<int, P> T;
vector<P> frontear;
vector<T> points;
bool bomb[54][54];
int r, c, m;

int cnt(P pos, bool fl = false){
	int res = 0;
	for(int i = -1;i <= 1;i++){
		for(int j = -1;j <= 1;j++){
			int tx = pos.first + i;
			int ty = pos.second + j;
			if(tx < 0 || ty < 0 || tx >= r || ty >= c)continue;
			if(bomb[tx][ty]){
				res++;
				if(fl){
					bomb[tx][ty] = false;
				}
			}		
		}
	}
	return res;
}

void solve(){
	points.clear();
	cin >> r >> c >> m;
	m = r*c -m ;
	if(m == 1){
		for(int i = 0;i < r;i++)
			for(int j = 0;j < c;j++)
				bomb[i][j] = true;
		bomb[0][0] = false;
	}
	else if(r >= 3 && c >= 3){
		if(m % 2 == 0 && m < 4 || m % 2 == 1 && m < 9){
			cout << "Impossible" << endl;
			return;
		}
		for(int i = 0;i < r;i++)
			for(int j = 0;j < c;j++){
				bomb[i][j] = true;
				if(m % 2 == 1 && i == 2 && j == 2)continue;
				if(i < 2 || j < 2)continue;
				points.push_back(T(i + j, P(i, j)));
			}
		sort(points.begin(), points.end());
		if(m % 2 == 1){
			for(int i = 0;i < 3;i++)
				for(int j = 0;j < 3;j++)
					bomb[i][j] = false;
			m -= 9;
		}
		else{
			for(int i = 0;i < 2;i++)
				for(int j = 0;j < 2;j++)
					bomb[i][j] = false;
			m -= 4;
		}
		for(int i = 2;i < r && m;i++){
			if(bomb[i][0] == false)continue;
			m -= 2;
			bomb[i][0] = bomb[i][1] = false;
		}
		for(int i = 2;i < c && m;i++){
			if(bomb[0][i] == false)continue;
			m -= 2;
			bomb[0][i] = bomb[1][i] = false;
		}
		for(int i = 0;i < points.size() && m;i++){
			m--;
			bomb[points[i].second.first][points[i].second.second] = false;
		}
	}
	else{
		for(int i = 0;i < r;i++)
			for(int j = 0;j < c;j++)
				bomb[i][j] = true;
		bomb[0][0] = false;
		m--;
		for(int i = 0;i < r;i++){
			if(m <= 0)break;
			for(int j = 0;j < c;j++){
				if(m <= 0)break;
				m -= cnt(P(i, j), true);
			}
		}
		if(m < 0){
			cout << "Impossible" << endl;
			return;
		}
	}
	for(int i = 0;i < r;i++){
		for(int j = 0;j < c;j++){
			if(i == 0 && j == 0)cout << "c";
			else if(bomb[i][j])cout << "*";
			else cout << ".";
		}                     
		cout << endl;
	}
}

int main(){
	int t;
	cin >> t;
	for(int i = 1;i <= t;i++){
		cout << "Case #" << i << ":" << endl;
		solve();
	}
	return 0;
}
