#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <sstream>
#include <fstream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <limits.h>
#include <time.h>

using namespace std;
typedef long long ll;

const int mod = 1e9+7;
const double eps = 1e-11;

int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

bool check(vector<vector<int> > arr){
	int n = arr.size(), m = arr[0].size();
	vector<vector<char> > used(n, vector<char> (m, false));
	queue<pair<int, int> > q;
	q.push(make_pair(0, 0));
	used[0][0] = true;
	while(!q.empty()){
		int x = q.front().second;
		int y = q.front().first;
		q.pop();
		int count = 0;
		for(int i=0; i<8; i++){
			int xx = x + dx[i];
			int yy = y + dy[i];
			if(xx >= 0 && yy >= 0 && yy < n && xx < m){
				if(arr[yy][xx])
					count++;
			}
		}
		if(count != 0)
			continue;
		for(int i=0; i<8; i++){
			int xx = x + dx[i];
			int yy = y + dy[i];
			if(xx >= 0 && yy >= 0 && yy < n && xx < m){
				if(!used[yy][xx]){
					used[yy][xx] = true;
					q.push(make_pair(yy, xx));
				}
			}
		}
	}

	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			if(arr[i][j] == 0 && !used[i][j]){
				return false;
			}
		}
	}

	return true;
}

void print(vector<vector<int> > arr){
	arr[0][0] = -1;
	for(int i=0; i<arr.size(); i++){
		for(int j=0; j<arr[i].size(); j++){
			if(arr[i][j] == -1)
				putchar('c');
			else{
				if(arr[i][j] == 0)
					putchar('.');
				else
					putchar('*');
			}
		}
		putchar('\n');
	}
}

int main(){
	freopen("C-small-attempt0.in", "r", stdin);
	freopen("output.txt", "w", stdout);
	int test;
	cin>>test;
	for(int tt = 0; tt < test; tt++){
		int n, m, k;
		cin>>n>>m>>k;
		vector<vector<int> > arr(n, vector<int> (m, 0));

		while(k >= n || k >= m){
			if(n > m){
				k -= m;
				for(int i=0; i<m; i++){
					arr[n-1][i] = 1;
				}
				n--;
			}
			else{
				k -= n;
				for(int i=0; i<n; i++){
					arr[i][m-1] = 1;
				}
				m--;
			}
		}

		if(k > 0){
			arr[n-1][m-1] = 1;
			k--;
		}

		int buf1 = 1, buf2 = 1;
		while(k > 0){
			if(n > m){
				arr[n-1-buf1][m-1] = 1;
				k--;
				buf1++;
				if(k == 0)
					break;
				arr[n-1][m-1-buf2] = 1;
				k--;
				buf2++;
			}
			else{
				arr[n-1][m-1-buf2] = 1;
				k--;
				buf2++;
				if(k == 0)
					break;
				arr[n-1-buf1][m-1] = 1;
				k--;
				buf1++;
			}
		}

		cout<<"Case #"<<tt+1<<":\n";
		if(check(arr))
			print(arr);
		else
			cout<<"Impossible\n";
	}
    return 0;
}