#include<iostream>
#include<vector>
#include<string>

using namespace std;


int main(){
	int C, N;
	vector<int> a = vector<int>(1001);
	vector<int> b = vector<int>(1001);
	vector<int> lev = vector<int>(1001);
	
	cin>>C; 
	for(int j=0; j<C; j++){
		cin>>N;
		for(int i=0; i<N; i++){cin>>a[i]>>b[i]; lev[i]=0;}
		int res=0;
		int total = 0;
		int level2s=0;
			bool found =true;
		while(level2s<N && found){
			while(found){
				found = false;
			for(int i=0; i<N;i++){
				if(lev[i]==2)continue;
				if(b[i]<=total){
					found=true;	
					total+=2-lev[i];
					res++;
					lev[i]=2;
					level2s++;
				}
			}
			}
			
			found = false;
			int besttwo=-1; int ind=0;
			for(int i=0; i<N; i++){
				if(lev[i]>0)continue;
				if(a[i]<=total && b[i]>besttwo){
					found=true;
					besttwo=b[i];
					ind=i;
				}

			}
			if(found){
					lev[ind]=1;
					total++;
					res++;

			}
		}
		if(level2s==N)
		cout<<"Case #"<<j+1<<": " <<res<<"\n";
		else
		cout<<"Case #"<<j+1<<": " <<"Too Bad"<<"\n";
	}
	
}
