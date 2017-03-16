#include<iostream>
#include <string>
using namespace std;

struct qt
{
   int s; // s= 1 or -1
   char c;// i or j or k or '1'
};

bool equal(qt a,qt b){
  if((a.s==b.s) and (a.c==b.c)){return true;}
  else {return false;}
}

void print(qt a){
  cout << a.s << " " << a.c <<endl;
}

qt multiply(qt a,qt b){
  
  qt ans;
  ans.s = a.s * b.s;
  ans.c = '1';
  
  if(a.c == '1') ans.c = b.c;
  else if(b.c == '1')  ans.c = a.c;
  else if (a.c == b.c) { ans.s *= (-1); ans.c='1';}
  else if ((a.c == 'i') and (b.c == 'j') ) ans.c = 'k';
  else if ((a.c == 'i') and (b.c == 'k') ) {ans.s *= (-1); ans.c = 'j';}
  else if ((a.c == 'j') and (b.c == 'k') ) ans.c = 'i';
  else if ((a.c == 'j') and (b.c == 'i') ) {ans.s *= (-1); ans.c = 'k';}
  else if ((a.c == 'k') and (b.c == 'i') ) ans.c = 'j';
  else if ((a.c == 'k') and (b.c == 'j') ) {ans.s *= (-1); ans.c = 'i';}
  
  return ans;
}

int main(){
  
  int T;
  cin >> T;
  
  for(int q=1;q<=T;q++){
    
    int L,X;
    cin >> L;
    cin >> X;
    
    char a[L] ;
    string str;
    int ans=0;

    
    cin >> str;

    for(int j=0;j < L; j++){
      a[j] = str[j];
      //cout << a[j] << endl;
    }
    
    qt Val;
    Val.s=1;
    Val.c='1';
    
    for (int j=0;j<L;j++){
      qt temp; temp.s=1; temp.c=a[j];
      Val = multiply(Val,temp);
    }
    //print(Val);
    qt dummy;dummy.s=Val.s;dummy.c=Val.c;
    for (int j=1;j<(X%4);j++){
      dummy = multiply(dummy,Val);
    }
    Val.s=dummy.s;Val.c=dummy.c;

    if(X%4==0){Val.s=1;Val.c='1';}
        //print(Val);
    if((Val.s==(-1)) and (Val.c=='1'))ans=1;
    
    if(ans==1){
      int t;
      if(X>=4){t=4;}
      else t=0;
      
      t+=(X%4);
      
      char S[L*t]; // simplified string
      
      for(int j=0;j<(L*t);j++){
	S[j]=a[j%L];
	//cout << a[j] << endl;
      }
      
      int p1=-1,p2=-1;
      
      qt N1; N1.s=1; N1.c='1';
      qt N2; N2.s=1; N2.c='1';
      qt iplus; iplus.s=1; iplus.c='i';
      qt kplus; kplus.s=1; kplus.c='k';
      
      for(int i=0;i<(L*t);i++){
	qt temp;temp.s=1; temp.c=S[i];
	N1 = multiply(N1,temp);
	if(equal(N1,iplus)){
	  p1=i;
	  break;
	}
      }
      for(int i=((L*t)-1);i>=0;i--){
	qt temp;temp.s=1; temp.c=S[i];
	N2 = multiply(temp,N2);
	if(equal(N2,kplus)){
	  p2=i;
	  break;
	}
      }
     
    if (((p1>-1) and (p2>-1)) and ( p1 < p2 + ( X*L - (L*t) ) )){
      ans=1;
    }
    else{ans=0;}
      
    }
    
     if(ans==1){    cout << "Case #" << q << ": "<<"YES"<<endl; }
     else { cout << "Case #" << q << ": "<<"NO"<<endl;}
  }
  
  return 0;
}