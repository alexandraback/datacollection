#include<iostream>
using namespace std;

long long t,k,c,s;

long long solve(long long tyl, long long akt, int poziom){
	
	if(poziom < c){
		if(akt == k)return solve((tyl + akt - 1) * k, akt, poziom + 1);
		return solve((tyl + akt - 1) * k, akt + 1, poziom + 1);
	}
	else return (tyl + akt);
}


int main(){
	
	cin >> t;
	
	for(int test = 1; test <= t; test++){
		cin >> k >> c >> s;
		cout << "Case #"<<test<<": ";
		
		if(c*s < k){
			cout <<"IMPOSSIBLE" << endl;
		}
		else{
			
			for(long long i = 1; i <= k; i += c){
				cout << solve(0,i,1) << " ";
			}	
		}
		cout << endl;
	}
	
	
	return 0;
}
