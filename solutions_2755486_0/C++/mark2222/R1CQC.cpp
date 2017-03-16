#include<cstdio>
#include<set>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;
struct marker{
    int start,end,strength;
    marker(){}
    marker(int sa,int ea,int stra){start=sa;end=ea;strength=stra;}
};
struct markercmp{
    bool operator()(marker a,marker b){
        return a.start<b.start;
    }
};
struct attack{
    int day,wallstart,wallend,strength;
    attack(){}
    attack(int da,int wsa,int wea,int stra){day=da;wallstart=wsa;wallend=wea;strength=stra;}
};
typedef set<marker,markercmp>::iterator markerit;
set<marker,markercmp> markers;
vector<attack> attacks;
vector<attack> cattacks;
int height[401];
marker createmarker(int start){
    return marker(start,0,0);
}
bool attackwinswall(attack cattack,marker cmarker){
    return cattack.wallstart<cmarker.end&&cattack.wallend>=cmarker.start&&cattack.strength>cmarker.strength;
}
int attacksuccess(attack cattack){
    /*markerit startit=markers.upper_bound(createmarker(cattack.wallstart)),
    endit=markers.lower_bound(createmarker(cattack.wallend));
    if(endit==markers.begin()||startit==markers.begin()) return true;
    else{
        int cpos=startit->start;
        while(startit!=endit){
            int npos=startit->start;
            if(npos>cpos) return true;
            else{
                if(attackwinswall(cattack,*startit)) return true;
            }
            cpos=startit->end;
            startit++;
        }
    }*/
    for(int i=cattack.wallstart;i<cattack.wallend;i++){
        if(height[i+200]<cattack.strength) return true;
    }
    return false;
}
void updatewall(attack cattack){
    for(int i=cattack.wallstart;i<cattack.wallend;i++){
        if(i<(-200)||i>200) printf("HELP!\n");
        if(height[i+200]<cattack.strength) height[i+200]=cattack.strength;
    }
}
bool cmp(attack a,attack b){
    return a.day<b.day;
}
int main(){
    freopen("R1CQC.in","r",stdin);
    freopen("R1CQC.out","w",stdout);
    int numcases;
    scanf("%d",&numcases);
    for(int ccase=0;ccase<numcases;ccase++){
        markers=set<marker,markercmp>();
        attacks.clear();
        memset(height,0,sizeof(height));
        int numtribes;
        scanf("%d",&numtribes);
        for(int i=0;i<numtribes;i++){
            int firstday,numattacks,firstwallstart,firstwallend,firststrength,dday,dpos,dstrength;
            scanf("%d%d%d%d%d%d%d%d",&firstday,&numattacks,&firstwallstart,&firstwallend,&firststrength,
                  &dday,&dpos,&dstrength);
            for(int i2=0;i2<numattacks;i2++){
                attack cattack(firstday+i2*dday,firstwallstart+i2*dpos,firstwallend+i2*dpos,firststrength+i2*dstrength);
                attacks.push_back(cattack);
            }
        }
        sort(attacks.begin(),attacks.end(),cmp);
        int cday=0;
        cattacks.clear();
        int numwins=0;
        for(int i=0;i<attacks.size();i++){
            if(attacks[i].day>cday){
                for(int i2=0;i2<cattacks.size();i2++){
                    if(attacksuccess(cattacks[i2])) numwins++;
                }
                for(int i2=0;i2<cattacks.size();i2++){
                    updatewall(cattacks[i2]);
                }
                cattacks.clear();
                cattacks.push_back(attacks[i]);
                cday=attacks[i].day;
            }
            else cattacks.push_back(attacks[i]);
        }
        for(int i2=0;i2<cattacks.size();i2++){
            if(attacksuccess(cattacks[i2])) numwins++;
        }
        for(int i2=0;i2<cattacks.size();i2++){
            updatewall(cattacks[i2]);
        }
        printf("Case #%d: %d\n",ccase+1,numwins);
    }
    return 0;
}
