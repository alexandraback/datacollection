#include<bits/stdc++.h>
using namespace std;

#define l long long

ifstream fin("input.txt");
ofstream fout("output.txt");



bool valid(string s,int u){
    for(int i=s.length()-1;i>=0;i--){
        if(s[i]=='?')
        {
            u/=10;continue;
        }
        if((s[i]-'0')!=(u%10))return false;u/=10;
    }
    return true;
}
int main(){
    int t;cin>>t;
    for(int j=1;j<=t;j++){
        string s1,s2;cin>>s1>>s2;

        int num1=0,num2=0;
        int ans=INT_MAX;
        int high=pow(10,s1.length());
        for(int i=0;i<high;i++){
            for(int k=0;k<high;k++){
                if(valid(s1,i)&&valid(s2,k)){
                    if(ans>abs(i-k))
                    {
                        ans=abs(i-k);num1=i;num2=k;
                    }
                }
            }
        }
        cout<<"Case #"<<j<<": ";

        stringstream sso1,sso2;

        sso1<<num1;sso2<<num2;
        string str1,str2;

        sso1>>str1;sso2>>str2;

        while(str1.length()<s1.length())str1="0"+str1;

        while(str2.length()<s2.length())str2="0"+str2;
        cout<<str1<<" "<<str2<<endl;

    }
}
