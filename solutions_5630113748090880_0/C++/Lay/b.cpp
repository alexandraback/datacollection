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

int main()
{
		
    int T;
    cin>>T;
	
    for(int t=1;t<=T;t++){
		int n;
		cin>>n;
		
		int cnt[2501]={};
		for(int i=0;i<2*n-1;i++){
			int h;
			for(int j=0;j<n;j++){
				cin>>h;
				cnt[h]++;
			}
		}
		
		vector<int> ans;
		for(int i=0;i<2501;i++){
			if(cnt[i]%2) ans.push_back(i);
		}
		
		 printf("Case #%d:",t);
		 for(int i=0;i<n;i++) cout<<" "<<ans[i];
		 cout<<endl;
		
    }
    
    return 0;
}