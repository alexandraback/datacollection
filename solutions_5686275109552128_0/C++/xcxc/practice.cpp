/*
ID: xiaoche4
PROG: skidesign
LANG: C++
*/
//#include "TC.cpp"
#include <iostream>
#include <sstream>
#include <fstream>
#include <cmath>
#include <ctime>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <bitset>
#include <utility>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
using namespace std;

int T,D;
int n[1001];
int ans;
void dfs(int cnum){
	if(cnum>ans) return;
	int mm=0;
	for(int i=1;i<10;i++){
		if(n[i]!=0)
			mm=i;
	}
	ans=min(ans,mm+cnum);
	if(mm<=3) return;
	for(int i=2;i<mm;i++){
		n[mm]--; n[i]++; n[mm-i]++;
		dfs(cnum+1);
		n[mm]++; n[i]--; n[mm-i]--;
	}
}
int main()
{
	freopen("B-small-attempt3.in","r",stdin);
	//freopen("AnsT.out","w",stdout);
	//ifstream fin("dict.out");
	ofstream fout("Ans.out");
	//FILE *fin=fopen("table.txt","r");
	//FILE *fout=fopen("Ans.out","w");
	cin>>T;
	for(int k=1;k<=T;k++){
		cin>>D; int get;
		for(int i=0;i<D;i++){
			cin>>get;
			n[get]++;
		}
		ans=9999; dfs(0);
		fout<<"Case #"<<k<<": "<<ans<<endl;
		for(int i=1;i<1001;i++)
			n[i]=0;
		cout<<k<<" ok"<<endl;
	}

	return 0;
}