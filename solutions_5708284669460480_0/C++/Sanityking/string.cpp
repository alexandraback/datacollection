#include <iostream>
#include <cstdio>
#include <cstring>
#include <fstream>
#include <algorithm>
#include <string>
using namespace std;

int t, k, l, s;
char lol[100];
string pos, tar;
FILE *inp, *out;

int highest, noof, tot, conut;

void roll(int x){
	if(x == s+1){
		++conut;
		noof = 0;
		string cur = "";
		for(int a = 1; a <= s; ++a) cur += lol[a];
		for(int a = 0; a <= s-tar.length(); ++a){
			//cout << a << " ";
			//cout << cur.substr(a, tar.length()) << endl;
			if(tar == cur.substr(a, tar.length())){
				++noof;
			}					
		}
		//cout << cur << " " << noof << endl;
		highest = max(highest, noof);
		tot += noof;
	}
	else{
		for(int a = 0; a < k; ++a){
			lol[x] = pos[a];
			roll(x+1);
		}
	}
	return;
}
	

int main(){
	//inp = fopen("a.in", "r");
	out = fopen("b.out", "w");
	fstream fin("a.in");
	//fstream fout("b.out");
	//fscanf(inp, "%d", &t);
	fin >> t;
	for(int ti = 1; ti <= t; ++ti){
		double ans = 0;
		double total = 0.0;
		//fscanf(inp, "%d%d%d", &r, &c, &w);
		fin >> k >> l >> s;
		fin >> pos;
		fin >> tar;
		sort(pos.begin(), pos.end());
		highest = 0;
		noof = 0, tot = 0, conut = 0;
		roll(1);
		//cout << highest << " " << tot << " " << conut << endl;
		ans = (double)highest - (double)tot/(double)conut;
		fprintf(out, "Case #%d: %llf\n", ti, ans);
		//printf("Case #%d: %llf\n", ti, ans);
	}
	//fclose(inp);
	fclose(out);
	return 0;
}
