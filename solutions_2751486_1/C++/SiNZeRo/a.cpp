#include <iostream>
#include <vector>
using namespace std;
int n,m;

long long shana(){
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
			//	cout<<lp<<" "<<i-lp<<endl;
				sz.push_back(i-lp);
				begin.push_back(lp);
			}
			lp=i+1;
		}
	}
	if (sz.size()==-1){
		int tmp=0;
		for (int j=0;j<sz[0];j++){
			if (sz[0]-(j+l)+1<0)
				break;
			tmp+=sz[0]-(j+l)+1;
			
		}
		return tmp;
	}
	int lastok=-1;
	int lastend=0;
	for (int i=0;i<sz.size();i++){
	
		for (int j=0;j<min(sz[i],l-1);j++){
			//cout<<"t"<<lastok+1<<endl;
			ans+=lastok+1;
		}
		if (i>0)
		for (int j=sz[i-1]+begin[i-1];j<begin[i];j++){
			ans+=lastok+1;
		}
		if (sz[i]>=l){
			for (int j=l;j<=sz[i];j++){
			//	cout<<begin[i]+j-l+1<<endl;
				ans+=begin[i]+j-l+1;
			}
			lastok=begin[i]+sz[i]-l;
			//cout<<"new ok"<<begin[i]+sz[i]-l<<endl;
		}
	}
	if (sz.size()==0)
	return 0;
		for (int j=sz[sz.size()-1]+begin[sz.size()-1];j<end;j++){
			ans+=lastok+1;
		}
	return ans;
}

int main(){
	int cn;
	scanf("%d",&cn);
	for (int cs=1;cs<=cn;cs++){
		cout<<"Case #"<<cs<<": "<<shana()<<endl;
	}
	return 0;
}
