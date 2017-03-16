
#include <iostream>
#include <vector>
#include <algorithm>
#include <bitset>

using namespace std;

int main(){
	int nt;
	cin >> nt;
	for(int t=0;t<nt;t++){
		int n;
		long a;
		vector<long> mote;
		cin >> a >> n;
		for(int i=0;i<n;i++){
			long temp;
			cin >> temp;
			mote.push_back(temp);
		}
		sort(mote.begin(),mote.end());

		long op=0;
		long abnd=mote.size();
		while(true){
			if(mote.size()==0)break;
			if(a>mote[0]){
				a+=mote[0];
				mote.erase(mote.begin());
				continue;
			}else{
				abnd=min(abnd,op+(signed)mote.size());
				while(a<=mote[0] && abnd>op){
					a+=(a-1);
					op++;
				}
				if(abnd<=op){
					op=abnd;
					break;
				}
			}
		}

		cout << "Case #" << t+1 << ": " << op << endl;
	}
	return 0;
}