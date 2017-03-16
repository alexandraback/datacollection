#include<cstdio>
#include<algorithm>
#include<string.h>
using namespace std;
int main()
{
    int t,n,i,j,k,len,res;
    char str[20][200];
    bool flag;
    int arr[20],test1[26];
    scanf("%d",&t);
    for(i=1;i<=t;i++)
    {
        scanf("%d",&n);
        res=0;
        for(j=0;j<n;j++)
        {
            arr[j]=j;
            scanf("%s",str[j]);
        }
        do
        {
            flag=true;
            for(j=0;j<26;j++)
            {
                test1[j]=-2;
            }
            len=0;
            for(j=0;j<n;j++)
            {
                for(k=0;str[arr[j]][k]!='\0';k++)
                {
                    if(test1[(int)(str[arr[j]][k]-'a')]==-2||test1[(int)(str[arr[j]][k]-'a')]==len-1)
                    {
                        test1[(int)(str[arr[j]][k]-'a')]=len;
                    }
                    else
                    {
                        flag=false;
                        break;
                    }
                    len++;
                }
                if(!flag)
                    break;
            }
            if(flag)
                res++;
        }while(next_permutation(&arr[0],&arr[n]));
        printf("Case #%d: %d\n",i,res);
    }
    return 0;
}
