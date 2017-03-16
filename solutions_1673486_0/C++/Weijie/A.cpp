#include<stdio.h>
#include<string.h>
#include<algorithm>

using namespace std;

FILE *fin,*fout;
int a,b;
double p[100010],containWrong[100010];

int main()
{
    fin = fopen("test.in","r");
    fout = fopen("ans.out","w");
    int T;
    fscanf(fin,"%d",&T);
    for(int i = 1;i <= T;++i){
        fscanf(fin,"%d%d",&a,&b);
        for(int i = 1;i <= a;++i)
            fscanf(fin,"%lf",&p[i]);
        containWrong[0] = 0;
        for(int i = 1;i <= a;++i){
            containWrong[i] = (1 - p[i]) + p[i] * containWrong[i - 1];
        }
        double ans = 10000000;
        double temp;
        for(int i = 0;i <= a;++i){
            temp = i + (1 - containWrong[a - i]) * (b - a + i + 1) 
                     + containWrong[a - i] * (b - a + i + 1 + b + 1);
            ans = min(ans,temp);
        }
        temp = 1 + b + 1;
        ans = min(ans,temp);
        fprintf(fout,"Case #%d: %.10f\n",i,ans);
    }
    fclose(fin);
    fclose(fout);
    system("pause");
    return 0;    
}
