#include <stdio.h>
#include <algorithm>
using namespace std;
struct ori {
       long long jami;
       long long bitm;
       bool operator<(const ori &a) const {return jami < a.jami;}
};
const int N = 50, NN = N/2;
int t, n;
long long a[1000];
long long dayofa[20][40];
long long jami;
ori mas1[34000000], mas2[34000000];
void bechdva(FILE* F, long long b1, long long b2)
{
long long bb = b1 | b2;
b1 = bb & b1;
b2 = bb & b2;
bool ind = 0;
for(int i=0;i<N;i++)
   if(b1 & (1<<i))
      {
      if(ind) fprintf(F, " ");
      ind = 1;
      fprintf(F, "%I64d",a[i]);
      }
fprintf(F, "\n");
ind = 0;
for(int i=0;i<N;i++)
   if(b2 & (1<<i))
      {
      if(ind) fprintf(F, " ");
      ind = 1;
      fprintf(F, "%I64d",a[i]);
      }
fprintf(F, "\n");
fflush(F);
}
void shedgena(long long* a, int i, int j, ori* mas)
{
long long ric;
for(int ii=0;ii<(1<<NN);ii++)
   {
   ric = 0;
   for(int jj=0;jj<NN;jj++)
      if(ii & (1<<jj))
         ric += a[i+jj];
   mas[ii].jami = ric;
   mas[ii].bitm = ii;
   }
}
int main()
{
freopen("C-large.in","r",stdin);
FILE* F = fopen("C-large.out","w");
scanf("%d",&t);
for(int it=1;it<=t;it++)
   {
   fprintf(F, "Case #%d:\n",it);
   fflush(F);
   scanf("%d",&n);
   for(int i=0;i<n;i++)
      scanf("%I64d",&a[i]);
   n = N;
   shedgena(a, 0, n/2, mas1);
   shedgena(a, n/2, n, mas2);
   int N = (1<<n/2);
   sort(mas1, mas1+N);
   sort(mas2, mas2+N);
   bool ind = 0;
   for(int i=0;i+1<N;i++)
      {
      if(mas1[i].jami == mas1[i+1].jami)
         {
         bechdva(F, mas1[i].bitm, mas1[i+1].bitm);
         ind = 1;
         break;
         }
      if(mas2[i].jami == mas2[i+1].jami)
         {
         bechdva(F, mas2[i].bitm << NN, mas2[i+1].bitm << NN);
         ind = 1;
         break;
         }
      }
   if(ind) continue;
   int j = 0;
   for(int i=0;i<N;i++)
      {
      if(mas1[i].jami == 0) continue;
      while(j < N && mas2[j].jami < mas1[i].jami) j++;
      if(mas1[i].jami == mas2[j].jami)
         {
         bechdva(F, mas1[i].bitm, mas2[i].bitm << NN);
         ind = 1;
         break;
         }
      }
   }
fclose(F);
return 0;
}
