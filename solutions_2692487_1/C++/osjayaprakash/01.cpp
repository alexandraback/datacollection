#include <iostream>
#include <algorithm>


using namespace std;


unsigned arr[1000005]; int N; unsigned  A;

int sol(int omoves, int from){
	int moves = 0;
//	cout << '*' << A <<  ' ' << from << endl;
	if(from>=N)
		return 0;
	if(omoves >= N)
		return (N-from);
	if(A > arr[from]){
		A+= arr[from];
		moves += sol(omoves, from+1);
	}else{
		A+=(A-1);
		moves += sol(omoves+1, from)+1;		
	}
	return min(moves, N-from);
}

int Solve(){
	cin >> A;
	cin >> N;
	for(int i=0;i<N;i++)
		cin >> arr[i];
	sort(arr, arr+N);
	cout << sol(0, 0);
}

int main(){
	int T;
	cin >> T;
	for(int i=1;i<=T;i++){
		cout << "Case #"<<i<<": ";
		Solve();
		cout << endl;
	}
}
