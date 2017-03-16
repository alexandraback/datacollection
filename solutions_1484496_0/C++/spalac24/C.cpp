#include<iostream>
#include<map>
#include<stack>
#include<vector>
#include<algorithm>
#include <cstring>
#include<queue>
#include<deque>
#include <iomanip>
#include<sstream>
#include<fstream>
#include<cstdio>
#include<cstring>
#include<cmath>

using namespace std;

typedef unsigned long long int ul;
typedef long long ll;

const double EPS = 1e-9;

template <class T> string toStr(const T &x){
stringstream s; s << x; return s.str();
}

template <class T> int toInt(const T &x){
stringstream s; s << x; int r; s >> r; return r;
}


int main () {
    cin.sync_with_stdio(false);
    cout.sync_with_stdio(false);
    int t;
    cin>>t;
    for (int cas = 1; cas <= t; ++cas) {
		cout<<"Case #"<<cas<<":"<<endl;
		int n;
		cin>>n;
		int arr [n];
		for (int i = 0; i < n; ++i) {
			cin>>arr[i];	
		}	
		int mask = 1<<n;
		map <int,int> mapa;
		bool is = false;
		while(mask--) {
		//	cout<<mask<<endl;
			int sum = 0;
			for (int i = 0; (1<<i) <= mask; i++) {
				if (mask & (1<<i)) {
					sum += arr[i];	
				}	
			}
			
			if (mapa[sum]){
			//	cout<<"Suma = "<<sum<<endl;
				is = true;
				bool firstprinted = false;
				for (int i = 0; (1<<i) <= mapa[sum]; ++i) {
					if ((1<<i)&mapa[sum]){
						if (firstprinted) cout<<" ";
						cout<<arr[i];	
						firstprinted = true;
					}	
				}cout<<endl;
				firstprinted = false;
				for (int i = 0; (1<<i) <= mask; ++i) {
					if ((1<<i) & mask) {
						if (firstprinted) cout<<" ";
						cout<<arr[i];
						firstprinted = true;	
					}
				}cout<<endl;
				break;	
			}
			mapa[sum] = mask;
				
		}
		if (!is) cout<<"Impossible"<<endl;
	}
    return 0;
}
