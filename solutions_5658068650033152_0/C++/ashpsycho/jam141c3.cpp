#include <iostream>
#include <fstream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <string>
#include <cmath>
#include <queue>
using namespace std;
int main(){
	int t,te,n,m,k,i,j,ans;
	ifstream f1;
	ofstream f2;
	f1.open("input.txt");
	f2.open("output.txt");
	f1>>t;
	for(te=0;te<t;te++){
		f1>>n>>m>>k;
		if(n<m)swap(n,m);
		if(m<3)ans=k;
		else{
			if(m==3){
				switch(n){
					case 3: {
						if(k<5)ans=k;else ans=k-1;
						break;
					}
					case 4: {
						if(k<5)ans=k;else if(k<8)ans=k-1;else ans=k-2;
						break;
					}					
					case 5:{
						if(k<5)ans=k;else if(k<8)ans=k-1;else if(k<11) ans=k-2; else ans=k-3;
						break;
					} 
					case 6:{
						if(k<5)ans=k;else if(k<8)ans=k-1;else if(k<11) ans=k-2; else if(k<14) ans=k-3;else ans=k-4;
						break;
					} 
				}
			}
			if(m==4){
					if(n==4){
						switch(k){
							case 1: {ans=1;break;}
							case 2: {ans=2;break;}
							case 3: {ans=3;break;}
							case 4: {ans=4;break;}
							case 5: {ans=4;break;}
							case 6: {ans=5;break;}
							case 7: {ans=6;break;}
							case 8: {ans=6;break;}
							case 9: {ans=7;break;}
							case 10: {ans=7;break;}
							case 11: {ans=8;break;}
							case 12: {ans=8;break;}
							case 13: {ans=9;break;}
							case 14: {ans=10;break;}
							case 15: {ans=11;break;}
							case 16: {ans=12;break;}
						}
					}
					else if(n==5){
						cout<<n<<" "<<m<<" "<<k<<"\n";
						switch(k){
							case 1: {ans=1;break;}
							case 2: {ans=2;break;}
							case 3: {ans=3;break;}
							case 4: {ans=4;break;}
							case 5: {ans=4;break;}
							case 6: {ans=5;break;}
							case 7: {ans=6;break;}
							case 8: {ans=6;break;}
							case 9: {ans=7;break;}
							case 10: {ans=7;break;}
							case 11: {ans=8;break;}
							case 12: {ans=8;break;}
							case 13: {ans=9;break;}
							case 14: {ans=9;break;}
							case 15: {ans=10;break;}
							case 16: {ans=10;break;}
							case 17: {ans=11;break;}
							case 18: {ans=12;break;}
							case 19: {ans=13;break;}
							case 20: {ans=14;break;}
					}
				}
			}
		}
		cout<<n<<" "<<m<<" "<<k<<"\n";
		cout<<"Case #"<<te+1<<": "<<ans<<"\n";
		f2<<"Case #"<<te+1<<": "<<ans<<"\n";
	}
	return 0;
}
