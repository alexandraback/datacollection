#include <iostream>
#include <vector>
using namespace std;

int main(){

	int t;
	cin>>t;
	for(int i=1; i<=t; i++){
		int row,col,mine, good;
		cin >> row >> col >> mine;
		good = row*col -mine;
		vector<vector<char> > v(row, vector<char>(col,'*'));
		int rr,cc,dd;
		int r,c,sit;
//		cout<<"entered\n";
		for(r=1; r<=row; r++){
			for(c=1; c<=col; c++){
				int extra_needed = good - r*c;
				if(extra_needed < 0) continue;
				if(extra_needed == 0){
					if(r==1 && row>1 && good>1) continue;
					if(c==1 && col>1 && good>1) continue;
					rr =r;
					cc =c;
					dd =0;
					sit =0;
					break;
				}
				if(r<row && extra_needed>1){
					if(r==1 && row>1 && good>1) continue;
                                        if(c==1 && col>1 && good>1) continue;
				    if(extra_needed < c){
					rr = r;
					cc = c;
					dd = extra_needed;
					sit =1;
					break;
				    }
				    if(extra_needed == c+1 && r<row-1 && r>=2 && c>=3){
					rr = r;	
					cc = c;
					dd = c-1;
					sit = 3 ;
					break;
				    }	
				}
				if(c<col && extra_needed>1){
					if(r==1 && row>1 && good>1) continue;
                                        if(c==1 && col>1 && good>1) continue;
				    if(extra_needed < r){
					rr = r;
					cc = c;
					dd = extra_needed;
					sit =2;
					break;
				    }
				    if(extra_needed == r+1 && c<col-1 && c>=2 && r>=3){
					rr = r;
					cc = c;
					dd = r-1;
					sit = 4;
					break;
				    }
				}
			}
			if(c<=col) break;
		}

//		cout<<"yo yo \n";
//		cout<<rr<<" "<<cc<<" "<<dd<<" "<<sit<<endl;
		if(r>row) cout<<"Case #"<<i<<":\nImpossible\n";
		else{
			for(int p=0; p<rr; p++){
				for(int q=0; q<cc; q++){
					v[p][q] = '.';
				}
			}

			if(sit==0){}
			if(sit==1 || sit==3){
				for(int extra=0; extra<dd; extra++){
					v[rr][extra] = '.';
				}
			}
			if (sit==2 || sit==4){
				for(int extra=0; extra<dd; extra++){
					v[extra][cc] = '.';
				}
			}
			if(sit==3){
				v[rr+1][0]='.';
				v[rr+1][1]='.';
			}
			if(sit==4){
				v[0][cc+1]='.';
				v[1][cc+1]='.';
			}
			
			v[0][0] = 'c';
			cout<<"Case #"<<i<<":\n";
			for(int p=0; p<row; p++){
				for(int q=0; q<col; q++){
					cout<<v[p][q];
				}
				cout<<"\n";
			}
		}
	}
	return 0;
}
			
