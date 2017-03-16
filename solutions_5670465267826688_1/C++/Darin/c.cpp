#include <cstdlib>
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <sstream>
using namespace std;

long long min(long long a, long long b){
	return a<b?a:b;
}
string mult(string s1, string s2){
	int sign1,sign2=1;
	char x,y;
	if (s1.length() == 2){
		sign1 = -1;
		x = s1[1];
	} else {
		sign1 = 1;
		x = s1[0];
	}

	if (s2.length() == 2){
		sign2 = -1;
		y = s2[1];
	} else {
		sign2 = 1;
		y = s2[0];
	}

	string temp;
	if (x=='1' && y=='1') temp="1";
	if (x=='1' && y=='i') temp="i";
	if (x=='1' && y=='j') temp="j";
	if (x=='1' && y=='k') temp="k";

	if (x=='i' && y=='1') temp="i";
	if (x=='i' && y=='i') temp="-1";
	if (x=='i' && y=='j') temp="k";
	if (x=='i' && y=='k') temp="-j";
	
	if (x=='j' && y=='1') temp="j";
	if (x=='j' && y=='i') temp="-k";
	if (x=='j' && y=='j') temp="-1";
	if (x=='j' && y=='k') temp="i";

	if (x=='k' && y=='1') temp="k";
	if (x=='k' && y=='i') temp="j";
	if (x=='k' && y=='j') temp="-i";
	if (x=='k' && y=='k') temp="-1";

	int sign = sign1 * sign2;
	if (sign < 0){
		if (temp.length()==2){
			return temp.substr(1,1);
		} else {
			return "-"+temp;
		}
	} else 
		return temp;
}

string get_exp(string base, long long exp){
	if (exp == 1){
		return base;
	} else {
		string temp = get_exp(base, exp / 2);
		temp = mult(temp, temp);
		if (exp % 2 == 1){
			temp = mult(temp, base);
		}
		return temp;
	}
}
int main(){
	freopen("C-large.in","r",stdin);
	freopen("C-large.txt","w",stdout);

	int tests;
	cin >> tests;
	for (int test=1; test<=tests; test++){
		int l;
		long long x;
		cin >> l >> x;
		string ss;
		cin >> ss;
		//cout << l << " " << x << endl;
		//cout << ss << endl;
		string str="";
		long long p = min(30,x);
		for (int i=0; i<p;i++){
			str += ss;
		}

		string s1="1";
		for (int i=0; i<ss.length();i++){
			stringstream s;
			s << ss[i];
			string s2;
			s >> s2;
			//cout << "i: " << i << " s1? " << s1 << endl; 
			s1 = mult(s1, s2);
		}
		//cout << "s1: " << s1 << endl;
		s1 = get_exp(s1,x);
		//cout << "s1: " << s1 << endl;
		if (s1 != "-1"){
			cout << "Case #" << test << ": " << "NO" << endl;
			continue;			
		}
		//cout << mult("i",'j') << endl;
		//cout << str << endl;
		int index=0;
		//find i;
		s1 = "1";
		while (index<str.length() && s1 !="i"){
			stringstream ss;
			ss << str[index];
			string s2;
			ss >> s2;
			s1 = mult(s1, s2);
			index++;
		}
		//cout << index << endl;
		if (s1 != "i"){
			cout << "Case #" << test << ": " << "NO" << endl;
			continue;
		}

		//find j;
		s1 = "1";
		while (index<str.length() && s1 !="j"){
			//cout << s1 << " " << index << " " << str[index] << endl;
			stringstream ss;
			ss << str[index];
			string s2;
			ss >> s2;
			s1 = mult(s1, s2);
			//cout << s1 << endl;
			index++;
		}	
		//cout << index << endl;
		if (s1 != "j" || index==str.length()){
			cout << "Case #" << test << ": " << "NO" << endl;
			continue;
		}
		cout << "Case #" << test << ": " << "YES" << endl;
	}
}