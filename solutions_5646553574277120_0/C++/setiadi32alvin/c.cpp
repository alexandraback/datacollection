#include<cstdio>
#include<iostream>
#include<cstring>
#include<cstdlib>
#include<map>
#include<utility>
#include<stack>
#include<queue>
#include<cmath>
#include<algorithm>
#include<vector>
#include<string>

#define LL long long
#define ii pair<int,int>
#define MP make_pair
using namespace std;
int t;
int ar[111],c,d,v,A[33],ans;
map<pair<int,int>,bool> mp;

priority_queue<pair<int,pair<int,int> > > q;

int cariBaru(int val,int bit){
	for(int i=v;i-val>=0;i--)
		if(bit&(1<<(i-val)))
			bit|=(1<<i);
	return bit;
}
void printBit(int bit){
	for(int i=0;i<=v;i++){
		printf("%d",bit%2);
		bit/=2;
	}
}
int cari(){
	mp.clear();
	while(!q.empty())	q.pop();
	int a,b;
	a = b= 0;
	for(int i=0;i<=v;i++)
		if(A[i]==1)	a|=(1<<i);
	for(int i=0;i<d;i++)
		b|=(1<<(ar[i]));
	q.push(MP(0,MP(b,a)));
	//printBit(a);
	//cout<<endl<<endl;
	int ret = 0;
	while(!q.empty()){
		int bitNum = q.top().second.first;
		int bitFlag = q.top().second.second;
		int val = -q.top().first;
		q.pop();
		if(mp.count(MP(bitNum,bitFlag))!=0)	continue;
		mp[MP(bitNum,bitFlag)] = 1;
		//cout<<bitFlag<<endl;
		//cout<<val<<" "<<bitFlag<<" "<<(1<<(v+1))-1<<endl;
		
		if(bitFlag == (1<<(v+1))-1 || val==5){
			ret = val;
			break;
		}
		//cout<<val<<" ";
		//printBit(bitNum);
		//cout<<" ";
		//printBit(bitFlag);
		//cout<<endl;
		for(int i=0;i<=v;i++){
			if((bitFlag&(1<<i))>0)	continue;
			for(int j=1;j<=i;j++){
				if(bitNum&(1<<j))	continue;
				int tempBitFlag = cariBaru(j,bitFlag);
				q.push(MP(-val-1,MP(bitNum|(1<<j), tempBitFlag)));
			}
		}
	}
	
	return ret;
}

int main(){
	scanf("%d",&t);
	for(int z=1;z<=t;z++){
		printf("Case #%d: ",z);
		scanf("%d%d%d",&c,&d,&v);
		memset(A,-1,sizeof(A));
		for(int i=0;i<d;i++)	scanf("%d",&ar[i]);
		A[0]=1;
		for(int i=0;i<d;i++)
			for(int j=v;j>=ar[i];j--)
				if(A[j-ar[i]]==1)	A[j]=1;
		ans=0;
		ans = cari();
		
		printf("%d\n",ans);
	}
	return 0;
}
