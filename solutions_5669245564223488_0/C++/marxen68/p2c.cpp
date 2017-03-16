/*
 * p2c.cpp
 *
 *  Created on: May 11, 2014
 *      Author: marxen68
 */

#include <iostream>
#include <fstream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

#define MOD 1000000007

string a[100];
long long int counter = 0;
int mod[26];

void initMod() {
	int i;
	for(i=0;i<26;i++) mod[i] = 0;
}

string abrev(string s) { // "a" is the same as "aa"
	int l = s.length();
	int i;
	string m;
	char c, p = s[0];
	m += p;
	for(i=1;i<l;i++) {
		c = s[i];
		if(c!=p) m += c;
		p = c;
	}
	return m;
}

void swap(string s[], int i, int j) {
	string tmp;
	tmp = s[i];
	s[i] = s[j];
	s[j] = tmp;
}

void model(string s) {
	int l = s.length();
	int i;
	vector<int> m;
	char c, p = s[0];
	m.push_back(p);
	for(i=1;i<l;i++) {
		c = s[i];
		if(c!=p) m.push_back(c);
		p = c;
	}

	initMod();
	for(i=0;i<26;i++) {
		mod[i] = count(m.begin(), m.end(), i + 97);
	}
}

int check(string s[], int l) {
	int i;
	string tmp = "";
	for(i=0;i<l;i++) {
		tmp += s[i];
	}
	model(tmp);
	for(i=0;i<26;i++) {
		if(mod[i] > 1) return 1;
	}
	return 0;
}

void permute(string s[], int i, int n)
{
//	cout << n << endl;
	int j;
	if (i == n) {
		if(check(s,n+1) == 0) counter++;
	} else {
		for (j = i; j <= n; j++)
		{
			swap(s,i,j);
			permute(s, i+1, n);
			swap(s,i,j);
		}
	}
}

void solve(int N, int tcase) {
	string tmp;
	counter = 0;
	int i = 0;
	int n = N;
	while(n>0) {
		cin >> tmp;
		a[i] = abrev(tmp);
//		cout << a[i] << endl;
		i++;
		n--;
	}
	permute(a,0,N-1);
	cout << "Case #" << tcase << ": " << counter%MOD << endl;
	return;
}

int main(void) {
	int T, N, tcase = 1;
	cin >> T;
	while(T>0) {
		cin >> N;
		solve(N,tcase);
		tcase++;
		T--;
	}
}



