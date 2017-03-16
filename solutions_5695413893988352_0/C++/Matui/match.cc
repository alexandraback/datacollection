#include<iostream>
#include<string>
using namespace std;
int T;
string cs,js;
int str2int(string s){
    int r =0;
    for(int i=0;i<s.size();i++){
        r*=10;
        r+=s[i]-'0';
    }
    return r;
}

int rc=0,rj=0,rd=99999;
string rcs,rjs;
void solve(string c,string j){
    size_t found = c.find('?');
    if(found!=string::npos){
        for(char i ='0';i<='9';i++){
            c[found] = i;
            solve(c,j);
        }
        return;
    }
    found = j.find('?');
    if(found!=string::npos){
        for(char i ='0';i<='9';i++){
            j[found] = i;
            solve(c,j);
        }
        return;
    }
    int r1 = str2int(c),r2=str2int(j),diff=max(r1-r2,r2-r1);
    if(diff<rd){
        rc = r1;
        rj = r2;
        rd = diff;
        rcs = c;
        rjs = j;
    }
    if(diff==rd){
        if(r1<rc){
        rc = r1;
        rj = r2;
        rd = diff;
        rcs = c;
        rjs = j; 
        }
        else if(r1==rc && r2<rj){
        rc = r1;
        rj = r2;
        rd = diff;
        rcs = c;
        rjs = j;
        }
    }
}

int main(){
    cin>>T;
    int case_n =1;
    while(T--){
        rd = 99999;
        cin>>cs>>js;
        solve(cs,js);
        cout<<"Case #"<<case_n++<<": "<<rcs<<' '<<rjs<<endl;
    }
}
