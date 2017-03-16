#include <iostream>
#include<string>
#include<vector>
#include<sstream>
#include<fstream>
#include<algorithm>
#include<cmath>
#include<set>
#include<map>
#include<stack>
#include<queue>
#include<cstdlib>
#include <iomanip>
using namespace std;
class node{public:
	int m_id;
	vector<node*> m_to;
};
const int M=1000;
int main() {
	int ts;cin>>ts;
	for(int t=1;t<=ts;t++){
		int N;cin>>N;
		vector<vector<int> > c(N);
		for(int k=0;k<N;k++){
			for(int h=0;h<N;h++)c[k].push_back(0);
			int m;cin>>m;
			for(int h=0;h<m;h++){
				int v;cin>>v;v--;
				c[k][v]=1;
			}
		}
		bool yn=false;
		for(int k=0;k<N;k++){
			for(int i=0;i<N;i++){
				for(int j=0;j<N;j++){
					int cikj=min(c[i][k],c[k][j]);// if(cikm>M)cikm=M;
					if(c[i][j] && cikj){yn=true;goto END;}
					c[i][j]=max(c[i][j],cikj);
				}					
			}
		}
		END:
		cout<<"Case #"<<t<<": "<<(yn?"Yes":"No")<<endl;
	}
	return 0;
}
/*
		vector<node> ns(N);
		for(int k=0;k<N;k++){
			ns[k].m_id=k;
			int m;cin>>m;
			for(int h=0;h<m;h++){
				int to;cin>>to;to--;
				ns[k].m_to.push_back(&ns[to]);
			}
		}
*/
