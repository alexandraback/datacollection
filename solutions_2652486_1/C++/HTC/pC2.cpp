#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>
#include<algorithm>
#include<set>
#include<vector>
#include<time.h>
using namespace std;
int R,N,M,K;
int num[100];
long long value[100];
int gen[100];
int ans[100];
struct XD{
    int choose[13];
    long long value[10][13];
}data[100005];
void getAns(int a){
    int i;
    for(i=0;i<N;i++)
        ans[i] = data[a].choose[i];
}
double guess(){
    double best = -1,tmp;
    int cnt,i,j,k;
    for(i=0;i<100000;i++){
        for(j=0;j<3;j++){
            cnt = 0;
            for(k=0;k<N;k++){
                if(data[i].value[j][k] == value[k]){
                    cnt++;
                }
            }
            tmp = (double)cnt / (double)K;
            if(tmp > best){
                best = tmp;
                getAns(i);
                //printf("OAO\n");
            }
        }
    }
}
void make(){
    int T = 100000,vnum=3;
    int i,x=0,j,k;
    long long pro;
    while(T--){
        for(i=0;i<N;i++){
            data[x].choose[i] = rand()%(M-1)+2;
        }
        for(i=0;i<vnum;i++){
            for(j=0;j<K;j++){
                pro = 1;
                for(k=0;k<N;k++){
                    if(rand()%2 == 0)
                        pro *= data[x].choose[k];
                }
                //printf("pro %lld\n",pro);
                data[x].value[i][j] = pro;
            }
            sort(data[x].value[i],data[x].value[i]+K);
        }
        x++;
    }
}
void print(){
    int i,j;
    for(i=0;i<10;i++){
        printf("==============\n");
        for(j=0;j<N;j++)
            printf("%d ",data[i].choose[j]);
        printf("\n");
        /*for(j=0;j<10;j++){
            for(int k=0;k<K;k++)
                printf("%lld ",data[i].value[j][k]);
            printf("\n");
        }*/
    }
}
int main (){
    freopen("C-small-2-attempt3.in","r",stdin);
    freopen("Csamll_2.txt","w",stdout);
    //freopen("A-large.in","r",stdin);
    //freopen("Alarge.txt","w",stdout);
    int ca,T,i,j;
    srand(time(0));
    scanf("%d",&T);
    for(ca = 1;ca <= T;ca++){
        printf("Case #%d:\n",ca);
        scanf("%d%d%d%d",&R,&N,&M,&K);
        make();
        for(i=0;i<R;i++){
            for(j=0;j<K;j++){
                scanf("%lld",&value[j]);
            }
            sort(value,value+K);
            //print();
            guess();
            for(j=0;j<N;j++)printf("%d",ans[j]);
            printf("\n");
        }
    }
    return 0;
}
