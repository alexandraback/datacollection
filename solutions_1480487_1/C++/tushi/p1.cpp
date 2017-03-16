#include<iostream>
#include<cstdio>
using namespace std;
#include<algorithm>
#include<string>
#include<cstring>
#include<cmath>
#define max(a,b) (a)>(b)?(a):(b)
#define fi(i,a,b) for(i=a;i<=b;i++)
#define fir(i,a,b) for(i=a;i>=b;i--)

double func(int ind, pair<int, int> p[], int n, int tot)
{
	double ans=100.000000, lo = 0.000000, hi = 100.000000, mid, oth, score, other;
	double diff, req;
	int i;
	pair<int, int> tmp;
	
	tmp = p[ind];
	int flt;
	while(fabs(hi-lo)>=1e-6)
	{
		other = 0;
		mid = (lo+hi)/2;
		
		oth = 100 - mid;
		
		score = tmp.first + double(tot)*mid/100;
		
		fi(i,0,n-1)
		{
			if(i!=ind)
			{
				if(double(p[i].first) < score)
				{
					diff = score - double(p[i].first);
					//cout<<diff<<'\n';
					
					req = (diff  * 100)/ double(tot);
					//cout<<req<<'\n';
					other += req;
					//cout<<other<<'\n';
					//cin>>flt;
				}
			}
		}
		
		//cout<<tmp.first<<" "<<mid<<" "<<score<<" "<<other<<'\n';
		//cin>>flt;
		if(other >= oth)
		{
			//cout<<tmp.first<<" "<<mid<<'\n';
			hi = mid;
			ans= mid;
		}
		
		else
		{
			lo = mid;
		}
	}
	
	//cout<<"\n\n"<<tmp.first<<" "<<ans<<'\n';
	//cin>>flt;
	
	if(ans<=1e-6)
	ans = 0;
	
	return ans;
}

int main()
{
	int t,i,k,n,index,num, total;
	double tmp_ans, ans[1001];
	pair <int, int> arr[1001];
	
	cin>>t;
	cout.precision(6);
	cout.setf(ios::fixed);
	fi(k,1,t)
	{
		total=0;
		cin>>n;
		
		fi(i,0,n-1)
		{
			cin>>num;
			arr[i] = make_pair(num,i);
			total += num;
		}
		
		sort(arr, arr+n);
		
		fi(i,0,n-1)
		{
			//tmp = arr[i];
			tmp_ans = func(i,arr,n,total);
			index = arr[i].second;
			ans[index] = tmp_ans;
			//cout<<"\n"<<index<<" "<<tmp_ans<<"\n";
		}
		
		cout<<"Case #"<<k<<": ";
		
		fi(i,0,n-1)
		cout<<ans[i]<<" ";
		
		cout<<'\n';
	}
	
	
	return(0);
}
