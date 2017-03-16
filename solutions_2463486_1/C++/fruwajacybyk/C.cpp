#include<cstdio>
#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<cmath>

using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define PII pair<int,int>
#define st first
#define nd second
#define mp make_pair
#define lint long long int
#define VI vector<int>
#define pb push_back
#define max_n 10000005

bool ispalindrome(lint n){
    VI v;
    while(n!=0){
        v.pb(n%10); 
        n=n/10;
    }
    int u = v.size();
    FOR(i,0,u/2) if(v[i]!=v[u-1-i]) return false;
    return true;
}

bool fair(int x){
    if(ispalindrome(x*1LL*x)) return true;
    return false;
}

int dobra[max_n];
int fer[max_n];

int pierw(lint U){
    int l=0,p=1;
    while(p*1LL*p < U) p*=2;
    while(p-l>1){
        int s = (l+p)/2;
        if(s*1LL*s<U) l = s;
        else p=s;
    }
    if(p*1LL*p>U) return p-1;
    else return p;
}


void check(int n){
    VI v,z;
    while(n!=0){
        v.pb(n%10); 
        n=n/10;
    }
    int u = v.size();
    FOR(j,0,11){
      int k=0;
      FOR(i,0,u) {k*=10; k+=v[u-1-i];}

      k*= ((j!=10)? 10 : 1); 
      k+= ((j!=10)? j : 0); 
      
      FOR(i,0,u) {k*=10; k+=v[i];}
      if(fair(k)) fer[k]=1; 
    }
    
}







int main(){
    int z; scanf("%d",&z);
    
    FOR(i,0,max_n) fer[i]=0;
    FOR(i,1,1000) check(i);
    FOR(i,1,10) if(fair(i)) fer[i]=1;
    dobra[0]=0;
    FOR(i,1,max_n) dobra[i] = dobra[i-1]+ fer[i];
    
    FOR(tn,1,z+1){
        lint A,B; cin>>A>>B;
        int x = pierw(A),y=pierw(B);
        if(x*1LL*x<A) x++;
        cout<<"Case #"<<tn<<": "<<dobra[y]-dobra[x-1]<<endl;
    }
}


