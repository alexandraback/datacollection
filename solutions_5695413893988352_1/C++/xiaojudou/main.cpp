#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<set>
#include<map>
#include<cmath>
#include<queue>
#include<vector>
#include<fstream>
#define eps 1e-5
#define mod 1000000007
using namespace std;
int t,n;
string j,c;
long long ans,ansj,ansc;
string ct,jt;
void upd(string cc,string jj)
{
    long long nc=0,nj=0;
    for(int i=0;i<(int)cc.length();++i)
    {
        if(cc[i]=='?')cc[i]='0';
        if(jj[i]=='?')jj[i]='0';
        nc=nc*10ll+(long long)(cc[i]-'0');
        nj=nj*10ll+(long long)(jj[i]-'0');
    }
    if(abs(nc-nj)<ans && nc<=ansc && nj<=ansj)
    {
        ans=abs(nc-nj);
        ct=cc;
        jt=jj;
    }
}
void dfs(int i,string cc,string jj){
    int lt=(int)cc.length();
    if(i>=lt){
        upd(cc,jj);return;
    }
    if(cc[i]==jj[i])dfs(i+1,cc,jj);
    string tmpc=cc,tmpj=jj;
    if(cc[i]=='?'){
        tmpc=cc,tmpj=jj;
        if((int)(jj[i]-'0')>0)
        {
            tmpc[i]=(char)(jj[i]-1);
            for(int j=i+1;j<lt;++j)
            {if(tmpc[j]=='?')tmpc[j]='9';
                if(tmpj[j]=='?')tmpj[j]='0';
            }
            upd(tmpc,tmpj);
        }
        
        
        tmpc=cc,tmpj=jj;
        tmpc[i]=tmpj[i];
        dfs(i+1,tmpc,tmpj);
        
        tmpc=cc,tmpj=jj;
        if((int)(jj[i]-'0')<9)
        {
            tmpc[i]=(char)(jj[i]+1);
            for(int j=i+1;j<lt;++j)
            {
                if(tmpc[j]=='?')tmpc[j]='0';
                if(tmpj[j]=='?')tmpj[j]='9';
            }
            upd(tmpc,tmpj);
        }
        
        tmpc=cc,tmpj=jj;
        if(i>=0 && cc[i-1]=='?' && jj[i-1]=='?')
        {
            tmpc[i-1]='1';
            tmpj[i-1]='0';
            for(int j=i+1;j<lt;++j)
            {
                if(tmpc[j]=='?')tmpc[j]='0';
                if(tmpj[j]=='?')tmpj[j]='9';
            }
            upd(tmpc,tmpj);
        }
    
    }else if(jj[i]=='?'){
        tmpc=cc,tmpj=jj;
        if((int)(cc[i]-'0')>0)
        {
            tmpj[i]=(char)(cc[i]-1);
            for(int j=i+1;j<lt;++j)
            {if(tmpc[j]=='?')tmpc[j]='0';
                if(tmpj[j]=='?')tmpj[j]='9';
            }
            upd(tmpc,tmpj);
        }
        
        
        tmpc=cc,tmpj=jj;
        tmpj[i]=tmpc[i];
        dfs(i+1,tmpc,tmpj);
        
        tmpc=cc,tmpj=jj;
        if((int)(cc[i]-'0')<9)
        {
            tmpj[i]=(char)(cc[i]+1);
            for(int j=i+1;j<lt;++j)
            {
                if(tmpc[j]=='?')tmpc[j]='9';
                if(tmpj[j]=='?')tmpj[j]='0';
            }
            upd(tmpc,tmpj);
        }
        
        tmpc=cc,tmpj=jj;
        if(i>=0 && cc[i-1]=='?' && jj[i-1]=='?')
        {
            tmpc[i-1]='0';
            tmpj[i-1]='1';
            for(int j=i+1;j<lt;++j)
            {
                if(tmpc[j]=='?')tmpc[j]='9';
                if(tmpj[j]=='?')tmpj[j]='0';
            }
            upd(tmpc,tmpj);
        }
    }else{
        tmpc=cc,tmpj=jj;
        if(cc[i]>jj[i])
        {
            for(int j=i+1;j<lt;++j)
            {
                if(tmpc[j]=='?')tmpc[j]='0';
                if(tmpj[j]=='?')tmpj[j]='9';
            }
            upd(tmpc,tmpj);
            
        }else if(cc[i]<jj[i])
        {
            for(int j=i+1;j<lt;++j)
            {
                if(tmpc[j]=='?')tmpc[j]='9';
                if(tmpj[j]=='?')tmpj[j]='0';
            }
            upd(tmpc,tmpj);
        }else
        {
            dfs(i+1,tmpc,tmpj);
        }
        
        
        if(i>=0 && cc[i-1]=='?' && jj[i-1]=='?')
        {
            tmpc=cc,tmpj=jj;
            tmpc[i-1]='1';
            tmpj[i-1]='0';
            for(int j=i+1;j<lt;++j)
            {
                if(tmpc[j]=='?')tmpc[j]='0';
                if(tmpj[j]=='?')tmpj[j]='9';
            }
            upd(tmpc,tmpj);
            
            tmpc=cc,tmpj=jj;
            tmpc[i-1]='0';
            tmpj[i-1]='1';
            for(int j=i+1;j<lt;++j)
            {
                if(tmpc[j]=='?')tmpc[j]='9';
                if(tmpj[j]=='?')tmpj[j]='0';
            }
            upd(tmpc,tmpj);
        }
    }
};
int main(){
    freopen("B-large.in.txt","r",stdin);
    freopen("b.out","w",stdout);

    cin>>t;
    for(int _=1;_<=t;++_){
        cin>>c>>j;
        ans=1ll<<61;
        ansj=ansc=ans;
        ct="";jt="";
                dfs(0,c,j);
        
        cout<<"Case #"<<_<<": "<<ct<<" "<<jt;

                cout<<endl;
    }
    return 0;
}