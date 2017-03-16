#include<iostream>
#include<stdio.h>
#include<string.h>
#include<vector>
#include<algorithm>
#include<map>
#include<math.h>
#include<climits>
using namespace std;

struct nod
{
    int day, x, y, str;
}arr[110];

int height[500], attmax[500];

int comp(nod a, nod b)
{
    return (a.day<b.day);
}

int main()
{
    freopen("inp.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int t, tr, att, stday, attl;
    scanf("%d",&t);
    int j=0;
    int caseno=1;
    while(t--)
    {
        for(int i=0; i<500; i++)
            height[i]=0;
        j=0;
        att=0;
        scanf("%d",&tr);
        while(tr--)
        {
            scanf("%d%d%d%d%d", &(arr[j].day), &attl, &(arr[j].x), &(arr[j].y), &(arr[j].str));
            att+=attl;
            arr[j].x+=250;
            arr[j].y+=250;
            j++;
            int a, b, c;
            scanf("%d%d%d",&a,&b,&c);
            attl--;
            while(attl--)
            {
                arr[j].day=(arr[j-1].day)+a;
                arr[j].x=arr[j-1].x+b;
                arr[j].y=arr[j-1].y+b;
                arr[j].str=arr[j-1].str+c;
                j++;
            }
        }
        sort(arr, arr+att, comp);
        int ans=0;
        for(int i=0; i<att; i++)
        {
            int flag=0;
            for(int j=((arr[i].x)+1); j<=(arr[i].y); j++)
            {
                if(flag)
                    break;
                if(height[j]<arr[i].str)
                {
                    flag=1;
                    ans++;
                }
            }
            if(i==0||arr[i].day!=arr[i-1].day)
            {
                for(int j=0; j<500; j++)
                    attmax[j]=0;
            }
            for(int j=arr[i].x+1; j<=arr[i].y; j++)
            {
                attmax[j]=max(attmax[j], arr[i].str);
            }
            if(i==(att-1)||(arr[i].day!=arr[i+1].day))
            {
                for(int j=0; j<500; j++)
                {
                    if(height[j]<attmax[j])
                        height[j]=attmax[j];
                }
            }
        }
        printf("Case #%d: %d\n", caseno++, ans);
    }
    return 0;
}
