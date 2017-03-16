#include <bits/stdc++.h>
using namespace std;


#define ll long long 

//char str[1111];
string str;

int main(){
	freopen("A-large.in","r",stdin);
	freopen("A-large.out","w",stdout);
	int t;
	cin>>t;
	int cas = 0;
	while(t--){
		cas++;
	//	scanf("%s",str);
		cin>>str;
		deque<char> ans;
		
		int len = str.size();
		
		for(int i=0;i<len;i++){
			if(i==0){
				ans.push_back(str[i]);
			}else{
				if(str[i]>=ans[0]){
					ans.push_front(str[i]);
				}else{
					ans.push_back(str[i]);
				}
			}
		}
		printf("Case #%d: ",cas);
		for(char ch:ans){
			cout<<ch;
		}
		cout<<endl;
	}
	return 0;
}
