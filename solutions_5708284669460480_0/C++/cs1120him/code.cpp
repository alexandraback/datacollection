#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("check.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int t;
    scanf("%d",&t);
    for(int i=1;i<=t;i++)
    {
        string ss = "";
        int k,l,s;
        scanf("%d %d %d",&k,&l,&s);
        char s1[101];
        char s2[101];
        scanf("%s %s",&s1,&s2);
        int a[s];
        for(int j=0;j<s;j++)
            a[j]=0;
        int total=1;
        for(int j=0;j<s;j++)
            total = total*k;

        int ma= -1, sum = 0;
        for(int j=0;j<total;j++)
        {
            ss = "";
            for(int x=0;x<s;x++)
            {
                ss = ss + s1[a[x]];
            }
            int count=0;
            for(int x=0;x<=s-l;x++)
            {
                int flag=0;
                for(int y=x;y<x+l;y++)
                {
                    if(s2[y-x]!=ss[y])
                    {
                        flag=1;
                        break;
                    }
                }
                if(!flag)
                    count++;
            }
            ma = max(ma,count);
            sum = sum + count;
            int q=s-1;
            while(a[q]==k-1)
            {
                a[q]=0;
                q--;
            }
            a[q] = a[q] + 1;
        }
        double ans = (double)((ma*total) - sum)/(double)total;
        cout<<"Case #"<<i<<": ";
        printf("%0.8lf\n",ans);
    }
    return 0;
}
