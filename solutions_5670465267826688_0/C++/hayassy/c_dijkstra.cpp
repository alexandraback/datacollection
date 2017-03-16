#include <iostream>
#include <string>
#include <vector>
using namespace std;

class ijk{
public:
  int o,i,j,k;
  ijk(){ o=1; i=j=k=0; }
  ijk(int w, int x, int y, int z){
    o=w; i=x; j=y; k=z;
  }
};

#define O ijk()
#define I ijk(0,1,0,0)
#define J ijk(0,0,1,0)
#define K ijk(0,0,0,1)

// a*b != b*a
ijk ijkmul(ijk a, ijk b){
  return ijk( a.o*b.o -a.i*b.i -a.j*b.j -a.k*b.k,
              a.o*b.i +a.i*b.o +a.j*b.k -a.k*b.j,
              a.o*b.j -a.i*b.k +a.j*b.o +a.k*b.i,
              a.o*b.k +a.i*b.j -a.j*b.i +a.k*b.o );
}
bool ijkeq(ijk a, ijk b){
  return a.o==b.o && a.i==b.i && a.j==b.j && a.k==b.k;
}
ijk ijkinv(ijk a){
  return ijk(-a.o, -a.i, -a.j, -a.k);
}
// work when a == O,I,J,K or that's inv
ijk ijkpow(ijk a, int n){
  if(n<=0) return ijk();
  return ijkmul(a, ijkpow(a,n-1));
  /*
  if(n==0) return ijk();
  if(n==1) return a;
  ijk tmp = ijkpow(a, n/2);
  if(n%2 == 0){
    return ijkeq(tmp,O)||ijkeq(tmp,ijkinv(O))? O : ijkinv(O);
  } else {
    return ijkeq(tmp,O)||ijkeq(tmp,ijkinv(O))? a : ijkinv(a);
  }
  */
}
// b * ijkdivr(a,b) = a (self define)
ijk ijkdivr(ijk a, ijk b){
  return ijkmul(ijkpow(b,2), ijkmul(b,a));
}
// ijkdivl(a,b) * b = a (self define)
ijk ijkdivl(ijk a, ijk b){
  return ijkmul(ijkpow(b,2), ijkmul(a,b));
}

ijk c2ijk(char c){
  switch(c){
  case 'i':
    return ijk(0,1,0,0);
  case 'j':
    return ijk(0,0,1,0);
  case 'k':
    return ijk(0,0,0,1);
  default:
    return ijk(1,0,0,0);
  }
}
ijk s2ijk(string str){
  ijk r = ijk(); // 1
  for(int i=0; i<(int)str.length(); i++){
    r = ijkmul(r,c2ijk(str[i]));
  }
  return r;
}
void printijk(ijk t){
  cerr << t.o << " " << t.i << " " << t.j << " " << t.k << endl;
}

//// main
int main(){
  int T; // number of question
  cin >> T; cin.ignore();
  for(int i=0; i<T; i++){
    int L;
    long long X;
    string str;
    cin >> L >> X; cin.ignore();
    cin >> str; cin.ignore();

    ijk strijk = s2ijk(str);
    ijk allijk = ijkpow(strijk, X%4);
    if(!ijkeq(allijk, ijkinv(O))){ // if ==ijk, ==-1
      cout << "Case #" << i+1 << ": " << "NO" << endl;
      continue;
    }

    int s1indx = -1;
    int s3indx = -1;

    // s1
    vector<ijk> list;
    ijk tmp;
    ijk search;

    list.clear();
    tmp = ijk();
    for(int j=0; j<(int)str.length(); j++){
      tmp = ijkmul(tmp, c2ijk(str[j]));
      list.push_back(tmp);
    }
    for(int j=0; j<L*4; j++){ // strijk^4 = 1
      if(j%L == 0){
        search = ijkdivr(I, ijkpow(strijk, j/L));
      }
      if(ijkeq(list[j%L], search)){
        s1indx = j;
        break;
      }
    }
    if(s1indx < 0){
      cout << "Case #" << i+1 << ": " << "NO" << endl;
      continue;
    }

    // s3
    list.clear();
    tmp = ijk();
    for(int j=0; j<(int)str.length(); j++){
      tmp = ijkmul(c2ijk(str[str.length()-1-j]), tmp);
      list.push_back(tmp);
    }
    for(int j=0; j<L*4; j++){ // strijk^4 = 1
      if(j%L == 0){
        search = ijkdivl(K, ijkpow(strijk, j/L));
      }
      if(ijkeq(list[j%L], search)){
        s3indx = j;
        break;
      }
    }
    if(s3indx < 0){
      cout << "Case #" << i+1 << ": " << "NO" << endl;
      continue;
    }
    //cout << "s3indx:" << s3indx << endl;

    if(s1indx + s3indx + 2 <= L*X){
      cout << "Case #" << i+1 << ": " << "YES" << endl;
    } else {
      cout << "Case #" << i+1 << ": " << "NO" << endl;
    }
  }

  return 0;
}
