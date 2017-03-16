#include <bits/stdc++.h>
using namespace std;

typedef long long int lli;
typedef vector<int> vi;
typedef pair<int,int> pi;



int main(){
	int tc; cin >> tc;
	for(int t=1;t<=tc;t++){
		cout << "Case #" << t << ": ";
		int n; cin >> n;
		if(n==0){
			cout << "INSOMNIA\n";
			continue;
		} else {
			int digit[10], count = 0; memset(digit,0,sizeof(digit));
			lli current=0, holder;
			while(count!=10){
				current += n;
				holder = current;
				while(holder){
					if(digit[holder%10]==0){
						digit[holder%10] = 1;
						count++;
					}
					holder /= 10;
				}
			}
			cout << current << endl;
		}
	}
}