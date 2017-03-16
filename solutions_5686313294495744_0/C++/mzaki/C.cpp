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


unsigned long long hash(string s1)
{
	vector<int> freq(26,0);
	for(int i=0;i<s1.length();i++)
		freq[s1[i]-'A']++;
    unsigned long long t=1,ret=0;
    for(int i=0; i<26; i++)
    {
        ret += t*freq[i];
        t=t*(unsigned long long)1000003;
    }
    return ret;
}

int rec(map<unsigned long long,unsigned long long> f,
		map<unsigned long long,unsigned long long> s,
		vector<unsigned long long> vf,
		vector<unsigned long long> vs,
		int j, int res) {
	if(j==vf.size()) {
		return res;
	}
	int r1 = rec(f,s,vf,vs,j+1,res);
	int r2 = 0;
	if(f[vf[j]]>1 && s[vs[j]]>1)	{
		res++;
		f[vf[j]]--;
		s[vs[j]]--;
		r2 = rec(f,s,vf,vs,j+1,res);
	}
	return max(r1,r2);
}
int main() {
	freopen("C.in","r",stdin);
	freopen("C.out","w",stdout);
	long long T,N,n,t;
	cin >>T;
	for(int i=0;i<T;i++) {
		cin>>N;
		string s1,s2;
		map<unsigned long long,unsigned long long> f;
		map<unsigned long long,unsigned long long> s;
		vector<unsigned long long> vf;
		vector<unsigned long long> vs;
		int maxF = 0, maxS = 0;
		while(N--) {
			cin>>s1>>s2;
			unsigned long long l1 = hash(s1);
			unsigned long long l2 = hash(s2);
			vf.push_back(l1);
			vs.push_back(l2);
			f[l1]++;
			s[l2]++;
		}
		int res = 0;
		 res = rec(f,s,vf,vs,0,0);
		// for(int j=0;j<vf.size();j++) {
		// 	if(f[vf[j]]>1 && s[vs[j]]>1)	{
		// 		res++;
		// 		f[vf[j]]--;
		// 		s[vs[j]]--;
		// 	}
		// }
		cout<<"Case #"<<(i+1)<<": "<<res<<endl;
	}
	return 0;
}