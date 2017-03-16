#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<string>
#include<set>
#include<vector>
#include<map>
#include<queue>
#include<deque>
#include<complex>


using namespace std;

#define ForL(Q,W) for(long long Q=0;Q<W;Q++)
#define For(Q,W) for(int Q=0;Q<W;Q++)
#define LLD long long
#define mkp make_pair
#define pb push_back
#define pf printf
#define sf scanf
#define prime 1000000007
#define debug
#ifdef debug
#define db(XZ) cout<<XZ<<" "
#define dbn() cout<<endl
#else 
#define db(XZ); 
#define dbn()
#endif

int toi(char c){
	return int(c-'a');
}

LLD fak(LLD x){
	if(x==0ll) return 1ll;
	else return (fak(x-1ll)*x)%prime;
	
}

int main(){
    int test;
	cin>>test;
    For(t,test){
    	cout<< "Case #"<<t+1<<": ";
		int n;
    	cin>>n;
    	vector<string> vlak(n);
    	For(i,n) cin>>vlak[i];
    	int from[26];
    	int num[26];
    	LLD rovnake[26];
    	int to[26];
    	For(i,26)from[i]=to[i]=-1;
    	For(i,26) num[i]=0;
		For(i,26) rovnake[i]=0ll;
    	
    	bool bad = false;
    	
		For(i,n){
			string pom = vlak[i];
			bool setko = true;
			For(i,pom.size()-1) if(pom[i]!=pom[i+1]) setko=false;
			if(setko) rovnake[toi(pom[0])]++;
			
			num[toi(pom[pom.size()-1])]++;
				
			For(j,pom.size()-1){
				num[toi(pom[j])]++;
				if(pom[j]!=pom[j+1]){
					
					if(from[toi(pom[j+1])]==-1){
						from[toi(pom[j+1])]=toi(pom[j]);
						
					}
					else bad=true;
					
					if(to[toi(pom[j])]==-1 ){
						to[toi(pom[j])]=toi(pom[j+1]);
						
					}
					else bad=true;
										
				}
			}
		}
		
		if(bad){
			cout<<0<<endl;
			continue;
		}    	
		
		
		LLD medz=1ll;
		For(i,26) medz*=fak(rovnake[i]);
		
		LLD comp =0ll;
		
		For(i,26){
			int now= i;
			//cout<<from[i]<<" "<<to[i]<<endl;
			if(num[now]==0) continue;
			comp++;
			
			while(now!=-1){
				num[now]=0;
				now=to[now];
				if(now==i){
					medz=0;
					break;
				}
			}
			
			now=i;
			while(now!=-1){
				num[now]=0;
				now=from[now];
				if(now==i){
					medz=0;
					break;
				}
			}
			
		}
		comp = fak(comp);
		//cout<<comp << " " <<medz << endl;
		cout<<(comp*medz)%prime;
    	
    	cout<<endl;
    }
    return 0;   
}
