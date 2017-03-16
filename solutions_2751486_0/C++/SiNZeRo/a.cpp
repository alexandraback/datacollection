#include <iostream>
#include <vector>
using namespace std;
int n,m;

int shana(){
	string s;
	int l;
	cin>>s>>l;
	int lp=0;
	long long ans=0;
	int end=s.length();
	vector<int> sz;
	vector<int> begin;
	for (int i=0 ;i<=end; i++){
		if (i==end || s[i]=='a' || s[i]=='e' ||s[i]=='i' ||s[i]=='o' ||s[i]=='u')
		{
			if (i!=lp){
				sz.push_back(i-lp);
				begin.push_back(lp);
			}
			lp=i+1;
		}
	}
	int lastok=0;
	if (sz.size()==1){
		int tmp=0;
		for (int j=0;j<sz[0];j++){
			if (sz[0]-(j+l)+1<0)
				break;
			tmp+=sz[0]-(j+l)+1;
			
		}
		return tmp;
	}
	for (int i=0;i<sz.size();i++){
		if (sz[i]>=l){
			ans+=(begin[i]+1-lastok)*(end-(begin[i]+l)+1);
			lastok=begin[i]+1;
		}
	}
	return ans;
}

int shana2(){
	string s;
	int l;
	cin>>s>>l;
	int lp=0;
	long long ans=0;
	int end=s.length();
	vector<int> b(end,0);
	for (int i=0 ;i<end; i++){
		if (i==end || s[i]=='a' || s[i]=='e' ||s[i]=='i' ||s[i]=='o' ||s[i]=='u')
		{
			b[i]=1;
		}
	}
	for (int i=0;i<end;i++)
	{
		for (int j=i;j<=end;j++){
			int c=0;
			for (int s=i;s<j;s++)
			{
				
				if (b[s]==1){
					c=0;
				}
				else 
					c++;
				if (c>=l){
					ans++;
					break;
				}
			}
			
		}
	}
	return ans;
}
int main(){
	int cn;
	scanf("%d",&cn);
	for (int cs=1;cs<=cn;cs++){
		printf("Case #%d: %lld\n",cs,shana2());
	}
	return 0;
}
