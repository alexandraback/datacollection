#include <bits/stdc++.h>

using namespace std;

char s1[1001];
char s2[1001];

long long int power(long long int b,long long int e)
{
    if(e==0)
    {
        return 1;
    }
    else if(e==1)
    {
        return b;
    }
    else
    {
        long long int p=power(b,e/2);

        if(e%2==0)
        {
            return (p*p);
        }
        else
        {
            return (p*p*b);
        }
    }
}

int main()
{
    int t;
    FILE *ftr=fopen("input.txt","r");
    FILE *ftr1=fopen("output.txt","w");
    fscanf(ftr,"%d",&t);

    for(int t1=1;t1<=t;t1++)
    {
        int k,l,s;
        double ans=0;
        double max1=0;
        fscanf(ftr,"%d%d%d",&k,&l,&s);

        fscanf(ftr,"%s",s1);
        fscanf(ftr,"%s",s2);

        long long int counter=power(k,s);

        for(long long int i=0;i<counter;i++)
        {
            long long int temp2=i;
            char s3[10];
            for(int j=0;j<s;j++)
            {
                s3[j]=(s1[temp2%k]);
                temp2=temp2/k;
            }

            double count1=0;
            
            for(int k=0;k<=(s-l);k++)
            {
                bool poss=true;

                for(int k1=k;k1<k+l;k1++)
                {
                    if(s3[k1]!=s2[k1-k])
                    {
                        poss=false;
                    }
                }

                if(poss)
                {
                    count1++;
                }
            }

            ans=ans+(count1/counter);
            max1=max(max1,count1);
        }

        fprintf(ftr1,"Case #%d: %.6lf\n",t1,max1-ans);

    }
return 0;}