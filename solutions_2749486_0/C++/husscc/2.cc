#include <iostream>
#include <cstdlib>
#include <cmath>
#include <cstdio>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;
const int offset = 500;
//int dp_X[500][201][201], dp_Y[500][201][201];
typedef pair<int, int> PR;
struct Move{
	int X, Y, step;
	Move(int x, int y, int s):X(x), Y(y), step(s) {}

	bool operator==(const Move &m) const{
		return X == m.X && Y == m.Y && step == m.step;
	}
};

struct hashpr{
	size_t operator()(const PR &pr) const{
		return (pr.first+offset)*offset+(pr.second+offset);
	}	
};

struct hash3{
	size_t operator()(const Move &m) const{
		return m.X*250000+m.Y*500+m.step;
	}
};

string work(int tar_X, int tar_Y){
	int step = 1;
	bool found = false;
	queue<int> x1, y1, x2, y2;
	unordered_set<PR, hashpr> us;
	unordered_map<Move, PR, hash3> um;

	x1.push(0); y1.push(0);

	while(1){
		us.clear();
		while(x1.size() > 0){

			int x = x1.front(), y = y1.front();
			x1.pop(); y1.pop();

			PR pr(x, y);
			Move m(0, 0, 0);
			m.step = step;

			//printf("step = %d, x = %d, y = %d\n", step, x, y);

			m.X = x+step; m.Y = y;
			if(tar_X == m.X && tar_Y == m.Y){
				found = true;
			}
			um[m] = pr;
			if(!us.count(PR(x+step, y))){
				x2.push(x+step); y2.push(y);
				us.insert(PR(x+step, y));
			}

			m.X = x-step; m.Y = y;
			if(tar_X == m.X && tar_Y == m.Y){
				found = true;
			}
			um[m] = pr;
			if(!us.count(PR(x-step, y))){
				x2.push(x-step); y2.push(y);
				us.insert(PR(x-step, y));
			}

			m.X = x; m.Y = y+step;
			if(tar_X == m.X && tar_Y == m.Y){
				found = true;
			}
			um[m] = pr;
			if(!us.count(PR(x, y+step))){
				x2.push(x); y2.push(y+step);
				us.insert(PR(x, y+step));
			}

			m.X = x; m.Y = y-step;
			if(tar_X == m.X && tar_Y == m.Y){
				found = true;
			}
			um[m] = pr;
			if(!us.count(PR(x, y-step))){
				x2.push(x); y2.push(y-step);
				us.insert(PR(x, y-step));
			}

		}
		if(found)
			break;
		swap(x1, x2);
		swap(y1, y2);
		step ++;
	}

	string path = "";

	int X = tar_X, Y = tar_Y;
	Move m(0, 0, 0); PR pr; 
	while(step > 0){
		m.X = X;
		m.Y = Y;
		m.step = step;
		pr = um[m];

		//printf("step = %d, x = %d, y = %d\n", step, X, Y);

		if(pr.first < m.X)
			path = "E"+path;
		else if(pr.first > m.X)
			path = "W"+path;
		else if(pr.second < m.Y)
			path = "N"+path;
		else
			path = "S"+path;

		step --;
		X = pr.first; Y = pr.second;
	}

	return path;
}

int main(){
	int T, X, Y;
	cin>>T;
	for(int i = 1; i <= T; i++){
		scanf("%d %d", &X, &Y);
		string ret = work(X, Y);
		printf("Case #%d: %s\n", i, ret.c_str());
	}
}