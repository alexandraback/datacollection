#include<iostream>
#include<algorithm>
#include<string.h>
#include<cmath>
#include<cstdio>
#include<vector>

using namespace std;

vector<string>v;

int main(){

    freopen("gcj_round1B_prbB_input.txt","r",stdin);
    freopen("gcj_round1B_prbB_output.txt","w",stdout);

    int t,l;
    cin>>t;
    for(l=1;l<=t;l++){
        v.clear();
        string s1,s2,temp="",ans1="",ans2="";
        cin>>s1>>s2;
        long long len,i,j,k,num=0,num1=0,a=0,b=0,found=0,cnt=0,cnt1=0,x=0,minm=0;
        len=s1.length();
        for(i=0;i<=9;i++){
            temp+=char(i+48);
            if(len>1){
                for(j=0;j<=9;j++){
                    temp+=char(j+48);
                    if(len>2){
                        for(k=0;k<=9;k++){
                            temp+=char(k+48);
                            v.push_back(temp);
                            temp.erase(2,1);
                        }
                        temp.erase(1,1);
                    }
                    else {
                        v.push_back(temp);
                        temp.erase(1,1);
                    }
                }
                temp.erase(0,1);
            }
            else {
                v.push_back(temp);
                temp.erase(0,1);
            }
        }
        for(i=0;i<v.size();i++){
            cnt=0;num=0;
            for(x=0;x<len;x++){
                if(v[i][x]!='?' && s1[x]!='?'){
                    if(v[i][x]==s1[x]){num=(num*10)+(v[i][x]-'0');cnt++;}
                }
                else if(v[i][x]!='?' && s1[x]=='?'){
                    cnt++;
                    num=(num*10)+(v[i][x]-'0');
                }
            }
            if(cnt!=len)continue;
            else cnt=0;
            for(j=0;j<v.size();j++){
            cnt1=0;num1=0;
            for(x=0;x<len;x++){
                if(v[j][x]!='?' && s2[x]!='?'){
                    if(v[j][x]==s2[x]){num1=(num1*10)+(v[j][x]-'0');cnt1++;}
                }
                else if(v[j][x]!='?' && s2[x]=='?'){
                    cnt1++;
                    num1=(num1*10)+(v[j][x]-'0');
                }
            }
            if(cnt1!=len)continue;
            else cnt1=0;
            if(found==0){
                minm=abs(num-num1);
                a=num;b=num1;
                found=1;
            }
            else {
                if(abs(num-num1)<minm)minm=abs(num-num1),a=num,b=num1;
                else if(abs(num-num1)==minm && num<a)minm=abs(num-num1),a=num,b=num1;
                else if(abs(num-num1)==minm && num==a && num1<b)minm=abs(num-num1),a=num,b=num1;
            }
            }
        }



        cout<<"Case #"<<l<<": ";
        while(a>0){
            ans1+=char((a%10)+48);
            a/=10;
        }
        for(i=ans1.length();i<len;i++)ans1=ans1+'0';
        while(b>0){
            ans2+=char((b%10)+48);
            b/=10;
        }
        for(i=ans2.length();i<len;i++)ans2=ans2+'0';
        for(i=ans1.length()-1;i>=0;i--)cout<<ans1[i];
        cout<<" ";
        for(i=ans2.length()-1;i>=0;i--)cout<<ans2[i];
        cout<<"\n";
    }

    return 0;






}

