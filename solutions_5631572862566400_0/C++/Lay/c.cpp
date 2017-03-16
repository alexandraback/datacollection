#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <cstdio>
#include <functional>
#include <set>
#include <sstream>
#include <map>
#include <queue>
#include <stack>

using namespace std;

bool is_valid(vector<int> &v,vector<int> &bff){
	
	for(int i=0;i<v.size();i++){
		int l=(i+1)%v.size();
		int r=i-1;
		if(r<0) r+=v.size();
		
		if( !(bff[v[i]]==v[l]) && !(bff[v[i]]==v[r]) ) return false;
	}
	
	return true;
	
}

int main()
{
		
    int T;
    cin>>T;
	
    for(int t=1;t<=T;t++){
		int n;
		cin>>n;

		vector<int> bff(n);
		for(int i=0;i<n;i++){
			cin>>bff[i];
			bff[i]--;
		}
		
		int res=0;
		int N=1<<n;
		for(int bit=1;bit<N;bit++){
			vector<int> v;
			for(int i=0;i<n;i++){
				if(bit&(1<<i)) v.push_back(i);
			}
			
			if(res>=v.size()) continue;
			
			do{
				
				if(is_valid(v,bff)){
					res=v.size();
					break;
				}
				
			}while(next_permutation(v.begin()+1,v.end()));
			
		}
		
		
		printf("Case #%d: %d\n",t,res);

		
    }
    
    return 0;
}