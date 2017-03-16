// Round1C.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include "iostream"
#include "string"
#include "vector"
#include "string"
#include "string.h"
#include "stdio.h"

using namespace std;

int main()
{
	int T;
	cin>>T;
	for(int tc=0;tc<T;tc++)
	{
		int N,M,K;
		cin>>N>>M>>K;
		int best=K;
		for(int s=3;s<=N;s++) for(int t=3;t<=M;t++)
		{
			int cover=s*t;
			int used=s*2+t*2-4;
			best=min(best,used+max(0,K-cover));
		}
		for(int i=1;i*2+1<=min(N,M);i++)
		for(int s=0;s+i*2+1<=N;s++) for(int t=0;t+i*2+1<=M;t++)
		{
			int cover=(i*2+1+s)*(t+i*2+1)-i*(i+1)*2;
			int used=i*4+s*2+t*2;
			best=min(best,used+max(0,K-cover));
		}
		cout<<"Case #"<<tc+1<<": "<<best<<endl;
	}
	return 0;
}