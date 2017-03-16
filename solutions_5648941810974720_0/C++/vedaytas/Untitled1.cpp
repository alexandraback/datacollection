#include<bits/stdc++.h>

using namespace std;
int x[26];
int main(){
	
	int t,i;
	string s;
	cin>>t;
	for(i=1;i<=t;i++){
		map<int,int> m;
		map<int,int> :: iterator it;
		for(int j=0;j<26;j++)
			x[j]=0;
		cin>>s;
		string ans,temp;
		int l=s.length();
		for(int j=0;j<l;j++){
			x[s[j]-65]++;
		}
		int xx;
		xx=x[22];
		x[14]-=xx;
		x[22]-=xx;
		x[19]-=xx;
		m[2]=xx;
		//cout<<m[2]<<endl;
		ans="";
		xx=x[6];
		x[4]-=xx;
		x[8]-=xx;
		x[6]-=xx;
		x[7]-=xx;
		x[19]-=xx;
		m[8]=xx;
		
		xx=x[25];
		x[25]-=xx;
		x[4]-=xx;
		x[17]-=xx;
		x[14]-=xx;
		m[0]=xx;
		
		xx=x[23];
		x[18]-=xx;
		x[23]-=xx;
		x[8]-=xx;
		m[6]=xx;
		
		xx=x[20];
		x[5]-=xx;
		x[14]-=xx;
		x[20]-=xx;
		x[17]-=xx;
		m[4]=xx;
		
		xx=x[5];
		x[5]-=xx;
		x[8]-=xx;
		x[21]-=xx;
		x[4]-=xx;
		m[5]=xx;
		
		xx=x[21];
		x[18]-=xx;
		x[13]-=xx;
		x[21]-=xx;
		x[4]-=xx*2;
		m[7]=xx;
		
		xx=x[8];
		x[8]-=xx;
		x[4]-=xx;
		x[13]-=xx*2;
		m[9]=xx;
		
		xx=x[19];
		x[7]-=xx;
		x[17]-=xx;
		x[4]-=xx*2;
		m[3]=xx;
		
		xx=x[14];
		x[14]-=xx;
		x[13]-=xx;
		x[4]-=xx;
		m[1]=xx;
		
		
		for(int j=0;j<10;j++){
			if(m[j]){
				for(int k=0;k<m[j];k++){
					ans+=char(j+48);
				}
			}
		}
		cout<<"Case #"<<i<<": "<<ans<<endl;
	}
	
	return 0;
}
