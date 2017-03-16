#include <cstdio>
#include <ctime>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <queue>
#include <map>
long long l[256],numbers[10],t;
std::string data;

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin>>t;
	for(int test_nr=1;test_nr<=t;test_nr++){
		std::cin>>data;
		for(int i=0;i<256;i++)
			l[i]=0;
		for(int i=0;i<10;i++)
			numbers[i]=0;
		for(int i=0;i<data.size();i++){
			l[data[i]]++;
		}
		numbers[0]=l['Z'];
		numbers[1]=l['O']-l['W']-l['U']-l['Z'];
		numbers[2]=l['W'];
		numbers[3]=l['H']-l['G'];
		numbers[4]=l['U'];
		numbers[5]=l['V']-l['S']+l['X'];
		numbers[6]=l['X'];
		numbers[7]=l['S']-l['X'];
		numbers[8]=l['G'];
		numbers[9]=l['I']-2*l['X']-l['G']-l['V']+l['S'];
		
		std::cout<<"Case #"<<test_nr<<": ";
		for(int i=0;i<10;i++){
			for(int j=0;j<numbers[i];j++){
				std::cout<<i;
			}
		}
		std::cout<<std::endl;
		
	}
}
