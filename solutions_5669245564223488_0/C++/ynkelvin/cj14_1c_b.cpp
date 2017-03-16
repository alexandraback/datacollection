#include <iostream>
#include <algorithm>  
#include <string>  
#include <vector>
using namespace std;

bool checkC(string car){
	bool c[26];
	char last = ' ';
	for (int i=0;i<26;i++){
		c[i] = false;
	}
	for (int i=0;i<car.size();i++){
		if (car[i]!=last && c[car[i]-97]){
			return false;
		} else {
			c[car[i]-97] = true;
		}
		last = car[i];
	}
	return true;
}

int main(){
	int T;
	cin >> T;
	for (int i=1;i<=T;i++){
		int count = 0;
		int N;
		int mul=1;
		cin >> N;
		string car[N];
		int carmul[N];
		for (int j=0;j<N;j++)
			carmul[j] = 1;
		vector<string> myVectorOfStrings;    
		for(int j=0;j<N;j++){
			cin >> car[j];

			  myVectorOfStrings.push_back(car[j]);
			  for (int k=0;k<j;k++){
			  	if (car[j].compare(car[k])==0){
			  		carmul[k]++;
			  		break;
			  	}
			  }
		}
		for (int j=0;j<N;j++)
			mul *= carmul[j];
  
  // In the vector we add all the sentences.
  // Note : It is possible to do myVectorOfStrings.push_back("Some sentence");

 
  // The elements must be sorted to output all the combinations
  sort (myVectorOfStrings.begin(),myVectorOfStrings.end());
 
  do {
  	string temp;
    //This printing can be improved to handle any number of sentences, not only four.
       	for (int z = 0; z < N; z++)
   	{
   		temp += myVectorOfStrings[z];
   	}
//cout << temp << endl;
   	if(checkC(temp)){
   		count++;
   	}
  } while ( next_permutation(myVectorOfStrings.begin(),myVectorOfStrings.end()) );
 
 cout << "Case #" << i << ": " <<count*mul<<endl;
	}
	return 0;
}