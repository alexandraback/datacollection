#include <bits/stdc++.h>
using namespace std;

#ifdef mahou_shoujo_madoka
    #define LLF "%I64d"
#else
    #define LLF "%lld"
#endif

typedef pair<int,int> PII;

long long ceil(long long num, long long div){
    return (num+div-1)/div;
}

int main(){
    int cs;
    scanf("%d",&cs);
    for(int no=1;no<=cs;no++){
        int n;
        vector<PII> u;
        scanf("%d",&n);
        for(int i=0;i<n;i++){
            int D,H,M;
            scanf("%d%d%d",&D,&H,&M);
            for(int j=0;j<H;j++) u.push_back(PII(D,-(M+j)));
        }
        long long ans=n=u.size();
        sort(u.begin(),u.end()); // second 越大，跑得越快
        for(int i=0;i<n;i++){
            if(i && u[i]==u[i-1]) continue;
            long long cnt=i;
            for(int j=0;j<n;j++){
                if(u[j].second>u[i].second){
                    long long tick=(-u[i].second)*(360ll-u[i].first);
                    long long catch_up=tick/(-u[j].second)-(360ll-u[i].first);
                    long long first_gap=(u[i].first-u[j].first+360)%360;
                    if(!first_gap) first_gap=360;
                    long long meet=0;
                    if(catch_up>=first_gap){
                        meet++;
                        catch_up-=first_gap;
                    }
                    meet+=catch_up/360;
                    cnt+=meet;
                }
                if(u[j].second<u[i].second){
                    long long tick=(-u[i].second)*(360ll-u[i].first);
                    long long catch_up=(360ll-u[i].first)-ceil(tick,-u[j].second);
                    long long first_gap=(u[i].first-u[j].first+360)%360;
                    if(!first_gap) first_gap=360;
                    long long meet=0;
                    if(catch_up>=first_gap){
                        meet++;
                        catch_up-=first_gap;
                    }
                    meet+=catch_up/360;
                    cnt+=meet;
                }
            }
            ans=min(ans,cnt);
        }
        for(int i=0;i<n;i++){
            if(i && u[i]==u[i-1]) continue;
            long long cnt=i+1;
            for(int j=0;j<n;j++){
                if(u[j].second>u[i].second){
                    long long tick=(-u[i].second)*(360ll-u[i].first);
                    long long catch_up=ceil(tick,-u[j].second)-(360ll-u[i].first)-1;
                    long long first_gap=(u[i].first-u[j].first+360)%360;
                    if(!first_gap) first_gap=360;
                    long long meet=0;
                    if(catch_up>=first_gap){
                        meet++;
                        catch_up-=first_gap;
                    }
                    meet+=catch_up/360;
                    cnt+=meet;
                }
                if(u[j].second<u[i].second){
                    long long tick=(-u[i].second)*(360ll-u[i].first);
                    long long catch_up=(360ll-u[i].first)-ceil(tick,-u[j].second);
                    long long first_gap=(u[i].first-u[j].first+360)%360;
                    if(!first_gap) first_gap=360;
                    long long meet=0;
                    if(catch_up>=first_gap){
                        meet++;
                        catch_up-=first_gap;
                    }
                    meet+=catch_up/360;
                    cnt+=meet;
                }
            }
            ans=min(ans,cnt);
        }
        printf("Case #%d: " LLF "\n",no,ans);
    }
}
