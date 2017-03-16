#include <bits/stdc++.h>
using namespace std;

int main(){
  int T;cin>>T;
  for(int t=0;t<T;t++){
    string s1,s2;cin>>s1>>s2;
    string x,y;int mn=10000000;
    for(int i=0;i<1000;i++){
      for(int j=0;j<1000;j++){
        string t1=to_string(i),t2=to_string(j);
        if(t1.size()>s1.size()||t2.size()>s2.size())break;
        while(t1.size()<s1.size())t1="0"+t1;
        while(t2.size()<s2.size())t2="0"+t2;
        bool f=1;
        for(int k=0;k<s1.size();k++){
          if(s1[k]!='?'&&s1[k]!=t1[k]){f=0;break;}
          if(s2[k]!='?'&&s2[k]!=t2[k]){f=0;break;}
        }
        if(f&&abs(i-j)<mn)mn=abs(i-j),x=t1,y=t2;
      }
    }
    cout<<"Case #"<<t+1<<": "; cout<<x<<" "<<y<<endl;;
  }
}