#include <fstream>
#include <sstream>
#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <algorithm>
#include <iomanip>
#include <map>
#include <set>
#include <queue>

using namespace std;

int L;
long long int X;
vector<int> V;
vector<int> I_POS;
vector<long long int> K_POS;


void Calc_I_POS(void);
void Calc_K_POS(void);

int PROD(int A, int B){

	int sign_A; int sign_B;
	if(A>0){sign_A=1;}
	else{sign_A=-1;}
	if(B>0){sign_B=1;}
	else{sign_B=-1;}
	A=abs(A); B=abs(B);

	int seki;
	if(A==1){
		if(B==1){seki=1;}
		else if(B==2){seki= 2;}
		else if(B==3){seki=3;}
		else if(B==4){seki= 4;}
		else {cout << "PROD エラー"<<endl; return -999;}
	}else if(A==2){
        if(B==1){seki= 2;}
		else if(B==2){seki= -1;}
		else if(B==3){seki= 4;}
		else if(B==4){seki= -3;}
		else {cout << "PROD エラー"<<endl; return -999;}
	}else if(A==3){
        if(B==1){seki= 3;}
		else if(B==2){seki=-4;}
		else if(B==3){seki= -1;}
		else if(B==4){seki=2;}
		else {cout << "PROD エラー"<<endl; return -999;}
	}
    else if(A==4){
        if(B==1){seki=4;}
		else if(B==2){seki= 3;}
		else if(B==3){seki= -2;}
		else if(B==4){seki= -1;}
		else {cout << "PROD エラー"<<endl; return -999;}
	}
	return seki*sign_A*sign_B;
};

/*int SHORT(long long int b, long long int e)
{
	if(b>e){ cout <<"エラー"<<endl; return -9999;}
 
     e=(e-b)%(4*L)+b; 

	 if(C[int(b)][int(e)]!=0){return C[int(b)][int(e)];}

	 int atai=1;
     int pos;

	 for(long long int  i=b;i<=e;i++){
		   pos=int(i%L);
            atai=PROD(atai,V[pos]);
	 }
	 C[int(b)][int(e)]=atai;
return atai;

};*/

int main()
{
	ifstream ifs("C-small-attempt2.in");
    ofstream ofs("answer_C_small");
	int T;
	ifs >> T; cout << "T= " << T <<endl;
   
   for(int t=0;t<T;t++){  // test cases

    ifs >> L; cout << "L= " << L << endl; 
	ifs >> X; cout << "X= " <<X <<endl;

	string str;
	ifs >> str; //cout <<str<<endl;
	V.clear();

	string str_num="01ijk";

	for(int i=0;i<int(str.size());i++){
		for(int k=1;k<=4;k++){
			if(str.substr(i,1)==str_num.substr(k,1)){V.push_back(k);}
		}
	}


	
	I_POS.clear();
	Calc_I_POS();

/*	cout <<"I_POS: " ;
	for(int i=0;i<int(I_POS.size());i++){
          cout << I_POS[i] <<"  ";
	}
   cout <<endl;*/

	
	K_POS.clear();
	Calc_K_POS();


	reverse(K_POS.begin(),K_POS.end());


 /* cout <<"K_POS: " ;
	for(int i=0;i<int(K_POS.size());i++){
          cout << K_POS[i] <<"  ";
	}
   cout <<endl;*/

	int ans=0;

	cout <<I_POS.size()<<endl;

	long long int Ip, Kp;  int S; long long int I_POS_ans=-9999, K_POS_ans=-9999;
	for(int i=int(I_POS.size())-1;i>=0;i--){  
		int flag=0; 
		for(int k=0;k<int(K_POS.size());k++){
              Ip=I_POS[i]; Kp=K_POS[k];
			  if(Ip+1>Kp-1){continue;}
			  if(flag==0){
                 S=1;
				 for(long long int m=Ip+1; m<=Kp-1; m++){
					 int pos;
					 pos=int(m%L);
					 S=PROD(S,V[pos]); 
				 }
				 flag=1;
				}
			  else{ 
				  for(long long int  m=K_POS[k-1]; m<=Kp-1;m++){
                           int pos;
						   pos=int(m%L);
						   
						   S=PROD(S,V[pos]);
				  }  
			       }
			  if(S==3){ans=1;   I_POS_ans= I_POS[i]; K_POS_ans=K_POS[k]; i=-1; k=int(K_POS.size())+1;}
		}
	}

	if(ans==1){
     int A=1;
	 for(long long int i=0;i<=I_POS_ans;i++){
		 int u;
		 u=i%L;
         A=PROD(A,V[u]); 
	 }
	 cout<<"A"<<endl;
	 int B=1;
	 for( long long int i=I_POS_ans+1; i<K_POS_ans;i++){
          int u;
		  u=i%L;
		  B=PROD(B,V[u]);
	 }
	 int C=1;
	 for( long long int i=K_POS_ans;i<=L*X-1 ;i++){
            int u;
			u=i%L;
			C=PROD(C,V[u]);
	 }

        cout <<"A= " << A <<"  B= " <<B<< "  C= " <<C <<endl;
         if(A!=2 || B!=3 || C!=4){cout <<"=============error==========="<<endl;} 
	 }

/*	for(int i=0;i<int(I_POS.size());i++){
		for(int k=0;k<int(K_POS.size());k++){
			if(I_POS[i]+1>K_POS[k]-1){continue;}
			//cout <<"SHORT= " << SHORT(I_POS[i]+1, K_POS[k]-1)<<endl;
			if(SHORT(I_POS[i]+1, K_POS[k]-1)==3){ ans=1;  i=int(I_POS.size())+1; k=int(K_POS.size())+1;  }
		}
		cout <<"I_POS= " << I_POS[i]<<endl;
	}*/


	cout << "Case #" <<t+1<<": ";
	if(ans==1){cout <<"YES" <<endl;}
	else{cout <<"NO"<<endl;}
    ofs << "Case #" <<t+1<<": ";
    if(ans==1){ofs <<"YES" <<endl;}
	else{ofs <<"NO"<<endl;}

   } // end of test cases

 return 0;
}

void Calc_I_POS(void){

	long long int I_max;
	I_max=X*L-1;
	if(I_max>4*L-1){I_max=4*L-1; }
	int atai=1; int pos;
	for(int i=0;i<=int(I_max);i++){
        pos=i%L;
        atai=PROD(atai,V[pos]);
		if(atai==2){I_POS.push_back(i);}
	}
};

void Calc_K_POS(void){

	long long int K_min;

	K_min=L*X-1-4*L;
	if(K_min<0){K_min=0;}
     int pos;
	 int atai=1;
	for(long long int  k=L*X-1; k>=K_min; k--){
        pos= int(k%L);
        atai=PROD(V[pos],atai);
		if(atai==4){K_POS.push_back(k);}
	}

};