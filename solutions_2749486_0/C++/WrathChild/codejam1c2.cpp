#include<cstdio>
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main()
{
//    freopen("C:\\Users\\wrathchild\\Desktop\\input.txt","r",stdin);
//    freopen("C:\\Users\\wrathchild\\Desktop\\output.txt","w",stdout);
    int test=0,temp=0;
    scanf("%d",&test);
    for(temp=1;temp<=test;temp++)
    {

        printf("Case #%d: ",temp);
        int x,y;scanf("%d",&x);scanf("%d",&y);
        if(x<0&&y>0)
        {
            x*=(-1);
            while(x--)printf("EW");
            while(y--)printf("SN");
        }
        else if(x==0)
        {
            if(y<0)
            {
                y*=(-1);
                while(y--)printf("NS");
            }
            else
                while(y--)printf("SN");
        }
        else if(y==0)
        {
            if(x<0)
            {
                x*=(-1);
                while(x--)printf("EW");
            }
            else
                while(x--)printf("WE");
        }
        else if(x<0&&y<0)
        {
            x*=(-1);;
            while(x--)printf("EW");
            y*=(-1);
            while(y--)printf("NS");
        }
        else if(x>0&&y<0)
        {
            while(x--)printf("WE");
            y*=(-1);
            while(y--)printf("NS");
        }
        else
        {
            while(x--)printf("WE");
            while(y--)printf("SN");
        }

        printf("\n");

}
    return 0;
}

