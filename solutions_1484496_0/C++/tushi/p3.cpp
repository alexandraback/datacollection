#include<iostream>
#include<cstdio>
using namespace std;
#include<algorithm>
#include<string>
#include<cstring>
#include<cmath>
#include<map>
#include<vector>
#define max(a,b) (a)>(b)?(a):(b)
#define fi(i,a,b) for(i=a;i<=b;i++)
#define fir(i,a,b) for(i=a;i>=b;i--)

int main()
{
	int t,n,j,k;
	long long int arr[501],i,lim=1<<20,tmp, ans1, ans2, sum;
	map<long long int, vector<long long int> > m;
	vector<long long int> v;
	vector<long long int>::iterator iter;
	bool found;
	
	cin>>t;
	
	fi(k,1,t)
	{
		found = false;
		m.clear();
		cin>>n;
		
		fi(i,0,n-1)
		{
			cin>>arr[i];
		}
		
		lim = 1<<n;
		
		fi(i,1,lim)
		{
			//tmp = i;
			sum = 0;
			fi(j,0,19)
			{
				if(i & 1<<j)
				{
					sum += arr[j];
				}
			}
			
			//cout<<i<<" "<<sum<<'\n';
			
			if(m.find(sum) == m.end())
			{
				v.clear();
				v.push_back(i);
				m[sum] = v;
			}
			
			else
			{
				v = m[sum];
				
				for(iter=v.begin(); iter!=v.end(); iter++)
				{
					tmp = *iter;
					if(!(tmp&i))
					{
						ans1 = tmp;
						ans2 = i;
						found =true;
						break;
					}
				}
				
				if(!found)
				{
					v.push_back(i);
					m[sum] = v;
				}
			} // end of else
			
			if(found)
			break;
		} // end of loop for i
		
		cout<<"Case #"<<k<<":\n";
		
		if(found)
		{
			//cout<<"answer "<<ans1<<" "<<ans2<<'\n';
			fi(j,0,19)
			{
				if(ans1 & 1<<j)
				{
					cout<<arr[j]<<" ";
				}
			}
			cout<<'\n';
			
			fi(j,0,19)
			{
				if(ans2 & 1<<j)
				{
					cout<<arr[j]<<" ";
				}
			}
			cout<<'\n';
			
		}
		
		else
		{
			cout<<"Impossible\n";
		}
	} // end of loop t
	
	return(0);
}
