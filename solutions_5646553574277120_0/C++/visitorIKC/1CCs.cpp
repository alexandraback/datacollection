#include <iostream>
#include <cstring>

using namespace std;
int main(){
//	ios::sync_with_stdio(0);
	int tc;cin>>tc;
	int ij=0;
	while(tc-->0){
		ij++;
		int c,d,v;cin>>c>>d>>v;
		int coin[d];
		bool in[31];
		memset(in,0,sizeof(in));
		int ans=5;
		for(int i=0;i<d;i++){
			cin>>coin[i];
			in[coin[i]]=true;
		}
		for(int i=0;i<=v;i++){
			if(in[i])continue;
			for(int j=0;j<=v;j++){
				if(in[j])continue;
				if(i==j&&j!=0)continue;
				for(int k=0;k<=v;k++){
					if(in[k])continue;
					if(k!=0&&(i==k||j==k))continue;
					for(int l=0;l<=v;l++){
						if(in[l])continue;
						if(l!=0&&(i==l||j==l||k==l))continue;
//						cout<<i<<' '<<j<<' '<<k<<' '<<l<<endl;
						bool can[v+1];
						memset(can,0,sizeof(can));
						can[0]=true;
						for(int m=0;m<d;m++){
							for(int n=v;n>=0;n--){
								if((n+coin[m]<=v)&&(can[n]==true))
									can[n+coin[m]]=true;
							}
//							cout<<can[4]<<endl;
						}
						for(int n=v;n>=0;n--){
							if((n+i<=v)&&(can[n]==true))
								can[n+i]=true;
						}
						for(int n=v;n>=0;n--){
							if((n+j<=v)&&(can[n]==true))
								can[n+j]=true;
						}
						for(int n=v;n>=0;n--){
							if((n+k<=v)&&(can[n]==true))
								can[n+k]=true;
						}
						for(int n=v;n>=0;n--){
							if((n+l<=v)&&(can[n]==true))
								can[n+l]=true;
						}
						bool tof=true;
						for(int n=0;n<=v;n++){
							if(can[n]==false)tof=false;
//							else cout<<n<<' ';
						}
//						cout<<endl;
						if(tof){
							int am=0;
							if(i!=0)am++;
							if(j!=0)am++;
							if(k!=0)am++;
							if(l!=0)am++;
							ans=min(ans,am);
						}
					}
				}
			}
		}
		cout<<"Case #"<<ij<<": ";
		cout<<ans<<endl;
	}
	return 0;
}
