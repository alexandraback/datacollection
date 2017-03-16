#include<bits/stdc++.h>
using namespace std;
int main()
{
	//freopen("inDsmall.in","r",stdin);
	//freopen("outDsmall.out","w",stdout);
	int T,kase=0;
	scanf("%d",&T);
	while(T--)
	{
        int X,R,C;
        scanf("%d%d%d",&X,&R,&C);
        if(C>R) swap(R,C);
        bool flag=1;
        if(X>=7) flag=0;
        else if(X>R) flag=0;
        else if((R*C)%X!=0) flag=0;
        else if((X+1)/2>C) flag=0;
        else if(X>=C*2 && C>1) flag=0;
        printf("Case #%d: %s\n",++kase,flag?"GABRIEL":"RICHARD");
	}
}
