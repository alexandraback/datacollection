#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
int n,nt,hd[2],hs,usd[55],ass[55],asn;
struct Time{
    int up, dn;
    char mi;
    bool operator<(Time b)const{
        int diff = up*b.dn-dn*b.up;
        return diff!=0?diff<0:mi<b.mi;
    }
    bool operator==(Time b){
        return up*b.dn==dn*b.up&&mi==b.mi;
    }
}tim[10000010], cur;
struct Point{
    int id, x, v;
    char ed;   
    bool operator<(Point b)const{
        int cc = x*cur.dn+v*cur.up - b.x*cur.dn-b.v*cur.up;
        if(cc!=0)return cc<0;
        if(cur.mi>0&&v!=b.v)return v<b.v;
        if(cur.mi<0&&v!=b.v)return v>b.v;
        return ed>b.ed;
    }
}inp[105];
int par[10000010], lin[10000010];
int findPar(int p, int& r){
    r=0;
    int t=p;
    while(par[t]!=t){
        r=(r+lin[t])%2;
        t=par[t];
    }
    int rr = 0, tt=p, tmp;
    while(par[tt]!=tt){
        tmp = (rr+lin[tt])%2;
        lin[tt] = (r-rr+2)%2;
        rr = tmp;
        
        tmp=par[tt];
        par[tt] = t;
        tt=tmp;
    }
    r=(r+lin[t]+2)%2;
    return t;
}
int findPar(int p){
    int tmp;
    return findPar(p, tmp);
}

int main(){
    int cas;   
    scanf("%d",&cas);
    for(int iii=0;iii<cas;iii++){
        scanf("%d",&n);
        for(int i=0;i<n;i++)par[i]=i;
        for(int i=0;i<n;i++){
            char tmp[5];
            scanf("%s%d%d",tmp,&inp[2*i].v, &inp[2*i].x); 
            inp[2*i+1].x=inp[2*i].x+5;
            inp[2*i+1].v=inp[2*i].v;
            inp[2*i+1].id = inp[2*i].id = i;
            inp[2*i+1].ed = 1;
            inp[2*i].ed = 0;
            if(tmp[0]=='R')lin[i]=0;
            else lin[i]=1;
            ass[i]=i;
        }  
        asn=n;
        tim[0].up=0;
        tim[0].dn=1;
        tim[0].mi=0;
        nt=1;
        tim[0].up=0;
        tim[0].dn=1;
        tim[0].mi=1;
        nt=2;
        for(int i=0;i<2*n;i++){
            for(int j=0;j<2*n;j++){
                if(inp[i].x<inp[j].x && inp[i].v>inp[j].v){
                    tim[nt].up = inp[j].x-inp[i].x;
                    tim[nt].dn = inp[i].v-inp[j].v;
                    tim[nt].mi = -1;
                    nt++;
                    tim[nt].up = inp[j].x-inp[i].x;
                    tim[nt].dn = inp[i].v-inp[j].v;
                    tim[nt].mi = 0;
                    nt++;
                    tim[nt].up = inp[j].x-inp[i].x;
                    tim[nt].dn = inp[i].v-inp[j].v;
                    tim[nt].mi = 1;
                    nt++;
                }
            }
        }
        std::sort(tim, tim+nt);
        int ttt;
        for(ttt=0;ttt<nt;ttt++){
            if(ttt!=0&&tim[ttt-1]==tim[ttt])continue;
            cur = tim[ttt];
            std::sort(inp, inp+2*n);
            hs=0;
            memset(usd,0,sizeof(usd));
            for(int i=0;i<2*n;i++){
                if(!inp[i].ed){
                    //printf("%d %d %d %d\n", hs, cur.up, cur.dn, inp[i].id);
                    if(hs==2)goto OUT;
                    if(hs==1){
                        //add edge  
                        usd[inp[i].id]=1;
                        usd[hd[0]]=1; 
                        int r1,r2;
                        int p1=findPar(ass[inp[i].id],r1),p2=findPar(ass[hd[0]],r2);
                        if(p1==p2){
                            if(r1==r2)goto OUT;   
                        }else{
                            if(lin[p1]!=-1&&lin[p2]!=-1&&r1==r2)goto OUT;
                            if(lin[p1]!=-1){
                                par[p2]=p1;
                                lin[p2]=(1 + r1-lin[p1]+r2-lin[p2]+4)%2;   
                            }else{
                                par[p1]=p2;
                                lin[p1]=(1 + r1-lin[p1]+r2-lin[p2]+4)%2;
                            }
                        }
                    }
                    hd[hs++]=inp[i].id;
                }else{
                    if(inp[i].id==hd[0]){
                        hd[0]=hd[1];
                        hs--;   
                    }else{
                        hs--;
                    }
                }
            }
            for(int i=0;i<n;i++){
                if(usd[i]==0){
                    ass[i]=asn;
                    par[asn]=asn;
                    lin[asn]=-1;
                    asn++;   
                }   
            }
        }
        OUT:;
        if(ttt==nt)printf("Case #%d: Possible\n",iii+1);
        else printf("Case #%d: %.8lf\n", iii+1, ((double)cur.up)/cur.dn);
        
    }
    scanf(" ");
}
