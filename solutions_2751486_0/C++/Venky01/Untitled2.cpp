#include<iostream>
#include<list>
#include <fstream>
#include <iostream>

using namespace std;

int getVovelCount(string s){
	int index =0;
	int vowel =0;

		while (s[index] != '\0') {
		switch (s[index]) {
		case 'a':
			vowel++;
			break;
		case 'e':
			vowel++;
			break;
		case 'i':
			vowel++;
			break;
		case 'o':
			vowel++;
			break;
		case 'u':
			vowel++;
			break;} index++;}
	return vowel;
}

list<int> getAllConsec(string s, int n){
	list<int> starts;

	for(int i=0;i<=s.length()-n;i++)
	{
		if(getVovelCount(s.substr(i,n))==0){
			starts.push_front(i);
		}
	}
	return starts;
}

bool isBetween(int start, int end, list<int> cons, int n){
//cout<<"start"<<start<<" end"<<end<<endl;
	for (list<int>::iterator it=cons.begin(); it!=cons.end(); ++it){
		if(*it>=start && (*it+n-1)<=end){

//cout<< "between\n";
			return true;
		}
		else if (*it+n-1 > end)
		{
			return false;
		}
	}
	return false;
} 

int main(){

	ifstream fin("input.txt");
    ofstream output("output.txt");
	int t =0;
	fin>>t;
	for(int tc=1;tc<=t;tc++){
		string input;
		int n;
		fin>>input;
		fin>>n;
		
		list<int> consonents = getAllConsec(input, n);

		for (list<int>::iterator it=consonents.begin(); it!=consonents.end(); ++it){

			cout << ' ' << *it;
		}/**/
		consonents.reverse();
		int nValue = 0;
		if(consonents.size()>0){
			for(int i=0;i<input.length(); i++){
	//cout<<"i:"<<i<<endl;
				for(int j=i+n-1; j<input.length(); j++){
	//cout<<"j:"<<j<<endl;
					if(isBetween(i,j,consonents, n)){
						nValue++;
					}
				}
			}
		}	

		output<<"Case #"<<tc<<": "<< nValue<<endl;
	}

}
