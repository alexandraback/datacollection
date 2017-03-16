#include <iostream>
#include <stdio.h>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <math.h>
#include <string>

using namespace std;

int f[26];

void init() {
	for(int i=0;i<26;i++)	f[i] = 0;
}

int toInt(string s) {
	int value = atoi(s.c_str()); 
	return value;
}
vector<int> get(string s) {
	vector<int> v;
	int c =0;
	int i[2];
	for(int j=0;j<s.length();j++) {
		if(s[j]=='?') {
			i[c++]=j;
		}
	}
	if(c==s.length())	return v;
	if(c==0)	{
		v.push_back(toInt(s));
	}
	else if(c==1) {
		for(int j=0;j<10;j++) {
			s[i[0]] = '0'+j;
			//cout<<s<<endl;
			v.push_back(toInt(s));
		}
	}
	else {
		for(int j=0;j<10;j++) {
			for(int k=0;k<10;k++) {
				s[i[0]] = '0'+j;
				s[i[1]] = '0'+k;
				v.push_back(toInt(s));				
			}
		}
	}
	return v;
}

int main() {
	freopen("B.in","r",stdin);
	freopen("B.out","w",stdout);
	long long T,N,n,t;
	cin >>T;
	string c ="";
	string j ="";
	int cc = 0, jj = 0;
	for(int i=0;i<T;i++) {
		cin>>c>>j;
		int rc=0,rj=0;
		vector<int> cv = get(c);
		vector<int> jv = get(j);
		sort(cv.begin(),cv.end());
		sort(jv.begin(),jv.end());
		int i1 = 0;
		int i2 = 0;
		int min = 10000;
		if(cv.size()==0 && jv.size()==0) {
			rc = 0;
			rj = 0;
		} 
		else if(cv.size()==0) {
			rj = jv[0];
			rc = jv[0];
		}
		else if(jv.size()==0) {
			rc = cv[0];
			rj = cv[0];
		}
		else {
		for(int l=0;l<cv.size();l++) {
			for(int k=0;k<jv.size();k++) {
				if(abs(cv[l]-jv[k])<min) {
					rc = cv[l];
					rj = jv[k];
					min = abs(cv[l]-jv[k]);
				}
			}
		}
			
		}

		cout<<"Case #"<<(i+1)<<": ";
		if(rc<10)	{
			if(c.length()==2) {
				cout<<"0";
			}
			else  if(c.length()==3) {
				cout<<"00";
			}
		}
		else if(rc<100 && c.length()==3)	cout<<"0";
		cout<<rc<<" ";
		if(rj<10 && j.length()==3)	cout<<"00";
		else if(rj<10 && j.length()==2)	cout<<"0";
		else if(rj<100 && j.length()==3)	cout<<"0";
		cout<<rj<<endl;
	}
	return 0;
}