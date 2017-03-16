#include <iostream>
#include <cstdio>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>

using namespace std;

#define forsn(i,s,n) for(int i = (s);i < (int)(n);i++)
#define forn(i,n) forsn(i,0,n)
#define dforsn(i,s,n) for(int i = (n - 1);i >= 0;i--)
#define dforn(i,n) dforsn(i,0,n)
#define esta(x,c) (c.find(x) != c.end())
#define all(v) v.begin(),v.end()
#define saludo cout << "HOLAA" << endl;

int main(){
	freopen("1A-B.in","r",stdin);
	freopen("1A-B.out","w",stdout);
	int t;
	cin >> t;
	forn(i, t){
		int n;
		cin >> n;
		int levels[n][3];
		vector<vector<int> > sorted2;
		forn(j,n){
			forn(k,2){
				cin >> levels[j][k];
			}
			levels[j][2] = 0;
	
			vector<int> sort2(3);
			sort2[0] = levels[j][1];
			sort2[1] = levels[j][0];
			sort2[2] = j;
			sorted2.push_back(sort2);
		}
		sort(all(sorted2));
		int stars = 0;
		int win = 0;
		int steps = 0;
		bool broken = false;
		while(win < n){
			if(sorted2[win][0] <= stars){
				stars += 2 - levels[sorted2[win][2]][2];
				levels[sorted2[win][2]][2] = 2;
				win++;
				steps++;
			}else{
				dforsn(j, 0, n){
					broken = true;
					if(sorted2[j][1] <= stars){
						if(levels[sorted2[j][2]][2] == 0){
							levels[sorted2[j][2]][2]++;
							stars++;
							steps++;
							broken = false;
							break;
						}
					}
				}
			}
			if(broken)
				break; //Esto es un asco.
		}
		if(!broken){
			cout << "Case #" << i + 1 << ": " << steps << endl;
		}else{
			cout << "Case #" << i + 1 << ": Too Bad" << endl;
		}
	}
}
