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
//手数を返す
int func(int a,int* mote,int i,int n){
	//cout<<"a="<<a<<"i="<<i<<endl;
	if(a==1){return n;}
	if(i>=n){return 0;}
	int answer=0;
	if(a>mote[i]){//食べられる
		a+=mote[i];//吸収
		answer+=func(a,mote,i+1,n);
	}else{//食べられない
		//足した場合と、すべて消した場合　どちらが良いのか
		int temp=func(2*a-1,mote,i,n);
		temp++;
		if(temp>n-i){
			return n-i;
		}else{//すべて消すのよりも食べるほうがいい場合
			return temp;
		}
	}
	return answer;
}

int main()
{
	unsigned long system_time_first= timeGetTime();
	//新たにファイルをオープンし、ストリームと結びつける
	//freopen("test.in", "r", stdin);
	freopen("A-large.in", "r", stdin);
	//freopen("test.out", "w", stdout);
	freopen("A-large.out", "w", stdout);

	int testcasenum;
	cin >> testcasenum;

	for (int t1 = 1; t1 <= testcasenum; ++t1) {
		printf("Case #%d: ", t1);
		int a,n;
		cin >> a>>n;
		
		int* mote=new int[n];
		for(int i=0;i<n;i++){
			cin>>mote[i];
		}
		
		sort(mote,mote+n);//小さい順に並べた
		int asn=0;
		asn=func(a,mote,0,n);
		cout<<asn<<endl;
		
	}
	unsigned long system_time_second= timeGetTime();
//cout<<system_time_second-system_time_first<<"msec"<<endl;
	return 0;
}
