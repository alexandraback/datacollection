#include<stdio.h>
#include<algorithm>
using namespace std;
#define LL long long
int M[8][8] = {
    0,1,2,3,4,5,6,7,
    1,0,3,2,5,4,7,6,
    2,3,1,0,6,7,5,4,
    3,2,0,1,7,6,4,5,
    4,5,7,6,1,0,2,3,
    5,4,6,7,0,1,3,2,
    6,7,4,5,3,2,1,0,
    7,6,5,4,2,3,0,1
};
inline int cal(int x,int y){
    return M[x][y];
}
char str[10005];
int data[10005];
int head[10005];
int back[10005];
int seg[10];
bool solve(int L,LL X){
    head[0] = 0;
    for(int i =1;i<=L;i++){
        head[i] = cal(head[i-1],data[i-1]);
    }
    back[L+1] = 0;
    for(int i =L;i>0;i--){
        back[i] = cal(data[i-1],back[i+1]);
    }
    int res = 0,ori= head[L];
    for(LL k = X;k;k>>=1){
        if(k&1){
            res = cal(res,ori);
        }
        ori = cal(ori,ori);
    }
    if(res!=1)
        return false;
    LL prev=(LL)1<<30,tail=(LL)1<<30;
    seg[0] = 0;
    int NN = 1;
    for(;;NN++){
        seg[NN] = cal(seg[NN-1],head[L]);
        if(seg[NN]==seg[0]) break;
    }
    
    int target;
    for(int i=0;i<=L;i++){
        target = cal(cal(2,head[i]),(head[i]!=0));
        for(int j =0;j<NN;j++){
            if(seg[j]==target){
                prev = min(prev,i+(LL)j*L);
            }
        }
    }
    for(int i=0;i<=L;i++){
        target = cal(cal(back[L-i+1],6),(back[L-i+1]!=0));
        for(int j =0;j<NN;j++){
            if(seg[j]==target){
                tail = min(tail,i+(LL)j*L);
            }
        }
    }
    if( prev+tail<L*X)
        return true;
    return false;
    
}
int main ()
{
    int T,L;
    LL X;
    scanf("%d",&T);
    for(int _=1;_<=T;_++){
        scanf("%d%lld",&L,&X);
        scanf("%s",str);
        for(int i = 0;i<L;i++){
            if(str[i]=='i'){
                data[i] = 2;
            }else if(str[i]=='j'){
                data[i] = 4;
            }else{
                data[i] = 6;
            }
        }
        bool ans = solve(L,X);
        printf("Case #%d: %s\n",_,ans?"YES":"NO");
    }
    return 0;
}