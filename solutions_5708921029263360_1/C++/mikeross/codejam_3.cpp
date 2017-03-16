#include <bits/stdc++.h>

using namespace std;

int main(){
	int t,n,z=1;
	
	cin>>t;
	while(t--){
		int j,p,s,k,J,P,S,i,ans=0;
		cin>>J>>P>>S>>k;
		map<pair<int,int>,int>jp;
		map<pair<int,int>,int>js;
		map<pair<int,int>,int>ps;
		int arr[1000][3];
		pair<int,int>y1,y2,y3;
		int x1,x2,x3;
		int cnt=0,cnt1=-1;
		for(j=1;j<=J;++j){
			cnt=-1;
			cnt1++;
			for(p=1;p<=P;++p){
					cnt++;
				for(s=1;s<=S;++s){
					//cout<<j<<p<<endl;
					y1 = make_pair(j,(p+cnt1)%P+1);
					if(jp.find(y1) == jp.end())
						jp.insert(make_pair(y1,1));
					x1 = jp.at(y1);
					if(x1>k)
					 	continue;
					 //jp.at(y1)=x1+1;
					  y2 = make_pair(j,(s+cnt)%S+1);
					  if(js.find(y2) == js.end())
						js.insert(make_pair(y2,1));
					 x2 = js.at(y2);
					 if(x2>k)
					 	continue;
					// js.at(y2)=x2+1;
					  y3 = make_pair((p+cnt1)%P+1,(s+cnt)%S+1);
					  if(ps.find(y3) == ps.end())
						ps.insert(make_pair(y3,1));
					 x3 = ps.at(y3);

					 if(x3>k)
					 	continue;
					 ps.at(y3)=x3+1;
					 jp.at(y1)=x1+1;
					 js.at(y2)=x2+1;
					 arr[ans][0]=j;
					 arr[ans][1]=(p+cnt1)%P+1;
					 arr[ans][2]=(s+cnt)%S+1;
					 ans++;
				}
			}
		}

		cout<<"Case #"<<z++<<": "<<ans<<endl;
		for(i=0;i<ans;++i)
			cout<<arr[i][0]<<" "<<arr[i][1]<<" "<<arr[i][2]<<endl;
	}
	return 0;
}