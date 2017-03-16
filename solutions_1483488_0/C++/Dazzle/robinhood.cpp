#include<iostream>
#include<cmath>
#include<fstream>
#include<map>
#include<set>
using namespace std;
int get_bit(int number){
	int count=0;
	while(number!=0){
		number/=10;
		count++;
	}
	return count;
}
int recycle(int number,int position,int bit){
	int base1=(int)pow(10.0,bit-position);
	int base2=(int)pow(10.0,position);
	int part1=number/base1;
	int part2=number%base1;
	int new_number=part2*base2+part1;
	return new_number;
}
int count_recycle_pair(int lower,int upper)
{
	int count=0;
	for(int n=lower;n<upper;n++){
		int bit=get_bit(n);
		set<int> recycled_map;
		recycled_map.clear();
		for(int i=1;i<bit;i++){
			int recycled=recycle(n,i,bit);
			if(recycled>=lower && recycled<=upper && recycled>n){
				if(recycled_map.find(recycled)==recycled_map.end()){
					recycled_map.insert(recycled);
					count++;
				}
			}
		}
	}
	return count;
}
int main()
{
	int t,T;
	ifstream fin;
	ofstream fout;
	fin.open("E:\\codejam\\input.txt");
	fout.open("E:\\codejam\\output.txt");
	fin>>T;
	int lower,upper;
	for(t=1;t<=T;t++){
		fin>>lower>>upper;
		int count=count_recycle_pair(lower,upper);
		fout<<"Case #"<<t<<": "<<count<<endl;
	}
	fout.close();
	/*
	
	int n;
	cin>>n;
	int bit=get_bit(n);
	cout<<bit<<endl;
	for(int i=1;i<bit;i++){
		cout<<recycle(n,i,bit)<<endl;
	}*/
	return 0;
}