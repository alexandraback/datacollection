#include <fstream>
#include <iostream>
#include <string>
#include <map>
#include <set>

using namespace std;

static long long L,X;
static string s;

#define I 2
#define J 3
#define K 5

struct quat {
  int n;
};

int table[7][7];


static quat q_one,q_neg_one,q_i,q_neg_i,q_j,q_neg_j,q_k,q_neg_k;


bool operator==(quat a, quat b) {
  return a.n == b.n;
}

bool operator!=(quat a, quat b) {
  return a.n != b.n;
}

quat operator-(quat a) {
  a.n*=-1;
  return a;
}

bool operator<(quat a,quat b){
  return a.n < b.n;
}

quat operator*(quat a, quat b) {
  
  quat c;
  c.n = a.n*b.n;

  int sign = c.n >0 ? 1 : -1;

  int abs_a = a.n > 0 ? a.n : -a.n;
  int abs_b = b.n > 0 ? b.n : -b.n;
  
  c.n = sign * table[abs_a][abs_b];

  return c;

}

void createQuats(){
  q_one.n = 1;
  q_neg_one.n = -1;
  
  q_i.n = I;
  q_neg_i.n = -I;
  
  q_j.n = J;
  q_neg_j.n = -J;

  q_k.n = K;
  q_neg_k.n = -K;

  for(int i=0;i<7;i++) {
    table[i][1] = i;
    table[1][i] = i;
  }

  table[I][I] = -1;
  table[J][J] = -1;
  table[K][K] = -1;

  table[I][J] = K;
  table[J][K] = I;
  table[K][I] = J;

  table[J][I] = -K;
  table[K][J] = -I;
  table[I][K] = -J;



}



quat power_of(quat a, long long x) {
  long long r = x%4;
  quat aux = q_one;

  for(long long i=0;i<r;i++) {
    aux = aux*a;
  }

  return aux;

}


string naive_solve() {

  if(L*X<3) {
    cout <<"here0"<<endl;
    return "NO";
  }

  quat* initial;
  quat* cumulative;
  initial = new quat[L*X];
  cumulative = new quat[L*X];

  for(long long j=0;j<X;j++){
    for(long long i=0;i<L; i++) {
      if(s[i] == 'i')
	initial[i+L*j] = q_i;
      else if(s[i] == 'j')
	initial[i+L*j] = q_j;
      else
	initial[i+L*j] = q_k;
    }
  }

  cumulative[0] = initial[0];
  bool i_found = false;
  bool k_found = false;

  if(cumulative[0] == q_i) {
    i_found= true;
  }

  for(long long i=1;i<L*X;i++) {
    cumulative[i] = cumulative[i-1]*initial[i];
    if(!i_found && cumulative[i] == q_i){
      i_found=true;
    } else if(!k_found && cumulative[i] == q_k) {
      k_found=true;
    }
  }

  bool last_found = cumulative[L*X-1] == q_neg_one;

  string res="";
  if(i_found && k_found && last_found)
    res = "YES";
  else
    res = "NO";

  delete(initial);
  delete(cumulative);
  return res;

}




string solve() {

  if(L*X<3) {
    cout <<"here0"<<endl;
    return "NO";
  }

  quat* initial;
  quat* cumulative;
  initial = new quat[L];
  cumulative = new quat[L];
  map< quat, set<long long> > finder;


  for(long long i=0;i<L; i++) {
    if(s[i] == 'i')
      initial[i] = q_i;
    else if(s[i] == 'j')
      initial[i] = q_j;
    else
      initial[i] = q_k;
  }

  cumulative[0] = initial[0];
  finder[cumulative[0]].insert(0);
  for(long long i=1;i<L;i++) {
    cumulative[i] = cumulative[i-1]*initial[i];
    finder[cumulative[i]].insert(i);
  }

  quat cumulative_last = cumulative[L-1];

  if(power_of(cumulative_last,X)!=q_neg_one) {
    delete(initial);
    delete(cumulative);
    cout <<"here1"<<endl;
    return "NO";
  }

  //Get final quats

  map< quat , long long > final_quats;
  map< long long, quat > final_quats_inv;

  final_quats[cumulative_last] = 1;
  final_quats_inv[1] = cumulative_last;

  for(long long i=2; i<= X; i++) {
    quat c = power_of(cumulative_last,i);
    if(final_quats.find(c)!=final_quats.end()) {
      break;
    } else {
      final_quats[c] = i;
      final_quats_inv[i] = c;
    }
  }


  //Find I in the string

  long long first_i, first_x;
  bool i_found = false;
  if(!finder[q_i].empty()){
    cout << "q_i no empty" << endl;
    set<long long>::iterator it = finder[q_i].begin();
    first_i = *it;
    first_x = 1;
    i_found = true;
  } else {
    cout << "q_i empty" << endl;
    for(map< long long, quat >::iterator it = final_quats_inv.begin(); it != final_quats_inv.end(); ++it) {
      int iter = it->first;
      quat f = it->second;
      quat f_inv = power_of(f,3)*q_i;
      if(!finder[f_inv].empty()) {
	set<long long>::iterator it2 = finder[f_inv].begin();
	first_i = *it2;
	first_x = iter;
	i_found = true;
	break;
      }
    }
  }

  if(!i_found) {
    delete(initial);
    delete(cumulative);
    cout <<"here2"<<endl;
    return "NO";
  }

  //Find k in string

  long long sec_i, sec_x;
  bool k_found = false;
  long long fc, sc;
  if(!finder[q_k].empty()){
    set<long long>::iterator it = finder[q_k].begin();
    sec_i = *it;
    sec_x = 1;
    
    fc = first_i+first_x*L;
    sc = sec_i+sec_x*L;
    
    if(fc < sc){
      k_found = true;
    }

  }
  if(!k_found) {

    for(map< long long, quat >::iterator it = final_quats_inv.begin(); it != final_quats_inv.end(); ++it) {
      int iter = it->first;
      quat f = it->second;
      quat f_inv = power_of(f,3)*q_k;
      if(!finder[f_inv].empty()) {
	set<long long>::iterator it2 = finder[f_inv].begin();
	sec_i = *it2;
	sec_x = iter;

	fc = first_i+first_x*L;
	sc = sec_i+sec_x*L;
    
	if(fc < sc){
	  k_found = true;
	  break;
	}

      }
    }
  }

  if(!k_found) {
    delete(initial);
    delete(cumulative);
    cout <<"here3"<<endl;
    return "NO";
  }

  delete(cumulative);
  delete(initial);
  return "YES";


}


int main() {

  ifstream input ("C-small-attempt1.in");
  ofstream output ("output.txt");
  int T;
  input >> T;
  createQuats();
  for (int i=1; i<=T; i++) {
    input >> L >> X >> s;
    output << "Case #" << i <<": " << naive_solve() << "\n";
  }

  input.close();
  output.close();

  return 0;
}
