#include<iostream>
#include<cstdio>
#include<vector>

using namespace std;

int Test,n;
int a[100];
int b[2000000];
int yy[2000010];
vector<int> vec[2000000];
const int N = (1<<20);

void print(int opt){
	for (int k = 0;k<20;++k){
		if ( ( opt & (1<<k) ) != 0 ){
			printf("%d ",a[k]);
		}
	}
	printf("\n");
}

void work(){
	cin >> n;
	for (int i = 0;i<n;++i){
		cin >> a[i];
	}

	for (int i = 0;i<N;++i) {
		b[i] = 0;
	}
	for (int i = 0;i<=2000000;++i){
		vec[i].clear();
	}
	for (int i = 1;i<N;++i){
		b[i] = b[i - (i & (-i))] + a[ yy[i & (-i)] ]; 
	}
	for (int i = 1;i<N;++i){
		vec[ b[i] ].push_back(i);
	}
	for (int i = 1;i<N;++i)
	if (vec[i].size()>=2){
		for (int j = 0;j<vec[i].size();++j)
		for (int k = j+1;k<vec[i].size();++k){
			if ( (vec[i][j] | vec[i][k]) == vec[i][j]+vec[i][k] ){
				print(vec[i][j]);
				print(vec[i][k]);
				return;
			}
		}
	}
}

int main(){
	freopen("C.in","r",stdin);
	freopen("C.out","w",stdout);
	cin >> Test;
	for (int i = 0;i<20;++i){
		yy[1<<i] = i;
	}
	for (int ii = 1;ii<=Test;++ii){
		printf("Case #%d: \n",ii);
		work();
	}
	return 0;
}
