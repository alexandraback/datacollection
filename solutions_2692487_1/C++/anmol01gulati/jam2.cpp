#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
#include<stdio.h>
#include<math.h>

using namespace std;

int main()
{
    int t,q,c;
    int x;
    int n,ans,temp,j;
    vector<int> mot,step;
        scanf("%d",&t);

        for (q = 1; q <= t; q++)
        {
                scanf("%d%d",&x,&n);
                ans=n;
                mot = vector<int>();
                step = vector<int>(n);
                for(j=0;j<n;j++)
                {
                        scanf("%d",&temp);
                        mot.push_back(temp);
                }
                sort(mot.begin(),mot.end());
                if(x!=1)
                {
                c=0;
                for(j=0;j<n;j++)
                {
                        while(x<=mot[j])
                        {
                                x=(2*x)-1;
                                c++;
                        }
                        step[j]=c;
                        x=x+mot[j];
                }
                for(j=0;j<n;j++)
                {
                        if((step[j]+n-j-1)<ans)
                                ans=(step[j]+n-j-1);
                }
                }
                printf("Case #%d: %d\n",q,ans);
        }
        return 0;
}
