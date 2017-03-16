#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	freopen("in.txt" , "r" , stdin);
	freopen("out.txt" , "w" , stdout);
	int T;
	scanf("%d" , &T);
	double c , f , x;
	for(int h=0 ; h<T ; h++){
		printf("Case #%d: " , h+1);		
		cin >> c >> f >> x;
		double t = 0;
		int i = 0;
		while(true){
			if( x/(2.0+f*i) <= x/(2.0+f*(i+1)) + c/(2.0+f*i) ) break;
			t += c / (2.0 + f * i);
			i++;
		}
		t += x/(2.0+f*i);
		printf("%0.7f\n" , t);
	}
	return 0;
}
