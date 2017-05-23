#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
int main(){
	freopen("test.in","r",stdin);
	freopen("test.out","w",stdout);
	int __;
	cin>>__;
	for(int _=1;_<=__;++_){
		printf("Case #%d: ",_);
		int n, count[26]={0},head[26]={0},tail[26]={0},mid[26]={0};
		string ins;
		cin>>n;
		bool flag = false;
		while(n--){
			cin>>ins;
			string pro="";
			pro += ins[0];
			for(int j=1;j<ins.length();++j) if(ins[j]!=ins[j-1]) pro+=ins[j];
			if(pro.length()==1) count[pro[0]-'a']++;
			else{
				for(int j=1;j<pro.length()-1;++j) mid[pro[j]-'a']++;
				head[ pro[0]-'a' ]++;
				tail[ pro[pro.length()-1]-'a' ]++;
				if(pro[0] == pro[pro.length()-1]) flag = true;
			}
		}

		//for(int i=0;i<26;++i) printf("%c : %d %d %d %d\n",(i+'a'),head[i],tail[i],mid[i],count[i]);
		for(int i=0;i<26;++i) if(head[i]>1 || tail[i]>1 || mid[i]>1 || (mid[i]>0 && (head[i]>0 || tail[i]>0 ||count[i]>0))) flag = true;
		if(flag) printf("0\n");
		else{
			long long res = 1, xx = 0;
			for(int i=0;i<26;++i)
				for(int j=count[i];j>1;--j){
					res*=j;
					res%=1000000007;
				}

			for(int i=0;i<26;++i)
				if(head[i]==0 && tail[i]==0 && count[i]>0) ++xx;
				else if(head[i]==0 && tail[i]==1) ++xx;
			//cout << xx << endl;
			for(int i=xx;i>1;--i){
					res*=i;
					res%=1000000007;
				}
			cout<<res<<endl;
		}
	}
	return 0;
}
