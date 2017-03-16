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


#define lld long long

vector<lld> store[2];
string s[2];


void populate(int i,int flag,lld num){
	
	if(i>=s[flag].size()){
		store[flag].push_back(num);
		return;
	}
	
	if(s[flag][i]=='?'){
		
		for(int j = 0;j<10;j++)
		{
			num = num * 10ll + j;
			populate(i+1,flag,num);
			num/=10ll;
		}
	}
	else{
		
		num = num * 10ll + (s[flag][i]-'0');
		populate(i+1,flag,num);
		num/=10ll;
	}
}

int digits(lld num){
	
	if(num==0)
		return 1;
	
	int sum = 0;
	
	while(num){
		sum++;
		num/=10;
	}
	return sum;
}

int main()
{
	freopen("input.in","r",stdin);
	//freopen("output.txt","w",stdout);
	
	cin.sync_with_stdio(0);
	cout.sync_with_stdio(0);
	

	int t;
	cin>>t;
	
	for(int tst=1;tst<=t;tst++){
		
		cin>>s[0]>>s[1];
		
		store[0].clear();
		store[1].clear();
		
		lld num = 0;
		populate(0,0,0);
		populate(0,1,0);
		
		sort(store[0].begin(),store[0].end());
		
		sort(store[1].begin(),store[1].end());
		
		int i = 0;
		int j = 0;
		
		lld diff = LLONG_MAX;
		lld c_s = LLONG_MAX;
		lld j_s = LLONG_MAX;
		
		while(i<store[0].size() && j<store[1].size()){
			
			if(store[0][i]<store[1][j]){
				
					lld cdiff = store[1][j] - store[0][i];
					
					if(cdiff<diff){
						diff = cdiff;
						c_s  = store[0][i];
						j_s =  store[1][j];
					}	
					else if(cdiff==diff){
						
						if(c_s>store[0][i]){
							c_s = store[0][i];
							j_s = store[1][j];
						}
						else if(c_s==store[0][i]){
							j_s = min(j_s,store[1][j]);
						}
					}
					i++;
			}
			else{
				
					lld cdiff = store[0][i] - store[1][j];
					
					if(cdiff<diff){
						diff = cdiff;
						c_s  = store[0][i];
						j_s =  store[1][j];
					}	
					else if(cdiff==diff){
						
						if(c_s>store[0][i]){
							c_s = store[0][i];
							j_s = store[1][j];
						}
						else if(c_s==store[0][i]){
							j_s = min(j_s,store[1][j]);
						}
					}
					j++;
			}
					
		}
		
		cout<<"Case #"<<tst<<": ";
		
		int len1 = s[0].size() - digits(c_s);
		
		while(len1){
			cout<<"0";
			len1--;
		}
		
		cout<<c_s<<" ";
		
		len1 = s[1].size() -  digits(j_s);
		
		while(len1){
			cout<<"0";
			len1--;
		}
		
		cout<<j_s<<endl;
		
	}
	
	return 0;
}

