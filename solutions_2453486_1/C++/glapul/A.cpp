#include<cstdio>
using namespace std;

char b [4][4];

bool test(char t)
{
    for(int i=0;i<4;i++)
    {
        bool res=true;
        for(int j=0;j<4;j++)
            if(b[i][j]!=t && b[i][j]!='T')
                res=false;
        if(res)
            return true;
    }
    for(int i=0;i<4;i++)
    {
        bool res=true;
        for(int j=0;j<4;j++)
            if(b[j][i]!=t && b[j][i]!='T')
                res=false;
        if(res)
            return true;
    }
    bool res=true;
    for(int i=0;i<4;i++)
    {
        if(b[i][i]!=t && b[i][i]!='T')
                res=false;
    }
    if(res)
        return true;
    res=true;
    for(int i=0;i<4;i++)
    {
        if(b[i][3-i]!=t && b[i][3-i]!='T')
                res=false;
    }
    if(res)
        return true;
    return false;
}
int main()
{
    int z;
    scanf("%d",&z);
    for(int zz=1;zz<=z;zz++)
    {
        for(int i=0;i<4;i++)
            scanf("%s",b[i]);
        int e=0;
        for(int i=0;i<4;i++)
            for(int j=0;j<4;j++)
                if(b[i][j]=='.')
                    e++;
        printf("Case #%d: ",zz);
        if(test('X'))
            printf("X won\n");
        else if(test ('O'))
            printf("O won\n");
        else if(e==0)
            printf("Draw\n");
        else
            printf("Game has not completed\n");

        //scanf("%*s");
    }


}
