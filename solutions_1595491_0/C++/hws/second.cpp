#include <iostream>
#include <fstream>
#include <string>
 
using namespace std;
int main(){
	
	ifstream cin("B-small-attempt0.in");
	ofstream cout("B-small-attempt0.out");

	int casees;
	int googlers;
	int time=0;
	int s,p,t;
	int result;
	cin >> casees;
	while(casees--){
		result=0;
		cin >> googlers;
		cin >> s >> p;
		for(int i=0;i<googlers;i++){
			cin >> t;
			if(t/3>=p){
				result++;
			}else if(t<p){
				continue;

			}else if((t-p)/2+1==p){
				result++;
			}else if((t-p)/2+2==p && s){
				result++;
				s--;
			}
		}
		cout << "Case #" << ++time << ": " << result << endl;

	}

	return 1;
}