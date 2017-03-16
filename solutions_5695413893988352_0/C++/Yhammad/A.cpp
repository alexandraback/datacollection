#include<iostream>
#include<string>
#include<map>
#include<algorithm>
#include<set>
#include<cmath>
#include<stdio.h>
#include<utility>
#include<queue>
#include<stack>
#include<deque>
#include<string.h>
using namespace std;

int main()
{
	int t;
	cin >> t;
	string c, C;
	vector<string> scores[3];
	for(int j = 0; j < 3; ++ j)
	for(int i = 0; i < 1000; ++ i){
		string pusher = to_string(i);
		while(pusher.size() < j + 1)
			pusher = "0" + pusher;
		scores[j].push_back(pusher);
	}
	//return 0;
	for(int z = 1; z <= t; ++ z){
		int mn =10000;
		int ri, rj;
		cin >> c >> C;

		for(int i = 0; i < 1000; ++ i){
			bool can = true;
			if(to_string(i).size() > c.size())
				continue;
			for(int j = 0; j < c.size(); ++ j){
				if(c[j] != scores[c.size()-1][i][j] && c[j] != '?'){
					can = false;
					break;
				}
			}
			if(!can) continue;
			for(int j = 0; j < 1000; ++ j){
				can = true;
				if(to_string(j).size() > c.size())
					continue;
				for(int k = 0; k < c.size(); ++ k){
					if(C[k] != scores[c.size()-1][j][k] && C[k] != '?'){
						can = false;
						break;
					}
				}
				if(can){
					// check output;
					if(mn > abs(i - j)){
						mn = abs(i - j);
						ri = i;
						rj = j;
					}
					else if(mn == abs(i-j)){
						if(i < ri){
							ri = i;
							rj = j;
						}
						else if(i == ri && j < rj){
							rj = j;
						}
					}
				}
			}
		}
		cout << "Case #" << z << ": " << scores[c.size()-1][ri] << ' ' << scores[c.size()-1][rj] << endl;
	}
	return 0;
}