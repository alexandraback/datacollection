#include<iostream>
#include<fstream>
#include<vector>
#include<set>

std::ifstream file;
std::ofstream ofile;

int bit;
int scale[] = {10,100,1000,10000,100000,1000000,10000000};
std::set< std::pair<int,int> > mSet;

int a;
int b;

int getCount( int num ){
	int o = num;
	
	int count = 0;
	for( int i=0;i<bit;i++ ){
		o = num;
		int oo = o / scale[i] + (o % scale[i]) * scale[bit - i - 1];
		if( b >= oo && oo > o){
			mSet.insert( std::make_pair( o , oo ) );
			count ++ ;
		}
	}
	return count;
}

int problem(){
	file >> a >> b;
	mSet.clear();
	
	int o = a;
	for( bit = 0 ; bit < 8 ; bit ++ ){
		o = o / 10;
		if( o == 0 ) break;
	}
	if( bit == 0 ) return 0;

	int count = 0;
	for( int i=a;i<=b;i++ ){
		count += getCount(i);
	}

	return mSet.size();
}


int main(int argc,char **argv){
	if( argc == 1 ){
		file.open("testc.txt");
		ofile.open("testco.txt");
	}else{
		file.open(argv[1]);
		ofile.open("C.out");
	}
	if( file.fail() || ofile.fail() )
		return -1;

	int n;
	file >> n;

	for( int i=0;i<n;i++ ){
		ofile << "Case #" << i+1 << ": " << problem() << std::endl;
	}

	return 0;
}

