#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>

using namespace std;

const int MAXN = 1000000 + 100;
const int MAXM = 5000 + 100;
const int inf = 2000000;

string dictionary[MAXN];
int dicsize = 0;

int prec[MAXM][10];
string s;

int df;
pair<int, int> cmp(const string & a, int x, int ld){
	int df = 0;
	if(a.size() > x+1)
		return  (pair<int, int>){-3, -3};
		
	int lastdiff = ld;
	int diff = inf;
	for(int i = 0; i < a.size(); i++)
		if( a[a.size() - 1 - i] != s[x - i]){
			df++;
			diff = lastdiff - (x-i);
			if(diff < 5)
				return  (pair<int, int>){-3, -3};
			lastdiff = x - i;
			}
	return (pair<int, int>){lastdiff, df};
	}

int sol(int x, int ld){
	if(x < 0)
		return 0;
		
	if(prec[x][ld] != -1)
		return prec[x][ld];
	
	int minchanges = inf;
	for(int i = 0; i < dicsize; i++){
		pair<int, int> dff = cmp(dictionary[i], x, ld);
		
		//~ cout << dictionary[i] << " " << x << " " << dff.first << " " << ld << " " << df << endl;
		if(dff.first != -3)
			minchanges = min(minchanges, dff.second + sol(x - dictionary[i].size(), (dff.first - (x - dictionary[i].size()) > 5 ? 6 + (x - dictionary[i].size()) : dff.first) ) );
		//cout << "| " << x << " " << ld << " " << minchanges << endl;
		}
	prec[x][ld] = minchanges;
	//~ cout << x << " " << ld << " " << minchanges << endl;
	return minchanges;
	}

int solve(){
	fill((int*)prec, (int*)prec + 10*MAXM, -1);
	
	cin >> s;
	int answ = sol(s.size()-1, s.size()-1 + 6);
	return answ;
	}

int main(){
	string t;
	ifstream zodynas;
  zodynas.open ("garbled_email_dictionary.txt");
  for(dicsize = 0; zodynas >> t; dicsize++)
		dictionary[dicsize] = t;
  zodynas.close();
  
	int testcases;
	scanf("%d", &testcases);
	
	int n, m;
	for(int testcase = 0; testcase < testcases; testcase++){
		printf("Case #%d: %d\n", testcase+1, solve());
		}
	
	
	return 0;
}
