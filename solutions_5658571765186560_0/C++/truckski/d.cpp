#include<cstdio>
#include<algorithm>
using namespace std;

bool solve()
{
	int X,R,C;
	scanf("%d%d%d",&X,&R,&C);
	int r, c;
	r=min(R,C);
	c=max(R,C);
	if(X==1) return true;
	if(X==2) 
	{
		return (c*r)%2==0;
	}
	if(X==3)
	{
		if(R<3 && C<3) return false;// 1_1 1_2 2_2
		if(R+C==8) return false; // 4_4
		if(r==1) return false; // 1_3 1_4
		if(r*c==8) return false; // 2_4
		//2_3 3_3 3_4
		return true;
	}
	if(r<2) return false; // 1_1 1_2 1_3 1_4
	if(r+c==8) return true; // 4_4
	if(r==2 && c==2) return false; // 2_2
	if(r==2 && c==3) return false; // 2_3
	if(r==3 && c==3) return false; // 3_3
	if(r==2 && c==4) return false; // 2_4
	//3_4
	return true;
}

int main()
{
	int ncases;
	scanf("%d",&ncases);
	for(int i = 1; i <= ncases; i++)
		printf("Case #%d: %s\n",i,solve()?"GABRIEL":"RICHARD");
	return 0;
}
