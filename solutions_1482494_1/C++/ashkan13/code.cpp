#include <iostream>
#include <algorithm>
using namespace std;

int n;
pair <int, int> st[1010];

int cal(){
	int sum = 0;
	int cnt = 0;
	while(1){
		bool fin = true;
		bool getStar = false;

		for(int i=0;i<n;i++){
			if(st[i].first != -1 && st[i].second != -1){
				fin = false;
				if(sum >= st[i].first){
					cnt++; 
					sum += 2;
					st[i].first = st[i].second = -1;
					getStar = true;
				}
			}
		}
		if(getStar) continue;

		for(int i=0;i<n;i++){
			if(st[i].first != -1){
				fin = false;
				if(sum >= st[i].first){
					cnt++;
					sum++;
					st[i].first = -1;
					getStar = true;
					break;
				}
			}
		}
		if(getStar) continue;

		for(int i=n-1;i>=0;i--){
			if(st[i].second != -1){
				fin = false;
				if(sum >= st[i].second){
					cnt++;
					sum++;
					st[i].second = -1;
					getStar = true;
					break;
				}
			}
		}
		if(fin) return cnt;
		if(!getStar) return -1;
	}
}

void main(){
	//*
	freopen("B-large.in","r",stdin);
	freopen("B-large.out","w",stdout);
	//*/

	int T;
	cin>>T;

	for(int tc=1;tc<=T;tc++){
		cin>>n;
		for(int i=0;i<n;i++) cin>>st[i].second>>st[i].first;
		sort(st,st+n);
		
		int ans = cal();

		cout<<"Case #"<<tc<<": ";
		if(ans < 1) cout<<"Too Bad";
		else cout<<ans;
		cout<<endl;
	}
}
/*
4
2
0 1
0 2
3
2 2
0 0
4 4
1
1 1
5
0 5
0 1
1 1
4 7
5 6

3
3
T
6
*/