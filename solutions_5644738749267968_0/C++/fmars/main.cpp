#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;
static int  compare (const void * a, const void * b)
{
  if (*(double*)a > *(double*)b) return 1;
  else if (*(double*)a < *(double*)b) return -1;
  else return 0;
}
int main()
{
    FILE*fin=fopen("in.txt","r");
    FILE*fout=fopen("out.txt","w");
    int t;
    fscanf(fin,"%d",&t);
    for(int i=1;i<=t;i++){
        int n;
        fscanf(fin,"%d",&n);
        double a[1000]={0},b[1000]={0};
        for(int j=0;j<n;j++)
            fscanf(fin,"%lf",&a[j]);
        qsort (a, n, sizeof(double), compare);
        for(int j=0;j<n;j++)
            fscanf(fin,"%lf",&b[j]);
        qsort (b, n, sizeof(double), compare);

        int dscore=0,score=0,p1,p2;
        for(p1=n-1,p2=n-1;p1>=0;p1--){
            if(a[p1]>b[p2]){
                score++;
            }
            else
                p2--;
        }
        for(p1=0,p2=0;p1<n;p1++){
            if(a[p1]>b[p2]){
                dscore++;
                p2++;
            }
        }
        fprintf(fout,"Case #%d: %d %d\n",i,dscore,score);

    }
    fclose(fin);
    fclose(fout);
    return 0;
}
