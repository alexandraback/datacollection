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
#define MAX 1005

int n;
struct node{
	
	string first;
	string second;
	
	int visited;
	node(){
		visited = 0;
	}
}a[MAX];



map<string,int> first,second,f,s;

int main()
{
	freopen("input.in","r",stdin);
	freopen("output.txt","w",stdout);
	
	cin.sync_with_stdio(0);
	cout.sync_with_stdio(0);

	int t;
	cin>>t;
	
	for(int tst=1;tst<=t;tst++){
		
		cin>>n;
		for(int i = 0;i<n;i++)
			cin>>a[i].first>>a[i].second;
		
		
		for(int i = 0;i<=n;i++)
			a[i].visited = 0;
			
		first.clear();
		second.clear();
		
		for(int i = 0;i<n;i++){
			first[a[i].first]++;
			second[a[i].second]++;
		}
		
		f.clear();
		s.clear();
		
		int count = 0;
		int check = 0;
		
		while(check<n){
			
			int flag = 0;
			for(int i = 0;i<n;i++){
				
				if(a[i].visited)continue;
				
				if(first[a[i].first]==1 || second[a[i].second]==1)
				{
					a[i].visited = 1;
					flag = 1;
					check++;
					f[a[i].first]++;
					s[a[i].second]++;
				}
			}
			
			if(flag==0){
				
				for(int i = 0;i<n;i++){
					
					if(a[i].visited)continue;
					
					if(f[a[i].first]!=0 && s[a[i].second]!=0){
						check++;
						count++;
						flag = 1;
						a[i].visited = 1;
						f[a[i].first]++;
						s[a[i].second]++;
					}
				}
			}
			
			if(flag==0){
				
				lld profit = -1;
				int idx = -1;
				
				for(int i = 0;i<n;i++){
					
					if(a[i].visited)continue;
					
					lld cost = (first[a[i].first] - f[a[i].first]) * (second[a[i].second]-s[a[i].second]);
					
					if(cost>profit){
						idx= i ;
						profit = cost;
					}
				}
				
				a[idx].visited = 1;
				f[a[idx].first]++;
				s[a[idx].second]++;
				check++;
				flag = 1;
			}
		}
		
		cout<<"Case #"<<tst<<": "<<count<<endl;
		
	}
	
	return 0;
}

