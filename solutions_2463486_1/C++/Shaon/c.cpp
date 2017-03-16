#include <cstdio>
#include <cstring>
#include <vector>
#include <cmath>
#include <cstdlib>

using namespace std;

typedef long long LL;

char str[50];
vector<LL> ans;

bool ispalindrome(int left,int right){
    if ( left>right )return true;

    return str[left]==str[right] && ispalindrome(left+1,right-1);
}

int main(){

    freopen("C-large-1.in","r",stdin);
    freopen("out.out","w",stdout);

    LL srt=sqrt( 1e14+1e3 );

    for (LL i=1;i<=srt;++i){
        sprintf(str,"%lld",i);
        if ( ispalindrome(0,strlen(str)-1) ){
            sprintf(str,"%lld",i*i);
            if ( ispalindrome(0,strlen(str)-1) ){
                ans.push_back(i*i);
                //printf("%lld\n",i*i);
            }
        }

    }
    int kase;
    scanf("%d",&kase);

    for (int kk=1;kase--;++kk){
        LL a,b;
        scanf("%lld %lld",&a,&b);
        int cnt=0;
        for (int i=0;i<ans.size();++i){
            if ( ans[i]>=a && ans[i]<=b ){
                ++cnt;
            }
        }

        printf("Case #%d: %d\n",kk,cnt);
    }
    return 0;
}
