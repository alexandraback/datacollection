#include <stdio.h>
#include <string.h>

char buffer[100];

int isConso(char c){
	if(c>=98&&c<=100)
		return 1;
	if(c>=102&&c<=104)
		return 1;
	if(c>=106&&c<=110)
		return 1;
	if(c>=112&&c<=116)
		return 1;
	if(c>=118&&c<=122)
		return 1;
	return 0;
}

int verify(int i, int size, int n, int len){
	//printf("------verifying i=%d size=%d\n",i,size);
	int x;
	int consecutive = 0;
	int limit = i+size;
	if(size<n)
		return 0;
	if(i+size>len)
		return 0;	

	for(x=i;x<limit;x++){
		if(x>=len)
			break;
		//printf("char %c\n",buffer[x]);
		if(isConso(buffer[x]))
			consecutive++;
		else
			consecutive = 0;
		//printf("consecutive=%d\n",consecutive);
		if(consecutive==n)
			return 1;
	}
	return 0;
}

int process(int n){
	int len;
	int i,j;
	int count = 0;
	int size;
	
	len = strlen(buffer);

	for(size=1;size<=len;size++){
		for(i=0;i<len;i++){
			count = count + verify(i,size, n,len);
		}
	}

	return count;
}

int main(){
	int t,k;
    int n;

	scanf("%d",&t);

   for(k=0;k<t;k++){
              
		scanf("%s",buffer);
		scanf("%d",&n);
      
       	if(k>0)
			printf("\n");
		printf("Case #%d: %d",k+1,process(n));
	}

return 0;
}
