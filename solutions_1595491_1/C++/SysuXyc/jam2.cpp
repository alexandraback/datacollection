#include<fstream>
#include<iostream>
#include<algorithm>
#include<memory.h>
using namespace std;

int main(){
	ifstream input("B-large.in");
	ofstream output("B-large.out");
	int T;
	input >> T;
	for(int tt=1;tt <= T;tt++){
		int n,s,p;
		input >> n >> s >> p;
		int tmp;
		int a=0,b=0;
		for(int i=0;i < n;i++){
			input >> tmp;
			if((tmp/3 == p-2 && tmp-tmp/3*3 == 2) || (tmp/3 == p-1 && tmp-tmp/3*3 == 0 && tmp/3 >= 1))
				a++;
			if(tmp/3 >= p || (tmp/3 == p-1 && tmp-tmp/3*3 >= 1))
				b++;
		}
		int ans;
		if(a <= s)
			ans=a+b;
		else 
			ans=s+b;
		output << "Case #" << tt << ": " << ans << endl;
	}
	
}