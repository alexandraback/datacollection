#include <stdio.h>

int main()
{
    int testCases,t;
    int rows, columns, mines,i,j;
    int rowsLeft, columnsLeft;
    //int possible;
    char tab[50][50];

    scanf("%d",&testCases);

    for(t=1;t<=testCases;t++)
    {
        scanf("%d %d %d",&rows,&columns,&mines);

        //possible = 0;

        if(mines == 0)
        {
            printf("Case #%d:\n",t);
            for(i=0;i<rows;i++)for(j=0;j<columns;j++)tab[i][j]='.';
            tab[0][0]='c';
            for(i=0;i<rows;i++){for(j=0;j<columns;j++)printf("%c",tab[i][j]);if(i!=rows-1)printf("\n");}
            if(testCases!=t)printf("\n");
            continue;
        }
        else if(rows == 1 || columns == 1)
        {
            printf("Case #%d:\n",t);

            printf("c");
            if(rows==1)
            {
                for(i=0;i<columns-mines-1;i++)printf(".");
                for(i=0;i<mines;i++)printf("*");
            }
            else
            {
                printf("\n");
                for(i=0;i<rows-mines-1;i++){printf(".");if(i<rows-mines-1)printf("\n");}
                for(i=0;i<mines;i++){printf("*");if(i<mines-1)printf("\n");}
            }

            if(testCases!=t)printf("\n");
            continue;
        }
        else if(rows == 2 && columns == 2)
        {
            if(mines == 3)
            {
            printf("Case #%d:\nc*\n**",t);
            if(testCases!=t)printf("\n");
            continue;
            }
            else
            {
            printf("Case #%d:\nImpossible",t);
            if(testCases!=t)printf("\n");
            continue;
            }
        }
        else if(rows*columns-1==mines)
        {
        printf("Case #%d:\n",t);
        for(i=0;i<rows;i++)for(j=0;j<columns;j++)tab[i][j]='*';
        tab[0][0]='c';
        for(i=0;i<rows;i++){for(j=0;j<columns;j++)printf("%c",tab[i][j]);if(i!=rows-1)printf("\n");}
        if(testCases!=t)printf("\n");
        continue;
        }

        for(i=0;i<rows;i++)for(j=0;j<columns;j++)tab[i][j]='.';
        tab[rows-1][columns-1]='c';

        rowsLeft = rows;
        columnsLeft = columns;
        while(mines)
        {
            if(rowsLeft>columnsLeft && rowsLeft>2 && mines>=columnsLeft)
            {
                for(i=columns-columnsLeft;i<columns;i++)tab[rows-rowsLeft][i]='*';
                rowsLeft--;
                mines-=columnsLeft;
            }
            else if(rowsLeft<columnsLeft && columnsLeft>2 && mines>=rowsLeft)
            {
                for(i=rows-rowsLeft;i<rows;i++)tab[i][columns-columnsLeft]='*';
                columnsLeft--;
                mines-=rowsLeft;
            }
            else if(rowsLeft==columnsLeft && columnsLeft>2 && mines>=rowsLeft)
            {
                for(i=rows-rowsLeft;i<rows;i++)tab[i][columns-columnsLeft]='*';
                columnsLeft--;
                mines-=rowsLeft;
            }
            else
            {
                if(mines < rowsLeft-1 && columnsLeft>2)
                {
                    while(mines)
                    {
                        mines--;
                        tab[rows-rowsLeft--][columns-columnsLeft]='*';
                    }
                }
                else if(mines < columnsLeft-1 && rowsLeft>2)
                {
                    while(mines)
                    {
                        mines--;
                        tab[rows-rowsLeft][columns-columnsLeft--]='*';
                    }
                }
                else if(mines < rowsLeft-2+columnsLeft-2 && columnsLeft>2 && rowsLeft>2)
                {
                    int rowsTemp = rowsLeft;
                    int columnsTemp = columnsLeft;
                    tab[rows-rowsLeft][columns-columnsLeft]='*';
                    mines--;
                    while(mines)
                    {
                        if(rowsLeft>3){rowsLeft--;tab[rows-rowsLeft][columns-columnsTemp]='*';mines--;continue;}
                        else if(columnsLeft>3){columnsLeft--;tab[rows-rowsTemp][columns-columnsLeft]='*';mines--;continue;}
                    }
                }
                else break;
            }
        }
        if(mines)
        {
            printf("Case #%d:\nImpossible",t);
            if(testCases!=t)printf("\n");
            continue;
        }
        else
        {
            printf("Case #%d:\n",t);
            for(i=0;i<rows;i++){for(j=0;j<columns;j++)printf("%c",tab[i][j]);if(i!=rows-1)printf("\n");}
            if(testCases!=t)printf("\n");
        }

    }

    return 0;
}
