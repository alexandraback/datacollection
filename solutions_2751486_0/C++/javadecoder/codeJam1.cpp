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
char str[1002];
int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int T,n;
    scanf("%d",&T);
    for(int I=1;I<=T;I++){
        string s;
        scanf("%s%d",str,&n);
        s = string(str);
        int L = s.length();
        LL c=0;
        for(int i = 0; i < L;i++){
            int m=0;
            for(int j = i  ; j < L ;j++){
                if(not_cons(s[j])) m++;
                else m=0;
                if(m >= n){
                    c+=(L-j);
                    break;
                }
            }
        }
        printf("Case #%d: %lld\n",I,c);
    }
    return 0;
}
