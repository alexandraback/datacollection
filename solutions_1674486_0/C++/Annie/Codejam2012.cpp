#include<iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <fstream>
#include <sstream>
using namespace std;

//Round 1c
//Diamond inherience
ifstream fin("data.in");
ofstream fout("data.out");
int dag[1000][1000], n;

bool existDiamond()
{
//	cout<<"--------------------------"<<endl;
	for(int u = 0; u < n; ++ u){
		for(int v = 0; v < n; ++ v){
			if(dag[v][u] == 0) continue;
			for(int w = 0; w < n; ++ w) {
				if(dag[u][w] == 0) continue;
	//			cout << u<<" : "<< v <<" : "<<w<<endl;
				dag[v][w] += dag[v][u]*dag[u][w];
				if(dag[v][w] > 1) return true;
			}
		}
	}
	return false;
}

int main()
{
	int testcases;
	fin >> testcases;
	for(int i = 0; i < testcases; ++ i) {
		memset(dag, 0, sizeof dag);
		fin>>n;
		int m = 0;
		for(int j = 0; j < n; ++ j){
			fin >> m;
			int to;
			for(int k = 0; k < m; ++ k){
				fin >> to;
				dag[j][to-1] = 1;
			}
		}
		fout<<"Case #"<<i+1<<": ";
		if(existDiamond()) fout<<"Yes"<<endl;
		else fout<<"No"<<endl;
	}
	return 0;
}

// Round 1a

/**
*/

/*
ifstream fin("C.in");
ofstream fout("C.out");

void add1(string& a)
{
	int i = a.length()-1;
	while(i >=  0){
		if(i >= a.length()) return;
		else if(a[i] == '9'){
			a[i] = ' ';
			-- i; 
		}
		else if(a[i] == ' '){
			a[i] = a[i-1];
			++ i;
		}
		else{
			++ a[i];
			++ i;
		}
	}
}

int getCount(string a, string b)
{
	set<string> ans;
	string temp(a.length(), '0');
	while(temp <= b){
		string upper = temp;
		reverse(upper.begin(), upper.end());
		if(upper >= a){
			for(int i = 1; i < temp.length(); ++ i){
				if(temp[i] < a[0]) continue;
				if(temp[i] > b[0]) break;
				upper = temp.substr(0, i)+temp.substr(i);
				if(upper < 
		}
		add1(temp);
	}
}

/*
// Problem C
ifstream fin("C.in");
ofstream fout("C.out");

void add1(string& a)
{
	int i = a.length()-1;
	while(i >= 0){
		if(a[i] == '9') a[i] = '0';
		else {++ a[i]; break;}
		-- i;
	}
}

int main()
{
	int testcases = 0;
	set<string> cand;
	fin >> testcases;
	for(int i = 1; i <= testcases; ++ i){
		string a, b;
		fin >> a>> b;
		int ans = 0;
		while(a < b){
			cand.clear();
			for(int j = 1; j < a.length(); ++ j){
				if(a[j] < a[0])  continue;
				string temp = a.substr(j)+a.substr(0, j);
				if(temp > a && temp <= b) cand.insert(temp);
			}
			ans += cand.size();
			add1(a);
		}
		fout<<"Case #"<<i<<": "<<ans<<endl;
	}//while
	return 0;
}

/*
//Problem B
ifstream fin("B.in");
ofstream fout("B.out");


int main()
{
	int uns[11], sur[11];
	uns[0] = sur[0] = 0;
	uns[1] = sur[1] = 1;
	for(int i = 2; i <= 10; ++ i){
		uns[i] = i+2*(i-1);
		sur[i] = i+2*(i-2);
	}

	int testcases = 0, N, p, s, t;
	fin >> testcases;
	for(int i = 1; i <= testcases; ++ i){
		fin >> N >> s>> p;
		int ans = 0;
		for(int j = 0; j < N; ++ j){
			fin>>t;
			if(t >= uns[p]) ++ ans;
			else if(t >= sur[p] && s > 0){ ++ ans; --s;}
		}
		fout<<"Case #"<<i<<": "<<ans<<endl;
	}
}*/

/*
//Problem A.
ifstream fin("A.in", ios::in);
ofstream fout("result.txt");

class Googlerese
{
public:
	map<char, char> resolve(vector<string> org, vector<string> out)
	{
		map<char, char> resolved;
		vector<bool> exist(26, false);
		for(int i = 0; i < org.size(); ++ i){
			for(int j = 0; j < org[i].length(); ++ j){
				if(org[i][j] == ' ') continue;
				resolved[org[i][j]] = out[i][j];
				exist[out[i][j]-'a'] = true;
			}
		}
		char no1 = ' ', no2 = ' ';
		for(char i ='a'; i <= 'z'; ++ i){
			if(resolved.find(i) == resolved.end()) no1 = i;
			if(!exist[i-'a']) no2 = i;
		}
		resolved[no1] = no2;			
		return resolved;
	}
};
int main()
{
	string orgs[] = {"y qee", "ejp mysljylc kd kxveddknmc re jsicpdrysi", "rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd", "de kr kd eoya kw aej tysr re ujdr lkgc jv"};
	string outs[] = {"a zoo", "our language is impossible to understand","there are twenty six factorial possibilities","so it is okay if you want to just give up"};
	vector<string> out(outs, outs+4), org(orgs, orgs+4);
	Googlerese g;
	map<char, char> resolved = g.resolve(org, out);

	char orig[128];
	int i = 1;
	while(fin.getline(orig, 128)){
		if(orig[0] >= '0' && orig[0] <= '9'){i = 1; continue;}
		for(int i = 0; orig[i] != '\0'; ++ i){
			if(resolved.find(orig[i]) != resolved.end()) orig[i] = resolved[orig[i]];
		}
		fout<<"Case #"<<i<<": "<<orig<<endl;
		++ i;
	}
	return 0;
}*/