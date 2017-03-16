#include <iostream>
#include <fstream>

using namespace std;


int main()
{
	int n,N;
	ifstream fin("input.txt");
	ofstream fout("output.txt");
	
	fin>>N;

	for(n=0;n<N;n++){
		int row,col,k;
		int i,j,t;
		int temp,ad,plu;
		fin>>row>>col>>k;
		int min = k;
		if(col < row){
			temp = col;
			col = row;
			row = temp;
		}
			

		for(i=1;i<col;i++){
			if(i+2>col)
				break;
			for(j=1;j<row;j++){
				if(j + 2 > row){
					break;
				}
				temp = 2*i + 2*j;
				if(k < temp + i*j)
					ad = 0;
				else 
					ad = k - temp - i*j;
				if(min > temp + ad){
					min = temp + ad;
				}
				plu = 0;
				for(t = 1;t<j;t++){
					if(i+2+t>col)
						break;
					plu += j-t;
					temp++;
					if(k < temp+plu+i*j)
						ad = 0;
					else
						ad = k-temp-i*j-plu;
					if(min > temp + ad){
						min = temp + ad;
					}
				}
			}
		}
		
		fout<<"Case #"<<n+1<<": "<<min<<endl;
	}


	return 0;
}


//fout.setf(ios::fixed);
//fout.precision(6);