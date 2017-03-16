#include<iostream>
#include<fstream>
#include<sstream>
#include<array>
#include<algorithm>
#include<vector>

typedef unsigned long long ull;


struct input {
    std::string S;
};

struct output {
    std::string S;
};

input parse(std::string line) {
    input I;
    I.S = line;
    
    return I;
}

output solve(input I){
    output O;
   
    std::vector<int> cnt(26, 0);
    for (char s : I.S) {
        cnt[s-'A']++;
    }
    
    while (cnt['Z'-'A']) {
      cnt['Z'-'A']--;
      cnt['E'-'A']--;
      cnt['R'-'A']--;
      cnt['O'-'A']--;
      O.S += "0";
    }
    while (cnt['W'-'A']) {
      cnt['T'-'A']--;
      cnt['W'-'A']--;
      cnt['O'-'A']--;
      O.S += "2";
    } 
    while (cnt['U'-'A']) {
      cnt['F'-'A']--;
      cnt['O'-'A']--;
      cnt['U'-'A']--;
      cnt['R'-'A']--;
      O.S += "4";
    }
    while (cnt['O'-'A']) {
      cnt['O'-'A']--;
      cnt['N'-'A']--;
      cnt['E'-'A']--;
      O.S += "1";
    }
    while (cnt['F'-'A']) {
      cnt['F'-'A']--;
      cnt['I'-'A']--;
      cnt['V'-'A']--;
      cnt['E'-'A']--;
      O.S += "5";
    }
    while (cnt['V'-'A']) {
      cnt['S'-'A']--;
      cnt['E'-'A']--;
      cnt['V'-'A']--;
      cnt['E'-'A']--;
      cnt['N'-'A']--;
      O.S += "7";
    }
    while (cnt['X'-'A']) {
      cnt['S'-'A']--;
      cnt['I'-'A']--;
      cnt['X'-'A']--;
      O.S += "6";
    }
    while (cnt['G'-'A']) {
      cnt['E'-'A']--;
      cnt['I'-'A']--;
      cnt['G'-'A']--;
      cnt['H'-'A']--;
      cnt['T'-'A']--;
      O.S += "8";
    }
    while (cnt['N'-'A']) {
      cnt['N'-'A']--;
      cnt['I'-'A']--;
      cnt['N'-'A']--;
      cnt['E'-'A']--;
      O.S += "9";
    }
    while (cnt['T'-'A']) {
      cnt['T'-'A']--;
      cnt['H'-'A']--;
      cnt['R'-'A']--;
      cnt['E'-'A']--;
      cnt['E'-'A']--;
      O.S += "3";
    }
    std::sort(O.S.begin(), O.S.end());
    for (uint32_t i = 0; i < 26; i++) {
        if (cnt[i] != 0) {
            std::cerr << "ERROR" << i << "\n";
        }
    }
    
    return O;
}

void print(output O, uint32_t line) {
    std::cout << "Case #" << line << ": ";
    std::cout << O.S;
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