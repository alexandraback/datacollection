#include<iostream>
#include<algorithm>
#include<string.h>
#include<vector>
#include<cmath>
using namespace std;

string c,s;
vector< string >c_val,s_val;
int n;

int find_num(string x) {
    int ten=1,temp=0,i;
    for(i=x.length()-1;i>=0;i--) {
        temp+=(x[i]-'0')*ten;
        ten*=10;
    }
    return temp;
}

string is_possible(int num,int idx) {
    int temp,i,cur=n-1,cnt=0;
    string toAdd="";
    if(idx==0) {
        temp=num;
        for(i=n-1;i>=0;i--) {
            if(temp<=0) break;
            cnt++;
            if(c[i]!='?' && c[i]-'0'!=(temp%10)) return "";
            char x=(temp%10)+'0';
            toAdd=x+toAdd;
            temp/=10;
        }
        if(temp<=0) {
            while(cnt<n) toAdd='0'+toAdd,cnt++;
            for(i=0;i<n;i++) if(c[i]!='?' && toAdd[i]!=c[i]) return "";
            return toAdd;
        } else return "";
    } else if(idx==1) {
        temp=num;
        for(i=n-1;i>=0;i--) {
            if(temp<=0) break;
            cnt++;
            if(s[i]!='?' && s[i]-'0'!=(temp%10)) return "";
            char x=(temp%10)+'0';
            toAdd=x+toAdd;
            temp/=10;
        }
        if(temp<=0) {
            while(cnt<n) toAdd='0'+toAdd,cnt++;
            for(i=0;i<n;i++) if(s[i]!='?' && toAdd[i]!=s[i]) return "";
            return toAdd;
        } else return "";
    }
}

int main()
{
    freopen("gcj_16_r1_b_2_in.txt","r",stdin);
    freopen("gcj_16_r1_b_2_out.txt","w",stdout);
    int t;
    cin>>t;
    for(int qq=1;qq<=t;qq++) {
        cout<<"Case #"<<qq<<": ";
        int i,j,m,temp,temp1,ten=1,ans=10000,cnt;
        string ans1,ans2;
        string x;
        cin>>c>>s;
        n=c.length(); cnt=0; c_val.clear(); s_val.clear();
        for(i=0;i<1000;i++) {
            if(is_possible(i,0)!="") {
                c_val.push_back(is_possible(i,0));
            }
            if(is_possible(i,1)!="") {
                s_val.push_back(is_possible(i,1));
            }
        }
        sort(c_val.begin(),c_val.end()); sort(s_val.begin(),s_val.end());
        for(i=0;i<c_val.size();i++) {
            for(j=0;j<s_val.size();j++) {
                if(abs(find_num(c_val[i])-find_num(s_val[j]))<ans) ans=abs(find_num(c_val[i])-find_num(s_val[j])),ans1=c_val[i],ans2=s_val[j];
            }
        }
        cout<<ans1<<" "<<ans2<<"\n";
    }
    return 0;
}
