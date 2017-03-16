#include <iostream>
#include <set>
#include <string>
using namespace std;

int main()
{
	int t,j=0;
	cin>>t;
	while(t--){
		j++;
		string s;
		int x, y,x1,y1;
		cin>>x>>y;
		x1=x;
		y1=y;
		if(x<0)
			x1=x*-1;
		if(y<0)
			y1=y*-1;
		if(x==0 && y==0){
			s="SSNEWWE";
		}
		else if(x1==0){
			if(y>0){
				for(int i=0;i<y1;i++){
					s.push_back('S');
					s.push_back('N');
				}
			}
			else{
				for(int i=0;i<y1;i++){
					s.push_back('N');
					s.push_back('S');
				}
			}
		}
		else if(y1==0){
			if(x>0){
				for(int i=0;i<x1;i++){
					s.push_back('W');
					s.push_back('E');
				}
			}
			else{
				for(int i=0;i<x1;i++){
					s.push_back('E');
					s.push_back('W');
				}
			}
		}
		else{
			if(y>0){
				for(int i=0;i<y1;i++){
					s.push_back('S');
					s.push_back('N');
				}
			}
			else{
				for(int i=0;i<y1;i++){
					s.push_back('N');
					s.push_back('S');
				}
			}

			if(x>0){
				for(int i=0;i<x1;i++){
					s.push_back('W');
					s.push_back('E');
				}
			}
			else{
				for(int i=0;i<x1;i++){
					s.push_back('E');
					s.push_back('W');
				}
			}
		}
		
		cout<<"Case #"<<j<<": "<<s<<endl;
	}
	return 0;
}
