#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cctype>

#include<cmath>
#include<iostream>
#include<fstream>

#include<string>
#include<vector>
#include<queue>
#include<map>
#include<algorithm>
#include<set>
#include<sstream>
#include<stack>
#include<utility>
#include<numeric>
#include<iterator>
using namespace std;

#define CLR(a) memset(a,0,sizeof(a))
#define SET(a) memset(a,-1,sizeof(a))
#define memo(a,b) memset(a,b,sizeof(a))

#define all(a) a.begin(),a.end()
#define pb push_back
#define mpp(a,b,c) make_pair(make_pair(a,b),c)

#define inf (1<<29)
#define i64 unsigned long long
#define pi (2.0*acos(0.0))
#define eps (1e-9)

typedef pair< int , int >  pii;
#define MAX 1000005

char str[MAX];
inline bool isVowel(char ch){
    if(ch =='a' || ch =='e' || ch =='i' || ch =='o' || ch =='u') return true;
    return false;
}
int main(){
    freopen("A-large.in","r",stdin);
    freopen("A-large.ans","w",stdout);
    i64 a,b,ans;
    int t,n,i,cs = 1;
    cin>>t;
    while(t--){
        scanf("%s %d",str,&n);
        int last = -1;
        int len = strlen(str);
        ans = 0;
        int cnt = 0;
        for(i = 0;str[i];i++){
            if(isVowel(str[i])){ cnt = 0; continue; }
            cnt++;
            if(cnt == n){
                a = i - n -last + 1;
                b = len - i;
                //cout<<i<<" "<<a<<" "<<b<<endl;
                ans+= a*b;
                last = i - n + 1;
                cnt--;
            }
        }
        cout<<"Case #"<<cs++<<": "<<ans<<endl;
    }
	return 0;
}
