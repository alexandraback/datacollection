#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
char i[100][100];
int max(int x,int y){ if( x>=y ) return x; return y; }
int gcd(int x,int y)
{
	if( x<0 ) x=-x; if( y<0 ) y=-y;
	while( 1 )
	{
		if( x==0 ) return y;
		if( y==0 ) return x;
		if( x>y ) x%=y;
		else y%=x;
	}
	return 0;
}
int main()
{
	int a,s,l,m,n,c,x,y,px,py,qx,qy,pqx,pqy,tx,ty,dx,dy,sx,sy;
	char *tcp;
int T,N;
scanf("%d",&N);
for(T=1;T<=N;T++)
{
	scanf("%d%d%d",&n,&m,&l);
	for(a=0;a<n;a++)
	{
		scanf("%s",i[a]);
		tcp=strchr(i[a],'X');
		if( tcp!=NULL ){ x=a; y=tcp-i[a]; tcp[0]='.'; }
	}
	c=0;
	for(a=-l;a<=l;a++)
	{
		for(s=-l;s<=l;s++)
		{
			if( a==0 && s==0 ) continue;
			if( gcd(a,s)>1 ) continue;
//printf("----- %d %d -----\n",a,s);
			px=x; py=y;
			dx=a; dy=s;
			if( dx>0 ) sx=1; else if( dx<0 ) sx=-1; else sx=0;
			if( dy>0 ) sy=1; else if( dy<0 ) sy=-1; else sy=0;
			qx=x; qy=y;
			while( 1 )
			{
//printf("%d %d %d %d %d %d\n",px,py,dx,dy,qx,qy);
				pqx=qx-px; pqy=qy-py;
				if( ( px!=x || py!=y ) && qx==x && qy==y )
					if( pqx*dy==pqy*dx )
					{
						if( (qx-px)*(qx-px)+(qy-py)*(qy-py)<=l*l ) c++;
						break;
					}
				tx=max(pqx*sx-1,0); ty=max(pqy*sy-1,0);
				if( tx*tx+ty*ty>l*l ) break;
				ty=(2*pqx+sx)*dy*sx*sy;
				tx=(2*pqy+sy)*dx*sx*sy;
				if( tx==ty )
				{
					if( i[qx+sx][qy+sy]=='#' && i[qx][qy+sy]=='.' && i[qx+sx][qy]=='.' ) break;
					if( i[qx+sx][qy+sy]=='.' ){ qx+=sx; qy+=sy; continue; }
				}
				if( ( ty<=tx || sy==0 ) && sx!=0 )
				{
					if( i[qx+sx][qy]=='#' )
					{
						px+=2*pqx+sx;
						dx=-dx;
						sx=-sx;
					}
					else qx+=sx;
				}
				else
				{
					if( i[qx][qy+sy]=='#' )
					{
						py+=2*pqy+sy;
						dy=-dy;
						sy=-sy;
					}
					else qy+=sy;
				}
			}
		}
	}
	printf("Case #%d: %d\n",T,c);
}
	return 0;
}
