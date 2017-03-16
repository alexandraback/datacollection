#include <iostream>
#include <cstdio>
#include <vector>
#include <deque>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <map>
using namespace std;
int n;
string temp;
string s[20];

string st;


string transform(string t){
	string res;
	res += t[0];
	for(int i=1; t[i]; i++){
		if(t[i]!=t[i-1]){
			res+=t[i];
		}
	}
	return res;
}
	
bool check(string st){	
	bool ck[200];
	memset(ck,0,sizeof ck);
	ck[st[0]]=true;
	for(int i=1; st[i]; i++){
		if( st[i] != st[i-1] && ck[st[i]]){			
			return false;
		}
		ck[st[i]]=true;
	}
	return true;
}

void solve(int test){
	
	printf("Case #%d: ", test+1);
	cin >> n;
	
	for(int i=0; i<n; i++){
		cin >> temp;
		s[i] = transform(temp);		
		//cout << "si= " << s[i] << endl;
	}
	
	int res=0;
	
	int index[10] = {0,1,2,3,4,5,6,7,8,9};
	do {
		string st = "";
		for(int i=0; i<n; i++){
			st += s[index[i]];			
		}
		//cout << st << endl;
		if(check(st)){
			res++;
		}
	} while ( next_permutation(index,index+n) );
	cout << res << endl;
	
}

int ntest;
int main(){
	freopen("B-small-attempt1.in","r",stdin);
	freopen("test.out","w",stdout);
	scanf("%d",&ntest);		
	for(int t=0; t<ntest; t++){
		solve(t);
	}
	return 0;
}
