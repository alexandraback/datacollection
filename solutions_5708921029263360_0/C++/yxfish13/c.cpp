#include<cstdio>
#include<cstring>
#include<iostream>

using namespace std;
long long B;
long long M;
int ans1[100][100];
int ans2[100][100];
int ans3[100][100];
int dt[100];
int J,P,S,K;
void Sol(){
    //int J,P,S,K;
    cin>>J>>P>>S>>K;
    memset(dt,0,sizeof(dt));
    memset(ans1,0,sizeof(ans1));
    memset(ans2,0,sizeof(ans2));
    memset(ans3,0,sizeof(ans3));
    if (S<=K){
      K=S;
      //printf("YES\n");
      //return;
    }
    printf(" %d\n",J*P*K);
    dt[0]=0;
    for (int i=1;i<P;i++)
      dt[i]=(dt[i-1]+K)%S;
    for (int i=0;i<J;i++)
      for (int j=0;j<P;j++)
        for (int tt=0;tt<K;tt++){
        int now=dt[j];
        ans1[i][j]++;//if()ans1[j][i]++;
        ans2[i][now]++;//ans2[now][i]++;
        ans3[now][j]++;//ans3[j][now]++;
        dt[j]=(dt[j]+1)%S;
        printf("%d %d %d\n",i+1,j+1,now+1);
      }
/*
    for (int i=0;i<=S;i++)
      for (int j=0;j<=S;j++)
        if (ans1[i][j]>K|| ans2[i][j]>K||ans3[i][j]>K){
          printf("NO %d %d\n",i+1,j+1);
          if (ans2[i][j]>K) printf("2\n");
          if (ans1[i][j]>K) printf("1\n");
          if (ans3[i][j]>K) printf("3\n");
          return;
        }
        printf("YES\n");
        return;*/
}
int main(){
    int T;
    freopen("c.in","r",stdin);
    freopen("c.out","w",stdout);
    scanf("%d",&T);
    for (int datanum=1;datanum<=T;datanum++){
        //S=rand()%15+1;
        //while (S>10) S=rand()%15+1;
        //P = rand()%S+1;
        //J= rand()%P+1;
        //K = rand()%10+1;
        //printf("%d %d %d %d\n",J,P,S,K);
        printf("Case #%d:",datanum);
        Sol();
    }
    //printf("fuck");
    fclose(stdout);
    return 0;
}
