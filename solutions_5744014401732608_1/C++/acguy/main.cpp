#include<iostream>
#include<cmath>
#include<queue>
using namespace std;
bool mp[52][52];
long long int B,M;
void p(){
      for(long long int i = 0;i<B;i++){
        for(long long int j = 0;j<B;j++){
          cout<<mp[i][j];
        }
        cout<<endl;
      }
}

int main(void){
  long long int T;
  cin>>T;
  for(long long int Ti=1;Ti<=T;Ti++){

    cin>>B>>M;
    if(M>((long long int)pow(2,B-2))){
      cout<<"Case #"<<Ti<<": IMPOSSIBLE"<<endl;
    }else{
      cout<<"Case #"<<Ti<<": POSSIBLE"<<endl;
      for(long long int i = 0;i<B+1;i++){
        for(long long int j = 0;j<B+1;j++){
          if(i<j){
            mp[i][j]=1;
          }else{
            mp[i][j]=0;
          }
        }
      }

      //      p();
      long long int upr = (long long int)pow(2,B-2);
      long long int s = upr-M;
      for(long long int i=1;i<B-1;i++){
        if(s&1){
          mp[i][B-1]=0;
        }
        s>>=1;
      }
        
      p();


    }
  }
  return 0;
}
