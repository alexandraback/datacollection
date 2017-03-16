#include <bits/stdc++.h>

using namespace std;

char c[100001],d[100001];
int array[100010][2];
map < pair<int,int>, int> my_map;
map < char,int> my;

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    my_map[make_pair(1,1)] = 1;
    my_map[make_pair(1,2)] = 2;
    my_map[make_pair(1,3)] = 3;
    my_map[make_pair(1,4)] = 4;
    my_map[make_pair(2,1)] = 2;
    my_map[make_pair(2,2)] = -1;
    my_map[make_pair(2,3)] = 4;
    my_map[make_pair(2,4)] = -3;
    my_map[make_pair(3,1)] = 3;
    my_map[make_pair(3,2)] = -4;
    my_map[make_pair(3,3)] = -1;
    my_map[make_pair(3,4)] = 2;
    my_map[make_pair(4,1)] = 4;
    my_map[make_pair(4,2)] = 3;
    my_map[make_pair(4,3)] = -2;
    my_map[make_pair(4,4)] = -1;

    my['1'] = 1;
    my['i'] = 2;
    my['j'] = 3;
    my['k'] = 4;
    int t;
    scanf("%d",&t);
    for(int j=1;j<=t;j++)
    {
        int l;
        long long x;
        scanf("%d %lld",&l,&x);
        scanf("%s",&c);
        array[0][0] = my[c[0]];
        array[0][1] = 1;
        for(int i=1;i<l;i++)
        {
            int ans = array[i-1][1]*my_map[make_pair(array[i-1][0],my[c[i]])];
            array[i][0] = abs(ans);
            if(ans<0)
                array[i][1] = -1;
            else array[i][1] = 1;
        }
        int check,flag;
        if(x%4==1)
        {
            check = array[l-1][0];
            flag = array[l-1][1];
        }
        if(x%4==2)
        {
            check = my_map[make_pair(array[l-1][0],array[l-1][0])];
            if(check<0)
                flag=-1;
            else flag=1;
            check = abs(check);
        }
        if(x%4==3)
        {
            int check1,flag1;
            check1 = my_map[make_pair(array[l-1][0],array[l-1][0])];
            if(check1<0)
                flag1=-1;
            else flag1=1;
            check1 = abs(check1);
            check = array[l-1][1]*flag1*my_map[make_pair(array[l-1][0],check1)];
            if(check<0)
                flag=-1;
            else flag=1;
            check = abs(check);
        }
        if(x%4==0)
        {
            check=1;
            flag=1;
        }
        if(check!=1 || flag!=-1)
        {
            cout<<"Case #"<<j<<": "<<"No\n";
            continue;
        }
        long long k = min(x,(long long)10);
        int s=0;
        while(k--)
        {
            for(int i=0;i<l;i++)
            {
                d[s++] = c[i];
            }
        }
        array[0][0] = my[d[0]];
        array[0][1] = 1;
        for(int i=1;i<s;i++)
        {
            int ans = array[i-1][1]*my_map[make_pair(array[i-1][0],my[d[i]])];
            array[i][0] = abs(ans);
            if(ans<0)
                array[i][1] = -1;
            else array[i][1] = 1;
        }
        int flag1=0,flag2=0;
        int i=0;
        for(;i<s;i++)
        {
            if(array[i][0]==2 && array[i][1]==1)
            {
                flag1=1;
                break;
            }
        }
        for(;i<s;i++)
        {
            if(array[i][0]==4 && array[i][1]==1)
            {
                flag2=1;
                break;
            }
        }
        if(flag1==1 && flag2==1)
        {
            cout<<"Case #"<<j<<": "<<"Yes\n";
        }
        else
        {
            cout<<"Case #"<<j<<": "<<"No\n";
        }
    }
    return 0;
}
