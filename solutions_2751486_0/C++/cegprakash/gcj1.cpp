#include<iostream>
#include<stdio.h>
#include<vector>
#include<queue>
#include<algorithm>
#include<stdlib.h>
#include<string.h>
#include<cstring>
#include<cmath>
#include<sstream>

using namespace std;

long long pos[1000005],minn,n;
bool isVowel(char a){
     if(a=='a'||a=='e'||a=='i'||a=='o'||a=='u')
        return false;
     return true;
}
/*
void search(long long left, long long right){
     if(left>right) return;
     long long mid=(left+right)/2;
     if(pos[mid]>=n)
     {
           minn=min(minn,mid);
           search(left,mid-1);                   
     }
     else search(mid+1,right);
}

*/
int main(){
    long long i,t,nvalue,sum;
    string s;
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin>>t;
    long long c=1;
    while(t--){
        sum=0;
        memset(pos,-1,sizeof(pos));
        cin>>s>>n;
        for(i=0;i<s.length();i++){                                  
           if(isVowel(s[i])){
              pos[i]=1; if(i-1>=0) pos[i]+=pos[i-1];  
              pos[i]=min(pos[i],n);                                          
           }
           else
            pos[i]=0;
        }
        
        //cout<<endl;
        //or(i=0;i<s.length();i++)
          //cout<<pos[i]<<" ";
        
        pos[s.length()]=(long long)1e9;
        /*
        for(i=0;i<=s.length()-n;i++){
              sum+=s.length()-pos[i];                                 
        } */ 
        long long from=0;
        for(i=0;i<s.length();i++){
           if(pos[i]==n){
             sum+=(i-n+1-from+1)*(s.length()-i);
             from=i-n+2;
             //cout<<from<<endl;
           }
        }
        cout<<"Case #"<<c++<<": "<<sum<<endl;
                       
    }
    return 0;
}
