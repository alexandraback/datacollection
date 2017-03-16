#include<bits/stdc++.h>
using namespace std;
char x[5001];
int cnt[300];
int ans[5001];
int main(){
    int T,n;
    FILE *in = fopen("in.txt","r");
    FILE *out = fopen("output.txt","w");
    fscanf(in,"%d",&T);
    for(int t=1;t<=T;t++){
        fscanf(in,"%s",x);
        int k=strlen(x);
        for(int i=0;i<200;i++) cnt[i]=0;
        for(int i=0;i<k;i++) cnt[x[i]]++;
        int now=0;
        while(cnt['Z']!=0){
            ans[now++]=0;
            cnt['Z']--;
            cnt['E']--;
            cnt['R']--;
            cnt['O']--;
        }
        while(cnt['X']!=0){
            ans[now++]=6;
            cnt['S']--;
            cnt['I']--;
            cnt['X']--;
        }
        while(cnt['U']!=0){
            ans[now++]=4;
            cnt['F']--;
            cnt['O']--;
            cnt['U']--;
            cnt['R']--;
        }
        while(cnt['F']!=0){
            ans[now++]=5;
            cnt['F']--;
            cnt['I']--;
            cnt['V']--;
            cnt['E']--;
        }
        while(cnt['V']!=0){
            ans[now++]=7;
            cnt['S']--;
            cnt['E']--;
            cnt['V']--;
            cnt['E']--;
            cnt['N']--;
        }
        while(cnt['G']!=0){
            ans[now++]=8;
            cnt['E']--;
            cnt['I']--;
            cnt['G']--;
            cnt['H']--;
            cnt['T']--;
        }
        while(cnt['W']!=0){
            ans[now++]=2;
            cnt['T']--;
            cnt['W']--;
            cnt['O']--;
        }
        while(cnt['O']!=0){
            ans[now++]=1;
            cnt['O']--;
            cnt['N']--;
            cnt['E']--;
        }
        while(cnt['T']!=0){
            ans[now++]=3;
            cnt['T']--;
            cnt['H']--;
            cnt['R']--;
            cnt['E']--;
            cnt['E']--;
        }
        while(cnt['I']!=0){
            ans[now++]=9;
            cnt['N']--;
            cnt['I']--;
            cnt['N']--;
            cnt['E']--;
        }
        sort(ans,ans+now);
        fprintf(out,"Case #%d: ",t);
        for(int i=0;i<now;i++) fprintf(out,"%d",ans[i]);
        fprintf(out,"\n");
    }
}
