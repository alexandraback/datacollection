#include<iostream>
#include<fstream>
#include<limits>
#include<sstream>
#include<array>
#include<algorithm>
#include<vector>

typedef unsigned long long ull;


struct input {
    std::string C, J;
};

struct output {
    std::string C, J;
};

input parse(std::string line) {
    input I;
    std::stringstream ss;
    ss << line;
    ss >> I.C >> I.J;
    
    return I;
}

void gen(std::string S, uint32_t I, std::vector<std::string>& V) {
    if (I == S.length()) {
        V.push_back(S);
        return;
    }
    if (S[I] == '?') {
        for  (uint32_t i = 0; i < 10; i++) {
            S[I] = i + '0';
            gen(S, I+1, V);
        }
    }
    else {
        gen(S, I+1, V);
    }
}

int64_t str2int(std::string S) {
    std::stringstream ss;
    ss << S;
    int64_t N;
    ss >> N;
    return N;
}

output bfsolve(std::string C, std::string J) {
  int64_t minD = 99999999999;
  output O;  
  std::vector<std::string> Cs, Js;
  gen(C, 0, Cs);
  gen(J, 0, Js);
  for (auto c : Cs) {
      for (auto j : Js) {
          int64_t diff = std::abs(str2int(c) - str2int(j));
          if (diff == minD) {
              if (str2int(c) < str2int(O.C)) {
                minD = diff;
                O.C = c;
                O.J = j;    
              }
              if (str2int(c) == str2int(O.C) && str2int(j) == str2int(O.J)) {
                minD = diff;
                O.C = c;
                O.J = j;    
              }
          }
          if (diff < minD) {
              minD = diff;
              O.C = c;
              O.J = j;
          }
      }
  }
  return O;
}

int64_t bestD;
output bestO;

void lsolve(std::string C, std::string J, uint32_t I, int64_t diff) {
    if (I == C.length()) {
        int64_t rdiff = std::abs(str2int(C) - str2int(J));
        if (rdiff < bestD) {
            bestO.C = C;
            bestO.J = J;
            bestD = rdiff;
        }
        if (rdiff == bestD) {
            if (str2int(C) < str2int(bestO.C)) {
                bestO.C = C;
                bestO.J = J;    
            }
            if (str2int(C) == str2int(bestO.C) && str2int(J) < str2int(bestO.J)) {
                bestO.C = C;
                bestO.J = J;    
            }
        }
        return ;
    }
    if (C[I] != '?' && J[I] != '?') {
        if (diff == 0) {
            if (C[I] > J[I]) {
                diff = 1;
            }
            if (C[I] < J[I]) {
                diff = -1;
            }
        }
        lsolve(C, J, I+1, diff);
    }
    else if (C[I] == '?' && J[I] != '?') {
        if (diff == 1) {
            C[I] = '0';
            lsolve(C, J, I+1, diff);
        }
        else if (diff == -1) {
            C[I] = '9';
            lsolve(C, J, I+1, diff);
        }
        else {
            if (J[I] < '9') {
                C[I] = J[I] + 1;
                lsolve(C, J, I+1, 1);
            }
            C[I] = J[I];
            lsolve(C, J, I+1, 0);
            if (J[I] > '0') {
                C[I] = J[I] - 1;
                lsolve(C, J, I+1, -1);
            }
        }
    }
    else if (J[I] == '?' && C[I] != '?') {
        if (diff == 1) {
            J[I] = '9';
            lsolve(C, J, I+1, diff);
        }
        else if (diff == -1) {
            J[I] = '0';
            lsolve(C, J, I+1, diff);
        }
        else {
            if (C[I] < '9') {
                J[I] = C[I] + 1;
                lsolve(C, J, I+1, -1);
            }
            J[I] = C[I];
            lsolve(C, J, I+1, 0);
            if (C[I] > '0') {
                J[I] = C[I] - 1;
                lsolve(C, J, I+1, 1);
            }
        }
    }
    else {
        if (diff == 0) {
            C[I] = '0';
            J[I] = '0';
            lsolve(C, J, I+1, 0);
            C[I] = '1';
            J[I] = '0';
            lsolve(C, J, I+1, 1);
            C[I] = '0';
            J[I] = '1';
            lsolve(C, J, I+1, -1);
        }
        else if  (diff > 0) {
            C[I] = '0';
            J[I] = '9';
            lsolve(C, J, I+1, diff);
        }
        else if  (diff < 0) {
            C[I] = '9';
            J[I] = '0';
            lsolve(C, J, I+1, diff);
        }
    }
}


output solve(input I){
    output O;
   
    //O = bfsolve(I.C, I.J);
    
    bestD = std::numeric_limits<int64_t>::max();
    lsolve(I.C, I.J, 0, 0);
    O = bestO;
    return O;
}

void print(output O, uint32_t line) {
    std::cout << "Case #" << line << ": ";
    std::cout << O.C << " " << O.J;
    std::cout << "\n";
}

int main(int argc, char* argv[]) {
    std::vector<std::string> args(argv, argv+argc);
    if (args.size() != 2)
        return 1;
    std::ifstream ifs(args[1]);
    std::string line;
    uint32_t lineNr = 0;
    while (true) {
        std::getline(ifs, line);
        if (!ifs)
            break;
        if (lineNr == 0) {
            lineNr++;
            continue;
        }
        input I = parse(line);
        output O = solve(I);
        print(O, lineNr++);
    }
}