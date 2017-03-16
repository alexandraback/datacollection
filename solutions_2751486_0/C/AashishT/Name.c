#include<stdio.h>


long int getNval(char name[],int L,int  n, int hash[])
{
  int i , j , k, smallCnt, tmp;
  long int count=0; 
  for( i = 0 ; i < L ; i++)
  {
     for( j = n ; j <= L -i ; j++ )
     {
       smallCnt = 0;
       for( k = i ; k <= i+j-1 && smallCnt < n ; k++ )
       {
          if( hash[name[k]] )
          {
             smallCnt +=hash[name[k]]; 
          }
          else
          {
             smallCnt = 0; 
          }
       }
       if( smallCnt >= n ) {
           count++;
//           tmp = i;
 //          while( tmp < i+j-1 ) { printf("%c",name[tmp++]);} 
//           printf("\n");
       } 
     } 
  }

   return(count);

}

int main(int argc, char **argv)
{

 int T, Tcp ;
 int L, n , i  ;
 long int nval; 
 int hash[256];
 char name[200];
 char *ptr;   

 for(i = 0 ; i < 256 ; i++)
 {
   hash[i] = 1;
 }

 hash[(unsigned char)'a'] = 0;
 hash[(unsigned char)'e'] = 0;
 hash[(unsigned char)'i'] = 0;
 hash[(unsigned char)'o'] = 0;
 hash[(unsigned char)'u'] = 0;
  
 FILE *fp = fopen(argv[1],"r"); 
 fscanf(fp,"%d\n",&T);
  Tcp = T;

  while( T-- )
  {
      
    fscanf(fp,"%s %d",&name,&n);
    ptr = name;
    L =0 ;
    while(*ptr != '\0' )
    {
       L++;
       ptr++;
    }
//    printf("%d",L);
    nval= getNval(name,L,n,hash);
    printf("Case #%d: %ld\n",Tcp-T,nval);
  }


}
