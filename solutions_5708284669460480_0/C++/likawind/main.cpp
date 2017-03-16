//
//  main.cpp
//  B
//
//  Created by Zhou Sun on 15/5/10.
//  Copyright (c) 2015年 Zhou Sun. All rights reserved.
//

#include <iostream>
using namespace std;
int nex[1000];
double f[105][105];
double fs[105][105];
void GetNext(string p)  
{  
    int pLen = p.size();  
    nex[0] = -1;  
    int k = -1;  
    int j = 0;  
    while (j < pLen - 1)  
    {  
        //p[k]表示前缀，p[j]表示后缀  
        if (k == -1 || p[j] == p[k])   
        {  
            ++k;  
            ++j;  
            nex[j] = k;  
        }  
        else   
        {  
            k = nex[k];  
        }  
    }  
}  
int KmpSearch(char* s, char* p)  
{  
    int i = 0;  
    int j = 0;  
    int sLen = strlen(s);  
    int pLen = strlen(p);  
    while (i < sLen && j < pLen)  
    {  
        //①如果j = -1，或者当前字符匹配成功（即S[i] == P[j]），都令i++，j++      
        if (j == -1 || s[i] == p[j])  
        {  
            i++;  
            j++;  
        }  
        else  
        {  
            //②如果j != -1，且当前字符匹配失败（即S[i] != P[j]），则令 i 不变，j = next[j]      
            //next[j]即为j所对应的next值        
            j = nex[j];  
        }  
    }  
    if (j == pLen)  
        return i - j;  
    else  
        return -1;  
}  

int main(int argc, const char * argv[]) {
    freopen ("out.txt","w",stdout);
    freopen ("in.txt","r",stdin);

    int ts;
    cin>>ts;
    for (int tt=1; tt<=ts; tt++) {
        
    int s,l,k,ss;
    string s1,s2;
    cin>>k >>l>>s;
    cin>>s1;
    cin>>s2;
    s2+='#';
    GetNext(s2);
        ss=0;
    memset(f, 0, sizeof(f));
    memset(fs,0,sizeof(fs));
    int j=l;
    for (int i=0; i<s-l+1; i++) {
        if (j==l) {
            ss++;
            j=nex[j];
        }
        j++;
    }
    f[0][0]=1;
    for (int i=1; i<=s; i++) {
        for (int t=-1;t<l;t++) 
        for (int j=0; j<k; j++) {
            int cur=t;
            while ((cur==l) || (cur!=-1 && s1[j]!=s2[cur+1])) {
                cur=nex[cur];
            }
            if (s1[j]==s2[cur+1]) {
                f[i][cur+2]+=1.0/k *f[i-1][t+1];
            }
            else
            f[i][0]+=1.0/k *f[i-1][t+1];
        }
    }
    for (int i=1; i<=s; i++) {
        for (int t=-1;t<l;t++) 
            for (int j=0; j<k; j++) {
                int cur=t;
                while ((cur==l) || (cur!=-1 && s1[j]!=s2[cur+1])) {
                    cur=nex[cur];
                }
                if (s1[j]==s2[cur+1]) {
                    if (f[i][cur+2]==0) {
                        continue;
                    }
                    fs[i][cur+2]+=fs[i-1][t+1]*f[i-1][t+1]/k/f[i][cur+2];
                    if (cur+1==l-1) {
                        fs[i][cur+2]+=1*f[i-1][t+1]/k/f[i][cur+2];
                    }
                }
                else{
                    if (f[i][0]==0) {
                        continue;
                    }
                    fs[i][0]+=fs[i-1][t+1]*f[i-1][t+1]/k/f[i][0];
                }
            }
    }
        if (f[s][l]==0) {
            ss=0;
        }

    double ss1=0;
    for (int i=0; i<=l; i++) {
        ss1+=fs[s][i]*f[s][i];
    }
    printf("Case #%d: %.10lf\n",tt,ss-ss1);
    }
    return 0;
}
