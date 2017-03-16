#include <cstdio>
#include <cctype>
int map[5][5]={{0},{0,1,2,3,4},
					{0,2,-1,4,-3},
					{0,3,-4,-1,2},
					{0,4,3,-2,-1}};
int op(int a,int b)
{
	int f=1;
	if(a<0) {a=-a;f=-1;}
	if(b<0)	{b=-b;f*=-1;}
	return f*map[a][b];
}
int main()
{
	int T,L,X;
	int str[10001],res=1;
	char temp;
	int ipos,kpos,lim;
	bool ifind,kfind,flag;
	freopen("C-small-attempt0.in","r",stdin);
	freopen("C.out","w",stdout);
	scanf("%d",&T);
	for(int j=1;j<=T;j++)
	{
		scanf("%d%d",&L,&X);
		res=1;
		for(int i=0;i<L;i++)
		{
			loop:
			scanf("%c",&temp);
			if(temp<'i'||temp>'k') goto loop;
			str[i]=temp-'g';
			res=op(res,str[i]);
		}
		flag=false;
		int remain=(X-1)%4;
		temp=res;
		while(remain--) temp=op(temp,res);
		if(temp!=-1) 
			goto judge;
		//search for i
		lim=X>4?4:X;
		res=1;ifind=false;
		for(int time=0;time<lim;time++) if(!ifind)
		for(int i=0;i<L;i++)
		{
			res=op(res,str[i]);
			if(res==2){
				ifind=true;
				ipos=time*L+i+1;
				break;
			}
		}
		//search for k
		res=1;kfind=false;
		for(int time=0;time<lim;time++) if(!kfind)
		for(int i=L-1;i>=0;i--)
		{
			res=op(str[i],res);
			if(res==4){
				kfind=true;
				kpos=(time+1)*L-i;
				break;
			}
		}
		flag=ifind&&kfind;
		if(flag&&X<8){
			if(ipos+kpos>=X*L)
				flag=false;
		}
		judge: if(flag) printf("Case #%d: YES\n",j);
		else printf("Case #%d: NO\n",j);
	}
	return 0;
}
