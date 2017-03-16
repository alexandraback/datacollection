using namespace std;
#include <algorithm>
#include <iostream>
#include <iterator>
#include <numeric>
#include <sstream>
#include <fstream>
#include <cassert>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cstdio>
#include <vector>
#include <cmath>
#include <queue>
#include <deque>
#include <stack>
#include <list>
#include <map>
#include <set>

typedef long long LL;
LL strtoi(string s){
    LL ans=0;
    for (char ch:s){
        ans=ans*10+ch-'0';
    }
    return ans;
}
const LL inf=1000000000000000000LL;
LL err;
LL mins;
LL mint;
string minstr,minttr;
void cc(string ts,string tt){
    LL s=strtoi(ts);
    LL t=strtoi(tt);
    LL c=abs(s-t);
    if (c<err){
        err=c;
        mins=s;
        minstr=ts;
        mint=t;
        minttr=tt;
    }else if (c==err&&s<mins){
        mins=s;
                minstr=ts;
        mint=t;
                minttr=tt;
    }else if (c==err&&s==mins&&t<mint){
        mint=t;
                minttr=tt;
    }
}
int main(){
    freopen("bsmall.in","r",stdin);
    freopen("bsmall.out","w",stdout);
    int t;
    cin>>t;
    cerr<<strtoi("123232323")<<endl;
    cerr<<inf<<endl;
    for (int time=1;time<=t;time++){
        string s,t;
        string ts,tt;
        cin>>s>>t;
        cerr<<s<<" "<<t<<endl;
        err=inf;
        mins=inf;
        mint=inf;
        minstr=s;
        minttr=t;
        int n=s.size();
        int check=0;
        int i=0;
        while (i<n){
            if (s[i]!='?'&&t[i]!='?'&&s[i]!=t[i]){
                break;
            }
            i++;
        }
        cerr<<time<<" "<<i<<endl;
        if (i==n){
                            for (int i=0;i<n;i++){
                    if (s[i]=='?')
                        if (t[i]=='?') s[i]='0';
                            else s[i]=t[i];
                    if (t[i]=='?')
                        if (s[i]=='?') t[i]='0';
                            else t[i]=s[i];
                }
                    minstr=s;
        minttr=t;
        }
        else{
            int now=i;
            cerr<<"now"<<now<<endl;
            if (s[now]>t[now]){
                ts=s;tt=t;
                for (int i=0;i<now;i++){
                    if (ts[i]=='?')
                        if (tt[i]=='?') ts[i]='0';
                            else ts[i]=tt[i];
                    if (tt[i]=='?')
                        if (ts[i]=='?') tt[i]='0';
                            else tt[i]=ts[i];
                }
                for (int i=now+1;i<n;i++){
                    if (ts[i]=='?') ts[i]='0';
                    if (tt[i]=='?') tt[i]='9';
                }
                cc(ts,tt);
                cerr<<ts<<" "<<tt<<endl;
                ts=s;tt=t;
                for (int i=now+1;i<n;i++){
                    if (ts[i]=='?') ts[i]='9';
                    if (tt[i]=='?') tt[i]='0';
                }
                int i;
                for (i=now-1;i>=0;i--){
                    if (ts[i]=='?'||tt[i]=='?'){
                        if (ts[i]!='?')
                            if (ts[i]=='9') tt[i]='0';
                            else {
                                    tt[i]=ts[i]+1;
                                    break;
                            }
                        else if (tt[i]!='?')
                            if (tt[i]=='0') ts[i]='9';
                            else {
                                 ts[i]=tt[i]-1;
                                 break;
                            }
                        else{
                            ts[i]='0';
                            tt[i]='1';
                            break;
                        }
                    }
                }
                cerr<<"i"<<i<<endl;
                cerr<<ts<<" "<<tt<<endl;
                for (int j=0;j<i;j++){
                       if (ts[j]=='?')
                        if (tt[j]=='?') ts[j]='0';
                            else ts[j]=tt[j];
                    if (tt[j]=='?')
                        if (ts[j]=='?') tt[j]='0';
                            else tt[j]=ts[j];
                }
                cc(ts,tt);
                cerr<<ts<<" "<<tt<<endl;

                                ts=s;tt=t;
                for (int i=now+1;i<n;i++){
                    if (ts[i]=='?') ts[i]='9';
                    if (tt[i]=='?') tt[i]='0';
                }
                //int i;
                for (i=now-1;i>=0;i--){
                    if (ts[i]=='?'||tt[i]=='?'){
                        if (ts[i]!='?')
                            if (ts[i]=='9') tt[i]='0';
                            else {
                                    tt[i]=ts[i]+1;
                                    break;
                            }
                        else if (tt[i]!='?')
                            if (tt[i]=='0') ts[i]='9';
                            else {
                                 ts[i]=tt[i]-1;
                                 break;
                            }
                        else{
                            ts[i]='9';
                            tt[i]='0';

                        }
                    }
                }
                for (int j=0;j<i;j++){
                       if (ts[j]=='?')
                        if (tt[j]=='?') ts[j]='0';
                            else ts[j]=tt[j];
                    if (tt[j]=='?')
                        if (ts[j]=='?') tt[j]='0';
                            else tt[j]=ts[j];
                }
                cc(ts,tt);
                cerr<<ts<<" "<<tt<<endl;
            }else{
                 ts=s;tt=t;
                for (int i=0;i<now;i++){
                    if (ts[i]=='?')
                        if (tt[i]=='?') ts[i]='0';
                            else ts[i]=tt[i];
                    if (tt[i]=='?')
                        if (ts[i]=='?') tt[i]='0';
                            else tt[i]=ts[i];
                }
                for (int i=now+1;i<n;i++){
                    if (tt[i]=='?') tt[i]='0';
                    if (ts[i]=='?') ts[i]='9';
                }
                cc(ts,tt);
                cerr<<ts<<" "<<tt<<endl;
                ts=s;tt=t;
                for (int i=now+1;i<n;i++){
                    if (ts[i]=='?') ts[i]='0';
                    if (tt[i]=='?') tt[i]='9';
                }
                int i;
                for (i=now-1;i>=0;i--){
                    if (ts[i]=='?'||tt[i]=='?'){
                        if (ts[i]!='?')
                            if (ts[i]=='9') tt[i]='0';
                            else {
                                    tt[i]=ts[i]-1;
                                    break;
                            }
                        else if (tt[i]!='?')
                            if (tt[i]=='9') ts[i]='0';
                            else {
                                 ts[i]=tt[i]+1;
                                 break;
                            }
                        else{
                            ts[i]='1';
                            tt[i]='0';
                            break;
                        }
                    }
                }
                for (int j=0;j<i;j++){
                       if (ts[j]=='?')
                        if (tt[j]=='?') ts[j]='0';
                            else ts[j]=tt[j];
                    if (tt[j]=='?')
                        if (ts[j]=='?') tt[j]='0';
                            else tt[j]=ts[j];
                }
                cc(ts,tt);
                cerr<<ts<<" "<<tt<<endl;
                                ts=s;tt=t;
                for (int i=now+1;i<n;i++){
                    if (ts[i]=='?') ts[i]='0';
                    if (tt[i]=='?') tt[i]='9';
                }
                //int i;
                for (i=now-1;i>=0;i--){
                    if (ts[i]=='?'||tt[i]=='?'){
                        if (ts[i]!='?')
                            if (ts[i]=='9') tt[i]='0';
                            else {
                                    tt[i]=ts[i]-1;
                                    break;
                            }
                        else if (tt[i]!='?')
                            if (tt[i]=='9') ts[i]='0';
                            else {
                                 ts[i]=tt[i]+1;
                                 break;
                            }
                        else{
                            ts[i]='0';
                            tt[i]='9';

                        }
                    }
                }
                for (int j=0;j<i;j++){
                       if (ts[j]=='?')
                        if (tt[j]=='?') ts[j]='0';
                            else ts[j]=tt[j];
                    if (tt[j]=='?')
                        if (ts[j]=='?') tt[j]='0';
                            else tt[j]=ts[j];
                }
                cc(ts,tt);
                cerr<<ts<<" "<<tt<<endl;
            }
        }
        cout<<"Case #"<<time<<": "<<minstr<<" "<<minttr<<endl;
    }
    return 0;
}
