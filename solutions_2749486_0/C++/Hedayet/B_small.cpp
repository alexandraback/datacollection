//Bismillahir Rahmanir Rahim

//For SHOSHI


#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cctype>
#include <cstdlib>
#include <vector>
#include <string>
#include <cstring>
#include <queue>
#include <set>
#include <stack>
#include <map>
#include <sstream>

using namespace std;

#define mp make_pair
#define rep(i,n) for(int i=0,_n=n;i<_n;i++)
#define reps(i,s,n) for(int i=s,_n=n;i<_n;i++)
#define pi 2.0*acos(0.0)
#define MAX 2147483647
#define MIN -2147483647
#define torad(a) (a*pi)/180.0;
#define eps 0.000000001
#define pb push_back
#define pf push_front
#define pob pop_back
#define pof pop_front

typedef long long ll;
typedef vector<int>VI;
typedef map<string,int> MSI;
typedef set<int>SI;
typedef pair<int,int>PAR;
typedef vector<PAR>VP;

PAR par[209][209][209];
int jump[209][209][309];

void BFS(int x,int y){
    queue<PAR>Q;
    queue<int>P;
    Q.push(mp(x,y));
    P.push(0);
    jump[x][y][0]=0;

    par[x][y][0]=mp(100,100);
    while(!Q.empty()){
        PAR u = Q.front();
        int i = P.front()+1;
        Q.pop();
        P.pop();

        int x = u.first;

        int y = u.second;

            if(i+x<=201&&jump[i+x][y][i]==-1){
                par[i+x][y][i] =u;
                jump[x+i][y][i]=i;
                Q.push(mp(i+x,y));
                P.push(i);
            }
            if(x-i>=0&&jump[x-i][y][i]==-1){
                par[x-i][y][i]=u;
                jump[x-i][y][i]=i;
                Q.push(mp(x-i,y));
                P.push(i);
            }
            if(i+y<=201&&jump[x][i+y][i]==-1){
                jump[x][i+y][i]=i;
                Q.push(mp(x,y+i));
                par[x][y+i][i]=u;

                P.push(i);
            }
            if(y-i>=0&&jump[x][y-i][i]==-1){
                par[x][y-i][i]=u;

                jump[x][y-i][i]=i;
                Q.push(mp(x,y-i));
                P.push(i);
            }
    }
}

string printPath(int x,int y){
    string ret;
    int j = -1;
    rep(i,201){
        if(jump[x][y][i]!=-1)
        {
            j=i;
            break;
        }
    }
//    cout<<j<<endl;

    while(j){
        //if(x==100&&y==100)break;
        //cout<<x<<" "<<y<<" "<<j<<endl;
        PAR p = par[x][y][j];
        int u = p.first;
        int v = p.second;
        //cout<<x<<" "<<y<<" "<<u<<" "<<v<<endl;
        if(x>u){
            ret+="S";
        }
        if(x<u){
            ret+="N";
        }
        if(y>v){
            ret+="E";
        }
        if(y<v)ret+="W";
        x=u,y=v,j--;
    }
    reverse(ret.begin(),ret.end());
    return ret;

}

int main()
{
	freopen("i3.txt","r",stdin);
	freopen("o3.txt","w",stdout);
	int kas,cas,x,y,z;
	PAR v = mp(-1,-1);

    rep(i,201){
        rep(j,201){
            rep(k,201)
            jump[i][j][k]=-1,
            par[i][j][k]=v;
        }

    }

	BFS(100,100);
	//cout<<jump[103][99][4]<<endl;
	//while(cin>>x>>y>>z)cout<<par[x][y][z].first<<" "<<par[x][y][z].second<<endl;
	cin>>kas;
	rep(cas,kas){
	    int x,y;
	    cin>>y>>x;
	    x+=100;
	    x=200-x;
	    y+=100;

	    string str = printPath(x,y);
	    cout<<"Case #"<<cas+1<<": "<<str<<endl;
	}

return 0;
}
