# include <stdio.h>
//http://www.geeksforgeeks.org/write-a-c-program-to-print-all-permutations-of-a-given-string/
#include<string.h>
 int hash[106],b[106];
/* Function to swap values at two pointers */
void swap (char *x, char *y)
{
    char temp;
    temp = *x;
    *x = *y;
    *y = temp;
}
  
/* Function to print permutations of string
   This function takes three parameters:
   1. String
   2. Starting index of the string
   3. Ending index of the string. */
void permute(char *a, int i, int n) 
{
   int j,ans; 
   if (i == n)
     {
     	ans=0;
     	for(j=0;j<n;j++)
     	{if(b[a[j]-97]%100==b[a[j+1]-97]/100)
     	ans++;}
     	hash[ans]++;
     }
   else
   {
        for (j = i; j <= n; j++)
       {
          swap((a+i), (a+j));
          permute(a, i+1, n);
          swap((a+i), (a+j)); //backtrack
       }
   }
} 
 
/* Driver program to test above functions */
int main()
{
	FILE *fi,*fo;
	fi = fopen("abc.txt", "r");
	fo = fopen("test.txt", "w+");
	int n,i;
   char a[106];
   int f,l,max,k=1;
	char s[105];
	fscanf(fi,"%d",&f);
	while(f--)
	{
		for(i=0;i<106;i++)
		hash[i]=0;
		fscanf(fi,"%d",&n);
		for(i=0;i<n;i++)
		{
			fscanf(fi,"%s",s);
			l=strlen(s);
			b[i]=(s[0]-96)*100+s[l-1]-96;
		}
	
   for(i=0;i<n;i++)
   a[i]=i+97; 
   permute(a, 0, n-1);
   max=0;
   for(i=1;i<105;i++)
   {
   	if(hash[i]>max)
   	max=hash[i];
   }
   if(max==0)
   fprintf(fo,"Case #%d: 0\n",k);
   else
   {
   	
   		max=0;
	   for(i=1;i<105;i++)
   		{
   			if(hash[i]!=0)
   			max=hash[i];
   		}
   		fprintf(fo,"Case #%d: %d\n",k,max);
   	}
   	k++;
}
   return 0;
}
