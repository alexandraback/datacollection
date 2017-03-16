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
#define MAX 55

int n,k;
int graph[MAX][MAX];


int main()
{
	
	freopen("input.in","r",stdin);
	freopen("output.txt","w",stdout);
	
	cin.sync_with_stdio(0);
	cout.sync_with_stdio(0);


	int t;
	cin>>t;
	
	
	for(int tst=1;tst<=t;tst++){
		
		cin>>n>>k;
		
		memset(graph,0,sizeof(graph));
		
		
		for(int i = n-2;i>=0;i--){
			
			for(int l = i+1;l<n-1;l++){
				
				for(int j = 0;j<n;j++){
					
					if(graph[l][j])
						graph[i][l] = 1;
				}
			}
			if(k>0)
			{
				graph[i][n-1] = 1;
				k--;
			}
		}
		
		if(k==0){
			
			cout<<"Case #"<<tst<<": POSSIBLE\n";
			
			for(int i = 0;i<n;i++){
				for(int j = 0;j<n;j++)
				cout<<graph[i][j];
				cout<<endl;
			}
		}
		else{
			cout<<"Case #"<<tst<<": IMPOSSIBLE\n";
		}
		
	}
	
	
	
	
	return 0;
}

