#include<iostream>
#include<string>


using namespace std;

int main(){
  long  j, k, i, l,m, A, B, flag, pin;
  long lay, num, C,N, T, S, p, score;
  string name;
  long matr[4][4];
  cin >> T;
  getline(cin,name);
  name.clear();
  j=0;
  for(i=0;i<T;i++){
    cout<<"Case #"<<i+1<<": ";
    flag = 0;
    for (j=0;j<4;j++){
      getline (cin, name);
      for (k=0;k<4;k++){
	if (name[k]=='X')
	  matr[j][k]=1;
	else if (name[k]=='O')
	  matr[j][k]=0;
	else if (name[k]=='T')
	  matr[j][k]=100;
	else
	  matr [j][k]=1000;
      }
    }
    for (j=0;j<4;j++){
      if ((matr[j][0]+matr[j][1]+matr[j][2]+matr[j][3]==4 || matr[j][0]+matr[j][1]+matr[j][2]+matr[j][3]== 103)&&flag==0){
	flag = 1;
	cout<<"X won";
      }
      if ((matr[j][0]+matr[j][1]+matr[j][2]+matr[j][3]==0 || matr[j][0]+matr[j][1]+matr[j][2]+matr[j][3]== 100)&&flag==0){
	flag = 1;
	cout<<"O won";
      } 
      if ((matr[0][j]+matr[1][j]+matr[2][j]+matr[3][j]==4 || matr[0][j]+matr[1][j]+matr[2][j]+matr[3][j]== 103)&&flag==0){
	flag = 1;
	cout<<"X won";
      }
      if ((matr[0][j]+matr[1][j]+matr[2][j]+matr[3][j]==0 || matr[0][j]+matr[1][j]+matr[2][j]+matr[3][j]== 100)&&flag==0){
	flag = 1;
	cout<<"O won";
      }   
    }


    if (flag == 0){
      if ((matr[0][0]+matr[1][1]+matr[2][2]+matr[3][3]==4 || matr[0][0]+matr[1][1]+matr[2][2]+matr[3][3]==103)&&flag==0){
	flag = 1;
	cout<<"X won";
      }
      if ((matr[0][0]+matr[1][1]+matr[2][2]+matr[3][3]==0 || matr[0][0]+matr[1][1]+matr[2][2]+matr[3][3]==100)&&flag==0){
	    flag = 1;
	cout<<"O won";
      }  
      if ((matr[0][3]+matr[1][2]+matr[2][1]+matr[3][0]==4 || matr[0][3]+matr[1][2]+matr[2][1]+matr[3][0]==103)&&flag==0){
	flag = 1;
	cout<<"X won";
      }
      if ((matr[0][3]+matr[1][2]+matr[2][1]+matr[3][0]==0 || matr[0][3]+matr[1][2]+matr[2][1]+matr[3][0]==100)&&flag==0){
	flag = 1;
	cout<<"O won";
      }
      
    }
    

    if (flag == 0){
      for (j=0;j<4;j++){
	for (k=0;k<4;k++){
	  if (matr[j][k]>500&&flag==0){
	    flag = 1;
	    cout<<"Game has not completed";
	  }
	}
      }
    }
    
    if (flag ==0)
      cout<<"Draw";
    
    cout<<"\n";
    getline(cin, name);
    name.clear();
  }
  return 0;
}
