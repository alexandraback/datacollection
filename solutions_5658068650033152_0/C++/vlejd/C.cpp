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

#define debug
#ifdef debug
#define db(XZ) cout<<XZ<<" "
#define dbn() cout<<endl
#else 
#define db(XZ); 
#define dbn()
#endif

LLD a,b,c;
int pole[22][22];
LLD counter;

void move(LLD y, LLD x){
	//cout<<"alvieee"<<endl;
	if(pole[y][x]==-1) return;
	pole[y][x]=-1;
	counter-=1ll;
	move(y-1ll,x);
	move(y+1ll,x);
	move(y,x-1ll);
	move(y,x+1ll);
	
}

int main(){
    For(i,22) For(j,22) pole[i][j]=-1;
	
	int test;
    cin>>test;
    For(t,test){
    	cout<< "Case #"<<t+1<<": ";
		cin>>a>>b>>c;
		LLD bast = a+a+b+b;
		
		ForL(who,1ll<<(a*b)){
			LLD score=0;
			ForL(i,a)
			ForL(j,b)
			if(((1ll<<(i*b+j))&who )!=0ll){
				pole[i+1ll][j+1ll]=-1;
				score+=1ll;
				
			}
			else pole[i+1ll][j+1ll]=0;
			/*
			ForL(i,a){
				ForL(j,b)
				cout<<pole[i][j];
				cout<<endl;
			}*/
			
			if(score>=bast) continue;
			
			//ci ma tolko enclosov
			counter=a*b;
			ForL(i,a) {
				move(i+1ll,1ll);
				move(i+1ll,b);
			}
			ForL(i,b){
				move(1ll,i+1ll);
				move(a,i+1ll);
			}
			//cout<<score<<" "<<counter<<endl;
			
			if(counter>=c){
				bast=score;
				//cout<<"lepsie "<<bast<<endl;
			}
		}
		
    	cout<<bast;
    	cout<<endl;
    }
    return 0;   
}
