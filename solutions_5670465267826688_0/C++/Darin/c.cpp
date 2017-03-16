#include <cstdlib>
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>

using namespace std;

int min(int a, int b){
	return a<b?a:b;
}
string mult(string s1, char y){
	int sign1,sign2=1;
	char x;
	if (s1.length() == 2){
		sign1 = -1;
		x = s1[1];
	} else {
		sign1 = 1;
		x = s1[0];
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

int main(){
	freopen("C-small-attempt0.in","r",stdin);
	freopen("C-small-attempt0.txt","w",stdout);

	int tests;
	cin >> tests;
	for (int test=1; test<=tests; test++){
		int l,x;
		cin >> l >> x;
		string ss;
		cin >> ss;
		string str="";
		
		for (int i=0; i<min(2000000,x);i++){
			str += ss;
		}
		string s1="1";
		for (int i=0; i<str.length();i++)
			s1 = mult(s1, str[i]);
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
			s1 = mult(s1, str[index]);
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
			s1 = mult(s1, str[index]);
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