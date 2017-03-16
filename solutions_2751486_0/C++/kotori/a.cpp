#include <iostream>
#include <stdio.h>
#include <cstring>
#include <queue>

using namespace std;

const int MAXINT=214748364;

const int dx[6]={-1,0,1,0,0,0};
const int dy[6]={0,1,0,-1,0,0};
const int dz[6]={0,0,0,0,1,-1};

struct p{
       int x,y,z;
       p(int x,int y,int z):x(x),y(y),z(z){}
};

int f[70][70][70];
char g[100][100];
int n,m,k,ans,t,x,a,b,c,T;
queue<p> q;
char str[10000];


int main(){
    //freopen("1.in","r",stdin);
    //freopen("1.out","w",stdout);
    cin >> T;
    int tot=0;
    while (T--){
          cin >> str >> n;
          
          int len=strlen(str);
          int ans=0;
          for (int i=0;i<len;i++)
              for (int j=i+n-1;j<len;j++){
                  int now=0;
                  for (int l=i;l<=j;l++){
                      if (((str[l]-'a')==0)||((str[l]-'e')==0)||((str[l]-'i')==0)||((str[l]-'o')==0)||((str[l]-'u')==0))
                         now=0;
                         else now++;
                      if (now>=n) {ans++;break;}
                  }
              }
          
          cout << "Case #"<<++tot<<": "<<ans<<endl;
    }
    //system("pause");
    return 0;
}
