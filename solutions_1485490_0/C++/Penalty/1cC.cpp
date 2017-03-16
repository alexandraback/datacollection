#include<iostream>
#include<string>
#include<sstream>
#include<vector>
#include<map>
#include<cstdio>
#include<algorithm>
using namespace std;

int main()
{
	int n;
	cin>>n;
	for(int i1=1;i1<=n;i1++) {
	        unsigned long long int x,y;
	        cin>>x>>y;
	        vector<unsigned long long int> v(x+2,0),q(x,0),w(y,0),p(x,0),e(y,0);
	        vector< vector<unsigned long long int> > vov(y+2,v);
	        for(int i=0;i<(x);i++) cin>>q[i]>>p[i];
	        for(int i=0;i<(y);i++) cin>>w[i]>>e[i];
	        /*for(int i=1;i<y+2;i++){
	                for(int j=1;j<x+2;j++){
	                        cout<<vov[i][j]<<"  ";
	                }
	                cout<<endl;
	        }*/
	        for(int i=1;i<y+1;i++){
	                for(int j=1;j<x+1;j++){
	                        if(e[i-1]==p[j-1]) {
	                                unsigned long long int z=max(vov[i-1][j],vov[i][j-1]);
	                                if(q[j-1] > w[i-1] && q[j-1] > 0 && w[i-1] > 0) {
	                                        z += (q[j-1]-w[i-1]);
	                                        
	                                        q[j-1] -= w[i-1];
	                                        w[i-1]=0;
	                               }else if(q[j-1] > 0 && w[i-1] > 0) {
	                                        z += q[j-1];
	                                        
	                                        w[i-1] -= q[j-1];
	                                        q[j-1]=0;
	                               }
	                                vov[i][j]=z;
	                        }else {
	                                vov[i][j]=max(vov[i-1][j],vov[i][j-1]);
	                        }
	                }
	             //   cout<<endl;
	        }
	/*        for(int i=1;i<y+2;i++){
	                for(int j=1;j<x+2;j++){
	                        cout<<vov[i][j]<<"  ";
	                }
	                cout<<endl;
	        }*/
	        unsigned long long int ans=vov[y][x];
		cout<<"Case #"<<i1<<": "<<ans<<endl;
	}
	return 0;
}
