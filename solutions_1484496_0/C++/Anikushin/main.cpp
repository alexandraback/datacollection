#include <iostream>
#include <vector>

using namespace std;

int main(){
	freopen("c.in","r",stdin);
	freopen("c.out","w",stdout);
	int T;
	cin >> T;
	for(int t=0;t<T;t++){
		int n;
		cin >> n;
		vector<int> s(20*100000+2,0);
		vector<int> a(20);
		for(int i=0;i<n;i++){
			cin >> a[i];
		}
		for(int m=0;m<(1<<20);m++){
			int ss=0;
			for(int j=0;j<n;j++){
				if((1<<j)&m)ss+=a[j];
			}
			s[ss]++;
		}
		int ans1=0,ans2=0;
		cout << "Case #" << t+1 << ":\n";
		int ss=1;
		while(ss<2000001){
			if(s[ss]>1)break;
			ss++;
		}
		if(ss==2000001){
			cout << "Impoossible\n";
		}
		for(int m=0;m<(1<<20);m++){
			int q=0;
			for(int j=0;j<n;j++){
				if((1<<j)&m)q+=a[j];
			}
			if(q==ss){
				if(ans1==0){
					ans1=m;
				}
				else{
					ans2=m;
					break;
				}
			}
		}
		for(int i=0;i<n;i++){
			if((1<<i)&ans1)cout << a[i] << " ";
		}
		cout << endl;
		for(int i=0;i<n;i++){
			if((1<<i)&ans2)cout << a[i] << " ";
		}
		cout << endl;
	}

	return 0;
}