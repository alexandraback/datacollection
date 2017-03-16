#include<iostream>
#include<cmath>
using namespace std;
int cycle(int num, int digits){
	int divider = pow(10, digits - 1);
	int msd = num / divider;
	num %= divider;
	num *= 10;
	num += msd;
	return num;
}
int main(){
	int tc, digits;
	cin>>tc;
	int a, b, curr, next, tot;
	for(int i = 1; i <= tc; i++){
		cin>>a>>b;
		tot = 0;
		digits = (int) log10(a) + 1;
		for(curr = a; curr < b; curr++){
			next = cycle(curr, digits);
			while(next != curr){
				//cout<<next;
				if(next > curr && next <= b)
					tot++;
				next = cycle(next, digits);
			}
		}
		cout<<"Case #"<<i<<": "<<tot<<endl;
	}
	return 0;
}
