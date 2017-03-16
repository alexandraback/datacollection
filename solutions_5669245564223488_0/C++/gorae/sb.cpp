#include <cstdio>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<string>v;



int main(){
freopen("1.in","r",stdin);
freopen("1.out","w",stdout);

	int T;
	scanf("%d",&T);
	for(int TT=1;TT<=T;TT++){
		v.clear();
		int n;
		scanf("%d",&n);
	
		string s;
		int to=0;
		for(int i=0;i<n;i++){
			cin>>s;
			int le=s.length();
			for(int j=le-1;j>0;j--){
				if(s[j]==s[j-1]) {
					s.erase(s.begin()+j);
				}
			}
			v.push_back(s);
		}

		vector<int> vv;
		for(int i=0;i<n;i++) vv.push_back(i);
		int ch[30];
		int ans=0;
		do{
			for(int i=0;i<30;i++) ch[i]=0;

			s="";
			for(int i=0;i<n;i++) {
				s+=v[vv[i]];
			}

			for(int i=s.length()-1;i>0;i--){
				if(s[i]==s[i-1]) s.erase(s.begin()+i);
			}
			int f=1;
			for(int i=s.length()-1;i>=0;i--){
				if(ch[s[i]-'a']) {f=0;break;}
				ch[s[i]-'a']=1;
			}
			if(f) ans++;
		}while(next_permutation(vv.begin(),vv.end()));




		printf("Case #%d: ",TT);
		printf("%d\n",ans);
	}

}
