#include<stdio.h>
#include<string.h>
int main(){
	char s[1000];
	char *p;
	int T,i,o,n,j,k,l,r;
	scanf("%d\n",&T);
	for(i=1;i<=T;i++){
		scanf("%s %d",s,&n);
		l=(int)strlen(s);
		//printf("%d %d%s\n",n,l,s);
		o=0;
		for(j=0;j<l;j++){
			r=0;
			for(k=j;k<l;k++){
			//	printf("%d%c%d %d %d\n",j,s[k],k,r,o);
				if(s[k]=='a'){r=0;continue;}
				if(s[k]=='e'){r=0;continue;}
				if(s[k]=='i'){r=0;continue;}
				if(s[k]=='o'){r=0;continue;}
				if(s[k]=='u'){r=0;continue;}
				r++;
				
				if(r<n)continue;
				o+=(l-k);
				//printf("%d %d %d\n",j,k,o);
				break;
			}
		}
		printf("Case #%d: %d\n",i,o);
	}
	return 0;
}

