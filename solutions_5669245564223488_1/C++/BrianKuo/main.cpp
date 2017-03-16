#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <math.h>

using namespace std;

bool ip(string s){
    bool x[26];
    for(int j=0;j<26;j++){
        x[j]=0;
    }
    for(int j=0;j<s.size();j++){
        if(x[s[j]-'a']==1&&s[j-1]!=s[j]){
            return false;
        }
        x[s[j]-'a']=1;
    }
    return true;
}

int main()
{
    ifstream fin("B-large.in");
    ofstream fout("B-large.out");
    int n;
    fin>>n;
    for(int t=1;t<=n;t++){
        long long ans=0;
        int S;
        fin>>S;
        string s[S];
        for(int i=0;i<S;i++){
            fin>>s[i];
            if(ip(s[i])==false)ans=-1;
            if(t==33)cout<<s[i]<<endl<<endl;
        }
        if(t==33)cout<<endl<<endl<<endl;
        int A[26],B[26];
        int IN[26];
        int ANS[26];
        for(int i=0;i<26;i++){
            A[i]=B[i]=ANS[i]=0;
            IN[i]=-1;
        }
        for(int i=0;i<S;i++){
            if(s[i][0]!=s[i][s[i].size()-1]){
                A[s[i][0]-'a']++;
                B[s[i][s[i].size()-1]-'a']++;
            }
            /*else{
                for(int j=1;j<s[i].size()-1;j++){
                    if(s[i][j]!=s[i][0]){
                        if(IN[s[i][j]-'a']!=-1&&IN[s[i][j]-'a']!=j){
                            ans=-1;
                            break;
                        }
                        IN[s[i][j]-'a']=i;
                    }
                }
            }*/
        }
        if(ans!=-1){
            for(int i=0;i<26;i++){
                if(A[i]>=2||B[i]>=2){
                    ans=-1;
                    break;
                }
                int c1=-1,c2=0,c3=-1;
                for(int j=0;j<S;j++){
                    if(s[j][0]-'a'!=i&&s[j][s[j].size()-1]-'a'==i){
                        c1=j;
                    }
                    else if(s[j][0]-'a'==i&&s[j][s[j].size()-1]-'a'==i){
                        c2++;
                        if(c1==-1||c1==c3)c1=j;
                    }
                    else if(s[j][0]-'a'==i&&s[j][s[j].size()-1]-'a'!=i){
                        c3=j;
                        if(c1==-1)c1=j;
                    }
                }
                ANS[i]=c2;
                while(c2>0){
                    c2--;
                    for(int j=0;j<S;j++){
                        if(s[j][0]-'a'==i&&s[j][s[j].size()-1]-'a'==i&&c1!=j){
                            if(t==33)cout<<"A: "<<s[c1]<<endl<<endl;
                            s[c1]=s[c1]+s[j];
                            if(t==33)cout<<"B: "<<s[c1]<<endl<<endl;
                            S--;
                            for(int k=j;k<S;k++){
                                s[k]=s[k+1];
                            }
                            if(c1>j)c1--;
                            if(c3>j)c3--;
                            /*for(int k=0;k<26;k++){
                                if(IN[k]==j)IN[k]=c1;
                                if(IN[k]>j)IN[k]--;
                            }*/
                        }
                    }
                }
                if(c3!=-1&&c1!=c3){
                    s[c1]=s[c1]+s[c3];
                    S--;
                    for(int k=c3;k<S;k++){
                        s[k]=s[k+1];
                    }
                    if(c1>c3)c1--;
                    /*for(int k=0;k<26;k++){
                        if(IN[k]==c3)IN[k]=c1;
                        if(IN[k]>c3)IN[k]--;
                    }*/
                }
                if(ans==-1)break;
            }
        }
        if(ans!=-1){
            string sa;
            for(int i=0;i<S;i++){
                if(t==33)cout<<s[i]<<endl<<endl;
                sa+=s[i];
                /*for(int j=1;j<s[i].size()-1;j++){
                    if(s[i][j]!=s[i][0]){
                        if(IN[s[i][j]-'a']!=-1&&IN[s[i][j]-'a']!=i){
                            ans=-1;
                            break;
                        }
                        IN[s[i][j]-'a']=i;
                    }
                }*/
            }
            if(ip(sa)==false){
                ans=-1;
            }
        }
        char ansstr[500];
        if(ans==-1)
            sprintf(ansstr,"Case #%d: 0\n",t);
        else{
            ans=1;
            for(int j=2;j<=S;j++){
                ans*=j;
                ans=ans%1000000007;
            }
            for(int i=0;i<26;i++){
                for(int j=2;j<=ANS[i];j++){
                    ans*=j;
                    ans=ans%1000000007;
                }
            }
            sprintf(ansstr,"Case #%d: %lld\n",t,ans);
        }
        fout<<ansstr;
    }
    return 0;
}
