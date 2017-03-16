#include <set>
#include <iostream>
#include <iomanip>
#include <algorithm>

using namespace std;

int main(){
	int T;
	cin >> T;
	for(int t=0;t<T;t++){
		int N;
		cin >> N;
		double a[N];
		double b[N];
		for(int i=0;i<N;i++) cin >> a[i];
		for(int i=0;i<N;i++) cin >> b[i];
		sort(a,a+N);
		sort(b,b+N);
		int z = 0;
		int p1 = 0;
		int p2 = 0;
		while(p2<N){
			if(a[p1]>b[p2]){
				p2++;
			} else {
				p1++;
				p2++;
			}
		}
		z = N-p1;
		int y = 0;
		
		p1 = 0;
		p2 = 0;
		while(p1<N){
			if(a[p1]<b[p2]){
				p1++;
			} else {
				p1++;
				p2++;
			}
		}
		y = p2;

		cout<<"Case #"<<t+1<<": "<<y<<" "<<z<<endl;
	}
}
