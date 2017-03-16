#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <list>
#include <string>
#include <algorithm>
#include <set>
#include <cmath>
#include <vector>
#include <map>
#include <iterator>
#include <sstream>
#include <fstream>
#include <list>
#include <set>
#include <stack>
#include <bitset>
#include <ctime>
 
#pragma comment(linker, "/STACK:256000000")
 
#define EPS 1e-7
 
const long double PI = 3.1415926535897932384626433832795;
 
using namespace std;
 
int aabs(int a){
	if (a<0) return -a;
	return a;
}

ifstream dictionary;
const int N_WORDS = 521196;
map<string, int> words;
string wordsList[N_WORDS];
char SPECIAL_CHAR = '#';
int MAX_WORD_LENGTH;

vector <vector <pair<int,int> > > masks;

void init(){
	dictionary = ifstream("garbled_email_dictionary.txt");
	MAX_WORD_LENGTH = 0;
	for (int i=0;i<N_WORDS;i++){
		getline(dictionary,wordsList[i]);
		MAX_WORD_LENGTH=max(MAX_WORD_LENGTH,(int)wordsList[i].length());
	}
	masks.resize(MAX_WORD_LENGTH+1);
	for (int i=0;i<=MAX_WORD_LENGTH;i++){
		for (int j=0;j<(1<<i);j++){
			int nt=0;
			int lastSpecial=-100;
			bool flag = true;
			for (int k=0;k<i;k++){
				if ((j&(1<<k))==0){
					if (k-lastSpecial<5){
						flag = false;
						break;
					}
					lastSpecial=k;
					nt++;
				}
			}
			if (flag){
				masks[i].push_back(make_pair(j,nt));
			}
		}
	}
	for (int i=0;i<N_WORDS;i++){
		string s = wordsList[i];
		int sl = s.length();
		for (int j=0;j<masks[sl].size();j++){
			string st=s;
			int mask = masks[sl][j].first;
			for (int k=0;k<sl;k++){
				if ((mask&(1<<k))==0){
					st[k]=SPECIAL_CHAR;
				}
			}
			if (words.find(st)==words.end()){
				words[st]=masks[sl][j].second;
			}
			else{
				words[st]=min(words[st],masks[sl][j].second);
			}
		}
	}
	//cout<<words.size();
}

int solveOne(){
	string s;
	cin>>s;
	int n=s.length();
	const int MAX_LENGTH = 60;
	int g[60][60];
	memset(g,255,sizeof(g));
	for (int i=0;i<n;i++){
		for (int j=1;j<=MAX_WORD_LENGTH;j++){
			string sp = s.substr(i,j);
			if (sp.size()!=j) continue;
			int spl = sp.length();
			for (int mn=0;mn<masks[spl].size();mn++){
				string st=sp;
				int mask = masks[spl][mn].first;
				for (int k=0;k<spl;k++){
					if ((mask&(1<<k))==0){
						st[k]=SPECIAL_CHAR;
					}
				}
				map<string, int>::iterator it = words.find(st);
				if (it!=words.end()){
					if (g[i][i+j]<0){
						g[i][i+j]=it->second;
					}
					else{
						g[i][i+j]=min(g[i][i+j],it->second);
					}
				}
			}
			
		}
	}

	const int INF = 1000000000;
	n++;
	vector<int> d (n, INF),  p (n);
	d[0] = 0;
	vector<char> u (n);
	for (int i=0; i<n; ++i) {
		int v = -1;
		for (int j=0; j<n; ++j){
			if (!u[j] && (v == -1 || d[j] < d[v])){
				v = j;
			}
		}
		if (d[v] == INF){
			break;
		}
		u[v] = true;
 
		for (size_t j=0; j<n; ++j) {
			int to = j,
				len = g[v][j];
			if (len>=0 && d[v] + len < d[to]) {
				d[to] = d[v] + len;
				p[to] = v;
			}
		}
	}
	return d[n-1];
}

void solveAll(){
	init();
	int t;
	cin>>t;
	for (int i=1;i<=t;i++){
		cout<<"Case #"<<i<<": "<<solveOne()<<"\n";
		//cout<<"Case #"<<i<<": "; solveOne(); cout<<"\n";
	}
}

int main(){
	freopen("input.txt","rt",stdin);
	freopen("output.txt","wt",stdout);
	cout.setf(ios::fixed);
	cout.precision(6);
	solveAll();
	return 0;
}