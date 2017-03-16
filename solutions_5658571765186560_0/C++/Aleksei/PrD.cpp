#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <cstdio>
#include <vector>
#include <string>
#include <cassert>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <numeric>
#include <sstream>
#include <string.h>
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	ifstream cin("input.txt");
	ofstream cout("output.txt");
	int ntests;
	cin>>ntests;
	for(int testnum=0; testnum<ntests; testnum++){
		int x, r, c;
		cin>>x>>r>>c;
		if(r*c % x != 0){
			cout<<"Case #"<<testnum+1<<": "<<"RICHARD"<<endl;
			continue;
		}
		if(r<x && c<x){
			cout<<"Case #"<<testnum+1<<": "<<"RICHARD"<<endl;
			continue;
		}
		if(x==1){
			cout<<"Case #"<<testnum+1<<": "<<"GABRIEL"<<endl;
		}else if(x==2){
			if(r%2==0 || c%2==0){
				cout<<"Case #"<<testnum+1<<": "<<"GABRIEL"<<endl;
			}else{
				cout<<"Case #"<<testnum+1<<": "<<"RICHARD"<<endl;
			}
		}else if(x==3){
			if(r<2 || c<2){
				cout<<"Case #"<<testnum+1<<": "<<"RICHARD"<<endl;
			}else{
				cout<<"Case #"<<testnum+1<<": "<<"GABRIEL"<<endl;
			}
		}else if(x==4){
			int other;
			if(r==x){
				other = c;
			}else{
				other = r;
			}
			if(other==1 || other==2){
				cout<<"Case #"<<testnum+1<<": "<<"RICHARD"<<endl;
			}else{
				cout<<"Case #"<<testnum+1<<": "<<"GABRIEL"<<endl;
			}
		}
	}
	return 0;
}
