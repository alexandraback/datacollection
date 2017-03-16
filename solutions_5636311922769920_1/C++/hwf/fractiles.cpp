#include<iostream>
#include<vector>
#include<cmath>
#include<fstream>

using namespace std;

bool tilespos(int k,int c,int s, vector<unsigned long long>& pos){
	if(c*s<k) return false;

	int i=0,j=0;
	unsigned long long d=pow(k,c-1),temp;
	unsigned long long p;
	while(i<s&&j<k){
		for(p=0,j=i*c,temp=d;j<c+i*c&&j<k;j++){
			p+=j*temp;
			temp/=k;
		}
		pos.push_back(p+1);
		i++;
	}

	return true;
}

void main(){

	fstream infile,outfile;
	int testnum,k,c,s;
	infile.open("D-large.in",ios::in);
	outfile.open("output.dat",ios::out);	
	infile>>testnum;

	vector<unsigned long long> result;
	bool isPossible;
	for(int i=1;i<=testnum;i++){
		infile>>k;
		infile>>c;
		infile>>s;
		isPossible=tilespos(k,c,s,result);
		outfile<<"Case #"<<i<<": ";
		if(isPossible){
			for(int j=0;j<result.size();j++){
				outfile<<result[j]<<' ';
			}
		}else{
			outfile<<"IMPOSSIBLE";
		}
		outfile<<'\n';
		result.clear();
	}

	/*tilespos(10,14,10,result);
	for(int j=0;j<result.size();j++){
		cout<<result[j]<<' ';
	}*/
}