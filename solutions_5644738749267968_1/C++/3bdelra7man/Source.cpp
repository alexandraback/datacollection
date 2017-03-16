#include <iostream>
#include <cstdio>
#include <algorithm>
#include <list>
#include <cstring>
#include <functional>
using namespace std;

list<double> Naomi , Ken , Naomi2 , Ken2;
bool Big(){
	list<double>::iterator it1 , it2;
	for (it1 = Naomi.begin(), it2 = Ken.begin(); it1 != Naomi.end(); it1++ , it2++)
		if( *it1 < *it2) return false;
	return true;
}
bool Big2(){
	list<double>::iterator it1 , it2;
	for (it1 = Ken2.begin(), it2 = Naomi2.begin(); it1 != Ken2.end(); it1++ , it2++)
		if( *it1 < *it2) return false;
	return true;
}
int main() {
	freopen("in.txt" , "r" , stdin);
	freopen("out.txt" , "w" , stdout);
	int T;
	scanf("%d" , &T);
	for(int h=0 ; h<T ; h++){
		printf("Case #%d: " , h+1);
		int n;
		scanf("%d" , &n);
		Naomi.clear();
		Ken.clear();
		Naomi2.clear();
		Ken2.clear();
		double x;
		for (int i = 0; i < n; i++){
			cin >> x;
			Naomi.push_back(x);
		}
		for (int i = 0; i < n; i++){
			cin >> x;
			Ken.push_back(x);
		}
		Naomi.sort( greater<double>() );
		Ken.sort( greater<double>() );
		Naomi2 = Naomi;
		Ken2 = Ken;
		while (!Big() && !Naomi.empty())
		{
			Naomi.pop_back();
			Ken.pop_front();
		}
		printf("%d" , Naomi.size());

		while (!Big2() && !Naomi2.empty())
		{
			Naomi2.pop_front();
			Ken2.pop_back();
		}
		printf(" %d\n" , n-Ken2.size());

	}
	return 0;
}
