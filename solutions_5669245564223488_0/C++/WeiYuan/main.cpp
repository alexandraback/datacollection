
#include <iostream>
#include <fstream>
#include <cstring>
#include <algorithm>
#include <vector>


using namespace std; 

int N;
string ary[101];

long long Perm(long long m,long long n){
	long long i;
	long long res=1;

	res=1;
	for(i=0;i<n;i++){
		res*=(m-i);
	}

	return res;
}

int tmp[101];


long long transfer(){
	int i,j,k;
	long long res;
	int head,tail,middle;
	int count,count1,pos;
	char ch;

	res=1;
	count=0,count1=0;
	
	for(i=0;i<N;i++){
		ch=ary[i][0];
		for(j=1;j<ary[i].size();){
			if(ary[i][j]==ch)
				ary[i].erase(j,1);
			else{
				ch=ary[i][j];
				j++;
			}
		}
	}
	
	for(i=0;i<N;i++)
		tmp[i]=0;
	
	for(i=0;i<26;i++){
		head=0;
		tail=0;
		middle=0;
		count=0;
		pos=-1;
		for(j=0;j<N;j++){
			if(ary[j][0]=='a'+i){
				head++;
				pos=j;
			}
			if(ary[j][ary[j].size()-1]=='a'+i){
				tail++;
				pos=j;
			}
			if(ary[j][0]=='a'+i&&ary[j][ary[j].size()-1]=='a'+i){
				count++;
			}
			for(k=1;k<ary[j].size()-1;k++){
				if(ary[j][k]=='a'+i)
					middle++;
			}
		}
		if((head==1&&tail==0)||(head==0&&tail==1)){
			tmp[pos]++;
		}
		
		if(middle>1)
			return 0;
		if((middle==1&&head>0)||(middle==1&&tail>0))
			return 0;

		if(count>0)		
			res*=Perm(count,count);			

		if(abs(head-tail)>1){
			return 0;
		}
		if(head==tail&&tail==count){
			if(head!=0)
				count1++;
		}
		else{}
	}
	for(i=0;i<N;i++){
		if(tmp[i]==2)
			count1++;
	}
	res=res*Perm(count1,count1);

	return res;
}

int main() {
	int T;
	long long res;
	char str[1024];
	char ch;

	fstream fin("B-small-attempt3.in", ios::in);
	fstream fout("result.txt", ios::out);

	fin >> T;
	fin.getline(str,1024);
	

	for (int i=0;i<T;i++){
		fin >> N;
		fin.getline(str,1024);
		
		for(int j=0;j<N;j++){
			fin >> str;
			ary[j]=str;
		}
		fin.getline(str,1024);

		res=transfer();
//		fin >> str;
		fout << "Case #" << i+1 << ": " << res << endl;

	}



	return 0;
}
