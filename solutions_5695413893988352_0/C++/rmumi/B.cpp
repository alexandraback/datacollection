#include <bits/stdc++.h>
#define mp make_pair
#define xx first
#define yy second
#define pb push_back
using namespace std;

bool odg(int x,string a)
{
    if(x>99 && a.size()<3)return 0;
    if(x>9 && a.size()<2) return 0;
    for(int i=1,j=(int)a.size()-1;j>=0;i*=10,j--)
        if(!(a[j]=='?' || (x/i)%10==(a[j]-'0')))return 0;
    return 1;
}


int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);

    int T;
    scanf("%d",&T);

    string a,b;

    for(int CASE=1;CASE<=T;CASE++)
    {
        printf("Case #%d: ",CASE);
        cin>>a>>b;
        int veci=0,svap=0;
        string oa=a,ob=b;
        int minio=1<<29,minia,minib;
        for(int i=0;i<999;i++)
        {
            for(int j=0;j<999;j++)
            {
                if(odg(i,a) && odg(j,b) && abs(i-j)<minio)
                {
                    minia=i;minib=j;minio=abs(i-j);
                }
            }
        }

        if(a.size()==3)
            printf("%03d %03d\n",minia,minib);
        if(a.size()==2)
            printf("%02d %02d\n",minia,minib);
        if(a.size()==1)
            printf("%01d %01d\n",minia,minib);
/*
        for(int i=0;i<a.size();i++)
        {
            if(a[i]!='?' && b[i]!='?')
            {
                if(a[i]>b[i])
                {
                    svap=1;swap(a,b);
                }
               veci=1;
               continue;
            }
            if(veci==0)
            {
                if(a[i]=='?' && b[i]=='?')
                    a[i]=b[i]='0';
                if(a[i]=='?')
                    a[i]=b[i];
                if(b[i]=='?')
                    b[i]=a[i];
            }else{
                if(a[i]=='?' && b[i]=='?')
                    {a[i]='9';b[i]='0';}
                if(a[i]=='?')
                    a[i]='9';
                if(b[i]=='?')
                    b[i]='0';
            }

        }
        if(svap)swap(a,b);
        cout<<a<<" "<<b<<endl;*/
    }
    return 0;
}
