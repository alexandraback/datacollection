#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<string>
#include<string.h>
#include<cstring>
#include<stack>
#include<queue>
#include<cassert>

using namespace std;

#define LL long long int 
#define PII pair<int,int> 
#define PB push_back
#define MP make_pair
#define INF 1000000000

int main(){
	int t,test,n,s,p,mins,minns,ans,x;
	scanf("%d",&test);
	for(t=1;t<=test;t++){
		scanf("%d %d %d",&n,&s,&p);
		if(p==0)minns=0;
		else minns=p+p-1+p-1;
		if(p==0)mins=0;
		else if(p==1)mins=1;
		else mins=p+p-2+p-2;
		ans=0;
		while(n--){
			scanf("%d",&x);
			if(x>=minns)
				ans++;	
			else if(s!=0){
				if(x>=mins){
					ans++;
					s--;
				}
			}
		}
		printf("Case #%d: %d\n",t,ans);
	}
	return 0;
}

