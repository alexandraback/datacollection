#include <iostream>
#include <fstream>
using namespace std;

void fill_t(char t[], const string &s, const string &r) {
	int l=s.size();
	for (int i=0;i<l;i++)
		t[s[i]]=r[i];
}

string translate(char t[],string s) {
	int l=s.size();
	for(int i=0;i<l;i++) { 
		s[i]=t[s[i]];
	}
	return s;
}

int main(int argc, char *argv[]) {
	char t[256]={0};
	string s1="ejp mysljylc kd kxveddknmc re jsicpdrysi";
	string r1="our language is impossible to understand";
	string s2="rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd";
	string r2="there are twenty six factorial possibilities";
	string s3="de kr kd eoya kw aej tysr re ujdr lkgc jv";
	string r3="so it is okay if you want to just give up";
	
	fill_t(t,s1,r1); fill_t(t,s2,r2); fill_t(t,s3,r3);
	t['y']='a'; t['e']='o'; t['q']='z';
	
	char missing=0;
	int mcount=0;
	bool done[256]={0};
	for(char i='a';i<='z';i++) { 
		if (!t[i]) { missing=i; mcount++; }
		done[t[i]]=true;
	}
	if (mcount==1) {
		char missing2;
		for(char i='a';i<='z';i++) { 
			if (!done[i]) missing2=i;
		}
		t[missing]=missing2;
	}
	
//	for(char i='a';i<='z';i++) cerr<<i<<"->"<<(t[i]==0?'?':t[i])<<endl;
	
	ifstream fin("A-small-attempt0.in");
	ofstream fout("A-small-attempt0.out");
	
	int n;
	fin>>n;
	string s;
		getline(fin,s);
	for(int i=0;i<n;i++) { 
		getline(fin,s);
		fout<<"Case #"<<i+1<<": "<<translate(t,s)<<endl;
	}
	fin.close();
	fout.close();
	return 0;
}

