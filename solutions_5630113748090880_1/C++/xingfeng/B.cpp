


#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>

using namespace std;

//#define DEBUG

void solve(int index){
	int N,num, maxNum = 0;
	int numCount[2510];
	vector<int> missing_num;

	memset(numCount, 0, sizeof(int)*2510);

	cin>>N;

#ifdef DEBUG
	cout<<"N "<<N<<endl;
#endif
	for(int i = 0;i<2*N-1;i++){
		for(int j = 0;j<N;j++){
			cin>>num;
			#ifdef DEBUG
				cout<<"i j num "<<i<<" "<<j<<" "<<num<<endl;
			#endif
			numCount[num]++;
			if(num > maxNum)
				maxNum = num;
		}
	}

	for(int i = 1;i<=maxNum;i++){


		if(numCount[i]%2==1)
			missing_num.push_back(i);
	}

	std::sort(missing_num.begin(), missing_num.end());

	cout<<"Case #"<<index<<":";

	for(int i = 0;i<missing_num.size();i++)
		cout<<" "<<missing_num[i];
	cout<<endl;
}

int main(){
	int T;

	cin>>T;

	for(int i = 0;i<T;i++){
		solve(i+1);
	}

}
