#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<map>
#include<cstring>
#include<queue>
#define MAX(a,b) (a>b?a:b)
#define MIN(a,b) (a<b?a:b)
#define pb push_back
#define mp make_pair
#define F first
#define S second
using namespace std;
const int n_max=400;
int t,i,j,k,n,T,P=100,x,y,newx,newy,X,Y;
map<pair<int,int>,bool> f;
map<pair<int,int>,string> S;
string s;
struct Ele{
       int x,y;
       Ele(int a,int b){x=a;y=b;};
          };
queue<Ele> Q;
int di[4]={1,-1,0,0};
int dj[4]={0,0,-1,1};
char ss[4]={'E','W','S','N'};


main()
{freopen("B-small-attempt0.in","r",stdin);
 freopen("out.txt","w",stdout);
 cin>>T;
 for(t=1;t<=T;t++){
      cin>>x>>y;
      S.clear();
      f.clear();
      Q.push(Ele(0,0));

      while(Q.size()){
            X=Q.front().x;
            Y=Q.front().y;
            s=S[mp(X,Y)];
            k=s.size()+1;
            if(X==x && Y==y)goto bolo;
            Q.pop();
            for(i=0;i<4;i++){
                    newx=X+k*di[i];
                    newy=Y+k*dj[i];
                    if(!f[mp(newx,newy)]){
                              S[mp(newx,newy)]=s+ss[i];
                              f[mp(newx,newy)]=1;
                              if(newx==x && newy==y)goto bolo;
                              Q.push(Ele(newx,newy));
                    }
            }

      }
      bolo: {}
      while(Q.size())Q.pop();
     cout<<"Case #"<<t<<": "<<S[mp(x,y)]<<endl;
    }

}
