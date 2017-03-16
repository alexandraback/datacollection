#include <fstream>
#include <string>
#include <sstream>
#include <iostream>

using namespace std;

int stoi(string str){
stringstream ss;
ss << str;
int i;
ss >> i ;
return i;
}

unsigned long long stoull(string str){
stringstream ss;
ss << str;
unsigned long long i;
ss >> i ;
return i;
}

unsigned long long binary_search(unsigned long long r,unsigned long long t)
{
   unsigned long long min,med,max;
   min=1;
   /*max=t;
   int count=0;*/
   med=1;
   for(;;){
	  if(t==2*med*med-med+2*r*med){return med;}
	  else if(t<2*med*med-med+2*r*med){med=med/2;break;}

	 // cout <<",med= " << med <<endl;
      med=med*2;
	  /*else{max=med;}
	  count++;
	  if(count>100)break;*/
   }

    min=med;
	max=med*2;

	int count=0;

	for(;;){
     med=(min+max)/2;
	 if(t==2*med*med-med+2*r*med){return med;}
	 else if(t>2*med*med-med+2*r*med){min=med;}
	 else{max=med;}

	// cout <<min <<endl;
	 count++;
	 if(count>100){break;}
	}

   return min;
}

int main()
{
	ifstream ifs("A-small-attempt0 (1).in");
	string str;
	ifs >> str;
   int T=stoi(str);
   cout << "T= " << T <<endl;
   ofstream ofs("answer");

   for(int n=0;n<T;n++){  // test case
    ifs >> str; unsigned long long r=stoull(str);
	ifs >> str; unsigned long long  t=stoull(str);

	cout << r << " " << t <<endl;

	unsigned long long i=binary_search(r,t);
	//cout << i << endl;
	for(;;){ 
		if((t>=2*i*i-i+2*r*i) && (t<2*(i+1)*(i+1)-(i+1)+2*r*(i+1))){break;}
		else{i++;}
	}

	

	/*for(;;){
	     med=(min+max)/2;
		 if(t=2*med*med-med+2*r*med){}
	    }*/

	cout << "Case #" << n+1 << ": " << i << endl;
ofs << "Case #" << n+1 << ": " << i << endl;

   } // end of test case

 return 0;
}