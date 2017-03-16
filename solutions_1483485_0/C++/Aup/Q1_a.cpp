#include<iostream>
#include<map>
#include<string>
#include<fstream>
std::map<char,char> mMapping;

int main(){
	std::string googlerese[3] = {"ejp mysljylc kd kxveddknmc re jsicpdrysi",
		"rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd",
		"de kr kd eoya kw aej tysr re ujdr lkgc jv"};
	std::string normal[3] = {"our language is impossible to understand",
		"there are twenty six factorial possibilities",
		"so it is okay if you want to just give up"};

	mMapping.insert( std::make_pair('z' , 'q') );
	mMapping.insert( std::make_pair('q' , 'z') );
	for( int i=0;i<3;i++ ){
		for( unsigned j=0;j<googlerese[i].length();j++ ){
			mMapping.insert( std::make_pair( googlerese[i][j],normal[i][j]) );
		}
	}
	//std::cout << mMapping.size() << std::endl;
	
	std::ifstream file;
	file.open("A-small-attempt0.in");
	std::ofstream ofile;
	ofile.open("A-small-attempt0.out");
	if( file.fail() || ofile.fail() )
		return 0;

	int n = 0;
	char stmp[1024];
	file.getline(stmp,1024);
	n = atoi(stmp);

	for( int i=0;i<n;i++ ){
		ofile << "Case #" << i+1 <<": ";
		std::string s;
		file.getline(stmp,1024);
		s=stmp;
		for( unsigned j=0;j<s.length();j++ ){
			ofile << mMapping[ s[j] ];
		}
		ofile << std::endl;
	}
	ofile.close();
	file.close();
	return 0;
}