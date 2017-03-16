#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
#include<map>
#include<string>

using namespace std;

int stoi1(string s)
{
    int k=0;
    for(int i=0;i<s.length();i++)
    {
        k=k*10+(s[i]-'0');
    }
    return k;
}

int main()
{
	int t;
    cin>>t;
    int cnt=1;
    while(t--)
    {
        string a,b;
        cin>>a>>b;
        string a1=a,b1=b;
        int n=a.length();
        string r1="10000",r2="10000";
        int min=1000;
        for(int i1=0;i1<10;i1++)
            for(int j1=0;j1<10;j1++)
                for(int k1=0;k1<10;k1++)
                    for(int i2=0;i2<10;i2++)
                        for(int j2=0;j2<10;j2++)
                            for(int k2=0;k2<10;k2++)
                                {
                                    a=a1;
                                    b=b1;
                                    if(a[0]=='?')
                                        a[0]='0'+i1;
                                    if(n>1&&a[1]=='?')
                                        a[1]='0'+j1;
                                    if(n>2&&a[2]=='?')
                                        a[2]='0'+k1;
                                    if(b[0]=='?')
                                        b[0]='0'+i2;
                                    if(n>1&&b[1]=='?')
                                        b[1]='0'+j2;
                                    if(n>2&&b[2]=='?')
                                        b[2]='0'+k2;
                                    int x= stoi1(a);
                                    int y= stoi1(b);
                                    if(abs(x-y)<=min)
                                    {
                                        if(abs(x-y)==min)
                                        {
                                            if(x<=stoi1(r1))
                                            {
                                                if(x==stoi1(r1))
                                                {
                                                    if(y<=stoi1(r2))
                                                    {
                                                        r1=a;
                                                        r2=b;
                                                    }
                                                }
                                                else
                                                {
                                                    r1=a;
                                                    r2=b;
                                                }
                                            }
                                        }
                                        else
                                        {
                                        min=abs(x-y);
                                        r1=a;
                                        r2=b;
                                        }
                                    }
                                }
    	cout<<"Case #"<< cnt++<<": "<<r1<<' '<<r2<<endl;
    }
}