#include<cstdio>
#include<cstring>
#include<algorithm>
#include<string>
#include<cstdlib>
#include<iostream>
using namespace std;
int main(){
	//freopen("C:/Users/lucio_yang/Downloads/A-large.in","r",stdin);
	//freopen("F:/A-large3.out", "w", stdout);
	//freopen("F:/B-large.in","r",stdin);
	//freopen("F:/B-lagre.out","w",stdout);
	int n;
	cin >> n;
	int cas = 1;
	string str;
	while (cin>>str){
		printf("Case #%d: ",cas++);
		int len = str.length();
		int ans = 1;
		char pre = str[0];
		for (int i = 1; i < len; i++){
			if (str[i] == pre){
				continue;
			}
			else{
				pre = str[i];
				ans++;
			}
		}
		if (str[len - 1] == '+'){
			ans--;
		}
		printf("%d\n",ans);
	}
	return 0;
}