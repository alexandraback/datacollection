#include<iostream>
#include<cstdlib>
using namespace std;
char *mapping="yhesocvxduiglbkrztnwjpfmaq";
int main(){
  char input[200];
  cin.getline(input,200);
  int no_of_cases =atoi(input);
  int k=1;
  while(no_of_cases){
    no_of_cases--;
    cout<<"Case #"<<k<<": ";
    cin.getline(input,200);
    for(int i=0;input[i];i++){
      if(input[i]>='a'&&input[i]<='z'){
	cout<<mapping[input[i]-'a'];
	continue;
      }
      cout<<input[i];
    }
    cout<<endl;
    k++;
  }

  return 0;
}
