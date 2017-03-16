#include <cstdio>
#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <algorithm>
#include <string>
#include <sstream>
#include <cmath>
#include <stack>
#include <queue>
#include <functional>

using namespace std;
struct point{
	point(int r, int c, int h){
		this->r = r;
		this->c = c;
		this->h = h;
	}
	int r, c;
	int h;
	bool operator<(const point &p) const{
		return h < p.h;
	}
};
int current[100][100];
int target[100][100];
int main(){
	int T;
	scanf("%d", &T);
	for(int current_case = 1; current_case <= T; ++current_case){
		printf("Case #%d: ", current_case);
		int N, M;
		scanf("%d%d", &N, &M);
		vector<point> v;
		for(int i = 0; i < N; ++i){
			for(int j = 0; j < M; ++j){
				current[i][j]=100;
				int h;
				scanf("%d",&h);
				v.push_back(point(i, j, h));
				target[i][j]=h;
			}
		}
		sort(v.begin(), v.end());
		bool ready = false;
		for(vector<point>::iterator it = v.begin(); it != v.end(); ++it){
			int c = current[it->r][it->c];
			if(c ==it->h){
				continue;
			}
			if(c < it->h){
				ready = true;
				cout << "NO";
				break;
			}
			//row
			bool ok = true;
			for(int i = 0; i < M; ++i){
				if(target[it->r][i]>it->h){
					ok = false;
					break;
				}
			}
			if(ok){
				for(int i = 0; i < M; ++i){
					current[it->r][i]=it->h;
				}
				continue;
			}
			ok = true;
			for(int i = 0; i < N; ++i){
				if(target[i][it->c] > it->h){
					ok = false;
					break;
				}
			}
			if(ok){
				for(int i = 0; i < N; ++i){
					current[i][it->c] = it->h;
				}
			}else{
				ready = true;
				cout << "NO";
				break;
			}
		}
		if(!ready){
			cout << "YES";
		}
		cout << endl;
	}
    return 0;
}
