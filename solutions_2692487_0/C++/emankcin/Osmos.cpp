#include<iostream>
#include<algorithm>
const int size = 1000;
int num[size];
__int64 d[size];
__int64 now = 0;
int count1[size];
int nowcount = 0, ans = 0;
using namespace std;
int main(void)
{
	int T, A, n;
	int i, j, k;
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);

	cin>>T;

	for(i = 0; i<T; i++){
		cin>>A>>n;
		for(j = 0; j<n; j++){
			cin>>num[j];
		}
		sort(num, num + n);
		now = A;
		nowcount = 0;
		for(j = 0; j<n; j++){
			if(num[j] < now){
				now += num[j];
				d[j] = now;
				count1[j] = nowcount;
			}
			else{
				if(num[j] == 1 || now <= 1){
					d[j] = now;
					nowcount++;
					count1[j] = nowcount;
				}
				else{
					while(num[j] >= now){
						now += now - 1;
						nowcount++;
					}
					now += num[j];
					d[j] = now;
					count1[j] = nowcount;
				}
			}
		}
		ans = nowcount;
		nowcount = 0;
		now = A;
		for(j = 0; j<n; j++){
			if(nowcount + 1 >= count1[j] && num[j] >= now){
				nowcount = count1[j];
				now = d[j];
			}
			else{
				if(num[j] < now){
					now += num[j];
				}
				else{
					nowcount++;
				}
			}
		}
		if(ans > nowcount)ans = nowcount;
		cout<<"Case #" <<i + 1<<": "<<ans<<endl;
		for(j = 0; j<size; j++){
			num[j] = d[j] = count1[j] = 0;
		}
	}


	return 0;
}