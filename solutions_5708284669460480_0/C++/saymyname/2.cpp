#include<iostream>
#include<fstream>
#include<set>
#include<algorithm>
#include<vector>
#include<cstring>
#include<map>
#include<iomanip>
using namespace std;
int T,K,L,S;
string target;
string key;
int totB;
double prob[30];
map<string,double>memo;

int solve(string str) {

    //string temp=str;
    int len=str.length();
    int len2=key.length();
    for(int i=0;i<len;i++)
    {
        bool flag=false;
        for(int j=0;j<len2;j++)
            if(str[i]==key[j]) flag=true;
        if(flag==false) return 0;
    }
    for(int i=1;i<len;i++)
    {
        int j=0;
        int k=i;
        for(j=0;j<len&&k<len;j++,k++)
            if(str[j]!=str[k])break;
        if(k==len)
        {
            return 1+(S-len)/i;
        }

    }

    return S/L;
}
int funIn(string str) {
    int ct=0;
        for(int i=0;i+L<=S;i++)
        {
            int j;
            int k=0;
            for(j=i;j<i+L;j++)
            {

             if(str[j]!=target[k]) break;
             k++;
            }
            if(j==i+L)
                ct++;
        }
        //cout<<"ct="<<ct<<endl;
return ct;
}
double dp(string str) {
  //  cout<<str<<" "<<S<<endl;
    if(str.length()==S)
    {
        return totB-funIn(str);
    }
     //cout<<str<<endl;
    //if(memo.find(str)!=memo.end())
    //    memo[str];
    double ret=0;
    for(int i=0;i<26;i++) {
        if(prob[i]>0)
        ret+=dp(str+(char)('A'+i))*prob[i];
    }
   // memo[str]=ret;
    return ret;
}

int main(){
    ifstream  fin("/Users/anupsing/Desktop/GCJ/input.txt");
    ofstream  fout("/Users/anupsing/Desktop/GCJ/output.txt");
    fin>>T;
    int cases=1;
    while(T--) {
        fin>>K>>L>>S;
        fin>>key;
        fin>>target;

        totB=solve(target);
      //  fout<<totB<<endl;
        for(int i=0;i<26;i++)
            prob[i]=0;
        for(int i=0;i<K;i++)
            prob[key[i]-'A']++;
        for(int i=0;i<26;i++)
            {
                prob[i]=prob[i]/(1.0*K);
                //cout<<prob[i]<<endl;
            }
        //cout<<"HI"<<endl;
       // memo.clear();
        double ans =dp("");
        fout << std::fixed;
        fout << std::setprecision(10);
        fout<<"Case #"<<cases++<<": "<<ans<<endl;
    }

    return 0;
}
