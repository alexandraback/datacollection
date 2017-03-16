#include<stdio.h>
#include<string.h>
#define MAX(a,b) a>b? a:b
#define MIN(a,b) a<b? a:b

int f_digit(int n)
{
    if(n>0)
        return 1+f_digit(n/10);
    else
        return 0;
}

void ship_s(char *s1,char *s2,int in2,int n)
{
    int i=0,j=in2;

    while(j<n)
    {
        s1[i]=s2[j];
        i++;j++;
    }

    j=0;
    while(i<n)
    {
        s1[i]=s2[j];
        i++;j++;
    }
    s1[n]='\0';
}

int main()
{
    int i,t;
    int a,b,n_digit;
    scanf("%d",&t);

    for(i=1;i<=t;i++)
    {

        scanf("%d %d",&a,&b);
        printf("Case #%d: ",i);

        int ans=0;
        bool isans[2000001]={0};
        n_digit=f_digit(a);

        for(int j=a;j<=b;j++)
        {
            if(!isans[j])
            {
                char s[n_digit+1],t[n_digit+1];
                int temp_a=0,temp_num;

                sprintf(s,"%d",j);

                for(int k=1;k<n_digit;k++)
                {
                    ship_s(t,s,k,n_digit);
                    sscanf(t,"%d",&temp_num);
                    if(temp_num<=b && temp_num>=a && !isans[temp_num] && temp_num!=j)
                    {
                        //printf("\nitself :%d pair:%d",j,temp_num);
                        isans[temp_num]=1;
                        temp_a++;
                    }

                }
                //if(temp_a)
                ans+=((temp_a+1)*temp_a)/2;
            }
        }
        //printf("\n");
        printf("%d\n",ans);
    }


    return 0;
}



