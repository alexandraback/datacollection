#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>
#include<algorithm>
#include<set>
#include<vector>
using namespace std;
int num[25];
struct XD{
    int set;
    int value;
}data[1 << 21];
bool cmp(XD a,XD b){
    return a.value < b.value;
}
int n,k;
int use[21];
int cal(){
    int i,ans=0;
    for(i=0;i<n;i++){
        if(use[i] == 1){
            ans = ans * 2 + 1;
        }else ans = ans * 2;
    }
    return ans;
}
void dfs(int pos,int sum){
    int i;
    if(pos == n){
        data[k].value = sum;
        data[k].set = cal();
        k++;
        //printf("sum %d\n",sum);
        //printf("k = %d\n",k);
        return;
    }
   // for(i=0;i<n;i++){
        use[pos] = 1;
        dfs(pos+1,sum+num[pos]);
        use[pos] = 0;
        dfs(pos+1,sum);
}
void pr(int z){
    int i=19,tmp,sp=0;
    tmp = data[z].set;
    while(tmp > 0){
        if(tmp % 2 == 1){
            if(sp == 1)printf(" ");
            sp = 1;
            printf("%d",num[i]);
        }
        i--;
        tmp /= 2;
    }
    printf("\n");
}
int main (){
    int T,ca=0,flag;
    int i,j;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        for(i=0;i<n;i++)scanf("%d",&num[i]);
        memset(use,0,sizeof(use));
        ca++;
        printf("Case #%d:\n",ca);
        k = 0;
        dfs(0,0);
        //printf("k %d end\n",k);
        sort(data,data+k,cmp);
        flag = 0;
        for(i=1;i<k;i++){
           // printf("%d\n",data[i].value);
            for(j=i+1;j<k;j++){
                if(data[i].value != data[j].value)break;
                //printf("%d %d\n",data[i].set^data[j].set,data[i].set & data[j].set);
                //system("pause");
                if(0 == (data[i].set & data[j].set)){
                    pr(i);
                    pr(j);
                    flag = 1;
                    break;
                }
            }
            if(flag == 1)break;
        }
    }
    return 0;
}


