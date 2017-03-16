#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
int T,N,M,K;
int bits[1<<21];
int bit(int x){
    int cnt=0;
    while(x){
             if(x&1)
                cnt++;
             x/=2;
    }
    return cnt;
}
void check(int s){
     for(int i=0;i<N;++i)
             for(int j=0;j<M;++j){
                     int z=i*M+j;
                     if((1<<z)&s)
                                 cout<<i<<" "<<j<<endl;
             }
}
int main(){
    freopen("C-small-attempt0.in","r",stdin);
    freopen("out.txt","w",stdout);
    for(int i=0;i<(1<<20);++i)
            bits[i] = bit(i);
    cin>>T;
    for(int cas=1;cas<=T;++cas){
            cin>>N>>M>>K;
            int NN = N*M;
            int ans=NN;
            for(int i=0;i<(1<<NN);++i){
                    int cnt=0;
                    for(int x=0;x<N;++x)
                            for(int y=0;y<M;++y){
                                    int z=x*M+y;
                                    if((1<<z)&i){
                                                 cnt++;
                                                 continue;
                                    } else if(x==0 || x==N-1 || y==0 || y==M-1){
                                      continue;
                                    }
                                //    if(i==133158)cout<<x<<"   "<<y<<endl;
                                    int x1=x,x2=x;
                                    int y1=y,y2=y;
                                    int z1=z;
                                    while(x1>=0){
                                        if((1<<z1)&i)
                                           break;
                                        z1-=M;
                                        x1--;
                                    }
                                    if(x1<0)continue;
                                    z1=z;
                                    while(x2<N){
                                                if((1<<z1)&i)
                                                   break;
                                                z1+=M;
                                                x2++;
                                    }
                                    if(x2>=N)continue;
                                    z1=z;
                                    while(y1>=0){
                                        if((1<<z1)&i)
                                            break;
                                        z1--;
                                        y1--;
                                    }
                                    if(y1<0)continue;
                                    z1=z;
                                    while(y2<M){
                                                if((1<<z1)&i)
                                                   break;
                                                z1++;
                                                y2++;
                                    }
                                    if(y2>=M)continue;
                                //    if(i==133158)cout<<x<<"  "<<y<<endl;
                                    cnt++;
                            }
                            if(cnt>=K){
                                     //  if(bits[i]==5 && i==133158)check(i);//cout<<i<<endl;
                                       ans=min(ans,bits[i]);
                                       }
            }
            printf("Case #%d: ",cas);
            printf("%d\n",ans);
    }
    return 0;
}
