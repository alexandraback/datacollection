#include <iostream>
#include <sstream>
#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <set>
using namespace std;

pair<char,bool> calc(pair<char,bool> cur,char nxt){
	if (cur.first=='1')
		cur.first=nxt;
	else if (cur.first=='i'){
		if (nxt=='i') {
			cur.first='1';
			cur.second=!cur.second;
		}
		if (nxt=='j') {
			cur.first='k';
		}
		if (nxt=='k') {
			cur.first='j';
			cur.second=!cur.second;
		}
	}
	else if (cur.first=='j'){
		if (nxt=='j') {
			cur.first='1';
			cur.second=!cur.second;
		}
		if (nxt=='i') {
			cur.first='k';
			cur.second=!cur.second;
		}
		if (nxt=='k') {
			cur.first='i';
		}
	}
	else if (cur.first=='k'){
		if (nxt=='k') {
			cur.first='1';
			cur.second=!cur.second;
		}
		if (nxt=='j') {
			cur.first='i';
			cur.second=!cur.second;
		}
		if (nxt=='i') {
			cur.first='j';
		}
	}
	return cur;
}

string getans(){
	int l,x;
	char s[100000];
	scanf("%d%d%s",&l,&x,s);
	if (x>20) x-=(x-20)/4*4;
	pair<char,bool> cur=make_pair('1',true);
	int stage=0;
	for (int i=0;i<x;i++){
		for (int j=0;j<l;j++){
			cur=calc(cur,s[j]);
			// printf("%c %d\n",cur.first,cur.second);
			if (stage==0&&cur.first=='i'&&cur.second){
				stage=1;
				cur=make_pair('1',true);
			}
			if (stage==1&&cur.first=='j'&&cur.second){
				stage=2;
				cur=make_pair('1',true);
			}
		}
	}
	if (stage==2&&cur.first=='k'&&cur.second) return "YES";
	else return "NO";
}

int main(){
	int N;
	scanf("%d",&N);
	for (int r=1;r<=N;r++){
		printf("Case #%d: %s\n",r,getans().c_str());
	}
	return 0;
}