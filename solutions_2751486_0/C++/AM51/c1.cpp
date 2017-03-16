#include<iostream>
#include<string>
#include<fstream>
using namespace std;
int val[1000001];
bool cons(char ch)
{
     if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u')return false;
     return true;
}
int main()
{
    int t,i,k,n,num1,num2,len,left;
    unsigned long long ans;
    string s;
    bool flg;
    ifstream fin;
    ofstream fout;
    fin.open("inp.txt");
    fout.open("out.txt");
    fin>>t;
    for(k=1;k<=t;k++){
                      fin>>s>>n;
                      len=s.length();
                      ans=0;flg=0;left=0;
                      if(cons(s[len-1]))val[len-1]=1;
                      else val[len-1]=0;
                      for(i=len-2;i>=0;i--){
                                         if(cons(s[i]))val[i]=val[i+1]+1;
                                         else val[i]=0;
                      }
                      for(i=0;i<len;i++){
                                     if(val[i]>=n){
                                                   /*if(i==0 && flg==0){flg=1;ans+=1;}
                                                   if((i+n)==len && flg==0){flg=1;ans+=1;}
                                                   if(i>0 && i<(len-n))ans+=1;*/
                                                   ans+=1;
                                                   num1=i-left;
                                                   num2=len-i-n;
                                                   ans+=num1+num2+num1*num2;
                                                   left=i+1;
                                                   //cout<<i<<" "<<num1<<" "<<num2<<" "<<ans<<endl;
                                     }
                      }
                      fout<<"Case #"<<k<<": "<<ans<<endl;
     }
     return 0;
}
                                        
