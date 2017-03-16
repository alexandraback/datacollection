#include<stdio.h>
#include<string.h>

int main()
{

    int cas;
    int data[1005][2];
    int N;
    bool check[1005][2];
    scanf("%d",&cas);
    for(int i=1;i<=cas;++i)
    {
        scanf("%d",&N);
        for(int j=0;j<N;j++)
        {
            scanf("%d %d",&data[j][0],&data[j][1]);
            check[j][0]=check[j][1]=false;
        }
        int complete = 0;
        int res=0;
        int star=0;
        while(complete<N)
        {
            bool flag_choose=false;
            for(int j=0;j<N;j++)
            {
                if(!check[j][1] && data[j][1]<=star)
                {
                    flag_choose=true;
                    if(!check[j][0])
                    {
                        star+=2;
                    }
                    else
                    {
                        star+=1;
                    }
                    check[j][0]=check[j][1]=true;
                    res++;
                    complete++;
                }
            }
            if(!flag_choose)
            {
                for(int j=0;j<N;j++)
                {
                    if(!check[j][0] && data[j][0]<=star)
                    {
                        flag_choose=true;
                        check[j][0]=true;
                        star+=1;
                        res++;
                        break;
                        //complete++;
                    }
                }
            }
            if(!flag_choose)
                break;
        }
        if(complete==N)
            printf("Case #%d: %d",i,res);
        else
            printf("Case #%d: Too Bad",i);

        if(i<cas)
            printf("\n");
    }
    return 0;
}
