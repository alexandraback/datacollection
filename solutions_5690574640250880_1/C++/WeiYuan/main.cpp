
#include <iostream>
#include <fstream>
#include <cstring>
#include <algorithm>


using namespace std; 

char ary1[50][50];
int R;
int C;
int M;
int rotated;

long fillR3(int mm){
	int i,j;
	long res;

	int rr;
	int cc;
	rr=3;
	cc=C;
	res=0;

		if(mm%3==0&&mm!=rr*cc-3){
			for(i=0;i<rr;i++){
				for(j=0;j<mm/3;j++){
					ary1[i][cc-1-j]='*';
				}
			}
			ary1[0][0]='c';
			return res;
		}
		else if(mm%3==1&&mm!=rr*cc-2&&mm!=rr*cc-5){
			for(i=0;i<rr;i++){
				for(j=0;j<mm/3;j++){
					ary1[i][cc-1-j]='*';
				}
			}
			ary1[rr-1][cc-1-mm/3]='*';
			ary1[0][0]='c';
			return res;
		}
		else if(mm%3==2&&mm!=rr*cc-1&&mm!=rr*cc-4&&mm!=rr*cc-7){
			for(i=0;i<rr;i++){
				for(j=0;j<mm/3;j++){
					ary1[i][cc-1-j]='*';
				}
			}
			ary1[rr-1][cc-1-mm/3]='*';
			ary1[rr-1][cc-1-mm/3-1]='*';
			ary1[0][0]='c';
			return res;
		}
		else{
			res=1;
			return res;
		}
}

long transfer(){
	int i,j;
	long res;
	int tmp;
	
	res=0;
	rotated=0;
	if(R>C){
		tmp=R;
		R=C;
		C=tmp;
		rotated=1;
	}
	for(i=0;i<50;i++){
		for(j=0;j<50;j++){
			ary1[i][j]='.';
		}
	}

	if(R==1){
		for(i=C-M;i<C;i++){
			ary1[0][i]='*';
		}
		ary1[0][0]='c';
		return res;
	}
	else if(R==2){
		if(M==R*C-1){
			for(i=0;i<R;i++){
				for(j=0;j<C;j++){
					ary1[i][j]='*';
				}
			}
			ary1[0][0]='c';
			return res;
		}
		else if((M%2==0)&&(M!=R*C-2)){
			for(i=0;i<M/2;i++){
				ary1[0][C-1-i]='*';
				ary1[1][C-1-i]='*';
			}
			ary1[0][0]='c';
			return res;
		}
		else{
			res=1;
			return res;
		}
	}
	else if(R==3){
		if(M==R*C-1){
			for(i=0;i<R;i++){
				for(j=0;j<C;j++){
					ary1[i][j]='*';
				}
			}
			ary1[0][0]='c';
			return res;
		}
		if(M==R*C-4){
			for(i=0;i<R;i++){
				for(j=0;j<C;j++){
					ary1[i][j]='*';
				}
			}
			ary1[0][0]='c';
			ary1[0][1]='.';
			ary1[1][0]='.';
			ary1[1][1]='.';
			return res;
		}
		res=fillR3(M);
	}
	else{
		if(M==R*C-1){
			for(i=0;i<R;i++){
				for(j=0;j<C;j++){
					ary1[i][j]='*';
				}
			}
			ary1[0][0]='c';
			return res;
		}
		if(M==R*C-4){
			for(i=0;i<R;i++){
				for(j=0;j<C;j++){
					ary1[i][j]='*';
				}
			}
			ary1[0][0]='c';
			ary1[0][1]='.';
			ary1[1][0]='.';
			ary1[1][1]='.';
			return res;
		}

		int rr=R;
		int cc=C;
		int mm=M;
		for(;;){
			if(mm>=cc&&rr>3){
				for(j=0;j<cc;j++){
					ary1[rr-1][cc-1-j]='*';
				}
				rr--;
				mm-=cc;
			}
			else{
				break;
			}
		}

		if(rr>3){
			if(mm==cc-1){
				for(j=0;j<cc-2;j++){
					ary1[rr-1][cc-1-j]='*';
				}
				ary1[rr-2][cc-1]='*';
			}
			else{
				for(j=0;j<mm;j++){
					ary1[rr-1][cc-1-j]='*';
				}
			}
			ary1[0][0]='c';
		}
		else{
			res=fillR3(mm);
		}
	}
	
	

	return res;
}

int main() {
	int T;
	long res;
	char str[1024];
	int m,n;

	fstream fin("C-large.in", ios::in);
	fstream fout("result.txt", ios::out);

	fin >> T;
	fin.getline(str,1024);

	for (int i=0;i<T;i++){
		fin >> R;
		fin >> C;
		fin >> M;
		fin.getline(str,1024);

		res=transfer();
//		fin >> str;
		if(res>0)
			fout << "Case #" << i+1 << ":" << endl << "Impossible" << endl;
		else{
			fout << "Case #" << i+1 << ":" << endl;
			if(rotated==0){
				for(m=0;m<R;m++){
					for(n=0;n<C;n++){
						fout << ary1[m][n];
					}
					fout << endl;
				}
			}
			else{
				for(m=0;m<C;m++){
					for(n=0;n<R;n++){
						fout << ary1[n][m];
					}
					fout << endl;
				}
			}
		}

	}



	return 0;
}
