#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>
#include<cmath>

using namespace std;

int task,n;
int a[1000],b[2000005];
int yy[2000010];
const int N = (1<<20);
vector<int> v[2000010];

void print(int opt){
	for (int k = 0;k<20;++k)
      {
		if (( opt & (1<<k) )!= 0)
            {
			printf("%d ",a[k]);
		}
	}
	printf("\n");
}

void work(){
	cin >> n;
	for (int i = 0;i<n;++i)
      {
		cin >> a[i];
	}

	for (int i = 0;i<N;++i) 
      {
		b[i] = 0;
	}
	for (int i = 0;i<=2000000;++i)
      {
		v[i].clear();
	}
	for (int i = 1;i<N;++i)
      {
		b[i] = a[ yy[i & (-i)] ] + b[i-(i& (-i))]; 
	}
	for (int i = 1;i<N;++i)
      {
		v[ b[i] ].push_back(i);
	}
	for (int i = 1;i<N;++i)
	if (v[i].size()>=2){
		for (int j=0;j<v[i].size();++j)
		for (int k=j+1;k<v[i].size();++k)
            {
			if ((v[i][j]|v[i][k]) == v[i][j]+v[i][k])
                  {
				print(v[i][j]);
				print(v[i][k]);
				return;
			}
		}
	}
}

int main(){
	freopen("C.in","r",stdin);
	freopen("C.out","w",stdout);
	cin >> task;
	for (int i = 0;i<20;++i)
      {
		yy[1<<i] = i;
	}
	for (int cnt = 1;cnt<=task;++cnt)
      {
		printf("Case #%d: \n",cnt);
		work();
	}
	return 0;
}
