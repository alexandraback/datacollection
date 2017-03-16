#include<bits/stdc++.h>
using namespace std;
string str,str2;
int n,m,pluso,ma,c,j;
vector<char>store,store2,now,now2;
void backtrack2(int i,int sum,int sum2){
   if(i==m){
    int diff=abs(sum-sum2);
    if(diff<ma){
        ma=diff;
        c=sum;
        j=sum2;
        store=now;
        store2=now2;
        pluso=sum+sum2;

    }
    else if(ma==diff){
       if(pluso>(sum+sum2)){
        c=sum;
        j=sum2;
        store=now;
        store2=now2;
        pluso=sum+sum2;
       }
       else if((sum+sum2)==pluso){
        if(j<sum2){
            c=sum;
            j=sum2;
            store=now;
        store2=now2;
        }

       }
    }
    return;
   }
   if(str2[i]=='?'){
    for(int l=0;l<=9;l++){
            char ch=l+48;
            now2.push_back(ch);
        backtrack2(i+1,sum,(sum2*10)+l);
    now2.pop_back();
    }
   }
   else{
   int    k=str2[i]-48;
   now2.push_back(str2[i]);
    backtrack2(i+1,sum,(sum2*10)+k);
     now2.pop_back();
   }

}
 void backtrack1(int i,int sum)
 {
     if(i==n){
        backtrack2(0,sum,0);
        return ;
     }
        if(str[i]=='?'){
            for(int l=0;l<=9;l++){
                    char ch=l+48;
                    now.push_back(ch);
                backtrack1(i+1,(sum*10)+l);
                now.pop_back();
            }

        }
        else{
               int k=str[i]-48;
               now.push_back(str[i]);
            backtrack1(i+1,(sum*10)+k);
            now.pop_back();
        }

 }

int main()
{
   freopen("B-small-attempt0 (1).in","r",stdin);
    freopen("outputEEE222.o","w",stdout);
    int test,u=1;
    cin>>test;
    while(test--){
    cin>>str>>str2;
    int i;
    n=str.size();
    m=str2.size();
    pluso=2147483647;
    ma=2147483647;
   backtrack1(0,0);
   printf("Case #%d: ",u++);
  for(i=0;i<store.size();i++)cout<<store[i];
  cout<<" ";
   for(i=0;i<store2.size();i++)cout<<store2[i];
  cout<<endl;
    }
}
