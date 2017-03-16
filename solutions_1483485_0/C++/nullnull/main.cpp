#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <map>
#include <queue>
#include <set>
#include <list>
#include <math.h>
#include <cstring>
using namespace std;

#define rep(i,start,m) for(int i=(int)(start);i<(int)(m);i++)
#define showarray(array,m) for(int sa_i=0;sa_i<(int)(m);sa_i++) cout << array[sa_i] <<" "; cout << endl;
#define showvector(array) for(int sa_i=0;sa_i<(int)(array.size());sa_i++) cout << array[sa_i] << " "; cout << endl;
stringstream ss;
#define cast(a,b) ss.clear(); ss<<a; ss>>b; ss.clear();
#define rev(s) (string((s).rbegin(), (s).rend()))
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << endl;
#define clr(a) memset((a), 0, sizeof(a))

int dx[] = {-1,0,1,0,1,1,-1,-1};
int dy[] = {0,-1,0,1,1,-1,1,-1};

template<class T>
int pyfind(const vector<T> &vect, const T &targ){
	for(int i=0;i<vect.size();i++){
		if(vect[i] == targ) return i;
	}
	return -1;
}

int n;
string str;

string org = "abcdefghijklmnopqrstuvwxyz ";
string trs = "yhesocvxduiglbkrztnwjpfmaq "; 
map<char,char> trans;

void solve(){
	rep(i,0,str.size()){
		cout << trans[str[i]];
	}
	cout << endl;
}

int main () {
	freopen("/Users/katsuma/c++/input.txt","rt",stdin);
	freopen("/Users/katsuma/c++/A-small-attempt0.in","rt",stdin);
	//freopen("/Users/katsuma/c++/output.txt","wt",stdout);
	freopen("/Users/katsuma/c++/A-small-attempt0out.txt","wt",stdout);
	rep(i,0,org.size()){
		trans[org[i]] = trs[i];
	}
	cin >> n;
	getline(cin, str);
	rep(i,0,n){
		getline(cin, str);
		cout << "Case #" << i+1 << ": " ; 
		solve();
	}
}

