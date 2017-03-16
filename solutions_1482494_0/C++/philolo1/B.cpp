#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <math.h>
#include <map>
#include <vector>
#include <set>
#include <algorithm>
#include <cstring>
#include <stack>
#include <queue>

// defines
#define ll long long int
#define REP(a,b) for(int (a)=0;a<(int)b;a++)
#define FOR(a,b,c) for(int (a)=b;a<(int)c;a++)
#define MP(A,B) make_pair(A,B)
#define PB push_back
#define S(a) scanf("%d",&a);
#define SCH(a) scanf("%s",a);
#define foreach(a,b) for(__typeof(b).begin() a  = b.begin(); a != b.end();a++)
#define debug(a) cout<<a<<endl;
#define INIT(a) memset(a,0,sizeof(a))

using namespace std;

vector< pair< pair<int,int> ,int> > s1;
set< pair<int,int> > s2;

bool used[2000];
bool one[2000];

int main(){
	int T;
	S(T);
	
	REP(t,T){
		int N;
		
		int stars =0;
		S(N);
		s1.clear();
		s2.clear();
		memset(used,false,sizeof(used));
		memset(one, false, sizeof(one));
		
		int steps =0;
		
		REP(n,N){
			int a;
			int b;
			S(a);
			S(b);
			
			s1.push_back(make_pair(make_pair(a,b),n));
			s2.insert(make_pair(b,n));
		}
		
		sort(s1.begin(),s1.end());
		
		bool change = true;
		
		while(stars<2*N && change){
			
			change=false;
			
			while(s2.size()!=0){
				pair<int,int> p = *s2.begin();
				
				if(p.first<=stars){
					//cout<<"SECOND " <<p.second<<endl;
					if(!one[p.second]){
						stars++;
					}
					stars++;
					steps++;
					used[p.second]=true;
					change = true;
					s2.erase(s2.begin());
				}else{
					break;
				}
				

			}
			
			bool found =false;
			int best =0;
			int pos =0;
			//cout<<"Hello "<<s1.size()<<endl;
			for(int n=0;n<(int)s1.size();n++){
				
				pair< pair<int,int> ,int>  p = s1[n]; 
			//	cout<<" P :"<<p.second<<endl;
				if(!used[p.second] && !one[p.second] && p.first.first <= stars){
					
					if(p.first.second>best){
						found =true;
						pos = n;
						best =p.first.second;
					}
				}
				
			}
			
			if(found){
				pair< pair<int,int> ,int>  p = s1[pos]; 
				one[p.second]=true;
				stars++;
				steps++;
				change = true;
			}
			
		}
		
		if(stars==2*N){
			printf("Case #%d: %d\n",t+1, steps);
		}else{
			printf("Case #%d: Too Bad\n",t+1);
		}
		
		
	}
}
