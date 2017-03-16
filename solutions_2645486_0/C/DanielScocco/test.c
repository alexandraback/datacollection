#include <stdio.h>
#include <math.h>

int arr[100];

int process(int e, int r, int n){
	int result = 0;
	int i;
	int spent;
	int current = e;

	for (i=0;i<n;i++){
		if(current>0)
			spent = (rand() % (current+1));
		else
			spent = 0;
		current-=spent;
		result += (spent * arr[i]);
		current += r;
		current = current % (e+1);
	}

	return result;
}

int main(){
    int k,t;
    int result;
	int e, r, n;
	int w;
	int max;
	int l;
	
	  
    scanf("%d",&t);
  
    for(k=0;k<t;k++){
		scanf("%d %d %d",&e,&r,&n);		

		for(w=0;w<n;w++)
			scanf("%d",&arr[w]);
		max = 0;

		for(l=0;l<30000000;l++){
        	result = process(e,r,n);
			if(result>max)
				max = result;
		}

        if(k>0)
          printf("\n");
        printf("Case #%d: %d",k+1,max);
    }

  return 0;
}
