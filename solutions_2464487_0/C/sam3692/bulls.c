# include<stdio.h>
# include<conio.h>
# include<string.h>
# include<math.h>

void main()
{
	int T,j;
unsigned long long i,r,t,dd,cnt,p,c=0;
FILE * fin = fopen("C:/Users/SAMARTH/Desktop/Code jam/input.in", "r");
FILE * out = fopen("C:/Users/SAMARTH/Desktop/Code jam/out.txt", "w");
fscanf(fin, "%d\n", &T);
for(j=0;j<T;j++)
{
fscanf(fin, "%llu %llu\n", &r,&t);
//printf("%lld %lld\n",r,t);
for(i=1;;i++)
  {
    p=2*i*i+i*(r+r-1);
     if(p<=t)
        continue;
     else 
       {
        cnt=i-1;
        break;
       }
   }
  printf("Case #%d: %llu\n",j+1,cnt);
  fprintf(out,"Case #%d: %llu\n",j+1,cnt);
}
fclose(fin);
fclose(out);
getch();
}