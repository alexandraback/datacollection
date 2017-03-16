// codejam.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
void q() {
	int testCases;
	cin>>testCases;
	int t[1001][10];
	for (int test = 1; test <= testCases; test++) {
		string temp;
		cin>>temp;
		int p=0;
		int index = 0;
		while (temp[index] != '/') {
			p *= 10;
			p += temp[index]-'0';
			index++;
		}
		index++;
		int q = 0;
		while (index < (int)temp.size()) {
			q *= 10;
			q += temp[index]-'0';
			index++;
		}
		//判断q
		if ((q & (q-1)) != 0) {
			cout<<"Case #"<<test<<": impossible"<<endl;
		} else {
			//
			t[1][0] = 0;
			//先找出来q究竟是2的多少次方
			int sq = 0;
			while ( ((1<<sq) & q)==0) sq++;
			int ti = 1;
			for (int i=1; i<=sq; i++) {
				t[1][i] = i;
				ti *= 2;
				for (int j=2; j<ti; j++) {
					if (j%2 == 0) {
						t[j][i] = t[j/2][i-1] + 1;
					} else {
						t[j][i] = min(t[j/2][i-1],t[j/2+1][i-1])+1;
					}
				}
				t[ti][i] = 0;
			}
			cout<<"Case #"<<test<<": "<<t[p][sq]<<endl;

		}
	}

};
long long lowest(long long big, long long small) {
	if (big%small == 0) return small;
	return lowest(small, big %small);
}
void q1() {
	int testCases;
	cin>>testCases;
	for (int test = 1; test <= testCases; test++) {
		string temp;
		cin>>temp;
		long long p=0;
		int index = 0;
		while (temp[index] != '/') {
			p *= 10;
			p += temp[index]-'0';
			index++;
		}
		index++;
		long long q = 0;
		while (index < (int)temp.size()) {
			q *= 10;
			q += temp[index]-'0';
			index++;
		}
		long long low = lowest(q,p);
		p /= low;
		q /= low;
		//判断q
		if ((q & (q-1)) != 0) {
			cout<<"Case #"<<test<<": impossible"<<endl;
		} else {
			int times = 0;
			while (p < q) {
				times ++;
				q /= 2;
			}
			cout<<"Case #"<<test<<": "<<times<<endl;
		}
	}

};
int main() {
	freopen("data.in","r",stdin);
	freopen("data.out","w",stdout);
	q1();
	fclose(stdin);
	fclose(stdout);
	return 0;
}



