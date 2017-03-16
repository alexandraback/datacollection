#include    <bits/stdc++.h>

#define     M_PI            3.14159265358979323846
#define     mod             1000000007
#define     inf             1000000000000000000
#define     mp              make_pair
#define     pb              push_back
#define     F               first
#define     S               second
#define     ll              long long
#define     pii             pair<int,int>
#define     pli             pair<ll,int>
#define     pil             pair<int,ll>
#define     pll             pair<ll,ll>
#define     si(t)           scanf("%d",&t)
#define     sii(m,n)        scanf("%d %d",&m,&n);
#define     sl(t)           scanf("%lld",&t)
#define     rep(i,n)        for(int i=0;i<n;i++)
#define     REP(i,a,b)      for(int i=a;i<=b;i++)
#define     RREP(i,a,b)     for(int i=a;i>=b;i--)
#define     N               5005

using namespace std;

string sa,sb;
int n;

void init(){

    REP(i,1,n){
        //f(sa[i] != '?' || sb[i] != '?') f =1;
        if(sa[i] != sb[i] && sa[i] != '?' && sb[i] != '?'){
            int k = abs(sa[i] - sb[i]);
            if(k > 5){
                if(sa[i-1] != '?' && sb[i-1] != '?'){}
                else if(sa[i-1] != '?'){
                    if(sa[i] < sb[i]){
                        if(sa[i-1] == '0') sb[i-1] = '0';
                        else sb[i-1] = sa[i-1] - 1;
                    }
                    else{
                        sb[i-1] = sa[i-1];
                    }
                }
                else if(sb[i-1] != '?'){
                    if(sb[i] < sa[i]){
                        if(sb[i-1] == '0') sa[i-1] = '0';
                        else sa[i-1] = sb[i-1] - 1;
                    }
                    else{
                        sa[i-1] = sb[i-1];
                    }
                }
                else {
                    if(sa[i] < sb[i]){ sa[i-1] = '1' ; sb[i-1] = '0';}
                    else {sa[i-1] = '0' ; sb[i-1] = '1';}
                }
            }
            else if(k < 5){
                if(sa[i-1] == '?' && sb[i-1] == '?') sa[i-1] = sb[i-1] = '0';
                else if(sa[i-1] == '?') sa[i-1] = sb[i-1];
                else sb[i-1] = sa[i-1];
            }
            else{
                if(sa[i-1] == '?' && sb[i-1] == '?') sa[i-1] = sb[i-1] = '0';
                else if(sa[i-1] == '?'){
                    
                    if(sb[i] < sa[i]){
                        if(sb[i-1] == '0') sa[i-1] = '0';
                        else sa[i-1] = sb[i-1] - 1;
                    }
                    else{
                        sa[i-1] = sb[i-1];
                    }
                }
                else if(sb[i-1] == '?'){
                    
                    if(sa[i] < sb[i]){
                        if(sa[i-1] == '0') sb[i-1] = '0';
                        else sb[i-1] = sa[i-1] - 1;
                    }
                    else{
                        sb[i-1] = sa[i-1];
                    }
                }
            }
            return ;
        } 
    }
}

void fun(int a,int p){
    if(a == n) return ;
    int c = p;
    if(p == -1){
        if(sa[a] == sb[a]) {if(sa[a] == '?') sb[a] = sa[a] = '0';}
        else if(sa[a] == '?') sa[a] = sb[a];
        else if(sb[a] == '?') sb[a] = sa[a];
        else{
            if(sa[a] > sb[a]) c = 0;
            else c = 1;
        }
    }
    else if(p == 0){
        if(sa[a] == '?') sa[a] = '0';
        if(sb[a] == '?') sb[a] = '9';
        c=0;
    }
    else if(p == 1){
        if(sa[a] == '?') sa[a] = '9';
        if(sb[a] == '?' ) sb[a] = '0';
        c = 1;
    }
    fun(a+1,c);
}

int main(){
    int t; si(t);
    REP(T,1,t){
        cin>>sa>>sb;
        n = sa.length();
        init();
        fun(0,-1);
        printf("Case #%d: ",T);
        rep(i,n) printf("%c",sa[i]);
        printf(" ");
        rep(i,n) printf("%c",sb[i]);
        printf("\n");
    }
    return 0;   
}

