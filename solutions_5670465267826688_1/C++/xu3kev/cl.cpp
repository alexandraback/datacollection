#include<iostream>
#include<string>
using namespace std;
int main(){
	/*
	1,i,j,k
	i,-1,k,-j
	j,-k,-1,i
	k,j,-i,-1

	1->0
	i->1
	j->2
	k->3
	-1->4
	-i->5
	-j->6
	-k->7
	*/

	int m[8][8]={{0,1,2,3,4,5,6,7},
	{1,4,3,6,5,0,7,2},
	{2,7,4,1,6,3,0,5},
	{3,2,5,4,7,6,1,0},
	{4,5,6,7,0,1,2,3}, 
    {5,0,7,2,1,4,3,6},
    {6,3,0,5,2,7,4,1},
    {7,6,1,0,3,2,5,4}};

	int T;
	cin>>T;
	long long int l;
	long long int x;
	
	string s;
	for(int cs=1;cs<=T;++cs){
		cin>>l>>x;
		cin>>s;

		if(x>8)
			x=(x-8)%4+8;
		cout<<"Case #"<<cs<<": ";
		int r=0;
		for(int i=0;i<l*x;++i){
			r=m[r][s[i%l]-'i'+1];
		}

		if(r != 4){
			cout<<"NO"<<endl;
			continue;
		}
		int id_i=l*x;
		r=0;
		for(int i=0;i<l*x;++i){
			r=m[r][s[i%l]-'i'+1];
			if(r == 1){
				id_i = i;
				break;
			}
		}
		r=0;
		int id_k=-1;
		for(int i=l*x-1;i>=0;--i){
			r=m[s[i%l]-'i'+1][r];
			if(r == 3){
				id_k = i;
				break;
			}
		}
		if(id_i<id_k){
			cout<<"YES"<<endl;
			r=0;
			for(int i=id_i;i>=0;--i){
				r=m[s[i%l]-'i'+1][r];
			}
			if(r != 1)
				cout<<"i !!!!!"<<endl;

			r=0;
			for(int i=id_i+1;i<id_k;++i){
				r=m[r][s[i%l]-'i'+1];
			}
			if(r != 2)
				cout<<"j !!!!!"<<endl;

			r=0;
			//for(int i=id_k;i<l*x;++i){
			//	r=m[r][s[i%l]-'i'+1];
			for(int i=l*x-1;i>=id_k;--i){
				r=m[s[i%l]-'i'+1][r];
			}
			if(r != 3)
				cout<<"k !!!!!"<<endl;
		}
		else{
			//cout<<id_i<<" "<<id_k<<" ";
			cout<<"NO"<<endl;
		}

	}



	return 0;

}
