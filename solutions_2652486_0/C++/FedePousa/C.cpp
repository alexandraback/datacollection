#define Federico using
#define Javier namespace
#define Pousa std;
#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include <vector>
#include <map>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <stack>
#include <queue>
#include <cstring>
#include <sstream>


Federico Javier Pousa

int main(){
	vector<int> ori;
	int act = 0;
	string rev[100];
	vector<int> prod[150];
	for(int i=2;i<=5;++i){
		for(int j=2;j<=5;++j){
			for(int k=2;k<=5;++k){
				stringstream ss;
				ss << i << j << k;
				rev[act] = ss.str();
				ori.push_back(act);
				if(find(prod[1].begin(),prod[1].end(),act)==prod[1].end())prod[1].push_back(act);
				if(find(prod[i].begin(),prod[i].end(),act)==prod[i].end())prod[i].push_back(act);
				if(find(prod[j].begin(),prod[j].end(),act)==prod[j].end())prod[j].push_back(act);
				if(find(prod[k].begin(),prod[k].end(),act)==prod[k].end())prod[k].push_back(act);
				if(find(prod[i*j].begin(),prod[i*j].end(),act)==prod[i*j].end())prod[i*j].push_back(act);
				if(find(prod[i*k].begin(),prod[i*k].end(),act)==prod[i*k].end())prod[i*k].push_back(act);
				if(find(prod[j*k].begin(),prod[j*k].end(),act)==prod[j*k].end())prod[j*k].push_back(act);
				if(find(prod[i*j*k].begin(),prod[i*j*k].end(),act)==prod[i*j*k].end())prod[i*j*k].push_back(act);
				act++;
			}
		}
	}
	
	
	int T, R, N, M, K, aux;
	cin >> T >> R >> N >> M >> K;
	cout << "Case #1:" << endl;
	for(int i=0;i<R;++i){
		vector<int> res = ori;
		vector<int> otro = ori;
		for(int j=0;j<K;++j){
			cin >> aux;
			set_intersection(res.begin(),res.end(),prod[aux].begin(),prod[aux].end(),otro.begin());
			res = otro;
		}
		cout << rev[res[0]] << endl;
	}
	
	
	return 0;
}
