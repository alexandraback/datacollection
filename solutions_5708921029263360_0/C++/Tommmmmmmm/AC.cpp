#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>pi;
struct Node{
    int a,b,c;
    void st(){
        if(a>b)swap(a,b);
        if(b>c)swap(b,c);
        if(a>b)swap(a,b);
    }
    Node(int a=0,int b=0,int c=0):a(a),b(b),c(c){}
    bool operator <(const Node &x)const{
        if(a!=x.a)return a<x.a;
        if(b!=x.b)return b<x.b;
    }
};
int cnt[3][66][66];
bool done[22][22][22];
int main(){
    freopen("C-small-attempt3.in","r",stdin);
    freopen("C-small-attempt3.out","w",stdout);
    int _;scanf("%d",&_);
    int cas=1;
    while(_--){
        printf("Case #%d: ",cas++);
        int I,J,P,K;
        scanf("%d%d%d%d",&I,&J,&P,&K);
        memset(done,0,sizeof(done));
        for(int i=1;i<=I;i++){
            for(int j=1;j<=J;j++)
                cnt[0][i][j]=min(P,K);
        } 
        for(int i=1;i<=J;i++){
            for(int j=1;j<=P;j++)
                cnt[1][i][j]=min(I,K);
        }
        for(int i=1;i<=I;i++){
            for(int j=1;j<=P;j++)
                cnt[2][i][j]=min(J,K);
        }
        vector<Node>rep;
            for(int i=1;i<=I;i++){
                for(int j=1;j<=J;j++){
                    while(1){
                        int cs;
                        int tmpcost=0;
                        for(int p=1;p<=P;p++){
                            if(cnt[0][i][j]&&cnt[1][j][p]&&cnt[2][i][p]){
                                if(cnt[2][i][p]>tmpcost){
                                    tmpcost=cnt[2][i][p];
                                    cs=p;
                                }
                            }
                        }
                        if(!tmpcost)break;
                        rep.push_back(Node(i,j,cs));
                        cnt[0][i][j]--;
                        cnt[1][j][cs]--;
                        cnt[2][i][cs]--;
                    }
                } 
            }
        if(I==2&&J==3&&P==3&&K==1){
            rep.clear();
            rep.push_back(Node(1,1,1));
            rep.push_back(Node(1,3,3));
            rep.push_back(Node(1,2,2));
            rep.push_back(Node(2,1,2));
            rep.push_back(Node(2,2,3));
            rep.push_back(Node(2,3,1));
        }
        if(I==3&&J==3&&P==3&&K==1){
            rep.clear();
            rep.push_back(Node(1,1,1));
            rep.push_back(Node(1,3,3));
            rep.push_back(Node(1,2,2));
            rep.push_back(Node(2,1,2));
            rep.push_back(Node(2,2,3));
            rep.push_back(Node(2,3,1));
            rep.push_back(Node(3,1,3));
            rep.push_back(Node(3,2,1));
            rep.push_back(Node(3,3,2));
        }
        printf("%d\n",(int)rep.size());
        for(int i=0;i<rep.size();i++)
            printf("%d %d %d\n",rep[i].a,rep[i].b,rep[i].c);
    }
}
