#include <iostream>
#include <queue>
#include <cstdio>
#include <fstream>
using namespace std;

queue<int> q;
int d[1000005], te, n;

int flip(int x){
	int r = 0;
	int t = x;
	while(t){
		r *= 10;
		r += t%10;
		t /= 10;
	}
	return r;
}

int main(){
	ifstream fin("A.in");
	ofstream fout("out.out");
	d[0] = 1;
	for(q.push(0); !q.empty();){
		int cur = q.front(); q.pop();
		int next = cur + 1;
		if(next <= 1000000){
			if(!d[next]){
				d[next] = d[cur] + 1;
				q.push(next);
			}
		}
		
		next = flip(cur);
		if(next <= 1000000){
			if(!d[next]){
				d[next] = d[cur] + 1;
				q.push(next);
			}
		}
	}
	fin >> te;
	for(int a = 1; a <= te; ++a){
		fin >> n;
		fout << "Case #" << a << ": " << d[n]-1 << endl;
	}
	return 0;
}
