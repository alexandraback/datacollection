// C.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include<string> 
#include<iostream> 
#include<fstream> 
#include<sstream> 
#include<vector>
#include<algorithm>
#include<bitset>


using namespace std;


int _tmain(int argc, _TCHAR* argv[])
{

	int Ndata;
	ifstream infile("good.in");
	ofstream OF("output.txt");

	

	 infile>>Ndata;
	 
	 
	 for(int idat=0;idat<Ndata;idat++){

		 int M,N,K;
		 infile>>M>>N>>K;
		 if(M<3||N<3||K<5){
			 OF<<"Case #"<<idat+1<<": "<<K<<endl;
		 } else{

			 int imin=1001;

			 for(int im=3;im<=M;im++){
				 for(int in=3;in<=N;in++){
					
					if(K<=im*in){
						
						int buf=im*in-K;
						if(buf>4) buf=4;


						if(2*im+2*in-6-buf<=imin) {
							//OF<<im<<" "<<in<<" "<<K<<" "<<buf<<endl;
							imin=2*im+2*in-6-buf;
						}
						//if(im==3&&in==5){
							//cout<<ibuf<<" "<<jbuf<<endl;
						//}

					}

				 }

			 }

			 OF<<"Case #"<<idat+1<<": "<<imin<<endl;
		 }

	 }

	 


	 infile.close();
	 OF.close();


	return 0;
}



						//int ibuf=im*in-4;	
						//int jbuf=K-ibuf; //0-4