#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define X first
#define Y sencond
ll ma,mb,cm;
string s,ss;


void dp(ll mna,ll mnb,int l)
{
   // cout<<mna<<mnb<<endl;
    if(l==s.size())
    {
        if(abs(mna-mnb)<cm)
        {
            mb=mnb;
            ma=mna;
            cm=abs(mna-mnb);
        }
        else
        {
            if(abs(mna-mnb)==cm)
            {
                if(mna<ma || (ma==mna && mnb<mb) )
                {
                    mb=mnb;
                    ma=mna;
                }
            }
        }
       return;
    }

    if(s[l]=='?' && ss[l]=='?'){
    for(int i=0; i<100; i++)
    {
        dp(mna*10+i/10,mnb*10+i%10,l+1);

        }
        }

   else{
    if(s[l]=='?'){
        for(int i=0; i<10; i++){
            dp(mna*10+i,mnb*10+(ss[l]-'0'),l+1);
        }
    }else if(ss[l]=='?'){
    for(int i=0; i<10; i++){
            dp(mna*10+(s[l]-'0'),mnb*10+i,l+1);
        }
    }
    else{
        dp(mna*10+(s[l]-'0'),mnb*10+(ss[l]-'0'),l+1);
    }
   }


}


int len(int a){
    int z=1;
    while(a>9){
        z++;
        a/=10;
    }
    return z;
}

int main()
{


    freopen("B-small-attempt1.in","rt",stdin);
    freopen("out.txt","wt",stdout);

    int t;
    cin>>t;
    for(int o=1; o<=t; o++)
    {

ma=mb=0;
cm=1e9;
        //  if(o==7)break;
        int r=0;
        cin>>s>>ss;
int f=s.size();
dp(0,0,0);
string mm="",nn="";

int h=len(ma);
int hh=len(mb);
for(int i=0; i<f-h; i++)mm+='0';
for(int i=0; i<f-hh; i++)nn+='0';

        cout<<"Case #"<<o<<": "<<mm<<ma<<" "<<nn<<mb<<endl;

    }

    return 0;
}




/*
// cout<<s<<" "<<ss<<endl;
for(int i=0; i<s.size(); i++)
{
    if(s[i]=='?' && ss[i]=='?')
    {
        if(r==0)s[i]=ss[i]='0';
        else if(r>0)
        {
            s[i]='0';
            ss[i]='9';
        }
        else
        {
            ss[i]='0';
            s[i]='9';
        }
    }
    else if(s[i]!='?' && ss[i]=='?')
    {
        if(r==0)ss[i]=s[i];
        else if(r>0)
        {
            ss[i]='9';
        }
        else
        {
            ss[i]='0';
        }
    }
    else if(s[i]=='?' && ss[i]!='?')
    {

        if(r==0)s[i]=ss[i];
        else if(r>0)
        {
            s[i]='0';
        }
        else
        {
            s[i]='9';
        }
    }else{

        if(r==0){
            if(s[i]>ss[i])r=1;
            else if(s[i]<ss[i]) r=-1;
        }


    }

}
*/
