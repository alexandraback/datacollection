#include <cstdio>
#include <vector>
using namespace std;


const long long th=10000000;
typedef long long int lld;

struct bigint {

	int sign;
	vector<long long> q;
	bigint(long long m =0) {
		if(m>=0) sign=1;
		else m*=(sign=-1);
		for(;m;m/=th) q.push_back(m%th);
	}

};

inline int _compare(bigint &X, bigint &Y) {
	if(X.sign!=Y.sign) return X.sign-Y.sign;
	vector<long long> &A=X.q, &B=Y.q;
	if(A.size() > B.size()) return X.sign;
	if(A.size() < B.size()) return -X.sign;
	for(int i=0; i<A.size(); ++i) {
		if(A[i]>B[i]) return X.sign;
		if(A[i] < B[i]) return -X.sign;
	}
	return 0;
}

bool operator >(bigint &X, bigint&Y) { return _compare(X, Y)>0; }

bigint operator + (bigint &X, bigint &Y) {
	bigint temp;
	vector <long long> &C = temp.q, &A=X.q, &B=Y.q;
	C.resize(A.size()>B.size()?A.size()+1:B.size()+1, 0);
	if(X.sign!=Y.sign) {
		temp.sign=X.sign;
		for(int i=0; i<C.size(); ++i)
			C[i]=(i<A.size()? A[i]:0)-(i<B.size()?B[i]:0);
		while(C.size()>1 && !C.back()) C.pop_back();
		if(C.back() <0) {
			temp.sign*=-1;
			for(int i=0; i<C.size(); ++i) C[i]*=-1;
		}
		for(int i=0; i<C.size()-1; ++i) C[i+1]+=C[i]+=th, C[i+1]--;
	} else {
		temp.sign=X.sign;
		for(int i=0; i<C.size(); ++i) C[i]=(i<A.size()?A[i]:0)+(i<B.size()?B[i]:0);
		for(int i=0; i<C.size()-1; ++i) C[i+1]+=C[i]/th, C[i]%=th;
	}

	while(C.size()>1 && !C.back()) C.pop_back();
	if(C.size() ==1 && C[0]==0 && temp.sign<0) temp.sign=1;
	return temp;
}

bigint operator * (bigint &X, bigint &Y) {

	if((X.q.size()==1 && !X.q[0]) || (Y.q.size()==1 && !Y.q[0])) return bigint(0);
	bigint temp; vector <long long> &C=temp.q, &A=X.q, &B=Y.q;
	temp.sign=X.sign*Y.sign;
	C.resize(A.size()+B.size(),0);
	for(int i=0; i<A.size(); ++i) for(int j=0; j<B.size(); ++j)
		C[i+j]+=A[i]*B[j];
	for(int i=0; i<C.size()-1; ++i) C[i+1]+=C[i]/th, C[i]%=th;

	while(C.size()>1 && !C.back()) C.pop_back();
	return temp;

}
bigint operator - (bigint &X) { bigint t = X; t.sign*=-1; return t; }
bigint operator - (bigint &X, bigint Y) { Y.sign*=-1; return X+Y; }

bigint r, paint;

bigint process() {

	bigint two=2, one=1, three=3;
	for(bigint res=2; ;res=res+one) {
		bigint temp=two*res*res+(two*r-one)*res;
		if(temp>paint) return res-one;
	}

}

int main() {

	int casen;

	scanf("%d", &casen);
	for(int t=0; t<casen; ++t) {

		long long int inp1, inp2;
		scanf("%lld %lld", &inp1, &inp2);
		r=inp1, paint=inp2;

		printf("Case #%d: ", t+1);
		bigint res=process();

		for(int i=0; i<res.q.size(); ++i) {
			printf("%lld", res.q[i]);
		}
		printf("\n");

	}

	return 0;

}