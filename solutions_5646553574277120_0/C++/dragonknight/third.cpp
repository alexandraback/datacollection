#include <stdio.h>
#include <algorithm>
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
int can_be_made(int,vector<int>,int);
int returned;
int main()
{
	int i,j,t,case_no,c,prev,d,v,sum,num,ans,sum_of_miss,pos;
	vector<int> ar;
	case_no=1;
	ifstream inf("C-small-attempt1.in");
	inf >> t;
	ofstream outf("output.txt");
	while(t--) {
		inf >> c;
		inf >> d;
		inf >> v;
		prev=d;
		int mem[50]={0};
		for(i=0;i<d;i++) {
			inf >> num;
			ar.push_back(num);
			mem[num]=1;
		}
		sum=ans=sum_of_miss=pos=0;

		if(mem[1]==0) {
			ans++;
			ar.push_back(1);
			d++;
		}
		if(v>1 && mem[2]==0) {
			ans++;
			ar.push_back(2);
			d++;
		}

		for(i=3;i<=v;i++) {
			printf("i=%d\n",i);
			if(mem[i]==0) {
				returned =0;
				if(can_be_made(i,ar,d)==0) {
					ar.push_back(i);
					mem[i]=1;
					d++;
				}
			}
		}
		outf << "Case #"<<case_no<<": "<<(d-prev)<<"\n";
		case_no++;
	}
	outf.close();
	inf.close();
	return 0;
}
int can_be_made(int value, vector<int> ar, int n)
{
	if(returned==1)
		return 1;

	if(value==0) {
		returned=1;
		return 1;
	}
	if(value<0 || n<=0)
		return 0;
	if(can_be_made(value-ar[n-1], ar, n-1)==1)
		return 1;
	if(can_be_made(value,ar,n-1)==1)
		return 1;
	if(returned==1)
		return 1;
	return 0;
}