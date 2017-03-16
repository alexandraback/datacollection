#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

bool noti(char cc){
	if( cc=='a' || cc=='u' || cc=='i' || cc=='o' || cc=='e' )
		return false;
	return true;
}

int main(){

	long long t;
	cin>>t;
	for(long long cou=1;cou<=t;cou++){
		int x,y;
		cin>>x>>y;
		int i=1;
		int X=0,Y=0;
		string r="";
		while(x!=X || Y!=y){
			
			if(i+X <= x){
				X+=i;
				r+="E";
			}
			else if(X-i >= x){
				X-=i;
				r+="W";
			}
			else if(Y+i <= y){
				Y+=i;
				r+="N";
			}
			else if(Y-i >= y){
				Y-=i;
				r+="S";
			}
			else{
				if(X < x){
					X++;
					i++;
					r+="WE";
				}
				else if( X > x){
					X--;
					i++;
					r+="EW";
				}
				else if( Y < y){
					Y++;
					i++;
					r+="SN";
				}
				else{
					Y--;
					i++;
					r+="NS";
				}
			}
		
			i++;
		}
		cout<<"Case #"<<cou<<": "<<r<<endl;
	}

	return 0;
}