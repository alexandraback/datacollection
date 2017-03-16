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


  for(long long i=0;i<L; i++) {
    if(s[i] == 'i')
      initial[i] = q_i;
    else if(s[i] == 'j')
      initial[i] = q_j;
    else
      initial[i] = q_k;
  }

  cumulative[0] = initial[0];
  bool i_found = false;
  bool k_found = false;

  if(cumulative[0] == q_i) {
    i_found= true;
  }

  for(long long i=1;i<L;i++) {
    cumulative[i] = cumulative[i-1]*initial[i];
    if(!i_found && cumulative[i] == q_i){
      i_found=true;
    } else if(!k_found && cumulative[i] == q_k) {
      k_found=true;
    }
  }

  quat cumulative_last = cumulative[L-1];
  bool last_found = power_of(cumulative_last,X) == q_neg_one;

  string res="";
  if(!last_found) {
    res ="NO";
    goto done;
  }
  if(i_found && k_found && last_found){
    res = "YES";
    goto done;
  }


  long long num_iters;

  num_iters = 4 <= X? 4 : X;

  for(long long pow = 1; pow <= num_iters-1;pow++){
    quat q_p = power_of(cumulative_last,pow);
    quat pow_3 = power_of(q_p,3);
    
    quat q_inv = !i_found ? pow_3*q_i : pow_3*q_k;
    
    for(long long i=0;i<L;i++) {
      if(!i_found && cumulative[i] == q_inv){
	i_found=true;
	q_inv = pow_3*q_k;
      } else if(!k_found && cumulative[i] == q_inv) {
	k_found=true;
	res = "YES";
	goto done;
      }
    }
  }    
  
  if(!i_found || !k_found) {
    res = "NO";
    goto done;
  }


 done:
  
  delete(initial);
  delete(cumulative);

  return res;


}


int main() {

  ifstream input ("C-large.in");
  ofstream output ("output.txt");
  int T;
  input >> T;
  createQuats();
  for (int i=1; i<=T; i++) {
    input >> L >> X >> s;
    output << "Case #" << i <<": " << solve() << "\n";
  }

  input.close();
  output.close();

  return 0;
}
