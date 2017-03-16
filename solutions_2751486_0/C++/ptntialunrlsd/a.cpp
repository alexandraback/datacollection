#include<iostream>
#include<fstream>

using namespace std;

bool isv(char c)
{
    if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u')
        return true;
    return false;
}

void out(int k,long long int ans)
{
    cout<<"Case #"<<k<<": "<<ans<<"\n";
}

int main()
{
    int t,i,n,l,j,c,k,fc,lc,lv;
    string s;
    long long int ans=0;
    ifstream cin("input");
    ofstream cout("output");
    cin>>t;

    for(k=1;k<=t;k++)
    {
        cin>>s>>n;
        l=s.size();

        c=0;
        lv=-1;
        for(i=0;i<l;i++)
        {
            if(!isv(s[i]))
            {
                c++;
            }
            else
            {
                c=0;
                lv=i;
            }
            if(c==n)
            {
                lc=i;
                fc=lc-n+1;
                break;
            }
        }

        if(i==l)
        {
            cout<<"Case #"<<k<<": 0"<<"\n";
            continue;
        }

        ans=fc+1;
        i=i+1;
        /*while(1)
        {
            if(!isv(s[j])&&c==n)
                break;
            if(!isv(s[j]))
            {
                c--;
            }
            j++;
        }
        ans=j+1;
        i=i+1;*/
        for(;i<l;i++)
        {
            /*if(!isv(s[i]))
                c++;
            while(1)
            {
                if(!isv(s[j])&&c==n)
                    break;
                if(!isv(s[j]))
                {
                    c--;
                }
                j++;
            }
            ans+=(j+1);*/
            if(isv(s[i]))
            {
                lv=i;
            }
            if(lv<=i-n)
            {
                fc=i-n+1;
                lc=i;
            }
            ans+=(fc+1);
        }

        cout<<"Case #"<<k<<": "<<ans<<"\n";
    }

    return 0;
}







