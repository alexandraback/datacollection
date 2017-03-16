#include <iostream>
#include <set>
using namespace std;
int n,m,a[100][100]={};			//n,m i,j  tate,yoko
bool row[100]={},col[100]={};			//1->ignorable
int rowsum,colsum;
int num[100]={};				//h kosuu
bool allx(int x,int muki,int basyo){
	bool flag=true;
	if(muki==1){			//tate
		for(int i=0;i<n;i++){
			if(row[i]) continue;
			if(a[i][basyo]!=x){
				flag=false;
				break;
			}
		}
		if(flag){
			col[basyo]=true;
			num[x]-=rowsum;
			colsum--;
//			cout << x << " tate "<< basyo << " " << num[x] << " " << rowsum << endl;
			return true;
		}
		else return false;
	}
	if(muki==2){			//yoko
		for(int i=0;i<m;i++){
			if(col[i]) continue;
			if(a[basyo][i]!=x){
				flag=false;
				break;
			}
		}
		if(flag){
			row[basyo]=true;
			num[x]-=colsum;
			rowsum--;
//			cout << x << " yoko "<< basyo << " " << num[x] << " " << colsum << endl;
			return true;
		}
		else return false;
	}
}
int main(){
	int t;
	cin >> t;
	for(int i=1;i<=t;i++){
		for(int j=0;j<100;j++){
			num[j]=0;
			row[j]=false;
			col[j]=false;
		}
		set<int> st;
		cin >> n >> m;
		rowsum=n;
		colsum=m;
		for(int j=0;j<n;j++){
			for(int k=0;k<m;k++){
				cin >> a[j][k];
				a[j][k]--;
				st.insert(a[j][k]);
				num[a[j][k]]++;
			}
		}
		int x=(*(st.begin()));
		while(true){
			bool renew=false;
			for(int j=0;j<n;j++){
				if(row[j]) continue;
				renew=renew || allx(x,2,j);
			}
			for(int j=0;j<m;j++){
				if(col[j]) continue;
				renew=renew || allx(x,1,j);
			}
			if(num[x]==0){
				if(st.upper_bound(x)==st.end()){
					cout << "Case #" << i << ": YES" << endl;
					break;
				}
				x=( *(st.upper_bound(x)) );
			}
			if(!renew){
				cout << "Case #" << i << ": NO" << endl;
				break;
			}
		}
	}
	return 0;
}