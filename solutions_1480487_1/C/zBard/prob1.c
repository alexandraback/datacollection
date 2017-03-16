# include <stdio.h>


int main(void)
{
    //var
    long int t,n,a,b,more;
    long int X, Y, val[200];
    double arr[200],temp,temp2;
    //loop
    int i,j,k;
    //string

    scanf("%ld",&t);
    for(i=0;i<t;i++)
    {   
        X=0;
        scanf("%ld ",&n);
        for(j=0;j<n;j++)
        {
            scanf("%ld ",&val[j]);
            X += val[j];
        }
        
        Y=X;
        b = n;
        for(j=0;j<n;j++)
        {
            temp = (((2.0*X)/n) - val[j])/(X);
            temp *= 100;
            if (temp < 0) 
            {
                arr[j] = 0;
                b--;
                Y -= val[j];
            }
            else arr[j] = 1;
        }

        //X = Y;
        if (X == 0) printf("\n ZERO\n");
        printf("Case #%d: ",i+1);
        for(j=0;j<n;j++)
        {
            if (arr[j] == 0) continue;
            temp = (((1.0*X+Y)/b) - val[j])/(X);
            temp *= 100;
            arr[j] = temp;
            /*
            for(k=0;k<n;k++)
            {
                if(k == j)
                    continue;
                temp2 = (((val[k] - val[j]) + X)*(100.0))/(2*X);
                if (temp2 < temp)
                    temp = temp2;
                //printf("Val i %ld , j %ld : %f\n",val[j],val[k],temp2);
            }
            arr[j] = temp;
            Y += temp;*/
            //printf("%0.06f ",temp);

        }
        for(j=0;j<n;j++)
        printf("%0.06f ",(arr[j]));
        printf("\n");
     }
            
    return 1;
}

        
