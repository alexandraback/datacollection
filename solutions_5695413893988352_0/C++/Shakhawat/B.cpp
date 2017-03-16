#include<bits/stdc++.h>

using namespace std;


#define pii pair <string, string>
typedef long long ll;


ll minVal;


string a, b;


ll ABS(ll a1, ll b1){
    if(a1>=b1)return (a1-b1);
    return b1-a1;
}


ll stringToInt(string a){
    stringstream ss;
    ss<<a;
    ll tmp;
    ss>>tmp;
    return tmp;
}

bool comp(pii a, pii b)
{
    if(stringToInt(a.first)==stringToInt(b.first))
    {
        return stringToInt(a.second)<stringToInt(b.second);
    }
    return a.first<b.first;
}

pii ans;

void rec(string aa, string bb, int aidx)
{
    if(aidx>aa.length())return;

    ll ab = ABS(stringToInt(aa), stringToInt(bb));
    if(aa.length()==aidx )
        {
        if(minVal>ab){
            ans = pii(aa,bb);
            minVal=ab;
        }
        else if(minVal==ab)
        {
            if(comp(ans, pii(aa,bb))==0)ans=pii(aa,bb);
        }
        return;
    }
    if(aa[aidx]!='?' and bb[aidx]!='?')
        {
        rec(aa,bb,aidx+1);
    }
    else if(aa[aidx]=='?' and bb[aidx]=='?')
        {
        for(int i=0;i<=9;i++)
        {
            for(int j=0;j<=9;j++)
                {
                string t1 = aa, t2=bb;
                t1[aidx] = char(i+'0');
                t2[aidx] = char(j+'0');
                rec(t1,t2,aidx+1);
            }
        }
    }
    else if(aa[aidx]=='?')
        {
        for(int i=0;i<=9;i++)
        {
            string t1 = aa;
            aa[aidx] = char(i+'0');
            rec(aa,bb,aidx+1);
        }
    }
    else if(bb[aidx]=='?')
    {
        for(int i=0;i<=9;i++)
            {
            string t1 = bb;
            bb[aidx]=char(i+'0');
            rec(aa,bb,aidx+1);
        }
    }
}

int main()
{
//    freopen("a.txt","r",stdin);
//    freopen("b.txt","w",stdout);

    int test,cased=0;
    cin>>test;
    while(test--)
    {
        printf("Case #%d: ", ++cased);
        minVal=(1ll<<19);
        cin>>a>>b;
        rec(a,b,0);
        cout<<ans.first<<" "<<ans.second<<endl;
    }

    return 0;
}
