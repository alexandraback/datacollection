#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <list>
#include <string>
#include <algorithm>
#include <set>
#include <cmath>
#include <vector>
#include <map>
#include <iterator>
#include <sstream>
#include <fstream>
#include <list>
#include <set>
#include <stack>
#include <bitset>
#include <ctime>
 
#pragma comment(linker, "/STACK:256000000")
 
#define EPS 1e-7
 
const long double PI = 3.1415926535897932384626433832795;
 
using namespace std;
 
int aabs(int a){
	if (a<0) return -a;
	return a;
}

string solveOne(){
	string res="";
	int xx, yy;
	cin>>xx>>yy;
	int x=0, y=0;
	int last=0;
	while (x!=xx){
		if (x<xx){
			last++;	x-=last; res+='W';
			last++;	x+=last; res+='E';
		}
		else{
			last++;	x+=last; res+='E';
			last++;	x-=last; res+='W';
		}
	}
	while (y!=yy){
		if (y<yy){
			last++;	y-=last; res+='S';
			last++;	y+=last; res+='N';
		}
		else{
			last++;	y+=last; res+='N';
			last++;	y-=last; res+='S';
		}
	}
	return res;
}

void solveAll(){
	int t;
	cin>>t;
	for (int i=1;i<=t;i++){
		cout<<"Case #"<<i<<": "<<solveOne()<<"\n";
		//cout<<"Case #"<<i<<": "; solveOne(); cout<<"\n";
	}
}

int main(){
	freopen("input.txt","rt",stdin);
	freopen("output.txt","wt",stdout);
	cout.setf(ios::fixed);
	cout.precision(6);
	solveAll();
	return 0;
}