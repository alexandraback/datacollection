/*
 * dec.cpp
 *
 *  Created on: 12 kwi 2014
 *      Author: admin
 */
#include <cstdio>
#include <deque>
#include <set>
#include <algorithm>

using namespace std;

int main(){
	int t;
	scanf("%d",&t);
	for(int i=0;i<t;i++){
		int n;
		scanf("%d",&n);
		double naomi[n];
		double ken[n];
		for(int j=0;j<n;j++){
			scanf("%lf",&naomi[j]);
		}
		for(int j=0;j<n;j++){
			scanf("%lf",&ken[j]);
		}
		sort(naomi,naomi+n);
		sort(ken,ken+n);
		deque<double>nao;
		deque<double>ke;
		set<double>nao2;
		set<double>ke2;
		for(int j=0;j<n;j++){
			nao.push_back(naomi[j]);
			ke.push_back(ken[j]);
			nao2.insert(naomi[j]);
			ke2.insert(ken[j]);
		}
		//simulating deceitful war, naomi plays always the smallest, but says variously, ken plays variously
		int deceitful_score=0;
		for(int j=0;j<n;j++){
			if(nao.front()>ke.front()){
				deceitful_score++;
				nao.pop_front();
				ke.pop_front();
			}
			else{
				nao.pop_front();
				ke.pop_back();
			}
		}
		//simulating war, naomi always plays the biggest, ken either plays the smallest one still bigger from it,
		//or if such move is not possible, plays the lowest one
		int war_score=0;
		for(int j=0;j<n;j++){
			double naomi_move=*(nao2.begin());
			nao2.erase(nao2.begin());
			set<double>::iterator it=ke2.end();
			it--;
			double ken_biggest=*it;
			if(ken_biggest>naomi_move){
				ke2.erase(upper_bound(ke2.begin(),ke2.end(),naomi_move));
			}
			else{
				war_score++;
				ke2.erase(ke2.begin());
			}
		}
		printf("Case #%d: %d %d\n",i+1,deceitful_score,war_score);
	}



}



