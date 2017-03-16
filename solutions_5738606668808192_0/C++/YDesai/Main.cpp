# include <iostream>
# include <cmath>
# include <vector>
# include <string>
# include <algorithm>
# include <ostream>
# include <fstream>

using namespace std;

typedef vector<int> vi;
typedef vector<vector<int> > vii;

//string CaseName = "C-small-prac";
string CaseName = "C-small-attempt5";
//string CaseName = "C-large";


long long int getNumber(long long int num, int base) {
  
  string tmp = to_string(num);
  
  int N = tmp.size();
  long long int ret = 0;
  for (int i = 0; i < N; i++) {
    
    ret += ((int)(tmp[i]-'0'))*(pow(base, N-i-1));
//    cout << ret << " " << (int)(tmp[i]-'0') << " " << pow(base, N-i-1) << endl;
  }
  
  
  return ret;
}

bool is_prime(long long int num) {
  
  if (num <= 1) {
    return false;
  } else if (num <= 3) {
    return true;
  } else if ((num%2 == 0) || (num%3 == 0)) {
    return false;
  } else {
    
    long long int i = 5;
    while (i*i <= num) {
      
      if ((num%i == 0) || (num%(i+2) == 0)) { 
        return false;
      }
      i = i+6;
    }
  }
  
  return true;

}


bool CheckMod(vi &num, int base, int factor) {
  
  bool res = false;
  
  int Ndigits = num.size();
  
  long long int sum = 0;
  
  long long int base8 = 1;
  
  for (int i = 1; i <=8; i++) {
    base8 = base8*base;  
  }
  
  
  for (int i = 0; i < Ndigits; i++) {
    
    
    long long int tmp;
        
    if (i > 7) {

      int tmp11 = (base8)%factor;
      
      long long int basen = 1;
      for (int j = 1; j <= i-7-1; j++) {
        basen = basen*base;
      }
      
      int tmp22 = (basen)%factor;
      tmp = (tmp11*tmp22)%factor;
      
    } else {
      long long int basen = 1;
      for (int j = 1; j <= i; j++) {
        basen = basen*base;
      }
      
      tmp = basen%factor;
    }

    
    int tmp1 = num[Ndigits-1-i]%factor;
    
    sum += (tmp*tmp1)%factor;
//    cout << sum << " ";
  }
  
//  cout << endl;
  long long int finalres = sum%factor;
  if (finalres == 0) {
    res = false;
  } else {
    res = true;
  }
  
  return res;
}


bool is_prime(vi &num, int base, int &factor) {
  
  
  int Nmax = 6;
  
  bool isprime = true;  
  int iter = 0;
  
  isprime = CheckMod(num, base, 2);
  if (!isprime) {
    factor = 2;
    return isprime;
  }
  
  isprime = CheckMod(num, base, 3);
  if (!isprime) {
    factor = 3;
    return isprime;
  }
  
  int i = 5;
  
  while (isprime && (iter <= Nmax)) {
    
    isprime = CheckMod(num, base, i);
    if (!isprime) {
      factor = i;
      return isprime;
    }
     
    isprime = CheckMod(num, base, i+2);
    if (!isprime) {
      factor = i+2;
      return isprime;
    }
    
    i = i+6;
    iter++;
  }
  
  return isprime;
}

vi get_binary_vector(long long int num) {
  
  string str;
  
  while (num > 0) {
    int rem = num%2;
    str+= to_string(rem);
    num = num/2;
  }
  
  reverse(str.begin(), str.end());
  
  vi ret(str.size());
  
  for (int i = 0; i < str.size(); i++) {
    ret[i] = str[i]-'0';
  }
  
  return ret;
}


void Solve(int N, int J, ofstream &Out) {
  
  int count = 0;
  
  long long int seed = (pow(2,N-1) + 1);
  
//  long long int seed = 0;
//  for (int i = 0; i < N; i++) {
    
//    seed += pow(2,i);
//  }
  
  
  int nloop = 0;
  
//  cout << seed << endl;
//  J = 1;
  while (count < J) {
    
    long long int curseed = seed+2*nloop;
    
    vi local = get_binary_vector(curseed);    
    
    // Check for ndigits //
    int ndigit = local.size();

    if (ndigit != N) {
      continue;
    }
    
    bool jamcoin = true;
    int localfactor[9];
    
    if (is_prime(curseed)) {
      jamcoin = false;
    }
    
    if (jamcoin) {
      for (int i = 2; i <= 10; i++) {
            
        int factor;
        if (is_prime(local, i, factor)) {
          jamcoin = false;
          break;
        } else {
          localfactor[i-2] = factor;
          
//          if ((i == 2) && (factor == 23)) {
//            cout << curseed << endl;
//          }
        }
      }      
    }
    
    nloop++;
    
    if (jamcoin) {
      
      for (int i = 0; i < local.size(); i++) {
//        cout << local[i];
        Out << local[i];      
      }
      
//      cout << " ";
      
      Out << " ";
      
      for (int i = 0; i < 9; i++) {
        
//        cout << localfactor[i] << " ";
        if (i != 8) {
          Out << localfactor[i] << " ";
        } else {
          Out << localfactor[i] << endl;
//          cout << endl;
        }
      }
//      cout << count << endl;
//      Out << endl;
      count++;
    }
  
  }   
  
  return;
}


int main() {

	int NCases; 
	ifstream In;
	In.open(CaseName+".in");
	
	// Reads Number of cases //
	In >> NCases;
	
	// Opens output stream //
	ofstream Out;
	Out.open(CaseName+".out");

//  cout << getNumber(110111,9) << endl;
//	vi test(16, 0);
//	test[0] = 1;
//	test[15] = 1;
//	test[14] = 0;
//	test[13] = 0;

//	for (int i = 0; i < test.size(); i++) {
//	  cout << test[i] ;
//	}
//	cout << endl;
//	int factor;
//	if (!	is_prime(test, 10, factor) ){
//	  cout << factor << endl;
//	}
	
// bool isprime = CheckMod(test, 10, 7);
//	cout << isprime << endl;
	
	int i,j;



	for (i = 1; i <= NCases; i++) {
		
		int N, J;
		In >> N >> J;

		Out << "Case #" << i << ":" << endl;
//		cout << "Case #" << i << ":" << endl;		
    
    Solve(N,J,Out);

	}
	// Close Input and Output Files //
	In.close();
	Out.close();

	return 0;

}
