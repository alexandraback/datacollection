#include<stdio.h>      
#include<stdlib.h>      
#include<math.h>  

void swap(long long * t, long long x, long long y);
int partition(long long * A, int left, int right);
void quickSort(long long *A, int left, int right);


int main() { 
	
	int T,i; 
	scanf("%d",&T);
	long long A;
	int N;
	for (i=1; i<=T; i++)
	{
		scanf("%lld", &A);
		scanf("%d", &N);
		int j; long long motes[101];
		for (j=1;j<=N;j++)
		{
			scanf("%lld", &motes[j]);
		}

		quickSort(motes,1,N);
		
		int count=1; int result=0; int cost=0;
		if (A==1) result=N;
		else 
		{
			while (count<=N)
			{
				while ((count<=N)&&(motes[count]<A))
				{
					A=A+motes[count];
					count++; //trwei ta mikrotera
				}
				
				if ((count<=N)||(cost!=0)){
					if (result!=0){
						if (N-count+1+cost<result) result=N-count+1+cost;}
					else result=N-count+1+cost;}
			
				while ((motes[count]>=A)&&(count<=N))
				{
					A=A+A-1;
					cost++;
				}
			}
		}

		printf("Case #%d: %d\n",i, result);
	}
	return 0;
}




void swap(long long * t, long long x, long long y)      
{      
     long long  temp; 
     temp=t[x];  
     t[x]=t[y];  
     t[y]=temp;  
     return;   
}    
  
  
int partition(long long * A, int left, int right)       
{      
   int i,j;      
   int pivot = A[left];      
          
   j = right + 1;      
   i=left-1;      
         
   while (1)       
   {      
          while (A[++i] < pivot) ;      
          while (A[--j] > pivot) ;      
          if (i < j) {swap(A, i, j);}      
          else return(j);             
   }       
}    
  
  
void quickSort(long long *A, int left, int right)       
{      
    if (left >= right) return; // At most 1 element      
    int q = partition(A, left, right);      
    quickSort(A, left, q);      
    quickSort(A, q+1, right);       
}  