#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int T;
ll L,X;
string sl;
string dpmul[10001];


string qmul(string x, string y) {
  if(x == "1") return y;
  if(x== "-1") {
    if(y =="1") return "-1";
    if(y=="-1") return "1";
    if(y=="i") return "-i";
    if(y=="-i") return "i";
    if(y=="j") return "-j";
    if(y=="-j") return "j";
    if(y=="k") return "-k";
    if(y=="-k") return "k";
  }
  if(x == "i") {
    if(y =="1") return "i";
    if(y=="-1") return "-i";
    if(y=="i") return "-1";
    if(y=="-i") return "1";
    if(y=="j") return "k";
    if(y=="-j") return "-k";
    if(y=="k") return "-j";
    if(y=="-k") return "j";
  }
  if(x == "-i") {
    if(y =="1") return "-i";
    if(y=="-1") return "i";
    if(y=="i") return "1";
    if(y=="-i") return "-1";
    if(y=="j") return "-k";
    if(y=="-j") return "k";
    if(y=="k") return "j";
    if(y=="-k") return "-j";
  }
  if(x == "j") {
    if(y =="1") return "j";
    if(y=="-1") return "-j";
    if(y=="i") return "-k";
    if(y=="-i") return "k";
    if(y=="j") return "-1";
    if(y=="-j") return "1";
    if(y=="k") return "i";
    if(y=="-k") return "-i";
  }
  if(x == "-j") {
    if(y =="1") return "-j";
    if(y=="-1") return "j";
    if(y=="i") return "k";
    if(y=="-i") return "-k";
    if(y=="j") return "1";
    if(y=="-j") return "-1";
    if(y=="k") return "-i";
    if(y=="-k") return "i";
  }
  if(x == "k") {
    if(y =="1") return "k";
    if(y=="-1") return "-k";
    if(y=="i") return "j";
    if(y=="-i") return "-j";
    if(y=="j") return "-i";
    if(y=="-j") return "i";
    if(y=="k") return "-1";
    if(y=="-k") return "1";
  }
  if(x == "-k") {
    if(y =="1") return "-k";
    if(y=="-1") return "k";
    if(y=="i") return "-j";
    if(y=="-i") return "j";
    if(y=="j") return "i";
    if(y=="-j") return "-i";
    if(y=="k") return "1";
    if(y=="-k") return "-1";
  }

}


int main () {

  cin >> T;

  for(int tc=1;tc<=T;tc++) {
    cin >> L >> X;
    cin >> sl;
    for(int i=0; i<10001; i++) dpmul[i] = " ";

    dpmul[0][0] = sl[0];

    for(int i=1; i<sl.size(); i++) {
      string ml = " ";
      ml[0]=sl[i];
      dpmul[i] = qmul(dpmul[i-1], ml);
    }
    /*
    for(int i=0; i<sl.size(); i++)
      cout << dpmul[i] << " ";
    cout << endl;
    */

    string block=dpmul[L-1];

    bool ifound = false;
    bool kfound = false;
    bool negone=false;

    if(block == "1") {
      negone = false;
    }
    else if(block == "-1") {
      if(X%2==1){
        negone = true;
        string tblock = "1";

        for(int it=0; it<min((ll)16,X); it++) {
          for(int i=0; i<sl.size(); i++) {
            if(qmul(tblock,dpmul[i]) == "i") ifound = true;
            if(qmul(tblock,dpmul[i]) == "k" && ifound) kfound = true;
          }
          tblock = qmul(tblock,block);
        }

      }
    }
    else {
      vector<string> cir(4," ");
      cir[0] = "1";
      cir[1] = block;
      cir[2] = qmul(cir[1], block);
      cir[3] = qmul(cir[2], block);

      if(cir[X%4] == "-1") {
        negone = true;
        string tblock = "1";
        for(int it=0; it<min((ll)16,X); it++) {
          for(int i=0; i<sl.size(); i++) {
            if(qmul(tblock,dpmul[i])== "i") ifound = true;
            if(qmul(tblock,dpmul[i])=="k" && ifound) kfound = true;
          }
          tblock = qmul(tblock, block);
        }
      }
    }


    if(ifound && kfound && negone)
      printf("Case #%d: YES\n",tc);
    else 
      printf("Case #%d: NO\n",tc);


  }

  return 0;
}