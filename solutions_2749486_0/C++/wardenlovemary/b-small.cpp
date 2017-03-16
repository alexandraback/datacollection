#include<iostream>
#include<map>
#include<string>
using namespace std;

#define ran 222

const int go[4][2]={0,1,1,0,0,-1,-1,0};

int T;
map<pair<int,int>,string> mp,nxt,ans;
map<pair<int,int>,string>::iterator it,t;

int main(){
	ans.clear();
	string dir_ch="NESW";
	mp[make_pair(0,0)]="";
	ans[make_pair(0,0)]="";
	for(int i=1;i<=500;i++){
		//cout<<i<<" "<<ans.size()<<endl;
		nxt.clear();
		for(it=mp.begin();it!=mp.end();it++){
			int x=(*it).first.first,y=(*it).first.second;
			for(int j=0;j<4;j++){
				int xx=x+go[j][0]*i,yy=y+go[j][1]*i;
				if(abs(xx)>ran||abs(yy)>ran)continue;
				
				pair<int,int>p=make_pair(xx,yy);
				string s=(*it).second+dir_ch[j];
				
				t=nxt.find(p);
				if(t==nxt.end())
					nxt[p]=s;
				
				if(abs(xx)<=100&&abs(yy)<=100&&ans.find(p)==ans.end())
					ans[p]=s;
			}
		}
		mp=nxt;
		if(ans.size()==(100*2+1)*(100*2+1)) break;
	}

	cin>>T;
	for(int _=1;_<=T;_++){
		int x,y;
		cin>>x>>y;
		it=ans.find(make_pair(x,y));
		cout<<"Case #"<<_<<": "<<(*it).second<<endl;
	}
	
	return 0;
}