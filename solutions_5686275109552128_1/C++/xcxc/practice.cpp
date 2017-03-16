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
int check(int mm){
	int ans=0;
	for(int i=1000;i>0;i--){
		if(i==mm) break;
		if(n[i]==0) continue;
		ans+=i/mm*n[i];
		if(i%mm==0)
			ans-=n[i];
	}
	return ans+mm;
}
int main()
{
	freopen("B-large.in","r",stdin);
	freopen("Ans.out","w",stdout);
	//ifstream fin("dict.out");
	//ofstream fout("Ans.out");
	//FILE *fin=fopen("table.txt","r");
	//FILE *fout=fopen("Ans.out","w");
	cin>>T;
	for(int k=1;k<=T;k++){
		cin>>D; int get;
		for(int i=0;i<D;i++){
			cin>>get;
			n[get]++;
		}
		int ans=9999;
		for(int i=1;i<=1000;i++){
			ans=min(ans,check(i));
		}
		cout<<"Case #"<<k<<": "<<ans<<endl;
		for(int i=1;i<1001;i++)
			n[i]=0;
	}

	return 0;
}