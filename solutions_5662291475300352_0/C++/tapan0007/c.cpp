
//  main.cpp
//  Practice

//  Copyright (c) 2014 Tapan. All rights reserved.
//

#include<stdio.h>
#include<iostream>
#include<vector>
#include<string.h>
#include<algorithm>
#include<deque>
#include<map>
#include<set>
#include<stack>
#include<stdlib.h>
#include<math.h>
#include<queue>
#include<functional>
using namespace std;
#define LL long long
#define si(x) scanf("%d",&x)
#define sc(x) scanf("%c",&x)
#define sl(x) scanf("%I64d",&x)
#define prl(x) printf("%I64d",x)
#define pri(x) printf("%d\n",x)
#define prs(x) printf("%s\n",x)
#define vl vector<ll>
#define vi vector<int>
#define vvl vector< vl >
#define vvi vector< vi >
#define pb push_back
#define mod 1000000007
#define mem(x,y) memset(x,y,sizeof(x))
#define f(i,a,b) for(int i=(a);i<(b);i++)

inline void solve(int turn){
    
    int m1 = 0,m2= 0,p1=0,p2=0;
    int N;
    cin >> N;
    if(N==1){
        int a,b,c;
        cin >> a >> b >> c;
        if(b==1){
            p1=a; m1=c;
        }
        else if(b==2){
            p1=p2=a; m1=c; m2=c+1;
            N=2;
        }
    }
    else{
        int a,b,c;
        cin >> a >> b >> c;
        p1=a; m1=c;
        cin >> a >> b >> c;
        p2=a; m2=c;
    }
    if(N==1){
        cout<<"Case #"<<turn<<": "<<0<<endl;
    }
    else if(N==2){
        if(p1<p2 or (p1==p2 and m1<m2)){
            swap(p1,p2);
            swap(m1,m2);
        }
        if(m1>m2){
            double Y=360-p2;
            Y/=360;
            Y+=1;
            Y*=m2;
            double X=360-p1;
            X/=360;
            X*=m1;
            
            if(Y>X){
                cout<<"Case #"<<turn<<": "<<0<<endl;
            }
            else if(Y+m2>X+m1){
                cout<<"Case #"<<turn<<": "<<1<<endl;
            }else{
                cout<<"Case #"<<turn<<": "<<1<<endl;
            }
        }else{
            double Y=360-p2;
            Y/=360;
            Y*=m2;
            double X=360-p1;
            X/=360;
            X+=1;
            X*=m1;
            
            if(X>Y){
                cout<<"Case #"<<turn<<": "<<0<<endl;
            }
            else if(X+m1>Y+m2){
                cout<<"Case #"<<turn<<": "<<1<<endl;
                
            }else{
                cout<<"Case #"<<turn<<": "<<1<<endl;
            }
        }
    }
}
void init() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}
inline void Refresh(void){
    
}

int main()
{
    int t; si(t);
    for(int i=1;i<=t;i++){
        solve(i);
    }
    return 0;
}