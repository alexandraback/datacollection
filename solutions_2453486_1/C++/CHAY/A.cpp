#include<cstdio>
int main () {
	int t,T;
	int i,j,n=4;
	int x,o,dot,ans;
	char s[5][5]={0};
	scanf("%d",&T);
	for(t=0;t<T;t++) {
		ans=0;dot=0;
		for(i=0;i<n;i++) scanf("%s",s[i]);
		for(i=0;i<n;i++) {
			x=0;o=0;
			for(j=0;j<n;j++) {
				if(s[i][j]=='X') x++;
				if(s[i][j]=='O') o++;
				if(s[i][j]=='T') {x++;o++;}
				if(s[i][j]=='.') dot++;
			}
			if(x==4) ans=1;
			if(o==4) ans=2;
		}
		for(i=0;i<n;i++) {
			x=0;o=0;
			for(j=0;j<n;j++) {
				if(s[j][i]=='X') x++;
				if(s[j][i]=='O') o++;
				if(s[j][i]=='T') {x++;o++;}
				if(s[j][i]=='.') dot++;
			}
			if(x==4) ans=1;
			if(o==4) ans=2;
		}
		x=0;o=0;
		for(i=0;i<n;i++) {
			if(s[i][i]=='X') x++;
			if(s[i][i]=='O') o++;
			if(s[i][i]=='T') {x++;o++;}
			if(s[i][i]=='.') dot++;
		}
		if(x==4) ans=1;
		if(o==4) ans=2;
		x=0;o=0;
		for(i=0;i<n;i++) {
			if(s[i][n-1-i]=='X') x++;
			if(s[i][n-1-i]=='O') o++;
			if(s[i][n-1-i]=='T') {x++;o++;}
			if(s[i][n-1-i]=='.') dot++;
		}
		if(x==4) ans=1;
		if(o==4) ans=2;
		if(ans==1) printf("Case #%d: X won\n",t+1);
		if(ans==2) printf("Case #%d: O won\n",t+1);
		if(ans==0)
			if(dot==0) printf("Case #%d: Draw\n",t+1);
			else printf("Case #%d: Game has not completed\n",t+1);
	}
	return 0;
}