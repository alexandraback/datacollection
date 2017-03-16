#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>
#include <set>
#include <map>
#include <queue>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>

using namespace std;
typedef long long ll;
const double eps = 1e-9;
const int mod = 1e9 + 7;

vector<int> arr;

int get(int numb){
	stringstream out1, out2;
	out1<<numb;
	string str;
	out1>>str;
	reverse(str.begin(), str.end());
	out2<<str;
	out2>>numb;
	return numb;
}

void dfs(int numb){
	arr[numb + 1] = min(arr[numb + 1], numb + 1);
	int buf = get(numb);
}

void print(int t, ll res){
	cout<<"Case #"<<t<<": "<<res<<"\n";
}

int main(){
	freopen("A-small-attempt0.in", "r", stdin);
	freopen("output.txt", "w", stdout);
	int test_count;
	cin>>test_count;
	arr.resize(1e6 + 10, 1e9);
	arr[1] = 1;
	queue<int> q;
	q.push(1);
	while(!q.empty()){
		int numb = q.front();
		q.pop();
		if((numb + 1) < arr.size() && arr[numb + 1] == 1e9){
			arr[numb + 1] = arr[numb] + 1;
			q.push(numb + 1);
		}
		int buf = get(numb);
		if(buf < arr.size() && arr[buf] == 1e9){
			arr[buf] = arr[numb] + 1;
			q.push(buf);
		}
	}
	for(int test=0; test<test_count; test++){
		ll numb;
		cin>>numb;
		print(test + 1, arr[numb]);
	}
	return 0;
}