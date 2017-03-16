#include <bits/stdc++.h>
using namespace std;

#include <fstream>

#define N 10005
#define ll long long

char A[N];
int B[N];

int multiply(int x, int y){
	int tot = x * y;
	int ans = 1;
	if(tot < 0)	ans = -1;

	x = abs(x), y = abs(y);

	if(x == 1)	return ans * y;
	else if(x == 2){
		if(y == 1)	return ans * x;
		else if(y == 2)	return ans * -1;
		else if(y == 3)	return ans * 4;
		else return ans * -1 * 3;
	}
	else if(x == 3){
		if(y == 1)	return ans * x;
		else if(y == 2)	return ans * -1 * 4;
		else if(y == 3)	return ans * -1;
		else return ans * 2;
	}
	else if(x == 4){
		if(y == 1)	return ans * x;
		else if(y == 2)	return ans * 3;
		else if(y == 3)	return ans * -1 * 2;
		else return ans * -1;
	}
}

int main(){

	ifstream cin("C-small-attempt1.in");
	ofstream cout("upload.out");

	int t, L, prefix, suffix, pre, intermid;
	ll x, pre_cycle, suff_cycle;

	cin>>t;

	for(int big = 1; big <= t; big++){

		prefix = -1, suffix = -1;

		bool ok = false;

		cin>>L>>x;
		cin>>A;

		pre = 1;

		for(int i = 0; i < L; i++){
			if(A[i] == 'i')	B[i] = 2;
			else if(A[i] == 'j')	B[i] = 3;
			else B[i] = 4;
		}

		//find best prefix, find best suffix

		pre = 1;
		for(int i = 0; i < min(x, (ll)4); i++){
			for(int j = 0; j < L; j++){
				pre = multiply(pre, B[j]);
				if(pre == 2){
					prefix = j;
					pre_cycle = i;
					goto end1;
				}
			}
		}
		end1:;

		pre = 1;
		for(int i = 0; i < min(x, (ll)4); i++){
			for(int j = L - 1; j >= 0; j--){
				pre = multiply(B[j], pre);
				if(pre == 4){
					suffix = j;
					suff_cycle = x - i - 1;
					goto end2;
				}
			}
		}
		end2:;
		
		if(prefix == -1 || suffix == -1)	goto ans;

		intermid = 1, pre = 1;

		if(x >= 8){
			x -= (pre_cycle + 1 + x - suff_cycle);
			x %= 4;
			for(int i = 0; i < x; i++)
				for(int j = 0; j < L; j++)	intermid = multiply(intermid, B[j]);
		}
		else{
			for(int i = pre_cycle + 1; i < suff_cycle; i++){
				for(int j = 0; j < L; j++)	intermid = multiply(intermid, B[j]);
			}	
		}

		if(pre_cycle == suff_cycle){
			for(int i = prefix + 1; i < suffix; i++)	pre = multiply(pre, B[i]);
		}	
		else{
			for(int i = prefix + 1; i < L; i++)	pre = multiply(pre, B[i]);
			pre = multiply(pre, intermid);
			for(int i = 0; i < suffix; i++)	pre = multiply(pre, B[i]);	
		}	
	
		if(pre == 3)	ok = true;
		ans:;
		cout<<"Case #"<<big<<": ";
		if(ok)	cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	return 0;
}