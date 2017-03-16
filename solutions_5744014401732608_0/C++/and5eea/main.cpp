#include <cstdio>
int b,m,l,nrt;
int main()
{
    freopen("B.in","r",stdin);
    freopen("B.out","w",stdout);
    scanf("%d",&nrt);
    for(l=1;l<=nrt;l++)
    {
        scanf("%d%d",&b,&m);
        printf("Case #%d: ",l);
        if(b==2)
        {
            if(m==1)
            {
                printf("POSSIBLE\n");
                printf("01\n00\n");
            }
            else printf("IMPOSSIBLE\n");
        }
        if(b==3)
        {
            if(m==1)
            {
                printf("POSSIBLE\n");
                printf("001\n000\n000\n");
            }
            else if(m==2)
            {
                printf("POSSIBLE\n");
                printf("011\n001\n000\n");
            }
            else printf("IMPOSSIBLE\n");
        }
        if(b==4)
        {
            if(m==1)
            {
                printf("POSSIBLE\n");
                printf("0001\n0000\n0000\n0000\n");
            }
            else if(m==2)
            {
                printf("POSSIBLE\n");
                printf("0011\n0000\n0001\n0000\n");
            }
            else if(m==3)
            {
                printf("POSSIBLE\n");
                printf("0101\n0011\n0001\n0000\n");
            }
            else if(m==4)
            {
                printf("POSSIBLE\n");
                printf("0111\n0011\n0001\n0000\n");
            }
            else printf("IMPOSSIBLE\n");
        }
        if(b==5)
        {
            if(m==1)
            {
                printf("POSSIBLE\n");
                printf("00001\n00111\n00011\n00001\n00000\n");
            }
            else if(m==2)
            {
                printf("POSSIBLE\n");
                printf("00011\n00111\n00011\n00001\n00000\n");
            }
            else if(m==3)
            {
                printf("POSSIBLE\n");
                printf("00111\n00111\n00011\n00001\n00000\n");
            }
            else if(m==4)
            {
                printf("POSSIBLE\n");
                printf("00111\n00111\n00011\n00001\n00000\n");
            }
            else if(m==5)
            {
                printf("POSSIBLE\n");
                printf("01001\n00111\n00011\n00001\n00000\n");
            }
            else if(m==6)
            {
                printf("POSSIBLE\n");
                printf("01011\n00111\n00011\n00001\n00000\n");
            }
           else  if(m==7)
            {
                printf("POSSIBLE\n");
                printf("01110\n00111\n00011\n00001\n00000\n");
            }
           else  if(m==8)
            {
                printf("POSSIBLE\n");
                printf("01111\n00111\n00011\n00001\n00000\n");
            }
            else printf("IMPOSSIBLE\n");
        }
        if(b==6)
        {
            if(m==1)
            {
                printf("POSSIBLE\n");
                printf("000001\n000000\n000000\n000000\n000000\n000000\n");
            }
            else if(m==2)
            {
                printf("POSSIBLE\n");
                printf("000011\n001111\n000111\n000011\n000001\n000000\n");
            }
            else if(m==3)
            {
                printf("POSSIBLE\n");
                printf("000110\n001111\n000111\n000011\n000001\n000000\n");
            }
            else if(m==4)
            {
                printf("POSSIBLE\n");
                printf("000111\n001111\n000111\n000011\n000001\n000000\n");
            }
            else if(m==5)
            {
                printf("POSSIBLE\n");
                printf("001001\n001111\n000111\n000011\n000001\n000000\n");
            }
            else if(m==6)
            {
                printf("POSSIBLE\n");
                printf("001011\n001111\n000111\n000011\n000001\n000000\n");
            }
            else if(m==7)
            {
                printf("POSSIBLE\n");
                printf("001110\n001111\n000111\n000011\n000001\n000000\n");
            }
            else if(m==8)
            {
                printf("POSSIBLE\n");
                printf("001111\n001111\n000111\n000011\n000001\n000000\n");
            }
            else if(m==9)
            {
                printf("POSSIBLE\n");
                printf("010001\n001111\n000111\n000011\n000001\n000000\n");
            }
            else if(m==10)
            {
                printf("POSSIBLE\n");
                printf("010011\n001111\n000111\n000011\n000001\n000000\n");
            }
            else if(m==11)
            {
                printf("POSSIBLE\n");
                printf("011010\n001111\n000111\n000011\n000001\n000000\n");
            }
            else if(m==12)
            {
                printf("POSSIBLE\n");
                printf("010111\n001111\n000111\n000011\n000001\n000000\n");
            }
            else if(m==13)
            {
                printf("POSSIBLE\n");
                printf("011010\n001111\n000111\n000011\n000001\n000000\n");
            }
            else if(m==14)
            {
                printf("POSSIBLE\n");
                printf("011011\n001111\n000111\n000011\n000001\n000000\n");
            }
            else if(m==15)
            {
                printf("POSSIBLE\n");
                printf("011110\n001111\n000111\n000011\n000001\n000000\n");
            }
            else if(m==16)
            {
                printf("POSSIBLE\n");
                printf("011111\n001111\n000111\n000011\n000001\n000000\n");
            }
            else printf("IMPOSSIBLE\n");
        }
    }
return 0;
}
