/*
ID: nishad.dawkhar
PROG: goodluck
LANG: C
*/
#include <stdio.h>
#include <stdlib.h>

void make_subsets(int a, int b, int c);
int match(int k);

int subset[7], product[10], no_of_matches=0;

int main()
{
    FILE *in  = fopen ("test.in", "r");
    FILE *out = fopen ("test.out", "w");
    int cases=1,t, i=0,j=0,p=0,a,b,c,final_a,final_b,final_c, temp,highest_match=0;
    int r,n,m,k;
    fscanf(in,"%d",&t);
    fprintf(out,"Case #1:\n");
    while(t--)
    {
        fscanf(in,"%d %d %d %d",&r,&n,&m,&k);
        while(j<r)
        {
            for(p=0,i=0; p<k; p++,i++)
            {
            fscanf(in,"%d",&product[i]);
            }
            /*make subsets*/
            for(highest_match=0,final_a=2,final_b=2,final_c=2,a=2; a<6; a++)
            {
                for(b=2; b<6; b++)
                {
                    for(c=2; c<6; c++)
                    {
                        make_subsets(a,b,c);
                        temp = match(k); //k equals number of prods to be matched
                        //if(a==2 && b==2 && c==3)
                        //printf("2,2,3 %d %d\n",temp,highest_match);
                        //if(a==3 && b==4 && c==3)
                        //printf("3,4,3 %d %d\n",temp,highest_match);
                        if(temp>highest_match)
                        {
                            highest_match = temp;
                            final_a=a;
                            final_b=b;
                            final_c=c;
                            //printf("%d%d%d\n",final_a,final_b,final_c);
                        }
                    }
                }
            }
            //printf("%d%d%d\n",final_a,final_b,final_c);
            fprintf(out,"%d%d%d\n",final_a,final_b,final_c);
            j++;
        }
    }
    return 0;
}

void make_subsets(int a, int b, int c)
{
    subset[0] = a;
    subset[1] = b;
    subset[2] = c;
    subset[3] = a*b;
    subset[4] = a*c;
    subset[5] = b*c;
    subset[6] = a*b*c;
}

int match(int k)
{
    int i, j, l,t, flag;
    int matches=0;
    for(i=0; i<k; i++)
    {
        for(flag=1,t = 0; t< i; t++)
        {
            if(product[t] == product[i])
            flag = 0;
        }
        if(flag==1)
        {
        for(j=0; j<7; j++)
        {
            if(product[i] == subset[j])
            {
            matches++;
            break;
            }
        }
        }
    }
    return matches;
}
