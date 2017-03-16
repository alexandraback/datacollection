#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <windows.h>
#include <mmsystem.h>
#pragma comment(lib,"WinMM.Lib")
using namespace std;
// nCr の計算
int combi(int n, int r)

{
    int child=1;
	int denom=1;
	int count=0;
	for(int i=n;i>n-r;i--){
		child*=i;
		count++;

	}
	for(int j=count;j>=1;j--){
		denom*=j;
	}
	if(denom!=0){
	return child/denom;
	}else{return 1;}
}

int func(int n){
	
	int k=(int)(sqrt((double)n)*0.5);//テキトーな予測
	int pyramid=k;
	//ピラミッドがなんだんめまであるか
	while(1){
		if(k*(2*k-1)<=n && (k+1)*(2*k+1)>=n){//ピラミッドのK段目にNがあること確定
			return k;
		}else if(k*(2*k-1)>n){
			k--;
		}else if((k+1)*(2*k+1)<n){
			k++;
		}
	}
}
double judge(int pyramid,int x,int y,int outer){
	int xysum=abs(x)+abs(y);
	if(xysum<=(1<<(pyramid-1))){
		return 1.0;
	}
	if(xysum>=(1<<(pyramid+1))){
		return 0.0;
	}
	if(y+1 >outer){return 0.0;}
	int sum=0;
	for(int i=0;y+1+i<xysum+1;i++){
		sum+=combi(xysum+1,y+1+i);
		
	}
	return (double)sum/double(1<<outer);
}
int main()
{
	unsigned long system_time_first= timeGetTime();
	//新たにファイルをオープンし、ストリームと結びつける
	freopen("B-small-attempt0.in", "r", stdin);
	//freopen("B-large.in", "r", stdin);
	//freopen("test.out", "w", stdout);
	freopen("B-.out", "w", stdout);

	int testcasenum;
	cin >> testcasenum;

	for (int t1 = 1; t1 <= testcasenum; ++t1) {
		printf("Case #%d: ", t1);
		int n,x,y;
		cin >>n>>x>>y;
		int pyramid=1;
		if(n>1){
			pyramid=func(n);
		}
		int outer=n-pyramid*(2*pyramid-1);
		double ans=judge(pyramid,x,y,outer);
		
		
		printf("%.lf\n",ans);
		//cout<<ans<<endl;

		
	}
	unsigned long system_time_second= timeGetTime();
//cout<<system_time_second-system_time_first<<"msec"<<endl;
	return 0;
}
