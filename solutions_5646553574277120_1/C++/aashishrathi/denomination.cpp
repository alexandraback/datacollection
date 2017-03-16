#include <bits/stdc++.h>

using namespace std;

int main(){
	int t;
	cin >> t;
	for(int num = 1; num <= t; num++){
		int c,d,v;
		cin >> c >> d >> v;
		int d_init[d];
		for(int i = 0; i < d; i++){
			cin >> d_init[i];
		}
		sort(d_init, d_init + d);
		int so_far = 0;
		int new_added = 0;
		int it = 0;
		while(so_far < v){
			if((so_far >= d_init[it] - 1) && (it < d)){
				so_far += c*d_init[it];
				it++;
			}
			else{
				so_far += c*(so_far+1);
				new_added++;
			}
		}
		cout << "Case #" << num << ": " << new_added << endl;
	}
}