#include<iostream>
#include<fstream>
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

output solve(input I){
    output O;
   
    O = bfsolve(I.C, I.J);
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