#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

typedef long long LL;

int H = 32;
const int maxn = 32+10;

int bit[maxn];


bool divp(int base,int x)
{
    LL now = 0;
    for(int i = H-1;i >= 0;--i)
    {
        now = now*base + bit[i];
        now = now%x;

    }
    return now == 0;
}


int res[maxn];

bool judge()
{
    int can[4] = {2,3,5,7};
    for(int i = 2;i <= 10;++i)
    {
        bool flag = false;
        for(int j = 0;j < 4;++j)
            if(divp(i,can[j]))
            {
                res[i] = can[j];
                flag = true;
            }
        if(!flag) return false;

    }
    return true;
}



int main()
{
//    int len = 10;
//
//    for(int i = 2;i <= 10;++i)
//    {
//        LL now = 1;
//        for(int j = 1;j <= 10;++j)
//        {
//            printf("%5lld%c",now," \n"[j==10]);
//            now *= i;
//        }
//
//    }
   // freopen("./test.txt","r",stdin);
    freopen("./C-small-attempt1.in","r",stdin);
    freopen("./out","w",stdout);
    int limit;
    int kase;
    scanf("%d",&kase);
    scanf("%d %d",&H,&limit);
    memset(bit,0,sizeof(bit));


    bit[0] = 1;
    bit[H-1] = 1;

//    int pos[20];
//    for(int i = 1;i <= 14;++i)
//        pos[i-1] = i;

    puts("Case #1:");
    int cnt = 0;
//    do
//    {
//        random_shuffle(pos,pos+14);
        for(int i = 0;i < (1 << H-2);++i)
        {
            for(int j = 0;j < H-2;++j)
                if(i & (1 << j))
                {
                    bit[j+1] = 1;
                }
            if(judge())
            {

                for(int j = H-1;j >= 0;--j)
                    printf("%d",bit[j]);
                for(int j = 2;j <= 10;++j)
                    printf(" %d",res[j]);
                putchar('\n');


    //
    //            printf("   FFF\n");
                cnt++;

            }
            if(cnt >= limit) break;
            for(int j = 0;j < H-2;++j)
                if(i & (1 << j))
                {
                    bit[j+1] = 0;
                }
        }
      //  printf("***** %d  %d\n",cnt,limit);
  //  }while(cnt != 0);

   // printf("****** %d\n",cnt);

}
