#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector> 
using namespace std;

int main()
{
    ifstream myfile;
    ofstream output;
    myfile.open("input.txt");
    output.open("output.txt");
    int numCase;

    myfile >> numCase;
	int height[2501];
	int N;
	
    for(int i=0; i< numCase ; i++){
    	for(int i=0; i< 2501 ;i ++){
			height[i]=0;
		}
        myfile >> N;
        int arr[2*N-1][N];
        vector<int> miss;
        int max = 0;
        for(int j=0; j < 2*N-1; j++){
        	for(int k =0 ; k < N ; k++){
        		
        		myfile >> arr[j][k]	;
        		if(max < arr[j][k]){
        			max = arr[j][k];
				}
        		height[arr[j][k]]++;
			}
		}
		for(int j=0; j<= max ; j++){
			if(height[j] %2 == 1){
				miss.push_back(j);
			}
		}
		sort(miss.begin(),miss.end());
		
		output << "Case #" << i+1 << ": " ;
		for(int j =0; j< miss.size(); j++){
			output << miss.at(j) <<" ";
		}
		output << endl;
		
    }

    myfile.close();
    output.close();
    return 0;
}



