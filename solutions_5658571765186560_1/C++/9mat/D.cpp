#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

#define FOR(i,n) for(int i = 0, n_ = (n); i < n_; i++)
#define FORS(i,s,n) for(int i = (s), n_ = (n); i < n_; i++)
#define ITER(it,v) for(auto it = (v).begin(); it != (v).end(); ++it)

template <typename T> void updatemax (T& a, const T& b) {
	if(b>a) a=b;
}

template <typename T> void updatemin (T& a, const T& b) {
	if(b<a) a=b;
}

using namespace std;

int main(){
	int T, X, R, C;
	cin>>T;

	FOR(icase, T){
		cin>>X>>R>>C;

		if((R*C)%X != 0 | (R<X & C<X)) {
			cout<<"Case #"<<icase+1<<": RICHARD"<<endl;
			continue;
		}

		if(X <= 2){
			cout<<"Case #"<<icase+1<<": GABRIEL"<<endl;
			continue;
		}

		if(X == 3){
			if(R==1 || C==1) 
				cout<<"Case #"<<icase+1<<": RICHARD"<<endl;
			else
				cout<<"Case #"<<icase+1<<": GABRIEL"<<endl;
			continue;
		}

		if(X==4){
			if(R <= 2 || C <=2) 
				cout<<"Case #"<<icase+1<<": RICHARD"<<endl;
			else
				cout<<"Case #"<<icase+1<<": GABRIEL"<<endl;
			continue;
		}

		if(X==5 | X==6){
			if(R <= 3 || C <=3) 
				cout<<"Case #"<<icase+1<<": RICHARD"<<endl;
			else
				cout<<"Case #"<<icase+1<<": GABRIEL"<<endl;
			continue;
		}

		
		cout<<"Case #"<<icase+1<<": RICHARD"<<endl;


	}
	return 0;
}

