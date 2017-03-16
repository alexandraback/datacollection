#include<iostream>
#include<stdio.h>
#include<string.h>
#include<map>
#include<set>
using namespace std;

map<string, int> ma,mb;
set<int> set_a,set_b;
int cnt_a,cnt_b;
string sa[20],sb[20];

int main(){
    //freopen("c.in","r",stdin);
    //freopen("c.out","w",stdout);
    int T,ca=0;
    int n,i,j;
    scanf("%d",&T);
    while(T--){
        ca++;
        scanf("%d",&n);
        ma.clear();
        mb.clear();
        cnt_a=0;
        cnt_b=0;
        int ans=0;
        for(i=0;i<n;i++){
            cin>>sa[i]>>sb[i];
            if(ma.find(sa[i]) == ma.end()){
                cnt_a++;
                ma[sa[i]]=cnt_a;
            }
            if(mb.find(sb[i]) == mb.end()){
                cnt_b++;
                mb[sb[i]]=cnt_b;
            }
        }
        for(int s=0;s<(1<<n);s++){
            int cnt=0;
            set_a.clear();
            set_b.clear();
            for(i=0;i<n;i++){
                if(s&(1<<i)){
                    cnt++;
                    set_a.insert(ma[sa[i]]);
                    set_b.insert(mb[sb[i]]);
                }
            }
            int ok=1;
            for(i=0;i<n;i++){
                if(set_a.find(ma[sa[i]])==set_a.end() || set_b.find(mb[sb[i]])==set_b.end()){
                    ok=0;
                    break;
                }
            }
            if(ok){
                ans=max(ans,n-cnt);
            }
        }
        printf("Case #%d: %d\n",ca,ans);
    }
    return 0;
}
