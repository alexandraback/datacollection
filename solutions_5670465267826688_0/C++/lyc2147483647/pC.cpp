#include<cstdio>
#include<algorithm>
char x[10010];
int change(char c)
{
		if(c=='i') return 2;
		else if(c=='j') return 3;
		else if(c=='k') return 4;
}
int mul(int a,int b)
{
		// 1,-1,2,3,4,-2,-3,-4
		// 1,-1,i,j,k,-i,-j,-k
		if(a==1||a==-1||b==1||b==-1) return a*b;
		if(a<0&&b<0) {a=-a;b=-b;}
		int c=1;
		if(a<0||b<0) c=-1;
		a=a<0?-a:a;
		b=b<0?-b:b;
		if(a==b) return -1*c;
		if(a==2&&b==3) return 4*c;
		if(a==3&&b==4) return 2*c;
		if(a==4&&b==2) return 3*c;
		if(a==3&&b==2) return -4*c;
		if(a==4&&b==3) return -2*c;
		if(a==2&&b==4) return -3*c;
}
int min(int a,int b){return a>b?b:a;}
int main()
{
		int T,n,m;
		FILE *in=fopen("in.txt","r");
		FILE *out=fopen("out.txt","w");
		fscanf(in,"%d",&T);
		for(int t=1;t<=T;t++)
		{
				fscanf(in,"%d%d%s",&n,&m,x);
				bool ok=false;
				int one=1;
				for(int i=0;i<n;i++) one=mul(one,change(x[i]));
				int all=1;
				int mm=m%4;
				for(int i=0;i<mm;i++) all=mul(all,one);
				if(all==-1)
				{
						int now=1;
						bool findi=false,findj=false;
						for(int s=0;s<min(m,8);s++)
							for(int i=0;i<n;i++)
							{
									now=mul(now,change(x[i]));
									if(now==2&&findi==false) 
									{
											findi=true;
											now=1;
									}
									if(now==3&&findj==false&&findi==true) findj=true;
							}
						if(findi==true&&findj==true) ok=true;
				}
				if(ok==true) fprintf(out,"Case #%d: YES\n",t);
				else if(ok==false) fprintf(out,"Case #%d: NO\n",t);
		}
}
