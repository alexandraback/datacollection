#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ifstream myfile;
    ofstream output;
    myfile.open("test.txt");
    output.open("output.txt");
    int numCase;

    myfile >> numCase;
	
	string str;
    for(int i=0; i< numCase ; i++){
        myfile >> str;
        string newstr = ""+string(1,str.at(0));
        int len = str.length();
        for(int j=1; j < len; j++){
        	if(str.at(j) >= newstr.at(0)){
        		newstr = str.at(j)+ newstr;
			}
			else{
				newstr = newstr+ str.at(j);
			}
        	
		}
		cout << newstr << endl;
		output << "Case #" << i+1 << ": " << newstr << endl;
    }



    
    myfile.close();
    return 0;
}



