#include<iostream>
#include<queue>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<string>
#include<cstring>
#include<map>
#include<numeric>
#include<sstream>
#include<cmath>
using namespace std;
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).end,(v).begin
#define pb push_back
#define f(i,x,y) for(int i=x;i<y;i++)
#define FOR(it,A) for(typeof A.begin() it = A.begin();it!=A.end();it++)
#define sqr(x) (x)*(x)
#define mp make_pair
#define clr(x,y) memset(x,y,sizeof x)
typedef pair<int,int> pii;
typedef long long ll;
typedef long double ld;
string cad;
int n;
int memo[55][55];

map<string,bool> mapa;


bool ver(int ind,string aux,int len){
	ind-=len;
	char c=aux[ind];
	f(i,0,26)if(c!=('a'+i)){
		aux[ind]='a'+i;
		if(mapa.count(aux))return true;
	}
	return false;
}

bool ver2(int ind1,int ind2,string aux,int len){
	ind1-=len;ind2-=len;
	char c1=aux[ind1],c2=aux[ind2];
	f(i,0,26)f(j,0,26)if((c1!=('a'+i)) && (c2!=('a'+j))){
		aux[ind1]='a'+i;
		aux[ind2]='a'+j;
		//cout<<aux<<endl;
		if(mapa.count(aux)){
			//cout<<aux<<endl;
			return true;
		}
	}
	return false;
}

int go(int pos,int ult){
	//cout<<pos<<" "<<ult<<endl;
	if(pos>n)return 0;
	if(memo[pos][ult]!=-1)return memo[pos][ult];
	int res=10000000;
	string aux="";
	f(log,0,10){
		if(pos+log >n) break;
		aux+=cad[pos+log-1];
		
		//sin error
		//if(aux=="jobs")cout<<"cc "<<pos<<" "<<ult<<endl;
	//	cout<<aux<<endl;
		if(mapa.count(aux)) res=min(res,go(pos+log+1,ult));
		
		//un error
		int ini,fin=pos+log;
		if(ult==0) ini=pos;
		else ini=max(ult+5,pos);
			f(i,ini,fin+1)
				if(ver(i,aux,pos)){// ver con un error
				//	cout<<aux<<endl;
					res=min(res,1+go(pos+log+1,i));
				}

		//dos errores
		 f(i,ini,fin+1)f(j,i+5,fin+1)
		 	if(ver2(i,j,aux,pos)){
				//cout<<aux<<" "<<i<<" "<<j<<endl; 
				res=min(res,2+go(pos+log+1,j));
			}
		 
	}
	return memo[pos][ult]=res;
}
int main(){
	//freopen("dic.txt", "r", stdin);
	
	//fclose (stdin);
	//freopen("inB","r",stdin);
	int todos=521196;
	while(todos--){
		cin>>cad;
		mapa[cad]=true;
	}
	
	int cases;
	//cout<<"vamos"<<endl;
	if(mapa.count("codejam"))cout<<"adad"<<endl;
	cin>>cases;
	//cout<<cases<<endl;
	f(t,1,cases+1){
	
		cin>>cad;
		//cout<<"ver "<<cad<<endl;
		n=cad.size();
		clr(memo,-1);	
		int res=go(1,0);
		cout<<"Case #"<<t<<": "<<res<<endl;
	}
	return 0;

}
