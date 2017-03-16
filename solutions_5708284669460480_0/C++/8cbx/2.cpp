#include<stdio.h>
#include<string.h>
#include<math.h>
int main()
{
    int k,l,s;
    char kk[10],ll[10];
    int times[36];
    int t;
    int cases;
    scanf("%d",&t);
    cases=0;
    while(t--)
    {
        cases++;
        memset(times,0,sizeof(times));
        scanf("%d%d%d",&k,&l,&s);
        scanf("%s",kk+1);
        scanf("%s",ll+1);
        for(int i=1;i<=k;i++)
        {
            times[kk[i]-'A'+1]++;
        }
        int todo=k,now=1,beg=1;
        while(now<s)
        {
            todo*=10;
            beg*=10;
            beg+=1;
            todo+=k;
            now++;
        }
        int ans=0;
        int chance=0;
        //printf("%d %d\n",todo,beg);
        for(int i=beg;i<=todo;i++)
        {
            char ss[10];
            //printf("%d\n",i);
            int tmp=i;
            int anss=0;
            int ready=1;
            int flag=0,flag2;
            memset(ss,0,sizeof(ss));
            while(tmp>0)
            {
                if(tmp%10>k||tmp%10==0)
                {
                    flag=1;
                    break;
                }
                ss[ready]=kk[tmp%10];
                tmp/=10;
                ready++;
            }
            if(flag==1)
            {
                continue;
            }
            else
            {
                /*for(int j=1;j<=s;j++)
                {
                    printf("%c",ss[j]);
                }
                printf("\n");*/
                for(int j=1;j<=s-l+1;j++)
                {
                    flag2=0;
                    for(int r=1;r<=l;r++)
                    {
                        //printf("%c %c %d %d\n",ss[j+r-1],ll[r],j+r-1,r);
                        if(ss[j+r-1]!=ll[r])
                        {
                            flag2=1;
                            break;
                        }
                    }
                    if(flag2==0)
                    {
                        anss++;
                        chance+=1;
                    }
                }
                //printf("anss %d\n",anss);
                if(anss>ans)
                {
                    ans=anss;
                }
            }
            //printf("--%d\n",i);
        }
        //printf("%d %d\n",chance,ans);
        printf("Case #%d: %lf\n",cases,(double)ans-(double)chance/(double)pow(k,s));
    }
    return 0;
}
