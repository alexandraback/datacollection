#include<iostream>
#include<fstream>
#include<sstream>
#include<array>
#include<algorithm>
#include<vector>
#include<map>

typedef unsigned long long ull;

struct topic {
    std::string S[2];
};

struct input {
  std::vector<topic> C;  
};

struct output {
    uint64_t C;
};



output solve(input I){
    output O;
    std::map<std::string, uint32_t> cnt[2];
    for (auto t : I.C) {
        cnt[0][t.S[0]]++;
        cnt[1][t.S[1]]++;
    }
    std::vector<topic> uniqueF, uniqueS, copy;
    std::vector<topic> rest;
    for (auto t : I.C) {
        if (cnt[0][t.S[0]] == 1) {
            uniqueF.push_back(t);
        }
        else if (cnt[1][t.S[1]] == 1) {
            uniqueS.push_back(t);
        }
        else if (cnt[0][t.S[0]] > 1 && cnt[1][t.S[1]] > 1) {
            copy.push_back(t);
        }
        else {
            rest.push_back(t);
        }
    }
    O.C = copy.size();
    
    return O;
}

void print(output O, uint32_t line) {
    std::cout << "Case #" << line << ": ";
    std::cout << O.C;
    std::cout << "\n";
}

int64_t str2int(std::string S) {
    std::stringstream ss;
    ss << S;
    int64_t N;
    ss >> N;
    return N;
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
        input I;
        uint32_t N = str2int(line);
        for (uint32_t i = 0; i < N; i++) {
            std::getline(ifs, line);
            std::stringstream ss;
            ss << line;
            topic C;
            ss >> C.S[0] >> C.S[1];
            I.C.push_back(C);
        }
        output O = solve(I);
        print(O, lineNr++);
    }
}