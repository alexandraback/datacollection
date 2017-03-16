#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>
#include <cstdio>
#include <math.h>
#include <queue>
#include <stack>
#include <map>
#include <cassert>
#include <set>
using namespace std;


const int N=500;


string p,q;
string nowx,nowy;
string ansx,ansy;
long long getNum(string s) {
    long long ret=0;
    for (int i=0;i<s.size();i++) {
        assert(s[i]>='0'&&s[i]<='9');
        ret=ret*10LL+s[i]-'0';
    }
    return ret;
}
bool gg(int x) {
    string c=p;string j=q;
    for (int i=0;i<x;i++) {
        if (c[i]=='?'&&j[i]=='?') {
                c[i]='0';
                j[i]='0';
            }
            else if (c[i]!='?'&&j[i]=='?') {
                j[i]=c[i];
            }
            else if (c[i]=='?'&&j[i]!='?') {
                c[i]=j[i];
            }
            else {
                if (c[i]!=j[i]) return false;
            }
    }
    if (c[x]=='?'&&j[x]=='?') {
                c[x]='1';
                j[x]='0';
            }
            else if (c[x]!='?'&&j[x]=='?') {
               if (c[x]=='0') return false;
                j[x]=c[x]-1;
            }
            else if (c[x]=='?'&&j[x]!='?') {
                if (j[x]=='9') return false;
                c[x]=j[x]+1;
            }
            else {
                if (c[x]!=j[x]) return false;
            }
    for (int i=x+1;i<c.size();i++) {
        if (c[i]=='?'&&j[i]=='?') {
                c[i]='0';
                j[i]='9';
            }
            else if (c[i]!='?'&&j[i]=='?') {
                j[i]='9';
            }
            else if (c[i]=='?'&&j[i]!='?') {
                c[i]='0';
            }
    }
    nowx=c;nowy=j;
    return true;

}
long long big() {
    int n=p.size();
    int s=0;
    long long dif=~0ULL>>1;
    for (int i=0;i<n;i++) {
        bool now=gg(i);
        if (!now) continue;
        long long a=getNum(nowx),b=getNum(nowy);
        //if (a==315&&b==279) cout<<"cao................."<<endl;
        long long dis=abs(a-b);
        if (dif>dis) {
            dif=dis;
            ansx=nowx;
            ansy=nowy;
        }
        else if (dif==dis) {
            if (nowx<ansx) {
                ansx=nowx;
                ansy=nowy;
            }
            else if (nowx==ansx) {
                if (nowy<ansy)
                    ansy=nowy;
            }
        }
    }
    swap(p,q);
    for (int i=0;i<n;i++) {
        bool now=gg(i);
        if (!now) continue;
        swap(nowx,nowy);
        long long a=getNum(nowx),b=getNum(nowy);
        long long dis=abs(a-b);
        if (dif>dis) {
            dif=dis;
            ansx=nowx;
            ansy=nowy;
        }
        else if (dif==dis) {
            if (nowx<ansx) {
                ansx=nowx;
                ansy=nowy;
            }
            else if (nowx==ansx) {
                if (nowy<ansy)
                    ansy=nowy;
            }
        }
    }
    swap(p,q);
    //cout<<"mabjodsjgoa"<<dif<<endl;
    return dif;
}


void eql() {
    string c=p,j=q;
    int n=c.size();
    int s=0;
    long long dif=big();
    for (int i=0;i<n;i++) {
        if (s==0) {
            if (c[i]=='?'&&j[i]=='?') {
                c[i]='0';
                j[i]='0';
            }
            else if (c[i]!='?'&&j[i]=='?') {
                j[i]=c[i];
            }
            else if (c[i]=='?'&&j[i]!='?') {
                c[i]=j[i];
            }
            else {
                if (c[i]>j[i]) s=1;
                else if (c[i]<j[i]) s=-1;
            }
        }
        else if (s==1) {
            if (c[i]=='?'&&j[i]=='?') {
                c[i]='0';
                j[i]='9';
            }
            else if (c[i]!='?'&&j[i]=='?') {
                j[i]='9';
            }
            else if (c[i]=='?'&&j[i]!='?') {
                c[i]='0';
            }
        }
        else {
            if (c[i]=='?'&&j[i]=='?') {
                c[i]='9';
                j[i]='0';
            }
            else if (c[i]!='?'&&j[i]=='?') {
                j[i]='0';
            }
            else if (c[i]=='?'&&j[i]!='?') {
                c[i]='9';
            }
        }
    }
    //cout<<"gao1 "<<dif<<endl;
    string nowx=c,nowy=j;
    long long a=getNum(nowx),b=getNum(nowy);
        long long dis=abs(a-b);
        if (dif>dis) {
            dif=dis;
            ansx=nowx;
            ansy=nowy;
        }
        else if (dif==dis) {
            if (nowx<ansx) {
                ansx=nowx;
                ansy=nowy;
            }
            else if (nowx==ansx) {
                if (nowy<ansy)
                    ansy=nowy;
            }
        }
    //cout<<"gao 2"<<dif<<endl;
    cout<<ansx<<" "<<ansy<<endl;
}


string c,j;

vector<string> a,b;
void dfs(int s,int n,string now) {
    if (s>=n) {
        a.push_back(now);
        return;
    }
    if (c[s]=='?') {
        for (int i=0;i<10;i++) {
            string nn=now+char('0'+i);
            dfs(s+1,n,nn);
        }
    }
    else {
        dfs(s+1,n,now+c[s]);
    }
}

void dfs2(int s,int n,string now) {
    if (s>=n) {
        b.push_back(now);
        return;
    }
    if (j[s]=='?') {
        for (int i=0;i<10;i++) {
            string nn=now+char('0'+i);
            dfs2(s+1,n,nn);
        }
    }
    else {
        dfs2(s+1,n,now+j[s]);
    }
}
int calc(string s) {
    int ret=0;
    for (int i=0;i<s.size();i++) {
        assert(s[i]>='0'&&s[i]<='9');
        ret=ret*10+s[i]-'0';
    }
    return ret;
}
void solve() {
    int n=c.size();
    a.clear();
    b.clear();
    dfs(0,n,"");
    dfs2(0,n,"");
    int dif=0x3f3f3f3f;
    string p="0",q="0";
    for (int i=0;i<a.size();i++) {
        for (int j=0;j<b.size();j++) {
            int aa=calc(a[i]);
            int bb=calc(b[j]);
            int now=abs(aa-bb);
            if (now<dif) {
                dif=now;
                p=a[i];
                q=b[j];
            }
            else if (now==dif) {
                if (a[i]<p) {
                    p=a[i];
                    q=b[j];
                }
                else if (p==a[i]) {
                    if (b[j]<q) {
                        q=b[j];
                    }
                }
            }
        }
    }
    cout<<p<<" "<<q<<endl;
}

int main () {
    freopen("hehe.txt","r",stdin);
    freopen("papa.txt","w",stdout);
    int T;
    cin>>T;
    while (T--) {
        cin>>p>>q;
        static int cas=1;
        cout<<"Case #"<<cas++<<": ";
        eql();
    }
    return 0;
}
