#include<cstdio>
#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
#include<map>
#include<set>
#include<stack>
#include<queue>
#include<string>
#include<iterator>
#include<string>
#include<sstream>
#include<cassert>
#include<ctime>
#include<cmath>

#define MP make_pair
#define PB push_back
#define X first
#define Y second
#define oo 2000000000
#define MOD 1000000007
#define LL long long int
#define PII pair<int,int>
#define DEBUG 0

using namespace std;
bool not_cons(char c){
    if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u') return false;
    return true;
}
char str[1000002];
int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int T,n;
    scanf("%d",&T);
    for(int I=1;I<=T;I++){
        scanf("%s%d",str,&n);
        int L = strlen(str);
        LL c=0;
        int i=0,j=0,m=0,s=0;
        for(int i=0;i<L;i++){
            //printf("i = %d\n",i);
            if(s>=i && m==n) c+=(L-j+1) ;//,puts("affed");
            else if(m==n){
                s=i;--m;
                while(j<L){
                    if(not_cons(str[j])){
                        if(m==0) s=j;
                        ++m;
                    }
                    else m=0;
                    ++j;
                    if(m==n) break;;
                }
                if(m==n) c+=(L-j+1) ;//, puts("pppp");
            }
            else{
                while(j<L){
                    if(not_cons(str[j])){
                        if(m==0) s=j;
                        ++m;
                    }
                    else m=0;
                    ++j;
                    if(m==n) break;;
                }
                if(m==n)  c+=(L-j+1);
                //printf("%d %d %d %lld\n",m,j,s,c);
            }
        }
        printf("Case #%d: %lld\n",I,c);
    }
    return 0;
}
