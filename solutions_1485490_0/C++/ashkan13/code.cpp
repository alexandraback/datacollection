#include <iostream>
using namespace std;

int n,m;
pair <int, long long> a[110], b[110];
#define kind first
#define val second

long long cal(int k1, int k2){
	long long temp, newSum;
	long long ret=0;
	for(int k=1;k<m;k++){
		if(a[k2].kind == b[k].kind){
			temp = 0;
			for(int kk=k-1;kk>=0;kk--)
				if(a[k1].kind == b[kk].kind) temp += b[kk].val;
			newSum = min(a[k1].val, temp);

			temp = 0;
			for(int kk=k;kk<m;kk++)
				if(a[k2].kind == b[kk].kind) temp += b[kk].val;
			newSum += min(a[k2].val, temp);
			ret = max(ret, newSum);
		}
	}
	return ret;
}

long long cal(){
	long long sum = 0;

	for(int k=0;k<m;k++)
		if(a[0].kind == b[k].kind) sum+=b[k].val;
	sum = min(sum, a[0].val);

	if(n == 1) return sum;

	long long newSum = 0, temp;

	for(int k=0;k<m;k++)
		if(a[1].kind == b[k].kind) newSum+=b[k].val;
	temp = a[1].val;
	if(a[1].kind == a[0].kind) temp += a[0].val;
	newSum = min(newSum, temp);
	sum = max(sum , newSum);

	// 0 & 1
	newSum = cal(0,1);
	sum = max(sum , newSum);

	if(n == 2) return sum;

	newSum = 0;
	for(int k=0;k<m;k++)
		if(a[2].kind == b[k].kind) newSum+=b[k].val;
	temp = a[2].val;
	if(a[1].kind == a[2].kind) temp += a[1].val;
	if(a[0].kind == a[2].kind) temp += a[0].val;
	newSum = min(newSum, temp);
	sum = max(sum , newSum);

	// 1 & 2
	newSum = cal(1,2);
	if(sum < newSum) sum = newSum;

	// 0 & 2
	newSum = cal(0,2);
	if(sum < newSum) sum = newSum;

	// 0 & 1 & 2
	for(int k=2;k<m;k++){
		if(a[2].kind == b[k].kind){
			long long ret = 0;
			//////////////////////////////

			for(int j=k-1;j>0;j--){
				if(a[1].kind == b[j].kind){
					long long newSum = 0;

					temp = 0;
					for(int kk=j-1;kk>=0;kk--)
						if(a[0].kind == b[kk].kind) temp += b[kk].val;
					newSum = min(a[0].val, temp);
					temp = 0;
					for(int kk=j;kk<k;kk++)
						if(a[1].kind == b[kk].kind) temp += b[kk].val;
					newSum += min(a[1].val, temp);
					
					ret = max(ret, newSum);
				}
			}

			temp = 0;
			for(int kk=k;kk<m;kk++)
				if(a[2].kind == b[kk].kind) temp += b[kk].val;
			ret += min(a[2].val, temp);
			
			//////////////////////////////
			sum = max(sum, ret);
		}
	}

	return sum;
}

void main(){
	//*
	freopen("c-small.in","r",stdin);
	freopen("c-small.out","w",stdout);
	//*/

	int T;
	cin>>T;

	for(int tc=1;tc<=T;tc++){
		cin>>n>>m;

		for(int i=0;i<n;i++)
			cin>>a[i].val>>a[i].kind;
		for(int i=0;i<m;i++)
			cin>>b[i].val>>b[i].kind;

		cout<<"Case #"<<tc<<": "<<cal();
		cout<<endl;
	}
}
/*
4
3 3
10 1 20 2 25 3
10 2 30 3 20 1
3 5
10 1 6 2 10 1
5 1 3 2 10 1 3 2 5 1
3 5
10 1 6 2 10 1
5 1 6 2 10 1 6 2 5 1
1 1
5000000 10
5000000 100

*/