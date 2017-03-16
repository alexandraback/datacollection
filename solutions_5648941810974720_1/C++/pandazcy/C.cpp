#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<cmath>
#include<algorithm>
#include<map>
using namespace std;
typedef long long ll;
int T,t,n,m;
char s[10][15]={"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};
char str[2010];
int num[20],num_s[300];
void solve(int pos,int sum){
    int i,j,k,len=strlen(s[pos]);
    for(i=0;i<len;i++){
        //printf("%c\n",s[pos][i]);
        num_s[s[pos][i]]-=sum;
    }

}
int main(){
    freopen("A-large.in","r",stdin);    //数据读入
    freopen("out.txt","w",stdout);  //数据输出

    int i,j,k;
    scanf("%d",&T);
    for(t=1;t<=T;t++){
        scanf("%s",str+1);
        n=strlen(str+1);
        memset(num,0,sizeof(num));
        memset(num_s,0,sizeof(num_s));
        for(i=1;i<=n;i++)
            num_s[str[i]]++;
        num[8]+=num_s['G'];solve(8,num_s['G']);
        num[0]+=num_s['Z'];solve(0,num_s['Z']);
        num[3]+=num_s['H'];solve(3,num_s['H']);
        num[4]+=num_s['U'];solve(4,num_s['U']);
        num[2]+=num_s['W'];solve(2,num_s['W']);
        num[5]+=num_s['F'];solve(5,num_s['F']);
        num[6]+=num_s['X'];solve(6,num_s['X']);
        num[7]+=num_s['S'];solve(7,num_s['S']);
        num[1]+=num_s['O'];solve(1,num_s['O']);
        num[9]+=num_s['I'];solve(9,num_s['I']);
        printf("Case #%d: ",t);
        for(i=0;i<=9;i++)
            for(j=1;j<=num[i];j++)
                printf("%d",i);
        printf("\n");
    }
}
