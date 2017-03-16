#include<bits/stdc++.h>
using namespace std;
typedef long long int LL;
#define getchar_unlocked getchar
#define pb push_back
#define mp make_pair
#define f first
#define sc second
#define M 1000000007
#define inf (int)(2e+9)
#define all(o) (o).begin(), (o).end()
/*#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;*/
int gcd(int a, int b) { return (b == 0 ? a : gcd(b, a % b)); }
inline LL power(LL x,LL y)
{
    LL ans=1;
    while(y>0){
        if(y&1)
            ans=(ans*x)%M;
        x=(x*x)%M;
        y/=2;
    }
    return ans;
}
inline int read()
{
    int ret = 0,temp=1;
    int c = getchar_unlocked();
    while(c<'0' || c>'9'){
        c = getchar_unlocked();
    }
    while(c>='0' && c<='9')
    {
        ret = (ret<<3) + (ret<<1) + c - '0';
        c = getchar_unlocked();
    }
        return ret;
}
string str;
int main()
{
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
    int t;
    scanf("%d",&t);

    for(int tt=1;tt<=t;tt++){
        printf("Case #%d: ",tt);        
        cin>>str;
        int n=str.size();
        int a[26];
        memset(a,0,sizeof a);
        for(int i=0;i<n;i++){
            a[str[i]-'A']++;
        }
        vector<int> V;
        int k=0;
 
                while(a[25]>0 && a[4]>0 && a['r'-'a']>0 && a['o'-'a']>0) {
                    V.pb(0);
                    a[25]--;
                    a[4]--;a['r'-'a']--;a['o'-'a']--;
                }
            
                while(a['t'-'a']>0 && a['w'-'a']>0 && a['o'-'a']>0){
                    V.pb(2);
                    a['t'-'a']--;a['w'-'a']--;a['o'-'a']--;
                }
                 while(a['s'-'a']>0 && a['i'-'a']>0 && a['x'-'a']>0 ){
                    V.pb(6);
                    a['s'-'a']--;a['i'-'a']--;a['x'-'a']--;
                }
                while(a['s'-'a']>0 && a['e'-'a']>1 && a['v'-'a']>0 && a['n'-'a']>0){
                    V.pb(7);
                    a['s'-'a']--;a['e'-'a']-=2;a['n'-'a']--;a['v'-'a']-=1;
                }
                while(a['e'-'a']>0 && a['i'-'a']>0 && a['g'-'a']>0 && a['h'-'a']>0 && a['t'-'a']>0){
                    V.pb(8);
                    a['e'-'a']--;a['i'-'a']--;a['g'-'a']--;a['h'-'a']--;a['t'-'a']--;
                }
                while(a['f'-'a']>0 && a['i'-'a']>0 && a['v'-'a']>0 && a['e'-'a']>0){
                    V.pb(5);
                    a['f'-'a']--;a['i'-'a']--;a['v'-'a']--;a['e'-'a']-=1;
                }
               
                while(a['f'-'a']>0 && a['o'-'a']>0 && a['u'-'a']>0 && a['r'-'a']>0){
                    V.pb(4);
                    a['f'-'a']--;a['u'-'a']--;a['o'-'a']--;a['r'-'a']--;
                }
                
             while(a['o'-'a']>0 && a['n'-'a']>0 && a['e'-'a']>0){
                    V.pb(1);
                    a['o'-'a']--;a['n'-'a']--;a['e'-'a']--;
                }
                
                while(a['n'-'a']>0 && a['i'-'a']>0 && a['n'-'a']>0 && a['e'-'a']){
                    V.pb(9);
                    a['n'-'a']--;a['i'-'a']--;a['n'-'a']--;a['e'-'a']--;
                }
                while(a['t'-'a']>0 && a['h'-'a']>0 && a['r'-'a']>0 && a['e'-'a']>1){
                    V.pb(3);
                    a['t'-'a']--;a['h'-'a']--;a['r'-'a']--;a['e'-'a']-=2;
                }
            sort(V.begin(),V.end());
        for(int i=0;i<V.size();i++) printf("%d",V[i]);
            printf("\n");
    }
}
