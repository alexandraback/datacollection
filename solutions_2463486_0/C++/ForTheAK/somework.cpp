#include<iostream>
#include<cstdio>
#include<string>
#include<sstream>
#include<cmath>
using namespace std;
long long parad[100000];
long long pos=0;
bool is_parad(long long num)
{
	stringstream ss;
	ss<<num;
	string s=ss.str();
	for(long long i=0;i<(int)s.length()/2;i++){
		if(s[i]!=s[(long long)s.length()-i-1])
			return false;
	}
	return true;
}
long long find_pos(long long x,int wh)
{
	long long l=0,h=pos-1;
	while(l<h-1){
		long long mid=(l+h)/2;
		if(parad[mid]>x){
			h=mid;
		}
		else if(parad[mid]<x){
			l=mid;
		}
		else
			return mid;
	}
	if(wh==1){
		if(parad[l]<x)
			return h;
		else
			return l;
	}
	else{
		if(parad[h]==x)
			return h;
		else
			return l;
	}
}
long long get_sqrt(long long x,int wh)
{
	long long temp=(long long)sqrt((double)x);
	if(temp*temp==x)
		return temp;
	if(wh==1)
		return temp+1;
	return temp;
}
int main()
{
	FILE *fp,*fp_;
	freopen_s(&fp,"data.in","r",stdin);
	freopen_s(&fp_,"data.out","w",stdout);
	for(long long i=1;i<=10000000;i++){
		if(is_parad(i)){
			parad[pos++]=i;
		}
	}
	int T;
	long long a,b;
	cin>>T;
	for(int k=0;k<T;k++){
		cin>>a>>b;
		int ans=0;
		long long a_sqrt=get_sqrt(a,1);
		long long b_sqrt=get_sqrt(b,2);
		long long pos_a=find_pos(a_sqrt,1);
		long long pos_b=find_pos(b_sqrt,2);
		for(long long cnt=pos_a;cnt<=pos_b;cnt++){
			if(is_parad(parad[cnt]*parad[cnt]))
				ans++;
		}
		cout<<"Case #"<<k+1<<": "<<ans<<endl;
	}
	fcloseall();
	return 0;
}