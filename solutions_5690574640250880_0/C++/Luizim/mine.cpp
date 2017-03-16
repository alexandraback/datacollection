#include <iostream>

using namespace std;

int main(){
	int t;
	cin>>t;
	for(int T=0;T<t;T++){
		int r, c, m;
		cin>>r>>c>>m;

		cout<<"Case #"<<T+1<<":"<<endl;
		if(r==c && c==1){
			if(m==1)
				cout<<"Impossible"<<endl;
			else
				cout<<'c'<<endl;

		}
		else if(r*c == m+1){
			for(int i=0;i<r;i++){
				for(int j=0;j<c;j++){
					cout<< (m > 0 ? '*': 'c');
					m--;
				}
				cout<<endl;
			}
		}
		else if(r==1 || c==1){
			if(r*c >= m + 2){
				for(int i=0;i<r;i++){
					for(int j=0;j<c;j++){
						cout<< (m > 0 ? '*': m==-1 ? 'c': '.');
						m--;
					}
					cout<<endl;
				}
			}else{
				cout<<"Impossible"<<endl;
			}
		}
		else if(r * c -m == 7 || r * c -m == 5){
			cout<<"Impossible"<<endl;
		}
		else if((r==2 || c==2)&&(r*c-m)%2==1){
			cout<<"Impossible"<<endl;
		}
		else{
			if(r*c >= m + 4){
				int points = r*c - m - 4;
				int p2=0, p3=0;
				for(int i=0;i<r;i++){
					if(i==0){
						if(points % 2 == 1){
							p3 = 3;
							
						}
						points -= p3;
						p2 = points/2;
						points -= p2;
					}
					if(i==1) points += p2;
					if(i==2) points += p3;

					for(int j=0;j<c;j++){
						if(i+j==0)
							cout<<'c';
						else if(j<2 && i<2)
							cout<<'.';
						else if(j==c-1 && points==2 && i!=0)
							cout<<'*';
						else if(points>0){
							cout<<'.';
							points--;
						}
						else 
							cout<<'*';
							
					}
					cout<<endl;
				}

			}else{
				cout<<"Impossible"<<endl;
			}	
		}
	}
}