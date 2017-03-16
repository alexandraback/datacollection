#include<iostream>
#include<cstring>

using namespace std;

int s[1000][1000];
int main(){
	int t;
	cin>>t;
	for(int i=1;i<=t;i++){
		int n;
		cin>>n;
		memset(s,255,sizeof s);
		for(int j=0;j<n;j++){
			int m;
			cin>>m;
			for(int k=0;k<m;k++){
				int a;
				cin>>a;
				s[j][a-1]=j;
			}
		}
		bool f=false;
		try{
		for(int j=0;j<n;j++)
			for(int k=0;k<n;k++)
				for(int l=0;l<n;l++)
					if(s[k][j]!=-1&&s[j][l]!=-1)
						if(s[k][l]!=-1)
							throw 0;
						else
							s[k][l]=j;
		}catch(int _){f=true;}
		cout<<"Case #"<<i<<": "<<(f?"Yes":"No")<<endl;
	}
	return 0;
}
