#include <iostream>
#include <cstdio>
#include <vector>
#include <climits>

using namespace std;

long long int eat(vector<int> *v, long long mote){
	bool change = true;
	while(change){
		change = false;
		int i = 0;
		while(i<v->size()){
			if ((*v)[i]<mote) {
				mote += (*v)[i];
				change = true;
				v->erase(v->begin()+i);
			}
			else i++;
		}
	}
	return mote;
}


int count(vector<int> *v, long long mote, int result){
	mote = eat(v,mote);
	
	int n = v->size();
	if (n==0) return result;
	
	int m2 = 2 * mote - 1;
	if (m2 == mote) return -1;
	
	int r = count(v,2 * mote - 1,result + 1);
	
	if (r==-1 || (result + n) < r) return result + n;
	else return r;
}

int main(){
	int z;
	scanf("%d", &z);
	for (int c = 1; c<=z;c++){
		long long int result = 0;
		long long int mote,n;
		int min = INT_MAX;
		scanf("%lld %lld",&mote,&n);
		vector<int> v;
		for (int i =0;i<n;i++){
			int x;
			scanf("%d",&x);
			if (x<mote) mote += x;
			else {
				if (x<min) min = x;
				v.push_back(x);
			}
		}

		result = count(&v,mote,0);
		if (result==-1) result = v.size();
		
		printf("Case #%d: %lld\n", c, result);
	}
	return 1;
}
