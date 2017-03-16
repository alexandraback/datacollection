#include <bits/stdc++.h>

using namespace std;

#define INTMAX 0x7FFFFFFF
#define INTMIN -0x80000000
#define LONGMAX 0x7FFFFFFFFFFFFFFF
#define LONGMIN -0x8000000000000000

int main(){
	ios_base::sync_with_stdio(false);
	int T;
	cin>>T;
	for(int case_nr=1; case_nr<=T; case_nr++){
		string c,j;
		cin>>c>>j;
		int n = c.length();
		long long md[n];
		md[n-1] = 0;
		for(int i=n-2; i>=0; i--){
			if(c[i+1]==j[i+1] && c[i+1]!='?'){
				md[i] = md[i+1];
			}
			else if(c[i+1]!='?' && j[i+1]!='?'){
				if(c[i+1]>j[i+1]){
					md[i] = 0;
					for(int k=i+1; k<n; k++){
						md[i] *=10;
						int dc = c[k] - '0';
						if(c[k]=='?')
							dc = 0;
						int dj = j[k] - '0';
						if(j[k]=='?')
							dj = 9;
						md[i] += dc-dj;
					}
				}
				else{
					md[i] = 0;
					for(int k=i+1; k<n; k++){
						md[i] *=10;
						int dc = c[k] - '0';
						if(c[k]=='?')
							dc = 9;
						int dj = j[k] - '0';
						if(j[k]=='?')
							dj = 0;
						md[i] += dj-dc;
					}
				}
			}
			else if(c[i+1]=='?' && j[i+1]=='?'){
				md[i] = md[i+1];
				
				long long m = 1;
				for(int k=i+2; k<n; k++){
					m *=10;
					int dc = c[k] - '0';
					if(c[k]=='?')
						dc = 0;
					int dj = j[k] - '0';
					if(j[k]=='?')
						dj = 9;
					m += dc-dj;
				}
				md[i] = min(md[i],m);
				
				m = 1;
				for(int k=i+2; k<n; k++){
					m *=10;
					int dc = c[k] - '0';
					if(c[k]=='?')
						dc = 9;
					int dj = j[k] - '0';
					if(j[k]=='?')
						dj = 0;
					m += dj-dc;
				}
				md[i] = min(md[i],m);
			}
			//exactly one question mark
			else{
				md[i] = md[i+1];
				
				if(c[i+1]=='?'&&j[i+1]<'9'){
					//c[i+1] = j[i+1] + 1;
					long long m = 1;
					for(int k=i+2; k<n; k++){
						m *=10;
						int dc = c[k] - '0';
						if(c[k]=='?')
							dc = 0;
						int dj = j[k] - '0';
						if(j[k]=='?')
							dj = 9;
						m += dc-dj;
					}
					md[i] = min(md[i],m);
				}
				if(c[i+1]=='?'&&j[i+1]>'0'){
					//c[i+1] = j[i+1] - 1;
					long long m = 1;
					for(int k=i+2; k<n; k++){
						m *=10;
						int dc = c[k] - '0';
						if(c[k]=='?')
							dc = 9;
						int dj = j[k] - '0';
						if(j[k]=='?')
							dj = 0;
						m += dj-dc;
					}
					md[i] = min(md[i],m);
				}
				
				if(j[i+1]=='?'&&c[i+1]<'9'){
					//j[i+1] = c[i+1] + 1;
					long long m = 1;
					for(int k=i+2; k<n; k++){
						m *=10;
						int dc = c[k] - '0';
						if(c[k]=='?')
							dc = 9;
						int dj = j[k] - '0';
						if(j[k]=='?')
							dj = 0;
						m += dj-dc;
					}
					md[i] = min(md[i],m);
				}
				if(j[i+1]=='?'&&c[i+1]>'0'){
					//j[i+1] = c[i+1] - 1;
					long long m = 1;
					for(int k=i+2; k<n; k++){
						m *=10;
						int dc = c[k] - '0';
						if(c[k]=='?')
							dc = 0;
						int dj = j[k] - '0';
						if(j[k]=='?')
							dj = 9;
						m += dc-dj;
					}
					md[i] = min(md[i],m);
				}
			}
		}
		/*
		for(int i=0; i<n; i++)
			cout<<md[i]<<" ";
		cout<<endl;
		*/
		for(int i=0; i<n; i++){
			if(c[i]=='?'&&j[i]=='?'){
				c[i] = '0';
				j[i] = '0';
				long long score = md[i];
				//c[i]=0, j[i]=1
				long long m = 1;
				for(int k=i+1; k<n; k++){
					m *=10;
					int dc = c[k] - '0';
					if(c[k]=='?')
						dc = 9;
					int dj = j[k] - '0';
					if(j[k]=='?')
						dj = 0;
					m += dj-dc;
				}
				if(m<score){
					c[i] = '0';
					j[i] = '1';
					score = m;
				}
				//c[i]=1, j[i]=0
				m = 1;
				for(int k=i+1; k<n; k++){
					m *=10;
					int dc = c[k] - '0';
					if(c[k]=='?')
						dc = 0;
					int dj = j[k] - '0';
					if(j[k]=='?')
						dj = 9;
					m += dc-dj;
				}
				if(m<score){
					c[i] = '1';
					j[i] = '0';
				}
			}
			else if(c[i]!='?'&&j[i]=='?'){
				long long score = LONGMAX;
				if(c[i]>'0'){
					j[i] = c[i]-1;
					score = 1;
					for(int k=i+1; k<n; k++){
						score *=10;
						int dc = c[k] - '0';
						if(c[k]=='?')
							dc = 0;
						int dj = j[k] - '0';
						if(j[k]=='?')
							dj = 9;
						score += dc-dj;
					}
				}
				if(md[i]<score){
					j[i] = c[i];
					score = md[i];
				}
				//j[i] = c[i]+1;
				if(c[i]<'9'){
					long long m = 1;
					for(int k=i+1; k<n; k++){
						m *=10;
						int dc = c[k] - '0';
						if(c[k]=='?')
							dc = 9;
						int dj = j[k] - '0';
						if(j[k]=='?')
							dj = 0;
						m += dj-dc;
					}
					if(m<score){
						j[i] = c[i]+1;
					}
				}
			}
			else if(c[i]=='?'&&j[i]!='?'){
				long long score = LONGMAX;
				if(j[i]>'0'){
					c[i] = j[i]-1;
					score = 1;
					for(int k=i+1; k<n; k++){
						score *=10;
						int dc = c[k] - '0';
						if(c[k]=='?')
							dc = 9;
						int dj = j[k] - '0';
						if(j[k]=='?')
							dj = 0;
						score += dj-dc;
					}
				}
				if(md[i]<score){
					c[i] = j[i];
					score = md[i];
				}
				if(j[i]<'9'){
					//c[i] = j[i]+1;
					long long m = 1;
					for(int k=i+1; k<n; k++){
						m *=10;
						int dc = c[k] - '0';
						if(c[k]=='?')
							dc = 0;
						int dj = j[k] - '0';
						if(j[k]=='?')
							dj = 9;
						m += dc-dj;
					}
					if(m<score){
						c[i] = j[i]+1;
					}
				}
			}
			
			if(c[i]!='?'&&j[i]!='?'&&c[i]>j[i]){
				for(int k=i+1; k<n; k++){
					if(c[k]=='?')
						c[k] = '0';
					if(j[k]=='?')
						j[k] = '9';
				}
				break;
			}
			if(c[i]!='?'&&j[i]!='?'&&c[i]<j[i]){
				for(int k=i+1; k<n; k++){
					if(c[k]=='?')
						c[k] = '9';
					if(j[k]=='?')
						j[k] = '0';
				}
				break;
			}
		}
		
		cout<<"Case #"<<case_nr<<": ";
		cout<<c<<" "<<j;
		cout<<"\n";
	}
	
}