/*
 * B.cpp
 *
 *  Created on: Apr 9, 2016
 *      Author: xing
 */

#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

//#define DEBUG

int solve(char* S){
	int rv=0;
	vector<char> str;

	for(int i = 0;S[i];++i){
		str.push_back(S[i]);
#ifdef DEBUG
		cout<<"i S[i] "<<i<<" "<<S[i]<<endl;
#endif
	}

	while(str.size()){
		while(str.size() && str.back() == '+')
			str.pop_back();

		if(!str.size())
			break;


		if(str[0] == '+'){
			rv++;
			for(int i = 0;i<str.size();++i)
				if(str[i] == '+')
					str[i] = '-';
				else
					break;
		}

		rv++;
		int len = str.size();
		for(int i = 0;i<len/2;++i){
			char tmp1, tmp2;
			tmp1 = str[i];
			tmp2 = str[len-i-1];
			if(tmp1 == '+')
				tmp1 = '-';
			else
				tmp1 = '+';

			if(tmp2 == '+')
				tmp2 = '-';
			else
				tmp2 = '+';

			str[i] = tmp2;
			str[len-i-1] = tmp1;
		}

		if(len%2 ==1){
			if(str[len/2] == '+')
				str[len/2] = '-';
			else
				str[len/2] = '+';
		}



	}

	return rv;
}

int main(){
	int T, rv;
	char S[200];
	cin>>T;
	gets(S);

	for(int i = 0;i<T;i++){
		gets(S);
		rv = solve(S);
		cout<<"Case #"<<(i+1)<<": "<<rv<<endl;
	}

}
