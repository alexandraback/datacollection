#include <bits/stdc++.h>
#define optimizar_io ios_base::sync_with_stdio(0);cin.tie
using namespace std;

char cadena[1002];
deque<char>D;

int T;
int N;

int main(){
	optimizar_io(0);
	cin>>T;
	for(int caso = 1;  caso <= T; caso++){
		cin>>cadena;
		D = deque<char>();
		for(N=0;cadena[N];N++);
		for(int i = 0; i < N ;i++){
			if(i==0){
				D.push_back(cadena[0]);
			} else {
				if(cadena[i]>=*(D.begin()))
					D.push_front(cadena[i]);
				else
					D.push_back(cadena[i]);
			}
		}
		cout<<"Case #"<<caso<<": ";
		for(auto it = D.begin(); it != D.end(); it++)
			cout<<*it;
		cout<<"\n";
	}
	return 0;
}