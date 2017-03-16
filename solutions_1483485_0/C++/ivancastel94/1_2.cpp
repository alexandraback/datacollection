#include<iostream>
#include<math.h>
#include<string.h>
#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    freopen("a.in","r",stdin);
    freopen("a.out","w",stdout);
    int n,i,j,k,t;
    string l="abcdefghijklmnopqrstuvwxyz";
    string s1="yhesocvxduiglbkrztnwjpfmaq";
    string a;
    scanf("%d\n",&n);
    for(i=0;i<n;i++){
        getline(cin,a);
        cout<<"Case #"<<i+1<<": ";
        for(j=0;j<a.length();j++){
            if(a[j]==' ')cout<<" ";
            else{
                for(k=0;k<26;k++)if(a[j]==l[k])cout<<s1[k];
                }
            }
        cout<<endl;    
        }
    }
