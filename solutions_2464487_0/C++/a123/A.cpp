#include<cstdio>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<map>
#include<sstream>
using namespace std;
int main(){
	int C;
	scanf("%d",&C);
	for(int Case=1; Case<=C; Case++){
		long long r,t,y;
		cin>>r>>t;
		y=(r<<1)+1;
		long long left=1,right=min((long long)sqrt(t>>1)+2,t/(y-2)+2),mid=(left+right)>>1,last=-1;
		while(mid!=last){
			last=mid;
			if(2*mid*mid<=t-(y-2)*mid)
				left=mid;
			else right=mid;
			mid=(left+right)>>1;
		}
		cout<<"Case #"<<Case<<": ";
		cout<<left<<endl;
	}
}

