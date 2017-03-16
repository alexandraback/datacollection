#include <cstdio>
#include <algorithm>
#include <set>
using namespace std;

int e[1010];
int l[1010];
int main (){
    int T;
    scanf("%d",&T);
    for(int I = 1 ; I <= T ; I ++ ){
        fill(l,l+1010,0);
        int n;
        scanf("%d",&n);
        for(int i = 0 ; i < n ; i ++){
            scanf("%d",e+i);
            e[i]--;
        }
        int maxs=0;
        for(int i = 0 ; i < n ; i ++){
            int now=i;
            //printf("S %d\n",i);
            set<int> s;
            do{
                //printf("T %d\n",now);
                if(s.find(now)==s.end())s.insert(now);
                else break;
                now=e[now];
            }while(now!=i);
            if(now==i)maxs=max(maxs,(int)s.size());
        }
        for(int i = 0 ; i < n ; i ++){
            int now=i;
            int pre;
            set<int> s;
            while(1){
                //printf("T %d\n",now);
                if(s.find(now)==s.end())s.insert(now);
                else break;
                pre=now;
                now=e[now];
            };
            if(e[now]==pre){
                l[now]=max(l[now],(int)s.size()-2);
            }
        }
        //for(int i = 0 ; i < n ; i ++)printf("%d,",l[i]);
        //puts("");
        int tmp=0;
        for(int i = 0 ; i < n ; i ++){
            for(int j = i+1 ; j < n ; j ++){
                if(e[i]==j&&e[j]==i){
                    tmp+=l[i]+l[j];
                    tmp+=2;
                }
            }
        }
        maxs=max(maxs,tmp);
        printf("Case #%d: %d\n",I,maxs);

    }

}
