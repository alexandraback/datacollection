#include <stdio.h>
#include <string.h>
#include <math.h>
#include <map>

using namespace std;

int ntc,r,a,b;
map<pair<int,int>,int> count;

int digit(int num){
	int r=0;
	while (num>0) {num/=10; r++;}
	return r;
}

int rotate(int num,int len,int dist){
	int ri=((int)pow(10,dist));
	int le=((int)pow(10,len-dist));
	int newnum=num/ri+(num%ri)*le;
	return newnum;
}

int check(int num,int lo,int hi){
	int r=0;
	int d=digit(num);
	for (int i=1;i<d;i++){
		int newnum=rotate(num,d,i);
		if ((newnum>num)&&(newnum>=lo)&&(newnum<=hi)&&(digit(newnum)==d)){
			if (count.count(make_pair(num,newnum))==0){
				count[make_pair(num,newnum)]=1;
				r++;
			}
		}
	}
	return r;
}

int main(){
	scanf("%d",&ntc);
	for (int tc=1;tc<=ntc;tc++){
		r=0;
		count.clear();
		scanf("%d %d",&a,&b);
		for (int i=a;i<=b;i++) r+=check(i,a,b);
		printf("Case #%d: %d\n",tc,r);
	}
	return 0;
}