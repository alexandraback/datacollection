#include<iostream>
#include<vector>
#include<string>

using namespace std;
	int T;
	int r,c,n;
vector<string > field;
bool check(int r, int c, int  n){
    if(r==1 || c==1){
	return true;
    }else if(r==2 || c==2){
	int fr = r*c-n;
	if(fr==1 || (!(fr%2) && fr!=2))return true; else return false;
    }else{
	int fr = r*c-n;
	if(fr>=8 || fr==6 || fr==1 || fr==4)return true; else return false;
   }
}
void construct(int r, int c, int  n){
//    cout<<r<<" "<<c<<" "<<n<<"\n";
    if(r==1){
	for(int i=c-1; i>=c-n; i-- )field[0][i]='*';
    }else if(c==1){
	for(int i=r-1; i>=r-n; i-- )field[i][0]='*';
    }else if(r==2){
	for(int i=c-1; i>=c-n/2; i--){
	    field[0][i]=field[1][i] = '*';
	}
	if(n%2) field[1][0]='*';
    }else if(c==2){
	for(int i=r-1; i>=r-n/2; i--){
	    field[i][0]=field[i][1] = '*';
	}
	if(n%2) field[0][1]='*';
    }else{
	if(n>=c && check(r-1, c, n-c)){
	    for(int i=0; i<c; i++)field[r-1][i]='*';
	    construct(r-1, c, n-c);
	}else if(n>=r && check(r, c-1, n-r)){
	    for(int i=0; i<r; i++)field[i][c-1]='*';
	    construct(r, c-1, n-r);
	}else{
	    for(int i=r-1; n>0 && i>=2; i--) {field[i][c-1]='*'; n--;}
	    for(int i=c-2; n>0; i--){field[r-1][i]='*'; n--;}
	}
    }
}
int main(){

	cin>>T; 
	for(int j=0; j<T; j++){
		cin>>r>>c>>n;
		field=vector<string>(r, string(c,'.'));
		if(!check(r,c,n))
		    cout<<"Case #"<<j+1<<":\nImpossible\n";
		else{
		    cout<<"Case #"<<j+1<<":\n";
		    construct(r, c, n);
		    field[0][0]='c';
		    for(int i=0; i<r; i++) {cout<<field[i]<<"\n";}
		}
		
		
	}
	
}
