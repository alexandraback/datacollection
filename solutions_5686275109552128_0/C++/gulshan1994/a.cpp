#include <vector>
#include <string>
#include<fstream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<set>
#include<string>
#include<iostream>
#include<algorithm>
#include<queue>
#include<cmath>
using namespace std;

int pancake(vector<int>& arr)
{
    //multiset<int>::iterator it;
    int i;
    sort(arr.begin(),arr.end());
    int val=arr[arr.size()-1];
    if(val==1||val==2||val==3)
        return val;
    //int max1,max2;
    //printf("%d\n",val);
    vector<int> temp;
    for(i=0;i<arr.size()-1;i++)
    {
        temp.push_back(arr[i]);
    }
    temp.push_back(ceil(val/2.0));
    temp.push_back(val-ceil(val/2.0));
    int max1=1+pancake(temp);
    //printf("%d\n",max1);
    temp.clear();
    for(i=0;i<arr.size();i++)
    {
        if(arr[i]>1)
            temp.push_back(arr[i]-1);
    }
    int max2=1+pancake(temp);
    //printf("%d\n",max2);
    temp.clear();
    return max1>max2?max2:max1;
}
int mini(int a,int b)
{
    return a>b?b:a;
}
int maxi(int a,int b)
{
    return a>b?a:b;
}

int main()
{
    //freopen("practice.in","r",stdin);
	freopen("B-small-attempt7.in","r",stdin);
	//freopen("D-large.in","r",stdin);
	freopen("output.out","w",stdout);
	int t,m;
	scanf("%d",&t);
	for(m=1;m<=t;m++)
    {
        int d,i;
        scanf("%d",&d);
        int p[d];
        for(i=0;i<d;i++)
            scanf("%d",&p[i]);
        int ans=*max_element(p,p+d);
        int z=2;
        int val;
        while(z<ans)
        {
            val=0;
            for(i=0;i<d;i++)
            {
                val+=(p[i]-1)/z;
            }
            ans=mini(ans,val+z);
            z++;
        }
        printf("Case #%d: ",m);
        printf("%d\n",ans);
    }
    return 0;
}
