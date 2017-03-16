#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

int main() {
	int T; cin>>T;
	for (int testCase=1; testCase<=T; testCase++) {
		string str; cin>>str;
		vector<int> alphabet(150, 0);
		vector<int> output(10, 0); 
		string str0="ZERO", str1="ONE", str2="TWO", str3="THREE", str4="FOUR", str5="FIVE", str6="SIX", str7="SEVEN", str8="EIGHT", str9="NINE";
		
		
		for (int i=0; i<str.size(); i++) alphabet[str[i]]++;
		
		int tmp;
		//0
		tmp=alphabet['Z'];
		output[0]=tmp;
		for (int i=0; i<str0.size(); i++) alphabet[str0[i]]-=tmp;
		
		//2
		tmp=alphabet['W'];
		output[2]=tmp;
		for (int i=0; i<str2.size(); i++) alphabet[str2[i]]-=tmp;
		
		//4
		tmp=alphabet['U'];
		output[4]=tmp;
		for (int i=0; i<str4.size(); i++) alphabet[str4[i]]-=tmp;
		
		//5
		tmp=alphabet['F'];
		output[5]=tmp;
		for (int i=0; i<str5.size(); i++) alphabet[str5[i]]-=tmp;
		
		//6
		tmp=alphabet['X'];
		output[6]=tmp;
		for (int i=0; i<str6.size(); i++) alphabet[str6[i]]-=tmp;
		
		//7
		tmp=alphabet['S'];
		output[7]=tmp;
		for (int i=0; i<str7.size(); i++) alphabet[str7[i]]-=tmp;
		
		//8
		tmp=alphabet['G'];
		output[8]=tmp;
		for (int i=0; i<str8.size(); i++) alphabet[str8[i]]-=tmp;
		
		//3
		tmp=alphabet['T'];
		output[3]=tmp;
		for (int i=0; i<str3.size(); i++) alphabet[str3[i]]-=tmp;
		
		//1
		tmp=alphabet['O'];
		output[1]=tmp;
		for (int i=0; i<str1.size(); i++) alphabet[str1[i]]-=tmp;
		
		//9
		tmp=alphabet['I'];
		output[9]=tmp;
		for (int i=0; i<str9.size(); i++) alphabet[str9[i]]-=tmp;
		
		//ans
		cout<<"Case #"<<testCase<<": ";
		for (int i=0; i<output.size(); i++) for (int j=0; j<output[i]; j++) cout<<i;
		cout<<endl;
	}
	
	return 0;
}
