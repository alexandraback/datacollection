#include <bits/stdc++.h>
typedef long long ll;

using namespace std;
int A[200][200];
int B[200][200];
int N,M;
vector<int> f(){
	int index=0;
	int cnt=0;
	int mn=9999;
	int jj=0;
	int jj2=0;
	for(int i=0;i<N;i++){
		cnt=0;
		mn=9999;
		for(int j=0;j<M;j++){
			if(B[j][i]<mn){
				mn=B[j][i];
				cnt=1;
				jj=j;
			} else if(B[j][i]==mn){
				cnt++;
				jj2=j;
			}
		}
		if(cnt==1){
			index=i;
			break;
		}
		for(int j=0;j<N;j++){
			B[jj][j]=9999;
			B[jj2][j]=9999;
		}
	}
	multiset<int> ms;
	ms.insert(mn);
	for(int i=0;i<M;i++){
		ms.insert(A[i][index]);
	}
	for(int i=0;i<N;i++){
		ms.erase(ms.find(A[jj][i]));
	}
	vector<int> ans;
	for(auto i=ms.begin();i!=ms.end();i++){
		ans.push_back(*i);
	}
	return ans;
}
int main(int argc, char const *argv[]){
	int T;
	cin >> T;
	for(int t=0;t<T;t++){
		cin >> N;
		M=2*N-1;
		for(int i=0;i<M;i++){
			for(int j=0;j<N;j++){
				cin >> A[i][j];
				B[i][j]=A[i][j];
			}
		}
		printf("Case #%d: ",t+1);
		vector<int> ans = f();
		for(int i=0;i<ans.size();i++){
			if(i)cout << " ";
			cout << ans[i];
		}
		cout << endl;
	}
	return 0;
}