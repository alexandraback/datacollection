#include<bits/stdc++.h>
using namespace std;
int main()
{	int t;
scanf("%d",&t);
for(int i=1;i<=t;i++){
	int x,l,r;
	scanf("%d %d %d",&x,&l,&r);
int check=1;
            if(r*l<x || (r*l)%x!=0 || x>=7){}
            else if(x==2){ if(l>1 && r>1){check=0;}}
            else if((r>(x-1) && l>(x-2))  ||  (r>(x-2) && l>(x-1)))check=0;
            if(check==0)printf("Case #%d: GABRIEL\n",i);
            else printf("Case #%d: RICHARD\n",i);
}
	}