#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
const ll p[]={1ll,
4ll,
9ll,
121ll,
484ll,
10201ll,
12321ll,
14641ll,
40804ll,
44944ll,
1002001ll,
1234321ll,
4008004ll,
100020001ll,
102030201ll,
104060401ll,
121242121ll,
123454321ll,
125686521ll,
400080004ll,
404090404ll,
10000200001ll,
10221412201ll,
12102420121ll,
12345654321ll,
40000800004ll,
1000002000001ll,
1002003002001ll,
1004006004001ll,
1020304030201ll,
1022325232201ll,
1024348434201ll,
1210024200121ll,
1212225222121ll,
1214428244121ll,
1232346432321ll,
1234567654321ll,
4000008000004ll,
4004009004004ll};
bool cheak(ll n){
    string st="";
    while (n>0){
        st+=n%10+'0';
        n/=10;
    }
    int len=st.length();
    for (int i=0;i<len/2; i++)
    if (st[i]!=st[len-i-1]) return false;
    return 1;
}
int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    //for (int i=1; i<10000000; i++)
    //if (cheak(1ll*i*i)&&cheak(1ll*i)) cout<<1ll*i*i<<"ll,"<<endl;
    int T; cin>>T;
    for (int tt=1;tt<=T;tt++){
        printf("Case #%d: ",tt);
        ll A,B;
        cin>>A>>B;
        int ans=0;
        for (int i=0; i<39; i++)
        if (p[i]>=A&&p[i]<=B) ans++;
        printf("%d\n",ans);
    }
}
