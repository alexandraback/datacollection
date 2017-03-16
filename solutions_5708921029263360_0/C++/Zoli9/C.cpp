#include <bits/stdc++.h>
using namespace std;
int test;
int j, p, s, k;
void osszes()
{
    cout<<j*p*s<<endl;
    for(int jj=1; jj<=j; jj++)
    {
        for(int pp=1; pp<=p; pp++)
        {
            for(int ss=1; ss<=s; ss++)
            {
                cout<<jj<<" "<<pp<<" "<<ss<<endl;
            }
        }
    }
}
void k1()
{
    if(s==3 && p==3 && j==3)
    {
        cout<<9<<endl;
        cout<<"1 1 1"<<endl;
        cout<<"1 2 2"<<endl;
        cout<<"1 3 3"<<endl;
        cout<<"2 1 2"<<endl;
        cout<<"2 2 3"<<endl;
        cout<<"2 3 1"<<endl;
        cout<<"3 1 3"<<endl;
        cout<<"3 2 1"<<endl;
        cout<<"3 3 2"<<endl;
    }
    else if(s==3 && p==3 && j==2)
    {
        cout<<6<<endl;
        cout<<"1 1 1"<<endl;
        cout<<"1 2 2"<<endl;
        cout<<"1 3 3"<<endl;
        cout<<"2 1 2"<<endl;
        cout<<"2 2 3"<<endl;
        cout<<"2 3 1"<<endl;
    }
    else if(s==3 && p==3 && j==1)
    {
        cout<<3<<endl;
        cout<<"1 1 1"<<endl;
        cout<<"1 2 2"<<endl;
        cout<<"1 3 3"<<endl;
    }
    else
    {
        s=2;
        if(s==2 && p==2 && j==2)
        {
            cout<<4<<endl;
            cout<<"1 1 1"<<endl;
            cout<<"1 2 2"<<endl;
            cout<<"2 1 2"<<endl;
            cout<<"2 2 1"<<endl;
        }
        else if(s==2 && p==2 && j==1)
        {
            cout<<2<<endl;
            cout<<"1 1 1"<<endl;
            cout<<"1 2 2"<<endl;
        }
        else
        {
            cout<<1<<endl;
            cout<<"1 1 1"<<endl;
        }
    }
}
void mindharom()
{
    cout<<18<<endl;
    cout<<"1 1 1"<<endl;
    cout<<"1 2 2"<<endl;
    cout<<"1 3 3"<<endl;
    cout<<"2 1 2"<<endl;
    cout<<"2 2 3"<<endl;
    cout<<"2 3 1"<<endl;
    cout<<"3 1 3"<<endl;
    cout<<"3 2 1"<<endl;
    cout<<"3 3 2"<<endl;

    cout<<"2 1 1"<<endl;
    cout<<"2 2 2"<<endl;
    cout<<"2 3 3"<<endl;
    cout<<"3 1 2"<<endl;
    cout<<"3 2 3"<<endl;
    cout<<"3 3 1"<<endl;
    cout<<"1 1 3"<<endl;
    cout<<"1 2 1"<<endl;
    cout<<"1 3 2"<<endl;
}
void hhk()
{
    cout<<12<<endl;
    cout<<"1 1 1"<<endl;
    cout<<"2 1 1"<<endl;
    cout<<"1 2 1"<<endl;
    cout<<"2 2 1"<<endl;

    cout<<"1 2 2"<<endl;
    cout<<"2 2 2"<<endl;
    cout<<"1 3 2"<<endl;
    cout<<"2 3 2"<<endl;

    cout<<"1 3 3"<<endl;
    cout<<"2 3 3"<<endl;
    cout<<"1 1 3"<<endl;
    cout<<"2 1 3"<<endl;
}
void hhe()
{
    cout<<6<<endl;
    cout<<"1 1 1"<<endl;
    cout<<"1 2 2"<<endl;
    cout<<"1 3 3"<<endl;
    cout<<"1 1 2"<<endl;
    cout<<"1 2 3"<<endl;
    cout<<"1 3 1"<<endl;
}
int main()
{
    cin>>test;
    for(int tt=1; tt<=test; tt++)
    {
        cin>>j>>p>>s>>k;
        cout<<"Case #"<<tt<<": ";
        if(k>=s) osszes();
        else if(k==1) k1();
        else
        {
            if(s==3 && p==3 && j==3) mindharom();
            else if(s==3 && p==3 && j==2) hhk();
            else if(s==3 && p==3 && j==1) hhe();
            else if(s==3 && p==2 && j==2)
            {
                s=2;
                osszes();
            }
            else if(s==3 && p==2 && j==1)
            {
                s=2;
                osszes();
            }
            else
            {
                s=2;
                osszes();
            }
        }
    }
    return 0;
}
