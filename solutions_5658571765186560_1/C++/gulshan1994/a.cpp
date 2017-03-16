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
	//freopen("D-small-attempt0.in","r",stdin);
	freopen("D-large.in","r",stdin);
	freopen("output.out","w",stdout);
	int t,m;
	scanf("%d",&t);
	for(m=1;m<=t;m++)
    {
        int X,R,C;
        scanf("%d %d %d",&X,&R,&C);
        bool ans=true;
        if(X>7)
            ans=false;
        else if(X>R&&X>C)
            ans = false;
        else if((R*C)%X!=0)
            ans = false;
        else if((X + 1)/2>mini(R,C))
            ans = false;
        else if(X==1||X==2||X==3)
            ans = true;
        else if(X == 4)
            ans=mini(R, C)>2;
        else if(X==5)
            ans=!(mini(R, C)==3&&maxi(R, C)==5);
        else if(X==6)
            ans=mini(R, C)>3;

        printf("Case #%d: ",m);
        if(ans)
            printf("GABRIEL\n");
        else
            printf("RICHARD\n");
    }
    return 0;
}
