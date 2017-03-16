#include"cstdio"
#include"cstdlib"

long long gcd (long long a, long long b)
{
    if (a==0) return b;
    return gcd(b%a,a);
}

main ()
{
    FILE *fpr,*fpw;
    fpr = fopen("A-small-attempt0.in","r+");
    fpw = fopen("A-small-attempt0.out","w+");
    int TEST;
    fscanf(fpr,"%d",&TEST);
    int n;
    int i;
    long long MAX=1;
    for (i=0;i<40;i++) MAX*=2;
    printf("%llu\n",MAX);
    for (n=0;n<TEST;n++)
    {
        fprintf(fpw,"Case #%d: ",n+1);
        char sLine[1000];
        int i;
        for (i=0;true;i++)
        {
            char temp;
            fscanf(fpr,"%c",&temp);
            if (temp=='\0' || temp=='\n') break;
            sLine[i]=temp;
        }
        fscanf(fpr,"%s",sLine);
        long long A=0;
        for (i=0;sLine[i]!='/';i++)
        {
            A*=10;
            A+=sLine[i]-'0';
        }
        long long B=0;
        for (i++;sLine[i]!='\0';i++)
        {
            B*=10;
            B+=sLine[i]-'0';
        }
        long long g = gcd(A,B);
        printf("%llu\n",g);
        long long bb = B/g;
        long long aa = A/g;
        if (MAX%bb!=0) fprintf(fpw,"impossible");
        else
        {
            double ans = (double)A/(double)B;
            printf("%lf\n",ans);
            for (i=1;true;i++)
            {
                if (ans>=0.5) break;
                ans*=2;
            }            
            fprintf(fpw,"%d",i);
        }
        
        fprintf(fpw,"\n");
    }
    
    printf("YAY!");
    
    scanf(" ");
}
