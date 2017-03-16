#include<cstdio>
#include<algorithm>
#include<iostream>
using namespace std;
const int MAX = 1000 + 10;
double rec1[MAX], rec2[MAX];
int main(){
	int TN;
	scanf("%d", &TN);
	for(int casen = 1 ; casen <= TN ; casen++){
		int n;
		scanf("%d", &n);
		for(int i = 0 ; i < n ; i++){
			cin>>rec1[i];
		}
		for(int i = 0 ; i < n ; i++){
			cin>>rec2[i];
		}
		sort(rec1, rec1+n);
		sort(rec2, rec2+n);
		int l = 0, r = 0, cnt1 = 0, cnt2 = 0;
		for(int i = 0 ; i < n && l != n ; i++, l++, cnt1++){
			while(l < n && rec1[l] < rec2[i]){
				l++;
			}
			if(l >= n) break;
		}
		l = 0, r = n-1;
		for(int i = n-1 ; i >= 0 ; i--){
			if(rec1[i] >= rec2[r]){
				l++;
				cnt2++;
			}else r--;
		}
		printf("Case #%d: %d %d\n", casen, cnt1, cnt2);
	}
	return 0;
}
