#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

bool solve_sub(int N,long *S, long* left, long* right,int n_left, int n_right,
		int currp,long sum_left, long sum_right,int * r_left,int * r_right)
{
	long v=S[currp];
	if(sum_left==sum_right && n_left!=0){
		*r_left=n_left;
		*r_right=n_right;
		 return true;
	}
	if(sum_left+v==sum_right) {
		//cout<<"!l"<<sum_left<<" "<<v<<" "<<sum_right<<endl;
		*r_left=(n_left+1);
		*r_right=n_right;
		left[n_left]=v;
		return true;
	}
	if(sum_left==sum_right+v){
		//cout<<"!r"<<sum_left<<" "<<sum_right<<" "<<v<<endl;
		*r_left=n_left;
		*r_right=(n_right+1);
		right[n_right]=v;
		return true;
	}
	if(currp<N-1){
		if(solve_sub(N,S,left,right,n_left,n_right,currp+1,sum_left,sum_right,r_left,r_right)) return true;
		if(solve_sub(N,S,left,right,n_left+1,n_right,currp+1,sum_left+v,sum_right,r_left,r_right)){
			left[n_left]=v;
			return true;
		}
		if(solve_sub(N,S,left,right,n_left,n_right+1,currp+1,sum_left,sum_right+v,r_left,r_right)){
			right[n_right]=v;
			return true;
		}

	}
	return false;
}

bool solve(int N,long *S,long* left,long * right,int *r_left,int *r_right)
{
	return solve_sub(N,S,left,right,0,0,0,0,0,r_left,r_right);
}

int main(int argc,char** argv)
{
	ifstream inpf;
	inpf.open(argv[1]);
	string line;
	getline(inpf,line);
	int T;
	stringstream(line)>>T;
	for(int i=0;i<T;++i)
	{
		getline(inpf,line);
		int N;
		stringstream ss(line);
		ss>>N;
		long S[N];
		long left[N];
		long right[N];
		int r_left=0;
		int r_right=0;
		for(int j=0;j<N;++j)
			ss>>S[j];
		bool ret=solve(N,S,left,right,&r_left,&r_right);
		cout<<"Case #"<<i+1<<":"<<endl;
		if(!ret){
			cout<<"Impossible"<<endl;
		}else{
			for(int j=0;j<r_left;++j)
				cout<<left[j]<<" ";
			cout<<endl;
			for(int j=0;j<r_right;++j)
				cout<<right[j]<<" ";
			cout<<endl;
		}

	}
	return 0;
}
