#include <iostream>
#include <vector>
#include <cmath>
#include <string>

using namespace std;


int main() {
	// your code goes here
	int numCases;
	cin >> numCases;
	for(int i=0; i<numCases; i++){
		cout << "Case #" << i+1 << ": ";
		int j,p,s,k;
		cin >> j >> p >> s >> k;
		/*int numFash;
		if(k!= 1){
			numFash = j * ((p<k)? p : k) * ((s<k)? s : k);
		}else{
			numFash = ((s<p)? s : p)+(j-1);
		}
		cout << numFash << "\n";*/
		vector<int> a;
		vector<int> b;
		vector<int> c;
		
		for(int z=1; z<=s; z++){
			for(int x=1; x<=j; x++){
				for(int y=1; y<=p; y++){
					a.push_back(x);
					b.push_back(y);
					c.push_back(z);
				}
			}
		}

		/*for(int y=0; y<a.size(); y++){
				cout << a[y] << " " << b[y] << " " << c[y] << "\n";
			}*/

		while(1){
			bool r = false;
			for(int x=0; x<a.size(); x++){
				int numAB = 1;
				int numAC = 1;
				int numBC = 1;
				for(int y=x; y<a.size(); y++){
					if(x != y){
						if(100*a[x]+10*b[x]+c[x] == 100*a[y]+10*b[y]+c[y]){
							a.erase(a.begin() + y);
							b.erase(b.begin() + y);
							c.erase(c.begin() + y);
							r = true;
							//cout << "ERASING: " << y << endl;
						}else if(10*a[x]+b[x] == 10*a[y]+b[y]){
							if(numAB >= k){
								a.erase(a.begin() + y);
								b.erase(b.begin() + y);
								c.erase(c.begin() + y);
								r = true;
								//cout << "ERASING: " << y << endl;
							}
							numAB++;
						}else if(10*a[x]+c[x] == 10*a[y]+c[y]){
							if(numAC >= k){
								a.erase(a.begin() + y);
								b.erase(b.begin() + y);
								c.erase(c.begin() + y);
								r = true;
								//cout << "ERASING: " << y << endl;
							}
							numAC++;
						}else if(10*c[x]+b[x] == 10*c[y]+b[y]){
							if(numBC >= k){
								a.erase(a.begin() + y);
								b.erase(b.begin() + y);
								c.erase(c.begin() + y);
								r = true;
								//cout << "ERASING: " << y << endl;
							}
							numBC++;
						}
					}
				}
			}
			if(!r)
				break;
		}
		/*else{
			int z1 = 1;
			int z2 = 1;
			int count = 0;
			for(int x=1; x<=j; x++){
				for(int y=1; y<=p; y++){
					if(count <= numFash){
						if((x>1 && x == z1)){
							cout << x << " " << y << " " << z2 << "\n";
							z2++;
						}else if(x < 2){
							cout << x << " " << y << " " << z1 << "\n";
						}
					}
					z1++;
					count ++;
				}
				z1 = (z1>s) ? 1 : z1;
			}
		}*/
			cout << a.size() << endl;
			for(int y=0; y<a.size(); y++){
				cout << a[y] << " " << b[y] << " " << c[y] << "\n";
			}

	}
	return 0;
}
