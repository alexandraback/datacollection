//
//  a.cpp
//  Problem Solving
//
//  Created by Abu Asif Khan Chowdhury on 4/30/16.
//  Copyright © 2016 Abu Asif Khan Chowdhury. All rights reserved.
//

#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#include <cmath>
#include <sstream>

using namespace std;

#define Set(N, j) (N|(1<<j))
#define reset(N, j) (N&~(1<<j))
#define Check(N, j) (bool)(N&(1<<j))
#define toggle(N, j) (N^(1<<j))
#define turnOff(N, j) (N & ~(1<<j))
#define CLEAR(A, x) ( memset(A,x,sizeof(A)) )
#define pii pair <string, string>
#define pb push_back
#define open freopen("D:/a.txt", "r", stdin);
#define write freopen("D:/b.txt","w", stdout);
#define inf (1ll<<28)
#define ll unsigned long long
#define mod 1000000007
#define gc getchar
#define ls(n) (n<<1)
#define rs(n) ls(n)|1
#define MID(a,b) ((a+b)>>1)
#define fs first
#define sc second
#define mx 100010

template<class T>inline bool read(T &x) {
    int c=getchar();
    int sgn=1;
    while((~c&&c<'0')||c>'9') {
        if(c=='-')sgn=-1;
        c=getchar();
    }
    for(x=0; ~c&&'0'<=c&&c<='9'; c=getchar())x=x*10+c-'0';
    x*=sgn;
    return ~c;
}

int main(){
    freopen("/Users/abuasifkhan/Desktop/Problem Solving/Problem Solving/a.in", "r", stdin);
    freopen("/Users/abuasifkhan/Desktop/Problem Solving/Problem Solving/b.out", "w", stdout);
    
    string s;
    int cnt[30];
    
    int test;
    read(test);
    for(int C=1; C<=test; C++) {
        cin>>s;
        memset(cnt,0,sizeof(cnt));
        for(int i=0;i<s.size();i++)
            cnt[s[i]-'A']++;
        int eliminate=0;
        vector<int>ans;
        while(eliminate<s.size())
        {
            if(cnt['Z'-'A'])
            {
                ans.push_back(0);
                cnt['Z'-'A']--;
                cnt['E'-'A']--;
                cnt['R'-'A']--;
                cnt['O'-'A']--;
                eliminate+=4;
            }
            else if(cnt['W'-'A'])
            {
                ans.push_back(2);
                cnt['T'-'A']--;
                cnt['W'-'A']--;
                cnt['O'-'A']--;
                eliminate+=3;
            }
            else if(cnt['X'-'A'])
            {
                ans.push_back(6);
                cnt['S'-'A']--;
                cnt['I'-'A']--;
                cnt['X'-'A']--;
                eliminate+=3;
            }
            else if(cnt['G'-'A'])
            {
                ans.push_back(8);
                cnt['E'-'A']--;
                cnt['I'-'A']--;
                cnt['G'-'A']--;
                cnt['H'-'A']--;
                cnt['T'-'A']--;
                eliminate+=5;
            }
            else if(cnt['S'-'A'])
            {
                ans.push_back(7);
                cnt['E'-'A']--;
                cnt['S'-'A']--;
                cnt['V'-'A']--;
                cnt['E'-'A']--;
                cnt['N'-'A']--;
                eliminate+=5;
            }
            else if(cnt['U'-'A'])
            {
                ans.push_back(4);
                cnt['F'-'A']--;
                cnt['O'-'A']--;
                cnt['U'-'A']--;
                cnt['R'-'A']--;
                eliminate+=4;
            }
            else if(cnt['F'-'A'])
            {
                ans.push_back(5);
                cnt['F'-'A']--;
                cnt['I'-'A']--;
                cnt['V'-'A']--;
                cnt['E'-'A']--;
                eliminate+=4;
            }
            else if(cnt['O'-'A'])
            {
                ans.push_back(1);
                cnt['O'-'A']--;
                cnt['N'-'A']--;
                cnt['E'-'A']--;
                eliminate+=3;
            }
            else if(cnt['R'-'A'])
            {
                ans.push_back(3);
                cnt['T'-'A']--;
                cnt['H'-'A']--;
                cnt['R'-'A']--;
                cnt['E'-'A']--;
                cnt['E'-'A']--;
                eliminate+=5;
            }
            else if(cnt['I'-'A'])
            {
                ans.push_back(9);
                cnt['N'-'A']--;
                cnt['I'-'A']--;
                cnt['N'-'A']--;
                cnt['E'-'A']--;
                eliminate+=4;
            }
            else break;
            
        }
        sort(ans.begin(),ans.end());
        
        printf("Case #%d: ", C);
        for(int i=0;i<ans.size();i++)
            printf("%d",ans[i]);
        printf("\n");
    }
    
    return 0;
}