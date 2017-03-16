#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <utility>
#include <set>
#include <map>
#include <iostream>
#include <queue>

using namespace std;

typedef long long LL;

#define PB push_back
#define FRO freopen("in.txt","r",stdin);

#define SIZE 1000100

int arr[SIZE];

int func(int x,int d){
    if ( d==0 )return 0;
    return (x-1)+func( x+x-1,d-1 );
}

struct node{
    int move,ind,sum;
    bool operator < (const node & p)const{return move>p.move;}
};

int main(){
    freopen("A-large.in","r",stdin);
    freopen("out.out","w",stdout);


    int kase;
    scanf("%d",&kase);

    for (int kk=1;kase--;++kk){
        node start;
        int total;
        scanf("%d %d",&start.sum,&total);

        for (int i=0;i<total;++i){
            scanf("%d",&arr[i]);
        }

        int move=0;
        sort(arr,arr+total);

        priority_queue<node> q;

        start.move=0;
        start.ind= 0;
        q.push(start);

        while(!q.empty()){
            node tt=q.top();q.pop();
            node an;
            //printf("%d %d %d\n",tt.ind,tt.move,tt.sum);
            if ( tt.ind == total ){
                move=tt.move;
                break;
            }

            if ( tt.sum>arr[tt.ind] ){
                an.ind=tt.ind+1;
                an.move=tt.move;
                an.sum=tt.sum+arr[ tt.ind ];
                q.push(an);
            }else{
                for (int i=1; func(tt.sum,i)>0    ;++i){

                    if ( tt.sum+func(tt.sum,i)>arr[ tt.ind ] ){
                        an.ind=tt.ind+1;
                        an.move=tt.move+i;
                        an.sum=tt.sum+func(tt.sum,i)+arr[ tt.ind ];
                        q.push(an);
                        break;
                    }
                }

                an.ind=tt.ind+1;
                an.move=tt.move+1;
                an.sum=tt.sum;
                q.push(an);
            }
        }
        printf("Case #%d: %d\n",kk,move);
    }

    return 0;
}
