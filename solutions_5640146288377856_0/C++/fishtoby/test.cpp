#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	int nn,r=1,n,m,w,i,j,cnt;
	scanf("%d",&nn);
	while(nn--){
		cin>>n>>m>>w;
		cnt=0;
		if(n>1){
			for(i=0;m-i>=w;i+=w) cnt++;
			cnt*=(n-1);
		}
		for(i=0;1;i+=w){
			if(m-i>=2*w){
				cnt++;
			}
			else if(m-i>w){
				cnt+=w+1;
				break;
			}
			else if(m-i==w){
				cnt+=w;
				break;
			}
		}
		cout<<"Case #"<< r <<": "<< cnt <<endl;
		r++;
	}
	return 0;
}
