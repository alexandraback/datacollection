#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll num(string s){
	ll ret=0;int i;
	for(i=0;i<s.size();++i){
		ret = ret*10+ s[i]-'0';
	}
	return ret;
}
int n,m;
string u,v,r1,r2;
ll diff= 4e18;
void dfs(int x,int ind,string a,string b){
	if(ind==n){
		if(abs(num(a)-num(b))<=diff){
			ll temp = abs(num(a)-num(b));
			if(diff==temp){
				if(a<r1 || ( a==r1 && b<r2))
					r1=a,r2=b;
			}
			else{
				r1= a,r2= b;
			}
			diff= temp;		}
		return;
	}
	if(x!=0){
		if(x==1){
			if(u[ind]=='?')a+='0';
			else a+=u[ind];
			if(v[ind]=='?')b+='9';
			else
				b+=v[ind];
		}
		else{
			if(u[ind]=='?')a+='9';
			else
				a+=u[ind];
			if(v[ind]=='?')b+='0';
			else
				b+=v[ind];
		}
		dfs(x,ind+1,a,b);
	}
	if(x==0){
		if(u[ind]!='?' && v[ind]!='?'){
			if(u[ind]<v[ind])
				dfs(2,ind+1,a+u[ind],b+v[ind]);
			else if(u[ind]>v[ind])
				dfs(1,ind+1,a+u[ind],b+v[ind]);
			else
				dfs(0,ind+1,a+u[ind],b+v[ind]);
		}
		else{
			if(u[ind]=='?' && v[ind]=='?'){
				char i,j;
				for(i='0';i<'2';++i)
					for(j='0';j<'2';++j){
						if(i<j)dfs(2,ind+1,a+i,b+j);
						else if(i>j)dfs(1,ind+1,a+i,b+j);
						else dfs(0,ind+1,a+i,b+j);
					}
			}
			else{			
				char stand,i,j;
				if(u[ind]=='?'){
					stand = v[ind];
					for(i=max('0',char(stand-1));i<=min('9',char(stand+1));++i){
						if(i==stand)
							dfs(0,ind+1,a+i,b+stand);
						else if(i>stand)
							dfs(1,ind+1,a+i,b+stand);
						else
							dfs(2,ind+1,a+i,b+stand);
					}
				}
				else if (v[ind]=='?'){
					stand = u[ind];
					for(i= max('0',char(stand-1));i<=min('9',char(stand+1));++i){
						if(i==stand)
							dfs(0,ind+1,a+stand,b+i);
						else if(i>stand)
							dfs(1,ind+1,a+stand,b+i);
						else
							dfs(2,ind+1,a+i,b+stand);
					}
				}
				else{					a+=u[ind],b+=v[ind];
					if(u[ind]<v[ind])
						dfs(2,ind+1,a,b);
					else if(u[ind]>v[ind])
						dfs(1,ind+1,a,b);
					else
						dfs(0,ind+1,a,b);
				}
			}
		}
	}
}
int main(){
	int T,i,j,test;
	cin>>T;
	string a,b;
	for(test=1;test<=T;++test){
		cin>>a>>b;
		if(a.size()<b.size())
			swap(a,b);
		n= a.size(),b.size();
		u = a,v= b;
		diff= 4e18;
		dfs(0,0,"","");
		cout<<"Case #"<<test<<": ";
		cout<<r1<<" "<<r2<<endl;
	}
}
