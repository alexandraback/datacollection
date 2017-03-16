#include <fstream>
#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;

void setminefield(int** minefield, int larger, int smaller, int diff){
	int i,j;
	for(i=0; i<larger; i++){
		for(j=0; j<smaller; j++){
			minefield[i][j]=1;
		}
	}
	if(diff==1) return;
	if(smaller==1){
		for(i=0; i<diff; i++){
			minefield[i][0]=0;
		}
	}
	else if(smaller==2){
		if(diff%2==0){
			for(i=0; i<diff/2; i++){
				minefield[i][0]=0;
				minefield[i][1]=0;
			}
		}
	}
	else{
		if(diff>=2*smaller){
			if((diff-1)%smaller!=0){
				for(i=0; i<diff/smaller; i++){
					for(j=0; j<smaller; j++){
						minefield[i][j]=0;
					}
				}
				for(j=0; j<(diff%smaller); j++){
					minefield[diff/smaller][j]=0;
				}
			}
			else{
				if(diff==2*smaller+1){
					for(i=0; i<2; i++){
						for(j=0; j<smaller-1; j++){
							minefield[i][j]=0;
						}
					}
					minefield[2][0]=0;
					minefield[2][1]=0;
					minefield[2][2]=0;
				}
				else{
					for(i=0; i<diff/smaller; i++){
						for(j=0; j<smaller; j++){
							minefield[i][j]=0;
						}
					}
					minefield[diff/smaller][0]=0;
					minefield[diff/smaller][1]=0;
					minefield[(diff/smaller)-1][smaller-1]=1;
				}
			}
		}
		else{
			if(diff%2==0){
				for(i=0; i<2; i++){
					for(j=0; j<diff/2; j++){
						minefield[i][j]=0;
					}
				}
			}
			else{
				for(i=0; i<2; i++){
					for(j=0; j<(diff-3)/2; j++){
						minefield[i][j]=0;
					}
				}
				minefield[2][0]=0;
				minefield[2][1]=0;
				minefield[2][2]=0;
			}
		}
	}
}

void flipflop(int **minefield, int larger){
	int temptemp[50][50];
	int i,j;
	for(i=0; i<larger; i++){
		for(j=0; j<larger; j++){
			temptemp[i][j]=minefield[i][j];
		}
	}
	for(i=0; i<larger; i++){
		for(j=0; j<larger; j++){
			minefield[i][j]=temptemp[j][i];
		}
	}

}

int main()
{
	int cases;
	int r,c;
	int m;
	int i,j,k;
	int yesorno;
	int la,sma;
	int diff;
	int** minefield;
	ifstream fin;
	ofstream fout;
	fin.open("C-small-attempt2.in");
	fout.open("C-small-attempt2.out");
	minefield = (int**) malloc(sizeof(int*) * 50);
	for(i=0; i<50; i++){
		minefield[i]=(int*) malloc(sizeof(int)*50);
	}
	
	
	fin >> cases;
	for(i=1; i<=cases; i++){
		fin >> r;
		fin >> c;
		fin >> m;
		if(r>c){
			la=r;
		}
		else{
			la=c;
		}
		sma=r+c-la;
		diff = r*c-m;
		switch(sma){
			case 1:
				yesorno = 1;
				break;
			case 2:
				if(diff ==2 || (diff > 1 && diff%2==1)){
					yesorno = 0;
				}
				else{
					yesorno = 1;
				}
				break;
			default:
				if(diff == 2 || diff == 3 || diff == 5 || diff == 7){
					yesorno = 0;
				}
				else{
					yesorno = 1;
				}
				break;
		}
		fout << "Case #" << i << ":" << endl;
		if(yesorno == 0){
			fout << "Impossible" << endl;
		}
		else{
			setminefield(minefield,la,sma, diff);
			minefield[0][0]=-1;
			if(la == c) flipflop(minefield,la);
			for(j=0; j<r; j++){
				for(k=0; k<c; k++){
					switch(minefield[j][k]){
						case -1:
							fout << "c";
							break;
						case 0:
							fout << ".";
							break;
						case 1:
							fout << "*";
							break;
						default:
							fout << "X";
							break;
					}
				}
				fout << endl;
			}
		}
	}

	for(i=0; i<50; i++){
		free(minefield[i]);
	}
	free(minefield);
	fin.close();
	fout.close();
	return 0;
}