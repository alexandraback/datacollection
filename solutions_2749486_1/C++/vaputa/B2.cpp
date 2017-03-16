#include <iostream>
#include <cstdio>
#include <cstring>
#include <set>

using namespace std;

set<int> v[1 << 5];
int hash(int x, int y){
	return (x + 1000) * 10000 + (y + 1000);
}
char out[1 << 20];

void find(int dep, int x, int y){
	if (v[dep - 1].count(hash(x,y)))
		return ;
	v[dep - 1].insert(hash(x, y));
	if (dep > 25){
		return ;
	}
	find(dep + 1, x + dep , y);
	find(dep + 1, x, y + dep);
	find(dep + 1, x - dep , y);
	find(dep + 1, x, y - dep);	
}

void generate(){
	find(1, 0, 0);
}

void trace(int dep, int x, int y){
	if (dep == 0)
		return ;
	if (v[dep - 1].count(hash(x - dep, y))){
		x -= dep;
		out[dep] = 'E';
	}
	else if (v[dep - 1].count(hash(x + dep, y))){
		x += dep;
		out[dep] = 'W';
	}
	else if (v[dep - 1].count(hash(x, y - dep))){
		y -= dep;
		out[dep] = 'N';
	}
	else if (v[dep - 1].count(hash(x, y + dep))){
		y += dep;
		out[dep] = 'S';
	}
	trace(dep - 1, x, y);
}

int solve(int dep , int x, int y){
	if (dep <= 20){
		if (v[dep].count(hash(x,y))){
			trace(dep, x, y);
			return 1;
		}
		else 
			return 0;
	}
	if (abs(x) >= abs(y)){
		if (x > 0){
			x -= dep;
			out[dep] = 'E';
		}
		else {
			x += dep;
			out[dep] = 'W';
		}
	}
	else {
		if (y > 0){
			y -= dep;
			out[dep] = 'N';
		}
		else {
			y += dep;
			out[dep] = 'S';
		}
	}
	return solve(dep - 1, x , y);
}

int main(){
	generate();
	int n, x, y;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i){
		scanf("%d %d", &x, &y);
		int tot = abs(x) + abs(y);
		int step = 0, ok = false;
		while (!ok){
			++step;
			if (step * (step + 1) / 2 >= tot && (step * (step + 1) / 2 - tot) % 2 == 0)
				ok = solve(step, x, y);
		}
		printf("Case #%d: ", i + 1);
		for (int i = 1; i <= step; ++i)
			putchar(out[i]);
		puts("");
	}
	return 0;
}
