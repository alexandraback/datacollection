#include<iostream>
#include<sstream>
#include<cstring>
#include<algorithm>
using namespace std;
	int T,A,B,res;
int isrecycle(int x){
	int ans=0;
	stringstream ss;
	string s;
	ss<<x;
	ss>>s;
	s=s+s;
	int temp=0;
	for(int i=1;i<(s.size()/2);i++){
		string t;
		for(int j=i;j<(s.size()/2)+i;j++)
			t+=s[j];
		ss.clear();
		ss<<t;
		ss>>temp;
		if(temp>x && temp <=B){
			//cout<<x<<endl;
			ans+=1;
		}
	}
	return ans;
}
int main(){
	freopen("test_input.txt","r",stdin);
	freopen("C-out.txt","w",stdout);
	scanf("%d",&T);
	for(int _T=1;_T<=T;_T++){
		res=0;
		scanf("%d%d",&A,&B);
		for(int i=A;i<=B;i++){
			  res+=isrecycle(i);
		}
		printf("Case #%d: %d\n",_T,res);
	}
	return 0;
}