#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <time.h>
#include <stdlib.h>

using namespace std;

int i,j,k,l,m,n,t,r,e,cur;
int mult[7];

int a[20][3];
int b[3];

void rec(int pos, int last){
	if (pos==n){
		for (int ii=0;ii<n;ii++){
			a[cur][ii]=b[ii];
			//cout<<b[ii];
		}
		cur++;
		//cout<<endl;
		return;	
	}
	//cout<<pos<<" aaaaaa       "<<cur_e<<"\n";
	int i;	
	for (i=last;i<=m;i++){
		b[pos]=i;
		rec(pos+1,i);	
	}
}

int main(){
	freopen("output.txt","w",stdout);
	cin>>t;
	for (i=1;i<=t;i++){
		cin>>r>>n>>m>>k;
		cout<<"Case #"<<i<<":\n";
		
		rec(0,2);
		for (j=0;j<r;j++){
			for (int ii=0;ii<k;ii++){		
				cin>>mult[ii];				
			}
			srand(time(NULL));	
			vector <int> indexes;	
			//cout<<cur<<endl;
			for (int jjj=0;jjj<cur;jjj++){
				int dd = 1;
				for(int ii=0;ii<k;ii++){
					int d = 0;			
					for (int jj=0;jj<(1<<n);jj++){
						int mm=1;
						for (int pp = 0; pp<n; pp++){
							if ((jj&(1<<pp))>0) mm *= a[jjj][pp];
						}
						//cout<<mm<<endl;
						if (mm==mult[ii]) {d=1;break;}
					}
					if (!d) {dd=0;break;}
				}
				if (dd) indexes.push_back(jjj);	
			}
			//for (int ii=0;ii<indexes.size();ii++){
			//	cout<<indexes[ii]<<endl;
			//}
			int index = indexes[rand()%(indexes.size())];
			for (int jjj=0;jjj<n;jjj++){
				cout<<a[index][jjj];
			}
			cout<<"\n";
		}
	}
	return 0;
}
