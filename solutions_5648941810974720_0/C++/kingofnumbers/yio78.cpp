#include <iostream>
#include <vector>
#include <stdio.h>
#include <stack>
#include <queue>
#include <string>
using namespace std;
int rep[26];

int sol[10];
void get_zero(){
	string s="ZERO";
	for(int i=0;i<4;i++){
		rep[s[i]-'A']--;
	}
	sol[0]++;
}
void get_one(){
	string s="ONE";
	for(int i=0;i<3;i++){
		rep[s[i]-'A']--;
	}
	sol[1]++;
}
void get_two(){
	string s="TWO";
	for(int i=0;i<3;i++){
		rep[s[i]-'A']--;
	}
	sol[2]++;
}
void get_three(){
	string s="THREE";
	for(int i=0;i<5;i++){
		rep[s[i]-'A']--;
	}
	sol[3]++;
}

void get_four(){
	string s="FOUR";
	for(int i=0;i<4;i++){
		rep[s[i]-'A']--;
	}
	sol[4]++;
}
void get_five(){
	string s="FIVE";
	for(int i=0;i<4;i++){
		rep[s[i]-'A']--;
	}
	sol[5]++;
}

void get_six(){
	string s="SIX";
	for(int i=0;i<3;i++){
		rep[s[i]-'A']--;
	}
	sol[6]++;
}

void get_seven(){
	string s="SEVEN";
	for(int i=0;i<5;i++){
		rep[s[i]-'A']--;
	}
	sol[7]++;
}


void get_eight(){
	string s="EIGHT";
	for(int i=0;i<5;i++){
		rep[s[i]-'A']--;
	}
	sol[8]++;
}

void get_nine(){
	string s="NINE";
	for(int i=0;i<4;i++){
		rep[s[i]-'A']--;
	}
	sol[9]++;
}

int T;
string in;
int main(){
	freopen("eee.in","r",stdin);
	freopen("out.txt","w",stdout);
	cin>>T;
	for(int jj=1;jj<=T;jj++){
		cin>>in;
		for(int i=0;i<26;i++){
			rep[i]=0;
		}
		for(int i=0;i<10;i++){
			sol[i]=0;
		}
		for(int i=0;i<in.length();i++){
			rep[in[i]-'A']++;
		}
		while(rep['Z'-'A']){
			get_zero();
		}
		while(rep['W'-'A']){
			get_two();
		}
		while(rep['G'-'A']){
			get_eight();
		}
		while(rep['X'-'A']){
			get_six();
		}
		while(rep['T'-'A']){
			get_three();
		}
		while(rep['R'-'A']){
			get_four();
		}
		while(rep['F'-'A']){
			get_five();
		}
		while(rep['V'-'A']){
			get_seven();
		}
		while(rep['O'-'A']){
			get_one();
		}
		while(rep['N'-'A']){
			get_nine();
		}
		cout<<"Case #"<<jj<<": ";
		for(int i=0;i<10;i++){
			while(sol[i]){
				sol[i]--;
				cout<<i;
			}
		}
		cout<<endl;
	}
}