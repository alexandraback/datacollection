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
	
	
	double t,I,n,ans;
	int i;
	cin>>t;
	double a[50],b[50],c[50];
	double t1,t2,spd1,spd2;
	rep(I,1,t+1){
		cin>>n;
		ans = 1;
		rep(i,0,n){
			cin>>a[i]>>b[i]>>c[i];
		}
		
		
		if((n == 1) && (b[0] == 1)){
				ans = 0;
			}
		else{
			//cout<<n<<endl;
			if(n == 1){
				spd1 = 360/c[0];
				spd2 = 360/(c[0]+1);
				t1 = (360-a[0])/(spd1);
				t2 = (360-a[0])/(spd2);
				//cout<<t1<<" "<<t2<<" "<<spd1<<" "<<spd2<<" ";
				t1 += 360/spd1;
				//cout<<t1<<endl;
				if(t1 > t2)	
					ans = 0;
				
			}
			else{
				spd1 = 360/c[0];
				t1 = (360-a[0])/(spd1);
				
				spd2 = 360/c[1];
				t2 = (360-a[1])/(spd2);
				//cout<<t1<<" "<<t2<<" "<<spd1<<" "<<spd2<<" "<<endl;
				if((t1+360/spd1 > t2) && (t1<=t2))
					ans = 0;
				if((t2+360/spd2 > t1) && (t1>=t2))
					ans = 0;
				
			}
			
		}
		cout<<"Case #"<<I<<": "<<ans<<endl;
		
	}
	
	return 0;
}

