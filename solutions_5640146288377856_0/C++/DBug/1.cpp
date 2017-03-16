#include<bits/stdc++.h>

//Author DBug<Deepak Sharma>

#define forn(i,n) for(long int i=0;i<n;i++)
#define fora(i,a,b) for(long int i=a;i<b;i++)
#define vi(v,n) int t;for(int i=0;i<n;i++){cin>>t;v.push_back(t);}
#define vo(v,n) for(int i=0;i<n;i++){cout<<v[i]<<",";}cout<<endl;
#define o(a) cout<<"Test:"<<a<<endl;

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	ifstream fin;
	fin.open("input.in");
	ofstream fout;
	fout.open("output.txt");
	int t,r,c,w,res;
	fin>>t;
	forn(it,t){
		fin>>r>>c>>w;
		if(c%w==0){
			res = (c/w)+(w-1);
		}
		else{
			res=(c/w)+(w);
		}
		if(it==0){
			fout<<"Case #"<<it+1<<": "<<res;
		}
		else{
			fout<<endl<<"Case #"<<it+1<<": "<<res;
		}
	}

}