#include<cstdio>
#include<cstring>
#define min(a,b) a<b?a:b
using namespace std;
int T,R,C,M,testNo,i,j,coloana,rand,X[]={-1,-1,-1,0,0,1,1,1},Y[]={-1,0,1,-1,1,-1,0,1};
char Tabla[60][60];
int verifica()
{
    int aux[60][60],val;
    memset(aux,0,sizeof(aux));
    for(int i=1;i<=R;i++)
        for(int j=1;j<=C;j++)
            if(Tabla[i][j] == '.')
            {
                aux[i][j]=1;
                for(int k=0;k<8;k++)
                    aux[i][j]&=(Tabla[i+X[k]][j+Y[k]]=='.');
            }
    for(int i=1;i<=R;i++)
        for(int j=1;j<=C;j++)
            if(Tabla[i][j]=='.')
            {
                if(aux[i][j])continue;
                val = 0;
                for(int k=0;k<8;k++)
                    val+=aux[i+X[k]][j+Y[k]];
                if(val)continue;
                return 0;
            }
    return 1;
}
int main()
{
   freopen("test.in","r",stdin);
   freopen("test.out","w",stdout);
   for(scanf("%d",&T);T;--T)
   {
       testNo++;
       printf("Case #%d:\n",testNo);
       scanf("%d%d%d",&R,&C,&M);
       memset(Tabla,'.',sizeof(Tabla));
       if(R*C-1 == M)
       {
           for(i=1;i<=R;i++)
                for(j=1;j<=C;j++)
                    Tabla[i][j]='*';
       }
       if(R*C-1 != M)
       {
           rand =R;
           coloana = C;
           while(M)
           {
               if(rand < coloana)
               {
                   if( rand - 1 == M)
                   {
                        if( coloana > 1)
                        {
                            --M;
                            Tabla[rand][coloana-1] = '*';
                        }
                        for(i=rand; i && M;i--,M--)Tabla[i][coloana] ='*';
                    }
                    else
                    {
                        for(i=rand; i && M;i--,M--)Tabla[i][coloana] ='*';
                        coloana = coloana - 1;
                    }
                    continue;
               }
               if(coloana-1 == M)
               {
                   if(rand > 1)
                   {
                       --M;
                       Tabla[rand-1][coloana] = '*';
                   }
                   for(i=coloana;i && M;i--,M--)Tabla[rand][i]='*';
               }
               else
               {
                   for(i=coloana;i && M;i--,M--)Tabla[rand][i]='*';
                   rand = rand - 1;
               }
           }
        }
        if(verifica())
        {
            Tabla[1][1] = 'c';
            for(i=1;i<=R;i++)
            {
                for(j=1;j<=C;j++)
                    printf("%c",Tabla[i][j]);
                printf("\n");
            }
            continue;
        }
        printf("Impossible\n");
   }
    return 0;
}
