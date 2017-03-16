#include<stdio.h>
#include<stdlib.h>


int main()
{

        int t;
        FILE *ip = fopen("A-large.in", "r");
        FILE *op = fopen("A-large-output.txt","w");
        fscanf(ip,"%d",&t);

        for(int iterationCount = 1; iterationCount<=t; iterationCount++)
        {
            printf("\nHere");
            int n;
            fscanf(ip,"%d",&n);

            int **array = (int**)malloc(sizeof(int)*n);
            for(int i=0;i<n;i++)
            {
                array[i] = (int*)malloc(sizeof(int)*n);
            }
            for(int i=0;i<n;i++)
                for(int j=0;j<n;j++)
                    array[i][j]=0;


            for(int i=0;i<n;i++)
            {
                int m;
                fscanf(ip,"%d",&m);

                for(int j=0;j<m;j++)
                {
                    int index;
                    fscanf(ip,"%d",&index);

                    array[i][index-1] = 1;

                }
            }

            for(int k=0;k<n;k++)
            {
                for(int i=0;i<n;i++)
                {
                    for(int j=0;j<n;j++)
                    {
                        if(array[i][k]==1 && array[k][j]==1)
                            array[i][j]+=1;
                    }

                }
            }
            int flag = 0;
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                {

                    if(array[i][j]>1)
                        flag = 1;
                }

            }


            if(flag==1)
                fprintf(op,"Case #%d: Yes\n",iterationCount);
            else
                fprintf(op,"Case #%d: No\n",iterationCount);
        }

        fclose(op);
        fclose(ip);
        return 0;
}




