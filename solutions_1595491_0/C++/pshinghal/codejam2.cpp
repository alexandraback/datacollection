#include<iostream>

using namespace std;

int main(){
	int n, t, s, p, curr, tot, max;
	cin>>t;
	for(int i = 1; i <= t; i++){
		tot = 0;
		cin>>n>>s>>p;
		for(int j = 0; j < n; j++){
			cin>>curr;
			max = curr / 3;
			if(curr % 3)
				max++;
			if(max >= p)
				tot++;
			else if(s){
				max = curr / 3;
				switch(curr % 3){
					case 0: if(max) max++; break;
					case 1: max++; break;
					case 2: max += 2;
				}
				if(max >= p){
					s--;
					tot++;
				}
			}
		}
		cout<<"Case #"<<i<<": "<<tot<<endl;
	}
	return 0;
}

