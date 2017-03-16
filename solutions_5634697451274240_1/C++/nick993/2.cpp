#include <iostream>
#include <algorithm>
#include <map>
#include <string>
#include <cstdio>


using namespace std;

map<string,int> mymap0;
map<string,int> mymap1;

const int inf=9999999;

bool allZero(string s) {
    for(int i=0;i<s.size();i++)
        if(s[i]!='0')   return false;
    return true;
}

bool allOne(string s) {
    for(int i=0;i<s.size();i++)
        if(s[i]!='1')   return false;
    return true;
}
int min_val0(string str);
int min_val1(string str) ;




int min_val0(string str) {
   //  cout<<endl;
    if(str.size()==0)   return 0;
    if(allZero(str))    return 0;
    if(allOne(str)) return 1;
    if(str=="01")   return 2;
    if(str=="10")   return 1;
    if(mymap0[str]!=0)  return mymap0[str];
    string str1=str.substr(0,str.size()-1);
    string str2="";
    for(int i=str1.size()-1;i>=0;i--) {
        str2+=('1'-str1[i])+'0';
    }

    //cout<<"String : "<<str1<<' '<<str2<<endl;
    char s1=str[0],s2=str[str.size()-1];
    string str3=(char)(('1'-s2)+'0')+str2;
    int val1,val2,val3,val4;
    //cout<<str<<" "<<"Pos s1 : "<<s1<<" s2 : "<<s2<<endl;
    if(s1=='0' && s2=='0') {
   // cout<<" Condn 00 ";
        val1= min(min_val0(str1),min_val1(str1)+1);
    }
    else if(s1=='0' && s2=='1') {
  //          cout<<" Condn 01 ";
        val1= inf;
    }
    else if(s1=='1' && s2=='0') {
        string str4=str3.substr(0,str3.size()-1);
    //    cout<<" Condn 10 ";
        val1= min(min(min_val0(str1),min_val1(str1)+1),1+min(min_val0(str4),min_val1(str4)+1));
    }
    else{
      //  cout<<" Condn 11 ";
        val1= min_val0(str3)+1;
    }
//    cout<<str<<" pos "<<val1<<endl;
    return mymap0[str]=val1;
}

int min_val1(string str) {
    // cout<<endl;
    if(str.size()==0)   return 0;
    if(allZero(str))    return 1;
    if(allOne(str)) return 0;
    if(str=="01")   return 1;
    if(str=="10")   return 2;
    if(mymap1[str]!=0)  return mymap1[str];
    string str1=str.substr(0,str.size()-1);
    string str2="";
    for(int i=str1.size()-1;i>=0;i--) {
        str2+=('1'-str1[i])+'0';
    }
    char s1=str[0],s2=str[str.size()-1];
    string str3=(char)(('1'-s2)+'0')+str2;
    int val1,val2,val3,val4;
    //cout<<str<<" "<<"Pos s1 : "<<s1<<" s2 : "<<s2<<endl;
    if(s1=='1' && s2=='1') {
   // cout<<" Condn 00 ";
        val1= min(min_val1(str1),min_val0(str1)+1);
    }
    else if(s1=='1' && s2=='0') {
  //          cout<<" Condn 01 ";
        val1= inf;
    }
    else if(s1=='0' && s2=='1') {
        string str4=str3.substr(0,str3.size()-1);
    //    cout<<" Condn 10 ";
        val1= min(min(min_val1(str1),min_val0(str1)+1),1+min(min_val1(str4),min_val0(str4)+1));
    }
    else{
      //  cout<<" Condn 11 ";
        val1= min_val1(str3)+1;
    }
  //  cout<<str<<" neg "<<val1<<endl;
    return mymap1[str]=val1;

}


int main() {
    ios::sync_with_stdio(false);
    freopen("f2.txt","r",stdin);
    freopen("o21.txt","w",stdout);
    int T;
    cin>>T;
    for(int t=0;t<T;t++) {
        mymap0.clear();
    mymap1.clear();
        string str;
        cin>>str;
        for(int i=0;i<str.size();i++)   str[i]=(str[i]=='+'?'0':'1');
        //cout<<"Given : "<<str<<endl;
        cout<<"Case #"<<t+1<<": "<<min(min_val0(str),min_val1(str)+1)<<endl;
    }
}
