#include<iostream>
#include<fstream>
using namespace std;
int main()
{
	const int SIZE=20;
	int number=1024;
	int A[SIZE];
	ifstream fin;
	fin.open("E:\\codejam\\input.txt");
	ofstream fout;
	fout.open("E:\\codejam\\output.txt");
	int T;
	fin>>T;
	int neglect;
	for(int t=1;t<=T;t++){
		fin>>neglect;
		for(int a=0;a<SIZE;a++){
			fin>>A[a];
		}
		bool flag=false;
		int i,j;
		for(i=1;i<number*number;i++){
			for(j=1;j<number*number;j++){
				if((i&j)==0){
					int sum1=0;
					int sum2=0;
					for(int l=0;l<20;l++){
						if(((i>>l)&1)==1){
							sum1+=A[l];
						}
						if(((j>>l)&1)==1){
							sum2+=A[l];
						}
						//cout<<sum1<<" "<<sum2<<endl;
					}
					//cout<<sum1<<" "<<sum2<<endl;
					if(sum1==sum2){
						//cout<<sum1<<" "<<sum2<<endl;
						flag=true;
						break;
					}
				}
			}
			if(flag==true)
				break;
		}
		cout<<"ok"<<" "<<t<<endl;
		if(flag==false){
			fout<<"Case #"<<t<<":"<<endl;
			fout<<"Impossible"<<endl;
		}
		if(flag==true){
			fout<<"Case #"<<t<<":"<<endl;
			bool first1=true;
			bool first2=true;
			for(int l=0;l<20;l++){
				if(((i>>l)&1)==1){
					if(first1==true){
						fout<<A[l];
						first1=false;
					}
					else
						fout<<" "<<A[l];
				}
			}
			fout<<endl;
			for(int l=0;l<20;l++){
				if(((j>>l)&1)==1){
					if(first2==true){
						fout<<A[l];
						first2=false;
					}
					else
						fout<<" "<<A[l];
				}
			}
		    fout<<endl;
		}
	}
	return 0;
}