#include <bits/stdc++.h>
#define MAXN 1000000
#define long long ll
using namespace std;
int th;
int a[2000],b[2000],child[2000],loai[2000];
bool xet[2000],xet2[2000];
int n,cc;
void openFile(){
	switch(th){
		case 0:
			freopen("inp","r",stdin);
  			freopen("out","w",stdout);
  			break;
		case 1: 
			freopen("C-small-attempt0.in","r",stdin);
  			freopen("C-small-attempt0.ou","w",stdout);
  			break;
  		case 2:
  			freopen("C-large.in","r",stdin);
  			freopen("C-large.ou","w",stdout);
  			break;
	}
  	
}
int find(int i){
	int rr=0;
	while(!xet[i]){
		rr++;
		xet[i]=true;
		i=b[i];
	}
	return rr;
}
void mainWork(){
	int test;	
	cin>>test;
	for(int qq=1;qq<=test;qq++){
		cout<<"Case #"<<qq<<": ";
		cin>>n;
		int res=0;
		for(int i=1;i<=n;i++){
			xet[i]=false;a[i]=0;
		}
		for(int i=1;i<=n;i++){
			cin>>b[i];
			a[b[i]]++;
		}
		bool ok=true;
		cc=0;
		while (ok){
			ok=false;
			for(int i=1;i<=n;i++){
				if(a[i]==0 && !xet[i]){
					cc++;
					loai[cc]=i;
					a[b[i]]--;
					xet[i]=true;
					ok=true;
				}
			}
		}
		//cuu vot
		for(int i=1;i<=n;i++){
			if(!xet[i]){//chua bi loai
				if(b[b[i]]==i) continue;//chua xet loai qua lai
				res=max(res,find(i));
			}
		}
		//tinh so con cua cac nut trong mang loai
		for(int i=1;i<=n;i++){
			xet2[i]=false;
			a[i]=0;	
			child[i]=0;
		}
		for(int i=1;i<=cc;i++)a[b[loai[i]]]++;
		ok=true;
		while (ok){
			ok=false;
			for(int i=1;i<=cc;i++){
				int x=loai[i];
				if(!xet2[x] && a[x]==0){
					xet2[x]=true;
					child[x]+=1;
					child[b[x]]=max(child[b[x]],child[x]);
					a[b[x]]--;
					ok=true;
				}
			}
		}
		/////////////////////////////
		int res2=0;
		for(int i=1;i<=n;i++)
		if(!xet[i]){//cac cap doi con lai
			res2+=2;
			int x=i,y=b[i];
			xet[x]=true;xet[y]=true;
			//tim noi vao x
			int rr=0;
			for(int j=1;j<=cc;j++){
				int xx=loai[j];
				if(b[xx]==x ) rr=max(rr,child[xx]);
			}
			res2+=rr;
			//tim noi vao y
			rr=0;
			for(int j=1;j<=cc;j++){
				int xx=loai[j];
				if(b[xx]==y ) rr=max(rr,child[xx]);
			}
			res2+=rr;
		}
		cout<<max(res,res2)<<endl;
	}
}
int main(){
	cin>>th;
	openFile();
	mainWork();
	return 0;
}
