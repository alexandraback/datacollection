#include<iostream>
#include<algorithm>
#include<string>

using namespace std;

string s[105];
long long cnt[105];

char change(char c){
	return c=='+'?'-':'+'; 
}

void inverse(int i,int pos){
	transform(s[i].begin(), s[i].begin()+pos, s[i].begin(), change);
	reverse(s[i].begin(), s[i].begin()+pos);
	cnt[i]++;
}

int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>s[i];
		while(true){
			int firstMinus = s[i].find('-');
			int lastMinus = s[i].rfind('-');
			if(firstMinus==string::npos){
				//cout<<s[i]<<endl;
				break; 
			}else{
				if(firstMinus!=0){
					//s[i].replace(s[i].begin(), s[i].begin()+firstMinus-1,firstMinus-1,'-');
					inverse(i,firstMinus);
				}
				inverse(i,lastMinus+1);
			}
		}
		cout<<"Case #"<<i<<": "<<cnt[i]<<endl;
	} 
	return 0;
}

