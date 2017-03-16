#include<stdio.h>
#include<string.h>
#include<math.h>

char a[102][102],s[102],e[102],vis[102],S,E;
int v[102],l[102],n,V;

int fun(int p,int d){
	int i,sum=0;
	vis[p]=1;
	for(i=0;i<n;i++){
		//printf("%s %s %d %d %d %d %c %c\n",a[p],a[i],d,vis[i],V,v[i],E,s[i]);
		if( vis[i]==0 && ( ((E==s[i]) && (V & v[i])==pow(2,E-'a')) ||((E!=s[i]) && (V & v[i])==0) ) ){
			if(d==n-1){
				vis[p]=0;
			 	return 1;
			 }
			 char op=E;
			 int ov=V;
			E=e[i];
			V=V|v[i];
			sum+=fun(i,d+1);
			E=op;
			V=ov;
		}
	}
	//printf("%s--%d\n",a[p],sum);
	vis[p]=0;
	return sum;
}
int main(){
	int t,z,i,j;
	scanf("%d",&t);
	for(z=1;z<=t;z++){
		scanf("%d",&n);
		for(i=0;i<n;i++){
			scanf("%s",a[i]);
			l[i]=strlen(a[i]);
			s[i]=a[i][0];
			e[i]=a[i][l[i]-1];
			v[i]=0;
			for(j=0;j<l[i];j++)
				v[i]=v[i]|(1<<(a[i][j]-'a'));
			vis[i]=0;
		}
		int ans=0;
		for(i=0;i<n;i++){
			S=s[i];
			E=e[i];
			V=v[i];//printf("a=%d %d %d %c %c %d\n",ans,l[i],v[i],s[i],e[i],vis[i]);
			ans+=fun(i,1);
		}
		printf("Case #%d: %d\n",z,ans);
	}
	return 0;
}





