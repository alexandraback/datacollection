#include<iostream>
#include<string>
using namespace std;

int absdf(int x,int y){
	return max(x-y,y-x);
}

void solve(int q){
	string C[2];
	int c[2][18],f=0;//1->C[0]が大
	cin>>C[0]>>C[1];
	int n=C[0].size();
	for(int k=0;k<2;++k){
		string::iterator it=C[k].begin();
		for(int i=0;i<n;++i){
			if(*it=='?'){
				c[k][i]=-1;
			}else{
				c[k][i]=((int)*it)-48;
			}
			++it;
		}
	}
	//C[0]を最初に最小化
	for(int i=0;i<n;++i){
		if(f==1){
			if(c[0][i]<0){
				c[0][i]=0;
			}
			if(c[1][i]<0){
				c[1][i]=9;
			}
		}else if(f==2){
			if(c[0][i]<0){
				c[0][i]=9;
			}
			if(c[1][i]<0){
				c[1][i]=0;
			}
		}else if(c[0][i]>c[1][i]&&c[1][i]>=0){
			f=1;
		}else if(c[1][i]>c[0][i]&&c[0][i]>=0){
			f=2;
		}else if(c[0][i]<0&&c[1][i]<0){
			if(i==n-1){
				c[0][i]=0;
				c[1][i]=0;
			}else if(c[0][i+1]>=0&&c[1][i+1]>=0){
				if(absdf(c[0][i+1],c[1][i+1])<5){
					c[0][i]=0;
					c[1][i]=0;
				}else if(c[0][i+1]-c[1][i+1]>5){
					c[0][i]=0;
					c[1][i]=1;
				}else if(c[0][i+1]-c[1][i+1]<-5){
					c[0][i]=1;
					c[1][i]=0;
				}else{
					int c0=0,c1=0,j=i+1;
					while(true){
						if(c0!=c1){
							break;
						}
						if(j==n-1){
							break;
						}
						++j;
						c0*=10;
						c1*=10;
						c0+=c[0][j];
						c1+=c[1][j];
					}
					if(c0==c1){
						if(c[0][i+1]<c[1][i+1]){
							c[0][i]=0;
							c[1][i]=0;
						}else{
							c[0][i]=0;
							c[1][i]=1;
						}
					}else if(c0<c1){
						if(c[0][i+1]<c[1][i+1]){
							c[0][i]=1;
							c[1][i]=0;
						}else{
							c[0][i]=0;
							c[1][i]=0;
						}
					}else{
						if(c[0][i+1]<c[1][i+1]){
							c[0][i]=0;
							c[1][i]=0;
						}else{
							c[0][i]=0;
							c[1][i]=1;
						}
					}
				}
			}else{
				c[0][i]=0;
				c[1][i]=0;
			}

		}else if(c[0][i]<0){
			if(i==n-1){
				c[0][i]=c[1][i];
			}else if(c[0][i+1]>=0&&c[1][i+1]>=0){
				if(absdf(c[0][i+1],c[1][i+1])<5){
					c[0][i]=c[1][i];
				}else if(c[0][i+1]-c[1][i+1]>5){
					c[0][i]=max(0,c[1][i]-1);
				}else if(c[0][i+1]-c[1][i+1]<-5){
					c[0][i]=min(9,c[1][i]+1);
				}else{
					int c0=0,c1=0,j=i+1;
					while(true){
						if(c0!=c1){
							break;
						}
						if(j==n-1){
							break;
						}
						++j;
						if(c[0][j]<0||c[1][j]<0){
							break;
						}
						c0*=10;
						c1*=10;
						c0+=c[0][j];
						c1+=c[1][j];
					}
					if(c0==c1){
						if(c[0][i+1]<c[1][i+1]){
							c[0][i]=c[1][i];
						}else{
							c[0][i]=max(0,c[1][i]-1);
						}
					}else if(c0<c1){
						if(c[0][i+1]<c[1][i+1]){
							c[0][i]=min(c[1][i]+1,9);
						}else{
							c[0][i]=c[1][i];
						}
					}else{
						if(c[0][i+1]<c[1][i+1]){
							c[0][i]=c[1][i];
						}else{
							c[0][i]=max(c[1][i]-1,0);
						}
					}
				}
			}else{
				c[0][i]=c[1][i];
			}
		}else if(c[1][i]<0){
			if(i==n-1){
				c[1][i]=c[0][i];
			}else if(c[0][i+1]>=0&&c[1][i+1]>=0){
				if(absdf(c[0][i+1],c[1][i+1])<5){
					c[1][i]=c[0][i];
				}else if(c[0][i+1]-c[1][i+1]>5){
					c[1][i]=min(9,c[1][i]+1);
				}else if(c[0][i+1]-c[1][i+1]<-5){
					c[1][i]=max(0,c[0][i]-1);
				}else{
					int c0=0,c1=0,j=i+1;
					while(true){
						if(c0!=c1){
							break;
						}
						if(j==n-1){
							break;
						}
						++j;
						c0*=10;
						c1*=10;
						c0+=c[0][j];
						c1+=c[1][j];
					}
					if(c0==c1){
						if(c[0][i+1]<c[1][i+1]){
							c[1][i]=c[0][i];
						}else{
							c[1][i]=min(9,c[1][i]+1);
						}
					}else if(c0<c1){
						if(c[0][i+1]<c[1][i+1]){
							c[1][i]=max(c[0][i]-1,0);
						}else{
							c[1][i]=c[0][i];
						}
					}else{
						if(c[0][i+1]<c[1][i+1]){
							c[1][i]=c[0][i];
						}else{
							c[1][i]=min(c[0][i]+1,9);
						}
					}
				}
			
			}else{
				c[1][i]=c[0][i];
			}
		}
	}
	cout<<"Case #"<<q<<":";
	for(int k=0;k<2;++k){
		cout<<" ";
		for(int i=0;i<n;++i){
			cout<<c[k][i];
		}
	}
	cout<<endl;
}

int main(){
	int Q;
	cin>>Q;
	for(int q=1;q<=Q;++q){
		solve(q);
	}
}
