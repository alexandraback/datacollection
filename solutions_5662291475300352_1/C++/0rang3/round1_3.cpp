#include<iostream>
using namespace std;
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<vector>
#include<map>
#include<queue>
#include<algorithm>
#include<cmath>
#include<set>
#include<ctime>
#include<stack>
#include<list>
#include<cassert>  
typedef pair<int,int> pii;
#define rep(i,j,n) for(i=j;i<n;i++)
#define pb push_back
#define sz(a) a.size()
#define ff first
#define ss second 
#define lli long long int

int main() {
		
	ios::sync_with_stdio(false);
	
	//clock_t start = std::clock();
	freopen ("inp.txt","r",stdin);
	freopen ("out.txt","w",stdout);
	//cout << "Time: " << (std::clock() - start) / (double)(CLOCKS_PER_SEC / 1000) << " ms" << std::endl;
	
	
	double t,I,n;
	lli i,j=0,ans;
	cin>>t;
	double a[50],b[50],c[50];
	double A[50],B[50];
	//double t1,t2,spd1,spd2;
	rep(I,1,t+1){
		cin>>n;
		lli cnt = 0;
		ans = 1;
		j =0;
		rep(i,0,n){
			
			cin>>a[i]>>b[i]>>c[i];
			cnt += b[i];
			for(int q =0; q<b[i]; q++){
				A[j] = a[i];
				B[j++] = c[i]+q;
			}
			
		}
		ans = cnt;
		rep(i,0,cnt){
			//cout<<A[i]<<" "<<B[i]<<" hahaha"<<endl;
			lli cur_ans = 0;
			double spd = 360/(double)B[i];
			double time = (360-A[i])/(double)spd;
			rep(j,0,cnt){
				if(i == j)
					continue;
				double spd2 = 360/B[j];
				double time2 = (360-A[j])/spd2;
				
				if(time < time2)	cur_ans++;
				else{
					double rem = (time-time2);
					double cccnt = rem/B[j];
					cccnt = int(cccnt);
					cur_ans += int(cccnt);
				//	cout<<cccnt<<" hhhh"<<endl;
				}
			
			}
			if(ans > cur_ans)
				ans = cur_ans;
		}
		
		
		
		cout<<"Case #"<<I<<": "<<ans<<endl;
		
	}
	
	return 0;
}

