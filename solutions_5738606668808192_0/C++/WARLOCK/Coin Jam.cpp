#include <bits/stdc++.h>

using namespace std;

long long power(long long a,long long b){
	long long ret = 1;
	while(b > 0){
		if(b%2==1)	ret = (ret*a);
		a *= a;
		b /= 2;
	}
	return ret;
}
int cnt = 0;
long long conv(string &str,int b){
	long long r = 0;
	for(int i=str.size()-1;i>=0;i--)
		if(str[i] == '1')
			r += power(b,str.size()-1-i);
	for(long long i=2;i*i<=r;i++)
		if(r%i == 0)
			return i;
	return -1;
}
bool valid(string &str){
	vector<long long> p;
	for(int i=2;i<=10;i++){
		p.push_back(conv(str,i));
		if(p.back()==-1)
			return false;
	}
	cout<<str<<" ";
	for(int i=0;i<p.size();i++)
		cout<<p[i]<<" ";
	cout<<"\n";
	return true;
}
bool precompute(string &str,int l=1){
	if(l==14){
		if(valid(str)){
			cnt++;
			if(cnt == 50)
				return true;
			return false;
		}
		return false;
	}
	str[l] = '0';
	if(precompute(str,l+1))
		return true;
	str[l] = '1';
	if(precompute(str,l+1))
		return true;
	str[l] = '0';
	return false;
}
int main(){
	freopen("temp.txt","r",stdin);
	freopen("C.txt","w",stdout);
	string str = "1000000000000001";
	cout<<"Case #1:\n";
	precompute(str);
	return 0;
}