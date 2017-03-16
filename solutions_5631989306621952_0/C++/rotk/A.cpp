#include <bits/stdc++.h>
#define MAXN 1000000
#define long long ll
using namespace std;
int th;

void openFile(){
	//th=0;
	switch(th){
		case 0:
			freopen("inp","r",stdin);
  			freopen("out","w",stdout);
  			break;
		case 1: 
			freopen("A-small-attempt0.in","r",stdin);
  			freopen("A-small-attempt0.ou","w",stdout);
  			break;
  		case 2:
  			freopen("A-large.in","r",stdin);
  			freopen("A-large.ou","w",stdout);
  			break;
	}
  	
}
void mainWork(){
	int test;
	string st;
	cin>>test;
	for(int qq=1;qq<=test;qq++){
		cout<<"Case #"<<qq<<": ";
		cin>>st;
		string res="";
		for(int i=0;i<st.length();i++){
			if(st[i]>='A'&& st[i]<='Z'){
				if(i==0 || st[i]>=res[0]){
					res=st[i]+res;
				}else{
					res=res+st[i];
				}
			}
		}
		cout<<res<<endl;
		
	}
}
int main(){
	cin>>th;
	openFile();
	mainWork();
	return 0;
}
