#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<iostream>
using namespace std;
int n;
int main()
{
	freopen("me.in","r",stdin);
	freopen("me.out","w",stdout);

	int tes;scanf("%d",&tes);
	for (int tt=1;tt<=tes;tt++){
		int st;
		int x,r,c;
		cin>>x>>r>>c;
		if(x>=7)st=1;
		else if(x==1)st=0;
		else if(x==2){
			if((r*c)%2==1)st=1;
			else st=0;
		}else if(x==3){
			if((r*c)%3)st=1;
			else{
				if(r==1||c==1)st=1;
				else st=0;
			}
		}else if(x==4){
			if((r*c)%4)st=1;
			else{
				if(r==1 ||c==1)st=1;
				else if(r<=3 && c<=3)st=1;
				else if(r==2||c==2)st=1;
				else st=0;
			}
		}
		if(st)printf("Case #%d: RICHARD\n",tt);
		else printf("Case #%d: GABRIEL\n",tt);
	}
	return 0;
}
		

