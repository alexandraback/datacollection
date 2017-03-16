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

//snippets
template<class T>  T gcd(T a,T b){if(b==0)return a;else return gcd(b,a%b);}
template<class T>T power(T a,T b){T result=1;while(b>0){if(b&1)	result = result * a;a = a*a;b>>=1;}return result;}
template<class T>T powerMod(T a,T b,T c){T result =1%c;while(b>0){if(b&1)result = (result * a)%c;a = (a*a)%c;b>>=1;}return result;}
template<class T>bool prime(T a){if(a==2)return true;else if(a%2==0)return false;for(int i=3;i*i<=a;i+=2){if(a%i==0)return false;}return true;}


set<pair<int,pair<int,int> > > hash;
vector<pair<int,pair<int,int> > > store;

map<pair<int,int>,int> visitedXZ,visitedXY,visitedYZ;

int main()
{
	
	freopen("input.in","r",stdin);
//	freopen("output.txt","w",stdout);
	
	cin.sync_with_stdio(0);
	cout.sync_with_stdio(0);


	int t,j,p,s,k;
	cin>>t;
	
	for(int tst=1;tst<=t;tst++){
		
		cin>>j>>p>>s>>k;
		
		hash.clear();
		
		for(int J = 1;J<=j;J++){
			
			for(int P = 1;P<=p;P++){
				
				for(int S =1;S<=s;S++){
					
					hash.insert(make_pair(J,make_pair(P,S)));
				}
			}
		}
		
		visitedXY.clear();
		visitedYZ.clear();
		visitedXZ.clear();
		
		store.clear();
		
	//	cout<<"done";
		
		for(set<pair<int,pair<int,int> > >::iterator it= hash.begin();it!=hash.end();it++){
			
			pair<int,pair<int,int> > pr = *it;
			
			int x = pr.first;
			int y = pr.second.first;
			int z = pr.second.second;
			
		//	cout<<visitedYZ[make_pair(y,z)]<<endl;
			if(visitedXY[make_pair(x,y)]>=k || visitedXZ[make_pair(x,z)]>=k || visitedYZ[make_pair(y,z)]>=k)
			continue;
				
		//	cout<<"d";	
			store.push_back(pr);
			visitedXY[make_pair(x,y)]++;
			visitedXZ[make_pair(x,z)]++;
			visitedYZ[make_pair(y,z)]++;
		}
		
		
		cout<<"Case #"<<tst<<": "<<store.size()<<endl;
		
		for(int i = 0;i<store.size();i++){
			
			cout<<store[i].first<<" "<<store[i].second.first<<" "<<store[i].second.second<<endl;
		}
		
	}
	
	
	
	
	return 0;
}

