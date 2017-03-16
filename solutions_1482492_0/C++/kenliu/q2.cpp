#include<stdio.h>
#include<string.h>
#include<iostream>
#include<algorithm>
#include<math.h>
#include<vector>
#include<map>
#include<set>
#include<stack>
#include<queue>
#define PI 3.141592653589793
#define DEBUG 0
#define INF 1000000007

using namespace std;

int T,N,A,cases=1;
double D;
vector<double>acc;
vector< pair<double,double> >pos;
void getNum(){
    int i,j,k;
    double tot_tm=0,a_acc,pre_tm,pre_dis,a_sp,b_sp,b_tm,b_dis,t1;
    bool ff;
    printf("Case #%d:\n",cases);
    for(j=0;j<A;j++){
        pre_tm=pre_dis=tot_tm=a_sp=0;
        a_acc=acc[j];
        //car b might be ahead at the beginning
        if(DEBUG)printf("a ac: %f\n",a_acc);
        ff=0;
        b_dis=pos[0].second;
        if(b_dis>0){
            if(b_dis>=D){                        //already farrer
                tot_tm = sqrt(D*2/a_acc);
                printf("%.8f\n",tot_tm);
                ff=1;
            }
            else{
                tot_tm+=sqrt((2*b_dis)/a_acc);
                a_sp=tot_tm*a_acc;
                pre_dis=b_dis;
                //go=1;
                if(DEBUG)printf("period %d(just go): time %f\n",0, tot_tm);
            } 
        }
        if(!ff){
            for(i=1;i<N;i++){
                //get b car's speed
                if(DEBUG)printf("pos[%d]: %f %f\n",i,pos[i].first,pos[i].second);
                b_dis=pos[i].second-pre_dis;
                b_tm=pos[i].first-pre_tm;
                b_sp = b_dis/b_tm;
                //adjust b car's time(might ended farer)
                if(pos[i].second>D){
                    b_tm = b_tm*(D-pre_dis)/b_dis;
                    b_dis=D-pre_dis;
                }
                t1 = ((b_sp-a_sp)*2)/a_acc;
                if(t1<b_tm){         //brake & follow b
                    a_sp=b_sp;
                    tot_tm=b_tm;
                    if(DEBUG){
                        printf("b_dis b_tm: %f %f\n",b_dis,b_tm);
                        printf("period %d(follow): time %f\n",i, b_tm);
                    }
                    //go=0;
                }
                else{                //just go
                    t1 = (-2*a_sp+sqrt(4*a_sp*a_sp+8*a_acc*b_dis))/(2*a_acc);
                    //go=1;
                    if(DEBUG){
                        printf("a_sp b_dis b_tm b_sp: %f %f %f %f\n",a_sp,b_dis,b_tm,b_sp);
                        printf("period %d(just go): time %f\n",i, t1);
                    }
                    a_sp=a_sp+a_acc*t1;
                    tot_tm+=t1; 
                    
                }
                //save 
                pre_dis = pos[i].second;
                pre_tm = b_tm;
                if(pos[i].second>=D)break;
            }
            printf("%.8f\n",tot_tm);
        }
    }
}
void init(){
    pos.clear();
    acc.clear();
}
int main(){
    int i,j,k;
    double a,b;
    scanf("%d",&T);
    if(DEBUG)printf("T: %d\n",T);
    for(i=0;i<T;i++){
        scanf("%lf %d %d",&D,&N,&A);
        if(DEBUG)printf("d n a: %f %d %d\n",D,N,A);
        for(j=0;j<N;j++){
            scanf("%lf %lf",&a,&b);
            if(DEBUG)printf("a,b:%f %f\n",a,b);
            pos.push_back(make_pair(a,b));
        }
        for(j=0;j<A;j++)
            scanf("%lf",&a),acc.push_back(a);
        getNum();
        cases++;
        init();
    }
            
    return 0;
}
