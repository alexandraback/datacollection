#include<cstdio>
#include<vector>
#include<cstring>
#include<map>
#include<algorithm>
using namespace std;
typedef long long ll;
typedef struct{
    ll firstattack;
    ll num;
    ll w,e;
    ll str;
    ll delay;
    ll dist;
    ll changestr;
}tribes_t;

bool sort_cmp(tribes_t a, tribes_t b){
    return a.firstattack < b.firstattack;
}
int main(void){
    freopen("C-small-attempt1.in","r",stdin);
    freopen("out5.txt","w",stdout);
    int tc, casecounter = 1;
    tribes_t tribe[20];
    scanf("%d",&tc);
    map<double,int>mapper;
    while(tc--){
        int numtribe;
        scanf("%d",&numtribe);
        for(int i=0;i<numtribe;i++){
            scanf("%lld %lld %lld %lld %lld %lld %lld %lld",&tribe[i].firstattack,
                  &tribe[i].num, &tribe[i].w,&tribe[i].e, &tribe[i].str,
                  &tribe[i].delay,&tribe[i].dist,&tribe[i].changestr);
        }
        mapper.clear();
        vector<tribes_t> att;
        att.clear();
        for(int i=0;i<numtribe;i++){
            tribes_t placeholder = tribe[i];
            for(int j=0;j<tribe[i].num;j++){
                att.push_back(placeholder);
                placeholder.firstattack+=placeholder.delay;
                placeholder.w += placeholder.dist;
                placeholder.e += placeholder.dist;
                placeholder.str += placeholder.changestr;
            }
        }
        tribes_t attacks[220];
        for(int i=0;i<att.size();i++){
            attacks[i] = att[i];
        }
        sort(attacks,attacks+(int)att.size(),sort_cmp);
       /* for(int i=0;i<att.size();i++){
            printf("%d \n",attacks[i].firstattack);
        }*/
        int curday = -1;
        int successful = 0;
        bool success = false;
        for(int i=0;i<(int)att.size();i++){
                success = false;
            if(curday!=attacks[i].firstattack){

                for(map<double,int>::iterator it = mapper.begin();it!=mapper.end();it++){
                    if(it->second < 0){
                        it->second*=-1;
                    }
                }

            }
            curday = attacks[i].firstattack;

            for(double j=attacks[i].w;j<=attacks[i].e;j+=0.5){
                //printf("%d\n",i);
                if(mapper.find(j)==mapper.end() || mapper[j]<attacks[i].str){
                    success = true;
                    mapper[j] = - attacks[i].str;
                }
            }
            if(success)successful++;

        }
        //if(success)successful++;
        printf("Case #%d: %d\n",casecounter++, successful);

    }



    return 0;
}
