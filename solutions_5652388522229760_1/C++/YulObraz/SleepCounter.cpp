#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>

using namespace std;
bool success(bool* met){
	for(int i=0;i<10;i++){
		if(met[i]==false)
			return false;
	}
	return true;
}
void update_met(int current, bool* met){
	int cur = current;
	while(cur!=0){
		met[cur%10]=true;
		cur=cur/10;
	}
}
int calc(int);
int calc(int start){
	bool* met=new bool[10];
	for(int i=0;i<10;i++)
		met[i]=false;
	int n =0;
	int current =start;
	while(!success(met)){
		if(n++>2000){
			cerr<<start;
			return 0;
		}
		update_met(current,met);
		current+=start;
	}
	return current-start;
}
int main(int argc,char *argv[]) {
	freopen(argv[1],"r",stdin);
	freopen(argv[2],"w",stdout);
	int tests;
	cin >> tests;
	for(int i=0; i<tests; i++){
		int target;
		cin>>target;

		int result = calc(target);
		cout << "Case #"<< (i+1)<<": ";
		if(result==0)
				cout<<"INSOMNIA";
		else cout<<result;
		cout<< endl;
	}
	return 0;
}
