#include <bits/stdc++.h>

using namespace std;

pair<int , pair < string, string  > > go(string a,string b)
{
    int cur=0;
    int i;
    for(i=0;i<a.size();i++)
        {
            if(a[i]=='?')
            {
                if(b[i]=='?')
                {
                    if(cur==1)
                    {
                        a[i]='0'; b[i]='9';
                    }
                    else if(cur==2)
                    {
                        a[i]='9'; b[i]='0';
                    }
                    else
                    {
                        a[i]=b[i]='0';
                    }
                }
                else
                {
                    if(cur==1) a[i]='0';
                    else if(cur==2) a[i]='9';
                    else a[i]=b[i];
                }
            }
            else if(b[i]=='?')
            {
                if(cur==1) b[i]='9';
                else if(cur==2) b[i]='0';
                else b[i]=a[i];
            }
            else
            {
                if(a[i]>b[i]&&!cur) cur=1;
                else if(b[i]>a[i]&&!cur) cur=2;
            }
        }
        return make_pair(cur,make_pair(a,b));
}

pair<string,string> get(pair< int, pair<string,string> > x, pair< int, pair<string,string> > y)
{
    string a=x.second.first,b=x.second.second;
    string c=y.second.first,d=y.second.second;
    long long aa=0,bb=0,cc=0,dd=0;
    int i;
    for(i=0;i<a.size();i++)
    {
        aa*=10; bb*=10; cc*=10; dd*=10;
        aa+=(a[i]-'0'); bb+=(b[i]-'0'); cc+=(c[i]-'0'); dd+=(d[i]-'0');
    }
    if(llabs(aa-bb)>llabs(cc-dd))
    {
        return {c,d};
    }
    else if(llabs(aa-bb)<llabs(cc-dd))
    {
        return {a,b};
    }
    else
    {
        if(aa<cc) return {a,b};
        else if(cc<aa) return {c,d};
        else if(bb<dd) return {a,b};
        else return {c,d};
    }
    return {a,b};
}

int main()
{
    freopen("B_large.in","r",stdin);
    freopen("B_large.out","w",stdout);
    int t;
    cin >> t;
    int tc;
    for(tc=1;tc<=t;tc++)
    {
        int cur=0; // 0 - equal |  1 - a > b | 2 - a < b
        string a,b;
        cin >> a >> b;
        int i;
        pair< int, pair<string,string> >x=go(a,b);
        cur=x.first;
        if(cur==0){
            cout << "Case #" << tc << ": " << x.second.first << " " << x.second.second << endl;
            continue;
        }
        if(cur==2) swap(a,b);
        int a1=0,b1=-1;
        for(i=0;i<a.size();i++)
        {
            if(a[i]<'9'&&a[i]>='0'&&b[i]=='?'&&b1==-1) b1=i;
        }
        i=0;
        while(a[i]=='?'&&b[i]=='?')
        {
            i++;
        }
        a1=i-1;
        if(a1>b1&&b1!=-1)
        {
            b[b1]=a[b1]+1;
        }
        else
        {
            a[a1]='0';b[a1]='1';
        }
        if(cur==2) swap(a,b);
        pair<int, pair<string,string> > y = go(a,b);
        pair< string,string > ans = get(x,y);
        //cout << x.second.first << " " << x.second.second << " " << y.second.first << " " << y.second.second << endl;
        cout << "Case #" << tc << ": " << ans.first << " " << ans.second << endl;
    }
}
