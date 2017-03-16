#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int isPalindrome(int n){
    int a[100],i=0,j;
    while(n>0){
        a[i++]=n%10;
        n/=10;
    }
    i--;
    for(j=0;j<=i;j++){
        if(a[j]!=a[i-j]){
            return 0;
        }
    }
    return 1;
}


int verify(char a[],int x,int y){
	int x1=0,y1=0,i;
	for(i=0;a[i]!='\0';i++){
		if(a[i]=='E'){
			x1+=i;	
		}
		
		if(a[i]=='W'){
			x1-=i;	
		}
		
		if(a[i]=='N'){
			y1+=i;	
		}
		
		if(a[i]=='S'){
			y1-=i;	
		}
	}
	if(x==x1&&y==y1){
	printf("true\n\n");
	}
	printf("x1=%d y1=%d\n",x1,y1);	
	
	


}
int mod(int a){
	if(a<0)
	a*=-1;
	return a;
} 


int main(){
    FILE *pt = fopen("outPogo.txt","w");
	char a[500];
	int i,j,k,n,x,y,t,x1,y1,minx,miny,changed;
	
	scanf("%d",&t);
	k=0;
	for(i=1;i<=t;i++){
		k=0;
		scanf("%d %d",&x,&y);
		minx=mod(x);miny=mod(y);
		x1=x;y1=y;
		changed = 0;
		for(j=1;j<=10;j++){
changed = 0;			
			if(j%2==1){
				if(x>0){
					if(minx>mod(x-j)){
						a[k++] = 'E';
						x-=j;
						minx = mod(x-j);
						changed = 1;
					}
				}		
				else if(x<0){
					if(minx>mod(x+j)){
						a[k++] = 'W';
						x+=j;
						minx = mod(x+j);
					changed = 1;
					}
				}
				
				
			}
			if(j%2==0){
				if(y>0){
					if(miny>mod(y-j)){
						a[k++] = 'N';
						y-=j;
						miny = mod(y-j);
			changed = 1;
					}
				}
				
				else if(y<0){
					if(miny>mod(y+j)){
			
						a[k++] = 'S';
						y+=j;
						miny=mod(y+j);
			changed = 1;
					}
				}
			}	
		printf("x=%d y=%d\n",x,y);	
		
		if(changed == 0)
		break;
					
		}
		//minimize x and y towards 0
		for(j=0;j<mod(x);j++){
			if(x<0){
				a[k++] = 'E';
				a[k++]='W';
			}
			else{
				a[k++] = 'W';
				a[k++]='E';
			
			}
				
			
		}
		for(j=0;j<mod(y);j++){
			if(y<0){
				a[k++] = 'N';
				a[k++]='S';
			}
			else{
				a[k++] = 'S';
				a[k++]='N';
			
			}
				
			
		}
		
		
		a[k++]='\0';
		verify(a,x1,y1);
		printf("%s\n",a);
		fprintf(pt,"Case #%d: %s\n",i,a);
	}   

    fclose(pt);
}
