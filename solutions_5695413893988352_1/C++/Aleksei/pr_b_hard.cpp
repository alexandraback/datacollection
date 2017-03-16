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

bool match(const string& a, int val){
	int n = a.size();
	for(int i=0; i<n; i++){
		int last = val%10;
		bool ok = a[n-i-1]=='?' || ((a[n-i-1]-'0')==last);
		if(!ok) return false;
		val/=10;
	}
	return true;
}

long long mindiff;
long long reza;
long long rezb;

long long toLong(const string& a){
	long long rez = 0LL;
	int n = a.size();
	for(int i=0; i<n; i++){
		rez*=10;
		rez+=(a[i]-'0');
	}
	return rez;
}

int compare(const string& a, const string& b, const int idx){
	int sign = 0;
	for(int i=0; i<idx; i++){
		if(a[i]>b[i]){ sign = 1; break; }
		else if(a[i]<b[i]){ sign = -1; break; }
	}
	return sign;
}

void ffind(string& a, string& b, int idx){
	int n = a.size();
	if(idx>=n){
		long long aa = toLong(a);
		long long bb = toLong(b);
		if(mindiff==-1){
			mindiff = abs(aa-bb);
			reza = aa;
			rezb = bb;
		}else if(abs(aa-bb)<mindiff){
			mindiff = abs(aa-bb);
			reza = aa;
			rezb = bb;
		}else if(abs(aa-bb)==mindiff){
			if(aa<reza || (aa==reza && bb<rezb)){
				mindiff = abs(aa-bb);
				reza = aa;
				rezb = bb;
			}
		}
		return;
	}
	if(a[idx]!='?' && b[idx]!='?'){
		ffind(a,b,idx+1);
	}else if(a[idx]=='?' && b[idx]!='?'){
		int sign = compare(a,b,idx);
		if(sign==0){
			a[idx] = b[idx];
			ffind(a,b,idx+1);
			if(b[idx]+1<='9'){
				a[idx] = b[idx]+1;
				ffind(a,b,idx+1);
			}
			if(b[idx]-1>='0'){
				a[idx] = b[idx]-1;
				ffind(a,b,idx+1);
			}
		}else if(sign<0){
			a[idx] = '9';
			ffind(a,b,idx+1);
		}else if(sign>0){
			a[idx] = '0';
			ffind(a,b,idx+1);
		}
		a[idx] = '?';
	}else if(a[idx]!='?' && b[idx]=='?'){
		int sign = compare(a,b,idx);
		if(sign==0){
			b[idx] = a[idx];
			ffind(a,b,idx+1);
			if(a[idx]+1<='9'){
				b[idx] = a[idx]+1;
				ffind(a,b,idx+1);
			}
			if(a[idx]-1>='0'){
				b[idx] = a[idx]-1;
				ffind(a,b,idx+1);
			}
		}else if(sign>0){
			b[idx] = '9';
			ffind(a,b,idx+1);
		}else if(sign<0){
			b[idx] = '0';
			ffind(a,b,idx+1);
		}
		b[idx] = '?';
	}else{
		int sign = compare(a,b,idx);
		if(sign==0){
			a[idx] = '0';
			b[idx] = '0';
			ffind(a,b,idx+1);
			a[idx] = '1';
			b[idx] = '0';
			ffind(a,b,idx+1);
			a[idx] = '0';
			b[idx] = '1';
			ffind(a,b,idx+1);
		}else if(sign==-1){
			a[idx] = '9';
			b[idx] = '0';
			ffind(a,b,idx+1);
		}else if(sign==1){
			a[idx] = '0';
			b[idx] = '9';
			ffind(a,b,idx+1);
		}
		a[idx] = '?';
		b[idx] = '?';
	}
}

int main(){
	ifstream cin("input.txt");
	ofstream cout("output.txt");
	int ntests;
	cin>>ntests;
	for(int testnum=0; testnum<ntests; testnum++){
		string a, b;
		cin>>a>>b;
		assert(a.size()==b.size());
		int n = a.size();
		reza = -1LL;
		rezb = -1LL;
		mindiff = -1LL;
		ffind(a,b,0);
		cout<<"Case #"<<testnum+1<<": "<<setfill('0') << setw(n)<<reza<<' '<<setfill('0') << setw(n)<<rezb<<endl;
	}
	return 0;
}
