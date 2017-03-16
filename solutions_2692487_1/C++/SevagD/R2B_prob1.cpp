#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

vector <int> motes;

map < pair<int,int> , int> DP;

int getmin(int pos, int A_size)
{
	if (pos==motes.size() || A_size>1000000)
		return 0;

	if (DP.count(make_pair(pos,A_size))>0)
		return DP[make_pair(pos,A_size)];

	if (motes[pos]<A_size){
		int res = getmin(pos+1, A_size+motes[pos]);
		DP[make_pair(pos,A_size)] = res;
		return res;
	}
	else{
		//add a mote
		int res1;
		if (A_size>1)
			res1 = getmin(pos, A_size*2-1)+1; //add a mote of size (A_size-1) bcuz that helps the most
		else 
			res1 = 1e9;

		//remove a mote
		int res2 = getmin(pos+1, A_size)+1;

		DP[make_pair(pos,A_size)] = min(res1,res2);
		return min(res1,res2);
	}
}


int main()
{
	int T, A, N;
	
	ifstream cin("A-large.in");
	ofstream cout("Sevag_A_large.out");

	cin>>T;

	for (int t=1; t<=T; t++)
	{
		cin>>A>>N;
		motes.resize(N);
		for (int i=0; i<N; i++){
			cin>>motes[i];
		}

		sort (motes.begin(), motes.end());

		DP.clear();
		int ans = getmin(0,A);

		cout<<"Case #"<<t<<": "<<ans<<endl;
	}

	return 0;
}