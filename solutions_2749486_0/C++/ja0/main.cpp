#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
typedef long long ll;

const int N = 111;
int t;
string s;

void go_left(){
	s += "EW";
}

void go_right(){
	s += "WE";
}

void go_down(){
	s += "NS";
}

void go_up(){
	s += "SN";
}

int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);

	scanf("%d", &t);
	for(int tc = 1; tc <= t; tc++){
		int x, y;
		scanf("%d%d", &x, &y);
		s = "";
		if(x > 0){
			if(y > 0){
				for(int i = 0; i < x; i++)go_right();
				for(int i = 0; i < y; i++)go_up();
			}else{
				for(int i = 0; i < x; i++)go_right();
				for(int i = 0; i > y; i--)go_down();
			}
		}else{
			if(y > 0){
				for(int i = 0; i > x; i--)go_left();
				for(int i = 0; i < y; i++)go_up();
			}else{
				for(int i = 0; i > x; i--)go_left();
				for(int i = 0; i > y; i--)go_down();
			}
		}
		printf("Case #%d: %s\n", tc, s.c_str());
	}

	return 0;
}