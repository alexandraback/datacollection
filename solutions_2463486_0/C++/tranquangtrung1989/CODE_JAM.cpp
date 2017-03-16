#include <iostream>
#include<fstream>
#include<vector>
#include<cmath>
using namespace std;
#define cin fin
#define cout fout
ifstream fin("in.txt");
ofstream fout("out.txt");
using namespace std;
bool isPalin(long long N){
	long long n=N;
    long long rs=N%10;
    N/=10;
    while(N>0){
    	rs=10*rs+N%10;
    	N/=10;
    }
    if(rs==n) return true;
    return false;
}
int main() {

	int T, A, B, start, end;
	vector<long long> paLinSet;
	vector<long long> fairSet;
	for(long long i=1;i<=(long long )pow(10.0, 7);i++){
		if(isPalin(i)) {
			paLinSet.push_back(i);
		}
	}
	for(unsigned int i=0;i<paLinSet.size();i++){
		if(paLinSet[i]*paLinSet[i]<=(long long )pow(10.0, 14)&&isPalin(paLinSet[i]*paLinSet[i]))
			fairSet.push_back(paLinSet[i]*paLinSet[i]);

	}

	cin >> T;
	for(int t=1;t<=T;t++){
		cin >> A >> B;
		start=0, end=fairSet.size()-1;
		while(A>fairSet[start]&&start<fairSet.size()) start++;
		while (B<fairSet[end]&&end>=0) end--;
		cout<<"Case #"<<t<<": ";
		if(start>=fairSet.size()||end<0||start>end) cout<<0;
		else cout<<end-start+1;
		cout<<endl;
	}
	return 0;
}
