
#include <iostream>
#include <fstream>
#include <cstring>
#include <algorithm>

using namespace std; 



#define MAX_LEN	1024


long X;
long Y;
long cx,cy;
int flagx;
int flagy;
char steps[10000000];
long scount=0;

int transfer(){
	long i=0,j=0,k=0;
	int m=0,n=0;

	int res=0;

	flagx=0;
	flagy=0;
	if(X<0){
		flagx=1;
		X=-X;
	}
	if(Y<0){
		flagy=1;
		Y=-Y;
	}

	cx=0;
	cy=0;
	scount=0;
	for(i=1;;i++){
		if(cx==X&&cy==Y)
			break;
		if(cx!=X){
			if(cx<X){
				if((X-cx)>=i){
					cx+=i;
					steps[scount]='E';
					scount++;
				}
				else{
					cx-=i;
					steps[scount]='W';
					scount++;
				}
			}
		}
		else if(cy!=Y){
			if(cy<Y){
				if((Y-cy)>=i){
					cy+=i;
					steps[scount]='N';
					scount++;
				}
				else{
					cy-=i;
					steps[scount]='S';
					scount++;
				}
			}
		}
	}
	steps[scount]='\0';

	for(i=0;i<scount;i++){
		if(flagx==1){
			if(steps[i]=='E')
				steps[i]='W';
			else if(steps[i]=='W')
				steps[i]='E';
		}
		if(flagy==1){
			if(steps[i]=='N')
				steps[i]='S';
			else if(steps[i]=='S')
				steps[i]='N';
		}
	}


	return res;
}

int main() {
	long i=0,j=0,k=0;
	int T;
	int res=0;

	char str[MAX_LEN];
	char *ps;

	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!

	fstream fin("B-small-attempt0.in", ios::in);
	fstream fout("result.txt", ios::out);


	fin >> T;
	fin.getline(str,1024);
	ps=str;

	for (i=0;i<T;i++){

		fin>>X;
		fin>>Y;
		fin.getline(str,1024);
		ps=str;

		res=transfer();

		//double precision
		//fout.setf(ios::fixed);
		//fout.precision(6);

		fout << "Case #" << i+1 << ": " << steps << endl;
	}



	return 0;
}
