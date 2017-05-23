#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<iomanip>
#define ll long long
//#define for(i,b,n) for(int (i)=(b);(i)<(n);(i)++)
#define endl "\n"
using namespace std;

vector<int>myvec;
int arr[200];
void add(int a, int sz){
	for(int i=1;i<=sz;i++){
		myvec.push_back(a);
	}
}

void func(string &s){
	for(int i=0;i<200;i++)arr[i]=0;
	for(int i=0;i<s.size();i++){
		arr[s[i]]++;
	}
	int two = arr['W'];
	add(2,two);
	arr['W']-=two; arr['T']-=two; arr['O']-=two;

	int eight = arr['G'];
	add(8,eight);
	arr['E']-=eight; arr['I']-=eight; arr['G']-=eight; arr['H']-=eight; arr['T']-=eight;

	int three = arr['H'];
	add(3,three);
	arr['T']-=three; arr['H']-=three; arr['R']-=three; arr['E']-=three; arr['E']-=three;

	int zero = arr['Z'];
	add(0,zero);
	arr['Z']-=zero; arr['E']-=zero; arr['R']-=zero; arr['O']-=zero;

	int six = arr['X'];
	add(6,six);
	arr['S']-=six; arr['I']-=six; arr['X']-=six;

	int four = arr['U'];
	add(4,four);
	arr['F']-=four; arr['O']-=four; arr['U']-=four; arr['R']-=four;

	int five = arr['F'];
	add(5,five);
	arr['F']-=five; arr['I']-=five; arr['V']-=five; arr['E']-=five;

	int seven = arr['V'];
	add(7,seven);
	arr['S']-=seven; arr['E']-=seven; arr['V']-=seven; arr['E']-=seven; arr['N']-=seven;

	int nine = arr['I'];
	add(9,nine);
	arr['N']-=nine; arr['I']-=nine; arr['N']-=nine; arr['E']-=nine;

	int one = arr['O'];
	add(1,one);
	arr['O']-=one; arr['N']-=one; arr['E']-=one;

	sort(myvec.begin(), myvec.end());
}


int main(){
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	ll t, answer = 0;
	cin>>t;
	for(ll j = 1; j <= t; j++){
		myvec.clear();
		string s;
		cin>>s;
		func(s);
		cout<<"Case #"<<j<<": ";
		for(int i=0;i<myvec.size();i++)cout<<myvec[i];
		cout<<endl;
	}
	
	return  0;
}