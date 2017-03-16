#include<iostream>
using namespace std;
int razl(string a,string b){
    int a1=0,b1=0;
    for(int i=0;i<a.size();i++){
        a1*=10;
        a1+=a[i]-'0';
    }
    //cout<<a<<" "<<a1<<endl;
    for(int i=0;i<b.size();i++){
        b1*=10;
        b1+=b[i]-'0';
    }
    return ((a1-b1>0)?(a1-b1):(b1-a1));
}
pair<int,string> mini(string a,string b,int ai,int bi,int min){
    pair<int,string> ans,test;
    ans.first=1000;
    if(ai!=a.size()){
        if(a[ai]!='?'){
            test=mini(a,b,ai+1,bi,min);
            if(test.first<ans.first)    ans=test;
        }
        else
        for(char i='0';i<='9';i++){
            a[ai]=i;
            test=mini(a,b,ai+1,bi,min);
            if(test.first<ans.first)    ans=test;
        }
    }else
        if(bi!=a.size()){
            if(b[bi]!='?'){
                test=mini(a,b,ai,bi+1,min);
                if(test.first<ans.first)    ans=test;
            }
            else
            for(char i='0';i<='9';i++){
                b[bi]=i;
                test=mini(a,b,ai,bi+1,min);
                if(test.first<ans.first)    ans=test;
            }
        }else{
            ans.first=razl(a,b);
            ans.second=a+" "+b;
        }
        return ans;
}
int a_case(int num){
    string s1,s2;
    cin>>s1>>s2;
    cout<<"Case #"<<num+1<<": "<<mini(s1,s2,0,0,0).second<<endl;
}
int main(){
    /*string s1,s2;
    cin>>s1>>s2;
    cout<<mini(s1,s2,0,0,0).second;*/
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        a_case(i);
    }
}

