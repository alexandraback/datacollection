#include<bits/stdc++.h>

using namespace std;

// Returns first integer with exactly n bits set
int popcnt_init(int n) { return (1 << n) - 1; }
// next higher number with same number of 1's in binary
int popcnt_next(int n){
	int c = (n & -n);
	int	 r = n+c;
	return (((r ^ n) >> 2) / c) | r;
}
int mx[8]={1,1,0,-1,-1,-1,0,1};
int my[8]={0,1,1,1,0,-1,-1,-1};
bool visited[25][25];
char board[25],mines[25][25];

bool stadoValido(int r,int c,int x,int y){
	for(int k=0;k<8;k++){
		int xx = x+mx[k];
		int yy = y+my[k];
		if(xx>=0 && xx<	r && yy>=0 && yy<c){
			//cout<<"HOLA"<<endl;
			if(mines[xx][yy]=='*')return 0;
		}
	}
	return 1;
}
bool check(int r,int c,int x,int y){
	if(x>=0 && x<r && y>=0 && y<c and !visited[x][y] and mines[x][y]=='.')return 1;
	return 0;
}

void show(int r,int c){
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++)cout<<mines[i][j];cout<<endl;	
	}
	cout<<endl;	
}

int main(){
	
	int n,nn,nc=0,r,c;cin>>nn;
	while(nn--){
		cin>>r>>c>>n;
		int sol = r*c;
		int mask = popcnt_init(n);
		bool b = 1;
		cout<<"Case #"<<++nc<<":"<<endl;
		if(n==0){
			memset(mines,'.',sizeof(mines));
			mines[0][0] = 'c';
			
			for(int i=0;i<r;i++){
				for(int j=0;j<c;j++)cout<<mines[i][j];cout<<endl;
			}
			continue;
			
		}
		while(true and b){
			
			//cout<<"mask: "	<<mask<<endl;
			memset(board,'.',sizeof(board));
			for(int j=0;j<r*c;j++){
				int maskt = 1<<j;
				if(mask&maskt){
					board[j] = '*';
				}
			}
			int j=0;
			for(int i=0;i<r*c;i++){
				mines[j][i%c] = board[i];
				//cout<<board[i];
				if((i+1)%c==0)j++;//cout<<endl;	
			}
		
			for(int i=0;i<r and b;i++){
				for(int j=0;j<c and b;j++){
					if(mines[i][j]=='.'){
				
						int cuantos = 0;
						queue<pair<int,int> > Q;
						if(stadoValido(r,c,i,j)){
							Q.push(make_pair(i,j));
						}
						memset(visited,false,sizeof(visited));
						visited[i][j] = 1;
						cuantos++;
						while(!Q.empty()){
						//cout<<"YES"<<endl;	
							int x = Q.front().first;
							int y = Q.front().second;
							Q.pop();
							for(int k=0;k<8;k++){
								int xx = x+mx[k];
								int yy = y+my[k];
								if(check(r,c,xx,yy)){
									cuantos++;
									if(stadoValido(r,c,xx,yy)){
										Q.push(make_pair(xx,yy));
									}
									visited[xx][yy]=1;
								}
							
							}
						}
						if(cuantos+n == r*c){
							mines[i][j] = 'c';
							//cout<<"CUANTOS: "<<cuantos<<endl;
							show(r,c);
							b = 0;
							break;
						}
					
					
					}
				}
			}
			mask = popcnt_next(mask);
			if(mask >= (1<<(r*c)))break;
		}
		if(b){
			cout<<"Impossible"<<endl;
		}
		
		
	}
}

/*
				for(int i=0;i<r;i++){
					for(int j=0;j<c;j++)cout<<mines[i][j];cout<<endl;	
				}
				cout<<endl;	
				*/
