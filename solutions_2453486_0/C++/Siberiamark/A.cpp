#include"iostream"
#include"cstdio"
using namespace std;
char M[6][6];
int main()
{
    freopen("A-small-attempt3.in","r",stdin);
    freopen("A.output.txt","w",stdout);
    int t;int i,j;int o=0;
    int ctx,cto,ctt;
    char A;
    int compelete;
    scanf("%d",&t);
    while(t--)
    {
        A='N';
        compelete=1;
        for(i=1;i<=4;i++)
        scanf("%s",M[i]+1);
        getchar();
        getchar();
        for(i=1;i<=4;i++)//行检查
        {
            ctx=0;cto=0;ctt=0;
            for(j=1;j<=4;j++)
            {
                if(M[i][j]=='.')
                compelete=0;
                if(M[i][j]=='X')
                ctx++;
                else if(M[i][j]=='O')
                cto++;
                else if(M[i][j]=='T')
                ctt++;
            }
            if(ctx==4||(ctx==3&&ctt==1))
            {A='X';continue;}
            if(cto==4||(cto==3&&ctt==1))
            {A='O';continue;}
        }
        if(A=='N')
        {
            for(i=1;i<=4;i++)//列检查
        {
            ctx=0;cto=0;ctt=0;
            for(j=1;j<=4;j++)
            {
                if(M[j][i]=='X')
                ctx++;
                else if(M[j][i]=='O')
                cto++;
                else if(M[j][i]=='T')
                ctt++;
            }
            if(ctx==4||(ctx==3&&ctt==1))
            {A='X';continue;}
            if(cto==4||(cto==3&&ctt==1))
            {A='O';continue;}
        }
        }//斜对角
        if(A=='N')
        {
            ctx=0;cto=0;ctt=0;
            for(i=1;i<=4;i++)
            {

                if(M[i][i]=='X')
                ctx++;
                else if(M[i][i]=='O')
                cto++;
                else if(M[i][i]=='T')
                ctt++;
                if(ctx==4||(ctx==3&&ctt==1))
                {A='X';continue;}
                if(cto==4||(cto==3&&ctt==1))
                {A='O';continue;}
        }
            if(A=='N')
            {
                ctx=0;cto=0;ctt=0;
                for(i=1;i<=4;i++)
                {

                    if(M[i][5-i]=='X')
                    ctx++;
                    else if(M[i][5-i]=='O')
                    cto++;
                    else if(M[i][5-i]=='T')
                    ctt++;
                    if(ctx==4||(ctx==3&&ctt==1))
                    {A='X';continue;}
                    if(cto==4||(cto==3&&ctt==1))
                    {A='O';continue;}
                }
            }
        }
        printf("Case #%d: ",++o);
        if(A=='N')
        {
            if(compelete==1)
            printf("Draw\n");
            else
            printf("Game has not completed\n");

        }
        else
        {
            if(A=='X')
            printf("X won\n");
            else
            printf("O won\n");
        }
    }

	return 0;
}
