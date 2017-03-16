#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

#include<fstream>
FILE *fin=freopen("a.in","r",stdin);
FILE *fout=freopen("a.out","w",stdout);

int main() {
	int T,t,n,j,c,x,y,d;
	string jam,cod;
	cin>>T;
	for (t=1;t<=T;t++) {
		cin>>jam>>cod;
		n=jam.length();
		d=j=c=99999999;
		printf("Case #%d: ",t);
		if (n==1) {
			for (x=0;x<10;x++)
			for (y=0;y<10;y++)
			if ((jam[0]=='?' || char(x+'0')==jam[0]) && (cod[0]=='?' || char(y+'0')==cod[0])
			&& (
				 abs(x-y)<d 
				 || (abs(x-y)==d && x<j)
				 || (abs(x-y)==d && x==j && y<c)
				 )
				 ) {
				 	d=abs(x-y);
				 	j=x;
				 	c=y;
				 }
		    printf("%d %d\n",j,c);
		}
		else if (n==2){
			for (x=0;x<100;x++)
			for (y=0;y<100;y++)
			if ((jam[0]=='?' || char(x/10+'0')==jam[0]) && (cod[0]=='?' || char(y/10+'0')==cod[0])
			&& (jam[1]=='?' || char(x%10+'0')==jam[1]) && (cod[1]=='?' || char(y%10+'0')==cod[1])
			&& (
				 abs(x-y)<d 
				 || (abs(x-y)==d && x<j)
				 || (abs(x-y)==d && x==j && y<c)
				 )
				 ) {
				 	d=abs(x-y);
				 	j=x;
				 	c=y;
				 }
	         printf("%d%d %d%d\n",j/10,j%10,c/10,c%10);
		}
		else if (n==3){
			for (x=0;x<1000;x++)
			for (y=0;y<1000;y++)
			if ((jam[0]=='?' || char(x/100+'0')==jam[0]) && (cod[0]=='?' || char(y/100+'0')==cod[0])
			&& (jam[1]=='?' || char(x%100/10+'0')==jam[1]) && (cod[1]=='?' || char(y%100/10+'0')==cod[1])
			&& (jam[2]=='?' || char(x%10+'0')==jam[2]) && (cod[2]=='?' || char(y%10+'0')==cod[2])
			&& (
				 abs(x-y)<d 
				 || (abs(x-y)==d && x<j)
				 || (abs(x-y)==d && x==j && y<c)
				 )
				 ) {
				 	d=abs(x-y);
				 	j=x;
				 	c=y;
				 }
	        printf("%d%d%d %d%d%d\n",j/100,j%100/10,j%10,c/100,c%100/10,c%10);
		}
	}
    return 0;
}

