#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <cstring>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <fstream>
#define si(i) scanf("%d",&i)
#define sl(i) scanf("%ld",&i)
#define sll(i) scanf("%lld",&i)
#ifndef ONLINE_JUDGE
    #define gc getchar
#else
    #define gc getchar_unlocked
#endif
#define ll long long
#define ull unsigned long long
#define rep(i,a,b) for(int i=a;i<b;i++)
#define repi(i,a,b) for(int i=a;i>b;i--)
#define MOD 1000000007


/*inline long double log2(const long double x)
{
    return  log(x) * M_LOG2E;
}*/


using namespace std;
const int _limit=100001;
template <class T> inline T read()
{
    T ret=0;
    char c=gc();
    while(c<'0'||c>'9')
        c=gc();
    while(c>='0'&&c<='9')
    {
        ret=10*ret+c-48;
        c=gc();
    }
    return ret;
}

ll counter=0;

bool check(string a)
{
    int arr[26]={0};
    char cur=a[0];
    arr[a[0]-'a']=1;
    rep(i,1,a.size())
    {
        if(a[i]!=cur)
        {
            if(arr[a[i]-'a']==1)
                return false;
            cur=a[i];
            arr[a[i]-'a']=1;
        }
    }
    return true;
}

void checker(vector <string> train, int current, int size, string a="")
{
    if(current==size)
    {
        //cout<<a <<endl;
        if(check(a))
        {
            counter++;
            return;
        }
    }
    else
    {
        rep(i,0,size)
        {
            if(train[i]=="")
                continue;
            string temp=train[i];
            string temp2=a;
            a+=train[i];
            train[i]="";
            checker(train, current+1, size, a);
            a=temp2;
            train[i]=temp;
        }
    }
}

int main()
{
    int t=read<int>();
    rep(i,0,t)
    {
        counter=0;
        int n=read<int>();
        vector <string> train;
        rep(j,0,n)
        {
            string t;
            cin>>t;
            train.push_back(t);
        }
        checker(train,0, train.size());
        cout<<"Case #"<<i+1<<": "<<counter<<endl;
    }
}
