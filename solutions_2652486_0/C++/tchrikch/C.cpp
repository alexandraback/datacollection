#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
#include<set>
#include<sstream>
#include<cmath>
#include<cstdio>
using namespace std;
#define REP(i,n) for(int i=0;i<n;++i)
#define REPD(i,n) for(int i=n;i>-1;--i)
#define FOR(i,j,k) for(int i=j;i<k;++i)
#define PB push_back
#define LL unsigned long long
#define MAX_S 101
#define MP make_pair

vector<string> data;
map<string,vector<int> > pData;

void get(string c,int m)
{
   if(c.size()==3) {data.PB(c);return;
   }	
   
   FOR(i,2,m+1)
   {
		string a = " ";
		a[0] = i +'0';
		get(c+a,m);
	}
}

void generate(int n,int m)
{
	get("",m);
	
	REP(i,data.size())
	{
		vector<int> tmp;
		int a = data[i][0]-'0';
		int b = data[i][1]-'0';
		int c = data[i][2]-'0';
		tmp.PB(1);
		tmp.PB(a);
		tmp.PB(b);
		tmp.PB(c);
		tmp.PB(a*b);tmp.PB(c*b);tmp.PB(a*c);
		tmp.PB(a*b*c);
		pData[data[i]] = tmp;
	}
	
//	REP(i,data.size()) {
//		cout<<data[i]<<endl;
//		REP(j,pData[data[i]].size()) cout<<pData[data[i]][j]<<" ";
//		cout<<endl;
//	}
}

int main(){
	
	
	 int ts=0; cin>>ts;
	 REP(ww,ts)
	 {
	    LL ret = 0;
		int r,n,m,k;
		cin>>r>>n>>m>>k;
		cout<<"Case #1:"<<endl;
		generate(n,m);
		
		REP(i,r)
		{
			vector<int> p(k,0);
			REP(j,k) cin>>p[j];
			
			REP(i,data.size())
			{
				vector<int> cmp = pData[data[i]];
				bool isOk = true;
				REP(j,p.size())
				{
					bool found = false;
					REP(k,cmp.size())
					{
						if(cmp[k]==p[j]) {found = true;break;
						}
					}
					if(!found)
					{
						isOk=false;break;}
				}
				
				if(isOk)
				{
					cout<<data[i]<<endl;
					break;
				}
			}
			
		}
		
	//	cout<<"Case #"<<(ww+1)<<": "<<ret<<endl;
	 }
	
	return 0;
}
