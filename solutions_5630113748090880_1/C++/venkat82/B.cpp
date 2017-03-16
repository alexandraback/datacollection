#include <bits/stdc++.h>
using namespace std;
int a[120][60];
int cnt[3000];
vector<int> v; 
int main(){
	int test;
	scanf("%d", &test);
	for (int w = 1; w <= test; w++) {
		printf("Case #%d:", w);
		int n;
		cin>>n;
		v.clear();
		for (int i = 1; i <= 2500; i++) cnt[i] = 0;
		for (int i = 0; i < 2 * n - 1; i++) {
			for (int j = 0; j < n; j++) {
				scanf("%d", &a[i][j]);
				cnt[a[i][j]]++;
			}
		}
		for (int i = 1; i <= 2500; i++) if(cnt[i] % 2 == 1) v.push_back(i);
		sort(v.begin(), v.end()); 
		for (int i = 0; i < int(v.size()); i++) cout<<" "<<v[i];
		cout<<endl;
	}
}