#include<iostream>
#include<fstream>
#include<cstdio>
using namespace std;
int ch[101][101];
int main()
{
    FILE *fp,*fp_;
    freopen_s(&fp,"data.in","r",stdin);
    freopen_s(&fp_,"data.out","w",stdout);
	int T,N,M;
    cin>>T;
    for(int k=0;k<T;k++){
		cin>>N>>M;
		for(int i=0;i<N;i++)
			for(int j=0;j<M;j++)
				cin>>ch[i][j];
		bool _break;
		for(int i=0;i<N;i++){
			_break=false;
			for(int j=0;j<M;j++){
				bool x_break=false,y_break=false;
				for(int r=0;r<N;r++)
					if(ch[r][j]>ch[i][j])
						x_break=true;
				for(int r=0;r<M;r++)
					if(ch[i][r]>ch[i][j])
						y_break=true;
				if(x_break&&y_break){
					_break=true;
					break;
				}
			}
			if(_break){
				cout<<"Case #"<<k+1<<": NO"<<endl;
				break;
			}
		}
		if(!_break){
			cout<<"Case #"<<k+1<<": YES"<<endl;
		}
    }
    fcloseall();
    return 0;
}