#include <bits/stdc++.h>
using namespace std;
int a[1000];
int main(){
	int t;
	cin >> t;
	for(int ii = 1; ii <= t; ii++ ){
		int c, d, v, cnt=0;
		cin >> c >> d >> v;
		
		int i;
		for( i = 0;i < d; i++)
			cin >> a[i];
		sort( a, a + d );

		int place = 0;
		int money = 0;
		while( money < v ){
			if(place == d || money < a[place] - 1){
				cnt++;
				money = money + ( money + 1) * c;
			}
			else {
				money += a[place] * c;
				place++;
			}
		}
		printf("Case #%d: %d\n",ii,cnt);
	}
}