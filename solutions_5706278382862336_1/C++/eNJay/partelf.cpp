#include<iostream>
#include<sstream>
#include<string>

using namespace std;


int main()
{
	int numTestCases;
	long P,Q;
	string in;
	
	cin>>numTestCases;
	
	for(int i = 0; i < numTestCases; i++){
		
		cin>>in;
		
		string p = "";
		string q = "";
		int k;
		for(k = 0; k < in.length(); k++){
			
			
			if(in.at(k) == '/')
				break;
			
			p = p + in.at(k);
		}
		k++;
		while(k<in.length()){
		
				q = q + in.at(k);
			k++;
		}
		
		//cout<<"seen"<<p<<"\n";
		
	//	cout<<"seen"<<q<<"\n";
		istringstream buffer1(p);
		buffer1>>P;
		istringstream buffer2(q);
		buffer2>>Q;
		
		
		int gen = 0;
		long num = 1;
		int j = 1;
		while(j<41){
			
			num = P * 2;
			
			if(num >= Q){
				if(gen == 0)
					gen = j;
					
			  P = num % Q;
			}
			else
			{
				P = num ;
			}
		
			if( j == 40){
				
				if(P % Q != 0){
					gen = -1;
				}
				
			} 
			j++;
		}
		
		
		if(gen != -1)
		 cout<<"Case #"<<(i+1)<<": "<<gen<<"\n";
	    else
		 cout<<"Case #"<<(i+1)<<": impossible\n";
	
	
	}


}
