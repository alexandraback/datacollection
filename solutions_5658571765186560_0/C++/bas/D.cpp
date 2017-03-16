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
		if (x==2){
		    if ( (r*c)%2 )rich=true;
		} else if(x==3){
		    if (r%3 && c%3) rich =true;
		    if(r==1 || c==1) rich=true;
		    if(r<3 && c<3) rich=true;
		} else if(x==4){
		    if(r+c<7) rich=true;
		}
		if(rich)
		    cout<<"Case #"<<j+1<<": RICHARD\n";
		else{
		    cout<<"Case #"<<j+1<<": GABRIEL\n";
		}
		
		
	}
	
}
