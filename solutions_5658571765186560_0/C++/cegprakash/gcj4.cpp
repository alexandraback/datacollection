#include <iostream>
#include <cmath>
#include <cstdlib>
#include <map>
#include <algorithm>
#include <sstream>
#include <set>
#include <cstring>
#include <vector>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	freopen("gcj4.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int t,c=1,x,R,C;
	string winner[]={"RICHARD","GABRIEL"};
	cin>>t;
	while(t--){
		cout<<"Case #"<<c++<<": ";
		cin>>x>>R>>C;
		switch(x){
			case 1:
				cout<<winner[1]<<endl;
				break;
			case 2:
				if(R%2 == 0 || C%2 == 0)
					cout<<winner[1]<<endl;
				else
					cout<<winner[0]<<endl;
				break;
			case 3:
				if((C==3&&R!=1) || (R==3&&C!=1) )
					cout<<winner[1]<<endl;
				else cout<<winner[0]<<endl;
				break;
			case 4:
				if(R+C>=7)
					cout<<winner[1]<<endl;
				else cout<<winner[0]<<endl;
				break;
		}
	}

	return 0;
}