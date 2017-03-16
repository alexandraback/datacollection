#include <iostream>
#include <vector>
#include <set>
using namespace std;

struct sets{
	int sum;
	bool is[20];
};

const int LIM = 1024*1024;

sets arr[LIM+100];
int n, s[20];

void fill_it(){
	for(int k = 1; k<LIM; k++){
		arr[k].sum = 0;
		for(int i=0;i<20;i++){
			if((k>>i) & 1){
				arr[k].is[i] = true;
				arr[k].sum += s[i];
			}
			else arr[k].is[i] = false;
		}
	}
}

void main(){
	//*
	freopen("C-small.in","r",stdin);
	freopen("C-small.out","w",stdout);
	//*/

	int T;
	cin>>T;

	for(int tc=1;tc<=T;tc++){
		cin>>n;
		for(int i=0;i<n;i++)
			cin>>s[i];

		bool ans = false;
		fill_it();

		int i, j;
		for(i=1;i<LIM;i++){
			for(j=i+1;j<LIM;j++){
				if(arr[i].sum == arr[j].sum){
					ans = true;
					break;
				}
			}
			if(ans == true) break;
		}

		cout<<"Case #"<<tc<<":\n";
		if(ans == false) cout<<"Impossible\n";
		else{
			for(int k=0;k<20;k++){
				if(arr[i].is[k]) cout<<s[k]<<' ';
			}
			cout<<endl;
			for(int k=0;k<20;k++){
				if(arr[j].is[k]) cout<<s[k]<<' ';
			}
			cout<<endl;
		}

	}
}
/*
2
20 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20
20 120 266 858 1243 1657 1771 2328 2490 2665 2894 3117 4210 4454 4943 5690 6170 7048 7125 9512 9600


*/