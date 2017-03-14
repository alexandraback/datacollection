#include<cstdio>
#include<algorithm>
using namespace std;
const int N=51;
int n,m,d;
char a[N][N];
bool b[N][N];
int gcd(int a,int b){
	b?gcd(b,a%b):a;
}
int main(){
	freopen("D-small-attempt1.in","r",stdin);
	freopen("D-small-attempt1.out","w",stdout);
	int ii,tt;
	int i,j,ti,tj,s,t,u,v,w,x,y,z;
	scanf("%d",&tt);
	for(ii=1;ii<=tt;ii++){
		printf("Case #%d: ",ii);
		scanf("%d%d%d",&n,&m,&d);
		for(i=0;i<n;i++){
			for(j=0;j<m;j++){
				scanf(" %c",&a[i][j]);
				if(a[i][j]=='X'){
					ti=i;
					tj=j;
				}
			}
		}

		w=2*(ti-1)+1;
		x=2*(tj-1)+1;
		y=2*(n-ti-2)+1;
		z=2*(m-tj-2)+1;

//		printf("%d %d %d %d\n",w,x,y,z);

		s=0;

		memset(b,0,sizeof(b));
		for(i=1;;i++){
			t=i/2;
			u=t*w+(i-t)*y;
			if(u>d)break;
			for(j=0;;j++){
				t=j/2;
				v=t*x+(j-t)*z;
				if(u*u+v*v>d*d)break;
				t=gcd(u,v);
				b[u/t][v/t]=1;
			}
		}
		for(i=0;i<N;i++)
			for(j=0;j<N;j++)
				s+=b[i][j];

		memset(b,0,sizeof(b));
		for(i=0;;i++){
			t=i/2;
			u=t*y+(i-t)*w;
			if(u>d)break;
			for(j=1;;j++){
				t=j/2;
				v=t*x+(j-t)*z;
				if(u*u+v*v>d*d)break;
				t=gcd(u,v);
				b[u/t][v/t]=1;
			}
		}
		for(i=0;i<N;i++)
			for(j=0;j<N;j++)
				s+=b[i][j];

		memset(b,0,sizeof(b));
		for(i=1;;i++){
			t=i/2;
			u=t*y+(i-t)*w;
			if(u>d)break;
			for(j=0;;j++){
				t=j/2;
				v=t*z+(j-t)*x;
				if(u*u+v*v>d*d)break;
				t=gcd(u,v);
				b[u/t][v/t]=1;
			}
		}
		for(i=0;i<N;i++)
			for(j=0;j<N;j++)
				s+=b[i][j];

		memset(b,0,sizeof(b));
		for(i=0;;i++){
			t=i/2;
			u=t*w+(i-t)*y;
			if(u>d)break;
			for(j=1;;j++){
				t=j/2;
				v=t*z+(j-t)*x;
				if(u*u+v*v>d*d)break;
				t=gcd(u,v);
				b[u/t][v/t]=1;
			}
		}
		for(i=0;i<N;i++)
			for(j=0;j<N;j++)
				s+=b[i][j];
		printf("%d\n",s);
	}
	return 0;
}
