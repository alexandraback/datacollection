#include <iostream>
#include <iomanip>
using namespace std;

int main(){
	int t;
	cin>>t;
	for(int i=0;i<t;i++){
		double c, f, x, ini = 2, n = 0;
		cin>>c>>f>>x;

		while(true){
			if((x-c)/ini < x/(ini+f)){
				n+=x/ini;
				break;
			}
			n += c/ini;
			ini += f;
		}

		cout<<"Case #"<<i+1<<": ";
		cout<< std::fixed;
		cout<< setprecision(7)<<n<<endl;
	}
}