#include<iostream>
#include<stdio.h>
#include<vector>
#include<set>
#include<cstring>
#include<algorithm>
#include<string>

using namespace std;

int main(){
    FILE *inf, *outf;
    inf=fopen("A-large.in","r");
    outf=fopen("A-large-result.in","w");
    
    int T,N;
    char input[1002];
    string s;
    
    fscanf(inf,"%d",&T);
    for(int i=0;i<T;i++){
        s.clear();
        fscanf(inf,"%s",input);
            for(int i=0;i<strlen(input);i++){
                if(s.size()==0)s.push_back(input[i]);
                else if(input[i]>=s[0]) s=input[i]+s;
                else s.push_back(input[i]);
            }            

            fprintf(outf,"Case #%d: %s\n",i+1,s.c_str());
            
    }
//    getchar();
}