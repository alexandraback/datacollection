#include<bits/stdc++.h>

// Author : Archit Jain :) Delhi Technological University
//#pragma comment (linker, "/STACK:256000000")

#define mp(x,y) make_pair(x,y)
#define trace1(x)                cerr << #x << ": " << x << endl;
#define trace2(x, y)             cerr << #x << ": " << x << " | " << #y << ": " << y << endl;
#define trace3(x, y, z)          cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl;
#define pi   3.14159265358979323846264338327950288

using namespace std;
typedef long long lld;
typedef pair<int,int> p;
//snippets
template<class T>  T gcd(T a,T b){if(b==0)return a;else return gcd(b,a%b);}
template<class T>T power(T a,T b){T result=1;while(b>0){if(b&1)	result = result * a;a = a*a;b>>=1;}return result;}
template<class T>T powerMod(T a,T b,T c){T result =1%c;while(b>0){if(b&1)result = (result * a)%c;a = (a*a)%c;b>>=1;}return result;}
template<class T>bool prime(T a){if(a==2)return true;else if(a%2==0)return false;for(int i=3;i*i<=a;i+=2){if(a%i==0)return false;}return true;}


#define MAX 2005
int cnt[30];

int main()
{
	freopen("input.in","r",stdin);
	//freopen("output.txt","w",stdout);
	
	cin.sync_with_stdio(0);
	cout.sync_with_stdio(0);
	
	string s;
	
	int t;
	cin>>t;
	
	for(int tst=1;tst<=t;tst++){
		
		cin>>s;
		
		int visited[10] = {0};
		
		memset(cnt,0,sizeof(cnt));
		
		for(int i = 0;i<s.size();i++)
			cnt[s[i]-'A']++;
		
		for(int i = 0;i<s.size();i++){
			
			if(s[i]=='Z' && cnt['Z'-'A']>0){
				
				cnt['Z'-'A']--;
				cnt['E'-'A']--;
				cnt['R'-'A']--;
				cnt['O'-'A']--;
				
				visited[0]++;
			}
		}
			
		for(int i = 0;i<s.size();i++){
			
			if(s[i]=='W' && cnt['W'-'A']>0){
				
				cnt['T'-'A']--;
				cnt['W'-'A']--;
				cnt['O'-'A']--;
				visited[2]++;
			}
		}
		
			
		for(int i = 0;i<s.size();i++){
			
			if(s[i]=='U'  && cnt['U'-'A']>0){
				
				cnt['F'-'A']--;
				cnt['O'-'A']--;
				cnt['U'-'A']--;
				cnt['R'-'A']--;
				
				visited[4]++;
			}
		}
		
			
		for(int i = 0;i<s.size();i++){
			
			if(s[i]=='X' && cnt['X'-'A']>0){
				
				cnt['S'-'A']--;
				cnt['I'-'A']--;
				cnt['X'-'A']--;
			
				visited[6]++;
			}
		}
		
			
		for(int i = 0;i<s.size();i++){
			
			if(s[i]=='G' &&  cnt['G'-'A']>0){
				
				cnt['E'-'A']--;
				cnt['I'-'A']--;
				cnt['G'-'A']--;
				cnt['H'-'A']--;
				cnt['T'-'A']--;
				
				visited[8]++;
			}
		}
		
			
		for(int i = 0;i<s.size();i++){
			
			if(s[i]=='H' && cnt['H'-'A']>0){
				
				cnt['T'-'A']--;
				cnt['H'-'A']--;
				cnt['R'-'A']--;
				cnt['E'-'A']--;
				cnt['E'-'A']--;
				visited[3]++;
			}
		}
		
				
		for(int i = 0;i<s.size();i++){
			
			if(s[i]=='O' && cnt['O'-'A']>0){
				
				cnt['O'-'A']--;
				cnt['N'-'A']--;
				cnt['E'-'A']--;
				visited[1]++;
			}
		}
		
		for(int i = 0;i<s.size();i++){
			
			if(s[i]=='F' && cnt['F'-'A']>0){
				
				cnt['F'-'A']--;
				cnt['I'-'A']--;
				cnt['V'-'A']--;
				cnt['E'-'A']--;
				visited[5]++;
			}
		}
		
			
		for(int i = 0;i<s.size();i++){
			
			if(s[i]=='S' && cnt['S'-'A']>0){
				
				cnt['S'-'A']--;
				cnt['E'-'A']--;
				cnt['V'-'A']--;
				cnt['E'-'A']--;
				cnt['N'-'A']--;
				visited[7]++;
			}
		}
		
		for(int i = 0;i<s.size();i++){
			
			if(s[i]=='N' && cnt['N'-'A']>0){
				
				cnt['N'-'A']--;
				cnt['I'-'A']--;
				cnt['N'-'A']--;
				cnt['E'-'A']--;
				visited[9]++;
			}
		}
		
				
		
	

		cout<<"Case #"<<tst<<": ";
		for(int i = 0;i<10;i++){
			
			for(int j = 0;j<visited[i];j++)
				cout<<i;
		}
		
		cout<<endl;
		
	}

	
	return 0;
}

