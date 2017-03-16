#include <map>
#include <set>
#include <cmath>
#include <stack>
#include <queue>
#include <string>
#include <vector>
#include <bitset>
#include <fstream>
#include <sstream>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <sys/time.h>
using namespace std;
#define li        long long int
#define rep(i,to) for(int i=0;i<((int)(to));++i)
#define pb        push_back
#define sz(v)     ((int)(v).size())
#define bit(n)    (1ll<<(li)(n))
#define all(vec)  (vec).begin(),(vec).end()
#define each(i,c) for(__typeof((c).begin()) i=(c).begin();i!=(c).end();i++)
#define MP        make_pair
#define F         first
#define S         second


string input[]={
"ejp mysljylc kd kxveddknmc re jsicpdrysi",
"rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd",
"de kr kd eoya kw aej tysr re ujdr lkgc jv",
"qz"
};

string output[]={
"our language is impossible to understand",
"there are twenty six factorial possibilities",
"so it is okay if you want to just give up",
"zq"
};


int main(){
	map<char,char> mp;
	rep(i,4)rep(j,sz(input[i])) mp[input[i][j]] = output[i][j];
	string str;
	li n;
	cin>>n;
	getline(cin,str);
	rep(play_turn, n){
		string str;
		getline(cin,str);
		cout<<"Case #"<<play_turn+1<<": ";
		rep(i,sz(str))if(mp.find(str[i]) == mp.end()) while(true);
		rep(i,sz(str)) cout<<mp[str[i]]; cout<<endl;
		
	}
}
