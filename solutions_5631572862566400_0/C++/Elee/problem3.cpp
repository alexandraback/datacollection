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
    int N;
    for(int i=0; i< numCase ; i++){
    	myfile >> N ;
    	int bff[N];
    	
    	for(int j =0; j < N ; j++){
    		myfile >> bff[j];
    	
		}
		int maxsize = 0;
		int check[N];
		int cnt;
		for(int j =0; j < N ; j++){
			for(int k=0; k < N ;k++){
				check[k] =0;
			}
			cnt = 0;
			check[j] = -1;
			int start = j;
			int old;
			bool isvalid = true;
			bool previous = false;
			while(isvalid){			
				old = start;	
				start = bff[start]-1;
				cnt++;
				if(check[start]  == -1){
					break;
				}
				else if(check[start] == 1){
					if(old == bff[start]-1)	{
						previous = true;
						break;
					}
					else{
						isvalid = false;
						break;
					}
				}
				else{
					check[start]++;	
				}
				
			}
			bool change = false;
			while(previous){
				change = false;
				for(int a = 0; a < N ; a ++){
					if(bff[a]-1 == old && check[a]== 0 && previous ) {
						cnt++;
						old = bff[a]-1;
						check[a]++;
						change = true;
						break;
					}
				}
				if(change == false){
					break;
				}
			}
			
			if(isvalid && maxsize < cnt){
				maxsize = cnt;
			}
			
		}
		
		output << "Case #" << i+1 << ": " << maxsize << endl;
		//cout << "Case #" << i+1 << ": " << maxsize << endl << endl;
		//cout << "--------------------"<< endl;
    }

    myfile.close();
    output.close();
    return 0;
}



