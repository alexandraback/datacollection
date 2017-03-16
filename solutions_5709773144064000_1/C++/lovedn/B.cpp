//UESTC_L3

#include <stdexcept>
#include <cstdarg>
#include <iostream>
#include <fstream>
#include <exception>
#include <memory>
#include <locale>
#include <sstream>
#include <set>
#include <list>
#include <bitset>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <string>
#include <utility>
#include <cctype>
#include <climits>
#include <cassert>
#include <cstdio>
#include <cstring>
#include <map>
#include <cmath>
#include <algorithm>
#include <ctime>
#include <vector>
#include <queue>
#include <deque>
#include <cstdlib>
#include <stack>
#include <iterator>
#include <functional>
#include <complex>
#include <valarray>
using namespace std;

int main()
{
	int test;
	scanf("%d",&test);
	
	int ct=0;
	while(test--){
		double c,f,x;
		scanf("%lf%lf%lf",&c,&f,&x);
		
		double sum=0;
		double t=0;
		double cnt=0;
		
		while(sum<x){
			if(c>x){
				t+=(x-sum)/(2+f*cnt);
				sum=x;
			}
			else if(sum<c){
				t+=(c-sum)/(2+f*cnt);
				sum=c;
			}
			else{
				if((x-sum)/(2+f*cnt)<=(x-sum+c)/(2+f*(cnt+1))){
					t+=(x-sum)/(2+f*cnt);
					sum=x;
				}
				else {
					cnt++;
					sum-=c;
				}
			}
		}
		printf("Case #%d: %.7f\n",++ct,t);
	}
	return 0;
}