#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

#define LMAX 1000010
string m[LMAX];

string Multiply(const string &A,const string &B)
{
    if(A=="1") return B;
    if(B=="1") return A;
    if(A[0]=='-' || B[0]=='-')
    {
        if(A[0]=='-' && B[0]=='-')
        {
            string C="",D="";
            C+=A[1],D+=B[1];
            return Multiply(C,D);
        }
        else
        {
            string C="",D="";
            if(A[0]=='-') { C+=A[1]; D+=B; }
            if(B[0]=='-') { C+=A; D+=B[1]; }
            string temp = Multiply(C,D);
            if(temp[0]=='-')  temp=temp[1];
            else temp = "-" + temp;
            return temp;
        }
    }
    if(A=="i")
    {
        if(B=="i") return "-1";
        if(B=="j") return "k";
        if(B=="k") return "-j";
    }
    if(A=="j")
    {
        if(B=="i") return "-k";
        if(B=="j") return "-1";
        if(B=="k") return "i";
    }
    if(A=="k")
    {
        if(B=="i") return "j";
        if(B=="j") return "-i";
        if(B=="k") return "-1";
    }
    return "";
}

string Power(string a,ll b)
{
    if(b==1LL) return a;
    else if(b%2LL!=0LL)
    {
        string temp = Power(a,b-1);
        return Multiply(a,temp);
    }
    else
    {
        string temp = Power(a,b/2LL);
        return Multiply(temp,temp);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    /*freopen("/Users/Ayur/Downloads/C-large.in","r",stdin);
    freopen("/Users/Ayur/Downloads/C-output.txt","w",stdout);*/
    /*string ss[]={"1","-1","i","j","k","-i","-j","-k"};
    string s,s1,s2; int i,j;
    for(i=0;i<8;i++)
    {
        cout<<ss[i]<<" : ";
        for(j=1;j<10;j++)
            cout<<Power(ss[i],j)<<' ';
        cout<<'\n';
    }*/
    /*string s="-j";
    ll x=1000000000001LL;
    cout<<Power(s,x);*/
    int t,tt,l,i,j,k,cnt;
    ll x;
    string s,p,temp,q;
    cin>>t;
    for(tt=1;tt<=t;tt++)
    {
        cout<<"Case #"<<tt<<": ";
        cin>>l>>x;
        cin>>s;
        if((ll)l*x<3LL) { cout<<"NO\n"; continue; }
        temp = s[0];
        m[0] = temp;
        for(i=1;i<l;i++)
        {
            temp=s[i];
            m[i]=Multiply(m[i-1],temp);
        }
        p=Power(m[l-1],x);
        if(p!="-1") cout<<"NO\n";
        else
        {
           /* cnt=0; posn=-1;
            for(j=0;j<l;j++)
            {
                if(m[j]=="i")
                {
                    cnt++;
                    posn=j;
                    break;
                }
            }
            if(cnt==0)
            {
                for(i=1;i<=10;i++)
                {
                    m[0]=Multiply(q,m[0]);
                    for(k=1;k<l;k++)
                    {
                        temp=s[k];
                        m[k]=Multiply(m[k-1],temp);
                    }
                    for(j=0;j<l;j++)
                    {
                        if(m[j]=="i")
                        {
                            cnt++;
                            posn=j;
                            break;
                        }
                    }
                    if(cnt==1)
                        break;
                }
            }
            if(cnt==0) cout<<"NO\n";
            else
            {
                for(j=posn+1;j<l;j++)
                {
                    if(m[j]=="k")
                    {
                        cnt++;
                        posn=j;
                        break;
                    }
                }
                if(cnt==1)
                {
                    for(i=1;i<=10;i++)
                    {
                        m[0]=Multiply(q,m[0]);
                        for(k=1;k<l;k++)
                        {
                            temp=s[k];
                            m[k]=Multiply(m[k-1],temp);
                        }
                        for(j=0;j<l;j++)
                        {
                            if(m[j]=="k")
                            {
                                cnt++;
                                posn=j;
                                break;
                            }
                        }
                        if(cnt==2)
                            break;
                    }
                }
                if(cnt==2 && (ll)posn<((ll)l*x)) cout<<"YES\n";
                else cout<<"NO\n";
            }*/
            k=l;
            x=min(x,50LL);
            for(i=2;i<x;i++)
            {
                for(j=0;j<l;j++)
                {
                    temp=s[j];
                    m[k]=Multiply(m[k-1],temp);
                    k++;
                }
            }
            cnt=0;
            for(i=0;i<l*x;i++)
            {
                if(m[i]=="i")
                {
                    cnt++;
                    break;
                }
            }
            if(cnt==0) cout<<"NO\n";
            else
            {
                for(j=i+1;j<l*x;j++)
                {
                    if(m[j]=="k")
                    {
                        cnt++;
                        break;
                    }
                }
                if(cnt==2) cout<<"YES\n";
                else cout<<"NO\n";
            }
           
        }
    }
    return 0;
}