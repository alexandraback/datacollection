#include<stdio.h>
#include<stdlib.h>
#include<string.h>
main()
{
    freopen("A-small-attempt4.in", "r", stdin);
    freopen("A-smal.out","w",stdout);



    int t;
    scanf("%d", &t);
    for(int a=0; a<t; a++)
    {

        int n;
        scanf("%d", &n);
        int s[n];
        for(int b=0; b<n; b++)
            scanf("%d",&s[b]);

        int x = 0;
        int max = -1;
        int d[n];

        for(int i=0; i<n; i++)
        {
            x+=s[i];
            d[i] = s[i];
            if(s[i]>max)
            {
                max=s[i];

            }
        }
        int x2 = x;
        double ans[n];

        double v = (double)2*x/n-max;
        if(v >= 0)
        {
            for(int i=0; i<n; i++)
            {
                ans[i] = (max - s[i] + v);
            }
        }
        else
        {
            int mina = -1;
            while(x>0)
            {
                int mini = -1;
                for(int i = 0; i < n; i++)
                {
                    if(s[i] > mina && (mini < 0 || s[i] < s[mini]))
                    {
                        mini = i;
                    }
                }
                mina = s[mini];
                int need = 0;
                for(int i = 0; i < n; i++)
                    if(s[i] < s[mini])
                    {
                        need += s[mini] - s[i];
                    }
                if(need > x)
                {
                    int c = 0;
                    for(int i = 0; i < n; i++)
                    {
                        if(s[i] < s[mini])
                            c++;
                    }
                    for(int i = 0; i < n; i++)
                    {
                        if(s[i] < s[mini])
                            ans[i] = s[i] - d[i] + (double)x/c;
                        else ans[i] = s[i] - d[i];
                    }
                    x = 0;
                    break;
                }
                else
                {
                    for(int i = 0; i < n; i++)
                    {
                        if(s[i] < s[mini])
                        {
                            x -= s[mini] - s[i];
                            s[i] = s[mini];
                        }
                    }
                    if(x == 0)
                    {
                        for(int i = 0; i < n; i++)
                            ans[i] = s[i] - d[i];
                    }
                }
            }
        }

        printf("Case #%d: ", a+1);
        for(int i=0; i<n; i++) printf("%.6lf ",ans[i]*100/x2);
        printf("\n");

    }
//    system("pause");
}
