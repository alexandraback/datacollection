#include<iostream>
#include<fstream>
#include<vector>
using namespace std;
double total;
double price;
double deadline;
double farmp;

int main()
{
	 ifstream in;
	 in.open("how.txt");
	 ofstream out;
	 out.open("output.txt");
	 out.precision(7);
	 out.setf(std::ios::fixed,std::ios::floatfield);
	int tc;
	in>>tc;
	 for(int t=0;t<tc;t++)
	 {
	 	out<<"Case #"<<(t+1)<<": ";
	 	total=0;

	 	double price;
	
	 	double deadline;
	 	 in>>price;
	 	 in>>farmp;
	 	 in>>deadline;
	 	 double no=2;
	 	 double c=0;
	 	 
	 	 
	 	       while(deadline!=c)
	 	       {
	 	       	  c+=price;
	 	       	   total+=(price/no);
					   double temp=deadline-c;
					   double way1,way2;
					   way1=temp/no;
					    way2=deadline/(no+farmp);
						 if(way1<way2)
						  {
						  	total+=temp/no;
						  	 out<<total<<endl;
						  	 break;
						  } 
						  else{
						  	 c-=price;
						  	 no+=farmp;
						  }
						  
	 	       }
	 	 
	     
	 }
}
