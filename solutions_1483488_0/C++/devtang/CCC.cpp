#include<iostream>
#include<cstdio>
using namespace std;
int a,b;
int T;
int len;
int data[9];
int note[2222222];

inline int pow(int x)
{
    int re;
    int temp = x;
    int ans=0;

    for(int i=1;i<len;i++)
    {
        re = temp%10;
        re *= data[len-1];
        temp /= 10;
        temp += re;
        if(temp > b)
        {
            continue;
        }
        if(note[temp] == x)
        {
            continue;
        }
        note[temp] = x;
        if(x < temp )
        {
            ans++;
        }
    }
    return ans;
}

int start()
{
    int ans = 0;
    for(int i=a;i<=b;i++)
    {
        ans += pow(i);
    }
    return ans;
}

void init()
{
    data[0]=1;
    data[1]=10;
    data[2]=100;
    data[3]=1000;
    data[4]=10000;
    data[5]=100000;
    data[6]=1000000;
    data[7]=10000000;
    data[8]=100000000;
    return ;
}

int main()
{
    freopen("C-small-attempt0.in","r",stdin);
    freopen("myresult.txt","w+",stdout);
    init();
    cin>>T;
    for(int tt=1;tt<=T;tt++)
    {
        cin>>a>>b;
        for (int i(0); i<2222222; ++i)note[i] = i;
        int temp = b;
        len = 0;
        while(temp>0)
        {
            len++;
            temp /= 10;
        }
        cout<<"Case #"<<tt<<": ";
        cout<<start()<<endl;
    }
    return 0;
}



