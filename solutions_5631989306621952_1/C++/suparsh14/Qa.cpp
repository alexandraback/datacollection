/*
 * Qa.cpp
 *
 *  Created on: Apr 16, 2016
 *      Author: suparsh14
 */

#include<bits/stdc++.h>

using namespace std;

int main(){

	int tc;
	scanf("%d ",&tc);
	char str[1001];
	for(int i=1;i<=tc;i++){
		deque<char> x;
		scanf("%s",str);
		int len=1;
		x.push_front(str[0]);
		while(str[len])
		{
			if(str[len]>=*x.begin()){
				x.push_front(str[len]);
			}
			else x.push_back(str[len]);
			len++;
		}

		printf("Case #%d: ",i);
		for(std::deque<char>::iterator it = x.begin(); it!=x.end(); ++it)
			std::cout<< *it;
		printf("\n");
	}



	return 0;
}



