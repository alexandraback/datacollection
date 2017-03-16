#include<cstdio>

int main()
{
    int T,tc,a,b,c,d,mod,temp,digit,skor;
    scanf("%d",&T);
    for(tc=1;tc<=T;tc++)
    {
        scanf("%d%d",&a,&b);
        if(a>b)
        {
            int temp = a;
            a = b;
            b = temp;
        }
        mod = 1;
        while(mod<b) mod *= 10;
        if(mod>b) mod /= 10;
        skor = 0;
        for(c=a;c<b;c++)
        {
            for(d=c+1;d<=b;d++)
            {
                temp = c;
                do
                {
                    digit = temp/mod;
                    temp = (temp%mod)*10 + digit;
                    if(temp==d)
                    {
                        skor++;
                        break;
                    }
                }
                while(temp!=c);
            }
        }
        printf("Case #%d: %d\n",tc,skor);
    }
    return 0;
}
