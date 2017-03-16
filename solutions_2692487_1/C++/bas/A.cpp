#include<iostream>
#include<vector>
#include<string>
#define big 1000000000
typedef long long ll;

using namespace std;
ll A, N;
vector<int> v;

ll f(ll A, int si , int fi){
    if(si>fi) return 0;
    if(v[si]<A){
        return f(A+v[si], si+1, fi);
    }else{
            ll do_nthg = fi-si+1;
        ll add_one = big;
        if(A>1){
            add_one = f(A*2-1, si, fi)+1;
        }
        return min(do_nthg, add_one);
    }
}

int main(){
	int C;
	cin>>C; 
	for(int j=0; j<C; j++){
		cin>>A>>N;
        v.resize(N);
		for(int i=0; i<N; i++){cin>>v[i];}
        sort(v.begin(), v.end());
		long long  res=f(A, 0, N-1);
		cout<<"Case #"<<j+1<<": " <<res<<"\n";
	}
	
}
