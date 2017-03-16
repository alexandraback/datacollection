#include<iostream>
#include<cstring>
using namespace std;
typedef long long ll;
int a[100][100],b[70];

int main(){
//	freopen("b.in","r",stdin);
//	freopen("b.out","w",stdout);
    int t;
    cin>>t;
    for(int ca=1;ca<=t;ca++){
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        ll n,m;
        cin>>n>>m;
        cout<<"Case #"<<ca<<": ";
        if(m>( 1 << (n-2))){
            cout<<"IMPOSSIBLE"<<endl;
        }else{
        	cout<<"POSSIBLE"<<endl;
            ll tmp=m,k=0;
            while(tmp){
                b[k++]=tmp%2;
                tmp/=2;
            }
            for(int i=1;i<n;i++){
                for(int j=i+1;j<n;j++){
                    a[i][j]=1;
                }
            }
            if(m==(1<<(n-2))){
            	for(int i=1;i<n;i++){
            		a[i][n]=1;
				}
			}else{
				for(int i=k-1;i>=0;i--){
              	 	if(b[i]){
                    	a[i+2][n]=1;
             	   }
         	   }
			}
            for(int i=1;i<=n;i++){
                for(int j=1;j<=n;j++){
                    cout<<a[i][j];
                }
                cout<<endl;
            }
        }
        
    }
    return 0;
}
