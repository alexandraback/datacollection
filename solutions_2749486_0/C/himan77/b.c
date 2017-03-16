#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(){
int i,j,k,T,u,v,n,a,x,y,temp_x,temp_y;

	scanf("%d",&T);

	for(k=0;k<T;k++){
		char s[501];temp_x = temp_y = 1;
		scanf(" %d %d",&x,&y);
 		i = 0;u=0;v=0;
		while(u != x){
			if(u+temp_x <= x){s[i++]='E';//if(x<0)x += temp_x; if(x>0)x += temp_x;
				u+=temp_x;}
			else {s[i++]='W';//if(x>0)x -= temp_x;if(x<0)x += temp_x;
				u-=temp_x;}
			temp_x++;		
		}
		while(v != y){
			if(v+temp_x <= y){s[i++]='N';//if(x<0)x += temp_x; if(x>0)x += temp_x;
				v+=temp_x;}
			else {s[i++]='S';//if(x>0)x -= temp_x;if(x<0)x += temp_x;
				v-=temp_x;}
			temp_x++;		
		}
		/*while(y != 0){
			if(y -temp_x < 0){s[i++]='S'; if(y<0)y += temp_x; if(y>0)y += temp_x;}
			else {s[i++]='N';if(y>0)y -= temp_x;if(y<0)y += temp_x;}
			temp_x++;		
		}*/
	s[i]='\0';
	printf("Case #%d: %s\n",k+1,s);
		

	}

	return 0;

}
