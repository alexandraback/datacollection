#include<iostream>
using namespace std;
int main()
{

	int T,s=1;
	int r,c,m;
	int i,j,t;
	int cells;
	int blanks;
	int sq;
	int count=0,countb,countm;
	bool imp = false,flip;
	cin>>T;
	while(T--){
		char output[51][51];
		imp = false;
		count = 0;
		cin>>r>>c>>m;
		cout<<"Case #"<<s++<<":"<<endl;
		cells = r*c;

		if(m >= cells) imp = true;
		if(r==1 && m>=c-1) imp =true;
		else if(c==1 && m>=r-1) imp = true;
		else if(r!=1 && c!= 1 && cells - m < 4) imp = true;
		blanks = cells - m;

		for(i=1,sq=1;sq*sq<=blanks;sq++,i++);
		sq--;i--;
		if(r!=1 && c!=1){
			if(sq <=2 && ((blanks-sq*sq == sq+1) || (blanks-sq*sq == 1))) imp =true;
			if(r<=3 && c<=3 && blanks-sq*sq == 1) imp = true;
			if( (r==2 || c==2) && m%2) imp = true;
		}
		if(m == r*c-1){
			for(i=0;i<r;i++){
				for(j=0;j<c;j++)
					if(!i && !j)
						cout<<"c";
					else
						cout<<"*";
				cout<<endl;
			}
			continue;
		}
		if(imp) {cout<<"Impossible"<<endl; continue;}
		for(i=0;i<r;i++)
			for(j=0;j<c;j++)
				output[i][j] = '*';

		if(r==1){
			for(i=0;i<blanks;i++)
				output[0][i] ='.';
			output[0][0] = 'c';
			goto JMP;	
		}
		if(c==1){
			for(i=0;i<blanks;i++)
				output[i][0] = '.';
			output[0][0] = 'c';
			goto JMP;
			
		}
		for(i=0;i<min(r,sq);i++){
			for(j=0;j<min(c,sq);j++){
				if(!i && !j){
					output[i][j] = 'c';
					count = 1;
				}
				else if(i+1<=sq && j+1<=sq){
					output[i][j] = '.';
					count++;
				}

			}
		}

		if(r<sq){
			for(j=sq;j<c;j++){
				for(i=0;i<r;i++){
					if(count >= blanks) break;
					output[i][j] = '.';
					count++;
				}
			}
		}
		else if(c<sq){
			for(i=sq;i<r;i++){
				for(j=0;j<c;j++){
					if(count >= blanks) break;
					output[i][j] = '.';
					count++;
				}
			}
		}

		else if(c>=sq && r>=sq && count<blanks){
			t = 0;
			while(count<blanks){
				for(i=0;i<sq && count<blanks && c>sq;i++){
					output[i][sq+t] = '.';
					count++;
				}
				for(j=0;j<sq && count<blanks && r>sq;j++){
					output[sq+t][j] = '.';
					count++;
				}
				t++;
			}
		}

		if(r>=2 && c>=2){
			for(i=0;i<r;i++){
				countm = 0;
				countb = 0;
				for(j=0;j<c;j++){
					if(output[i][j] == '*') countm++;
					if(output[i][j] == '.') countb++;
				}
				if(countb == 1 && countm+countb == c && i){
					output[i][1] = '.';
					output[i-1][c-1] = '*';
					//if(i-1 <= 1 || c-1 <=1)
						//imp = true;
				}
			}
			for(j=0;j<c;j++){
				countm = 0;
				countb = 0;
				for(i=0;i<r;i++){
					if(output[i][j] == '*') countm++;
					if(output[i][j] == '.') countb++;
				}
				if(countb == 1 && countm+countb == r && j){
					output[1][j] = '.';
					output[r-1][j-1] = '*';
					//if(j-1 <= 1 || r-1 <=1)
						//imp = true;

				}
			}
		}
		
		if(imp) {cout<<"Impossible"<<endl; continue;}
		else{
JMP:		output[0][0] = 'c';
			for(i=0;i<r;i++){
				for(j=0;j<c;j++)
					cout<<output[i][j];
				cout<<endl;
			}
		}
	}


}
