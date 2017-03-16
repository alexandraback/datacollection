#include<iostream>
#include<vector>
#include<string>

using namespace std;
	int T;
	int x, r,c;
int main(){

	cin>>T; 
	for(int j=0; j<T; j++){
		cin>>x>>r>>c;
		bool rich = false;
		if(x>6) rich=true;
		if((r*c)%x)rich=true;
		if(r<x && c<x) rich=true;
		if(x==3){
		    if(r==1 || c==1) rich=true;
		}
		else if(x==4){
		    if(r<3 || c<3) rich=true;
		
		} else if(x==5){
		    if(r>c)swap(r,c);
		    if(r<3) rich=true;
		    if(r==3 && c<10) rich=true;
		}else if(x==6){
		    if(r<4 || c<4) rich=true;
    
		}
		if(rich)
		    cout<<"Case #"<<j+1<<": RICHARD\n";
		else{
		    cout<<"Case #"<<j+1<<": GABRIEL\n";
		}
		
		
	}
	
}
