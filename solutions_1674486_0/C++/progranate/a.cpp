#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>
#include<fstream>
#include<iomanip>

using namespace std;

int sub_sub(int dest, int start, vector<int> s[1000], int flag[1000]){
	if(dest==start) return 1;
	if(flag[dest]==1) return 0;
	int num=0;
	for(int i=0; i<s[start].size(); i++){
		flag[s[start][i]]=1;
		num+=sub_sub(dest, s[start][i], s, flag);
		flag[s[start][i]]=0;
	}
	return num;
}

void sub(vector<int> s[1000], int n){
	int start;
	int dest;
	int num;
	int flag[1000];
	srand((unsigned int)time(NULL));

	for(int i=0; i< 1000; i++){
		flag[i]=0;
	}

	for(int j=0; j<100000; j++){
	start=rand() % n;
	do{
		dest=rand()%n;
	}while(dest==start);
	
	flag[start]=1;
		num=sub_sub(dest, start, s, flag);
		if(num>=2){
			cout << "Yes" << endl;
			return;
		}
	flag[start]=0;
	}
	cout << "No" <<endl;
	return;
}

int main(int argc, char **argv){
	string buf;
	int in_num;
	int n;
	vector<int> s[1000];
	int r=1;
	vector<double> tmp;
	
	if(argc==1){
		cout << "Please input file name!!" << endl;
		return -1;
	}


	ifstream ifs(argv[argc-1]);
	//cout << "File open succeeded!" << endl;
	ifs >> buf;
	in_num=atoi(buf.c_str());
	
	for(int j=0;j<in_num; j++){
		// file input
		ifs >> buf;
		n=atoi(buf.c_str());
		for(int i=0;i<n;i++){
			ifs>>buf;
			int class_num=atoi(buf.c_str());
			for(int j=0; j<class_num; j++){
				ifs>>buf;
				s[i].push_back(atoi(buf.c_str())-1);
			}
			//cout << s[i] << endl;
		}

		// computation
		printf("Case #%d: ", r);
		sub(s, n);
		for(int i=0;i<n;i++){
			s[i].clear();
		}
		r++;
	}

	return 0;
}
