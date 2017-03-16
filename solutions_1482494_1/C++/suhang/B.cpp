#include <map>
#include <cmath>
#include <vector>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

const	int N=1024;

int		n,id;
bool	mk[N],mk2[N];

struct jilu {
	int x,y;
}p[N];

int main(){
	freopen("B.in","r",stdin);
	freopen("B.out","w",stdout);
	
	int test;
	
	for (scanf("%d",&test);test--;){
		scanf("%d",&n);
		for (int i=1;i<=n;i++)
			scanf("%d%d",&p[i].x,&p[i].y),mk[i]=mk2[i]=0;
		bool flag=0;
		int now=0,res=0;
		for (;;){
			flag=1;
			for (int i=1;i<=n;i++)
			if (!mk[i] && now>=p[i].y){
				flag=0;
				now+=2;
				res++;
				mk[i]=mk2[i]=1;
			}
			for (int i=1;i<=n;i++)
			if (!mk2[i] && mk[i] && now>=p[i].y){
				flag=0;
				now+=1;
				res++;
				mk[i]=mk2[i]=1;
			}
			if (flag){
				int best=0;
				for (int i=1;i<=n;i++)
				if (!mk[i] && now>=p[i].x){
					if (!best)
						best=i;
					else
					if (p[i].y>p[best].y)
						best=i;
				}
				if (best){
					flag=0;
					mk[best]=1;
					now++;
					res++;
				}
			}
			if (flag)
				break;
		}
		flag=0;
		for (int i=1;i<=n;i++)
		if (!mk2[i])
			flag=1;
		printf("Case #%d: ",++id);
		if (flag)
			printf("Too Bad\n");
		else
			printf("%d\n",res);
		
	}
	
	return 0;
}
