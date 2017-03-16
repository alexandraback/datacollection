#include <bits/stdc++.h>

std::string s1, s2;
unsigned long long i1, i2;
//int dp[20][10][10][3] = {};

unsigned long long uabs(unsigned long long a, unsigned long long b){
    return std::max(a, b) - std::min(a, b);
}

int main(){
    int T;
    std::cin >> T;
    for(int t=1; t<=T; ++t){
        std::cin >> s1 >> s2;
        i1 = 0; i2 = 0;
        
        /*for(int i=0; i<s1.size(); ++i){
            if(s1[i] != '?' && s2[i] != '?' && s1[i] != s2[i]){
                if(s1[i] < s2[i]) {
                    for(int j=i+1; j<s1.size(); ++j){
                        if(s1[j] == '?') s1[j] = '9';
                        if(s2[j] == '?') s2[j] = '0';
                    }
                }else{
                    for(int j=i+1; j<s1.size(); ++j){
                        if(s1[j] == '?') s1[j] = '0';
                        if(s2[j] == '?') s2[j] = '9';
                    }
                }
            }
        }*/
        
        unsigned long long bdiff = ULLONG_MAX;
        unsigned long long b1, b2;
        for(size_t i=0; i<s1.size(); ++i){
            if(s1[i] == '?' && s2[i] == '?') {
                unsigned long long i1c = i1, i2c = i2;
                i1c = i1c*10 + 0;
                i2c = i2c*10 + 1;
                
                for(size_t j=i+1; j<s1.size(); ++j){
                    i1c *= 10;
                    if(s1[j] == '?') i1c += 9;
                    else i1c += (s1[j] - '0');
                    i2c *= 10;
                    if(s2[j] == '?') i2c += 0;
                    else i2c += (s2[j] - '0');
                }
                
                if(uabs(i1c, i2c) < bdiff){
                    b1 = i1c;
                    b2 = i2c;
                    bdiff = uabs(i1c, i2c);
                }else if(uabs(i1c, i2c) == bdiff){
                    if(i1c < b1 || (i1c == b1 && i2c < b2)){
                        b1 = i1c;
                        b2 = i2c;
                        bdiff = uabs(i1c, i2c);
                    }
                }
                
                i1c = i1;
                i2c = i2;
                i1c = i1c*10 + 1;
                i2c = i2c*10 + 0;
                //std::cout << "# " << i1c << " " << i2c << std::endl;

                for(size_t j=i+1; j<s1.size(); ++j){
                    i1c *= 10;
                    if(s1[j] == '?') i1c += 0;
                    else i1c += (s1[j] - '0');
                    i2c *= 10;
                    if(s2[j] == '?') i2c += 9;
                    else i2c += (s2[j] - '0');
                }
                
                //std::cout << "@ " << i1c << " " << i2c << std::endl;
                
                if(uabs(i1c, i2c) < bdiff){
                    b1 = i1c;
                    b2 = i2c;
                    bdiff = uabs(i1c, i2c);
                }else if(uabs(i1c, i2c) == bdiff){
                    if(i1c < b1 || (i1c == b1 && i2c < b2)){
                        b1 = i1c;
                        b2 = i2c;
                        bdiff = uabs(i1c, i2c);
                    }
                }
                
                i1*=10;
                i2*=10;
            }else if(s1[i] == '?'){
                unsigned long long i1c = i1, i2c = i2;
                if(s2[i] != '0'){
                    i1c = i1c*10 + (s2[i] - '0')-1;
                    i2c = i2c*10 + (s2[i] - '0');
                    
                    for(size_t j=i+1; j<s1.size(); ++j){
                        i1c *= 10;
                        if(s1[j] == '?') i1c += 9;
                        else i1c += (s1[j] - '0');
                        i2c *= 10;
                        if(s2[j] == '?') i2c += 0;
                        else i2c += (s2[j] - '0');
                    }
                    
                    if(uabs(i1c, i2c) < bdiff){
                        b1 = i1c;
                        b2 = i2c;
                        bdiff = uabs(i1c, i2c);
                    }else if(uabs(i1c, i2c) == bdiff){
                        if(i1c < b1 || (i1c == b1 && i2c < b2)){
                            b1 = i1c;
                            b2 = i2c;
                            bdiff = uabs(i1c, i2c);
                        }
                    }
                }
                
                if(s2[i] != '9'){
                    i1c = i1;
                    i2c = i2;
                    i1c = i1c*10 + (s2[i] - '0')+1;
                    i2c = i2c*10 + (s2[i] - '0');
                    
                    for(size_t j=i+1; j<s1.size(); ++j){
                        i1c *= 10;
                        if(s1[j] == '?') i1c += 0;
                        else i1c += (s1[j] - '0');
                        i2c *= 10;
                        if(s2[j] == '?') i2c += 9;
                        else i2c += (s2[j] - '0');
                    }
                    
                    if(uabs(i1c, i2c) < bdiff){
                        b1 = i1c;
                        b2 = i2c;
                        bdiff = uabs(i1c, i2c);
                    }else if(uabs(i1c, i2c) == bdiff){
                        if(i1c < b1 || (i1c == b1 && i2c < b2)){
                            b1 = i1c;
                            b2 = i2c;
                            bdiff = uabs(i1c, i2c);
                        }
                    }
                }
                
                i1=i1*10+(s2[i] - '0');
                i2=i2*10+(s2[i] - '0');
            }else if(s2[i] == '?'){
                unsigned long long i1c = i1, i2c = i2;
                if(s1[i] != '0'){
                    i1c = i1c*10 + (s1[i] - '0');
                    i2c = i2c*10 + (s1[i] - '0')-1;
                    
                    for(size_t j=i+1; j<s1.size(); ++j){
                        i1c *= 10;
                        if(s1[j] == '?') i1c += 0;
                        else i1c += (s1[j] - '0');
                        i2c *= 10;
                        if(s2[j] == '?') i2c += 9;
                        else i2c += (s2[j] - '0');
                    }
                    
                    if(uabs(i1c, i2c) < bdiff){
                        b1 = i1c;
                        b2 = i2c;
                        bdiff = uabs(i1c, i2c);
                    }else if(uabs(i1c, i2c) == bdiff){
                        if(i1c < b1 || (i1c == b1 && i2c < b2)){
                            b1 = i1c;
                            b2 = i2c;
                            bdiff = uabs(i1c, i2c);
                        }
                    }
                }
                
                if(s1[i] != '9'){
                    i1c = i1;
                    i2c = i2;
                    i1c = i1c*10 + (s1[i] - '0');
                    i2c = i2c*10 + (s1[i] - '0')+1;
                    
                    //std::cout << i1c << " " << i2c << std::endl;
                    
                    for(size_t j=i+1; j<s1.size(); ++j){
                        i1c *= 10;
                        if(s1[j] == '?') i1c += 9;
                        else i1c += (s1[j] - '0');
                        i2c *= 10;
                        if(s2[j] == '?') i2c += 0;
                        else i2c += (s2[j] - '0');
                    }
                                        
                    if(uabs(i1c, i2c) < bdiff){
                        b1 = i1c;
                        b2 = i2c;
                        bdiff = uabs(i1c, i2c);
                    }else if(uabs(i1c, i2c) == bdiff){
                        if(i1c < b1 || (i1c == b1 && i2c < b2)){
                            b1 = i1c;
                            b2 = i2c;
                            bdiff = uabs(i1c, i2c);
                        }
                    }
                }
                
                i1=i1*10+(s1[i] - '0');
                i2=i2*10+(s1[i] - '0');
            }else{
                i1=i1*10+(s1[i] - '0');
                i2=i2*10+(s2[i] - '0');
                
                unsigned long long i1c = i1, i2c = i2;
                if(i1 < i2){
                    for(size_t j=i+1; j<s1.size(); ++j){
                        i1c *= 10;
                        if(s1[j] == '?') i1c += 9;
                        else i1c += (s1[j] - '0');
                        i2c *= 10;
                        if(s2[j] == '?') i2c += 0;
                        else i2c += (s2[j] - '0');
                    }
                    
                    //std::cout << "$ " << i1c << " " << i2c << " " << (uabs(i1c, i2c)) << std::endl;
                    
                    if(uabs(i1c, i2c) < bdiff){
                        b1 = i1c;
                        b2 = i2c;
                        bdiff = uabs(i1c, i2c);
                    }else if(uabs(i1c, i2c) == bdiff){
                        if(i1c < b1 || (i1c == b1 && i2c < b2)){
                            b1 = i1c;
                            b2 = i2c;
                            bdiff = uabs(i1c, i2c);
                        }
                    }
                }else{                    
                    for(size_t j=i+1; j<s1.size(); ++j){
                        i1c *= 10;
                        if(s1[j] == '?') i1c += 0;
                        else i1c += (s1[j] - '0');
                        i2c *= 10;
                        if(s2[j] == '?') i2c += 9;
                        else i2c += (s2[j] - '0');
                    }
                                        
                    if(uabs(i1c, i2c) < bdiff){
                        b1 = i1c;
                        b2 = i2c;
                        bdiff = uabs(i1c, i2c);
                    }else if(uabs(i1c, i2c) == bdiff){
                        if(i1c < b1 || (i1c == b1 && i2c < b2)){
                            b1 = i1c;
                            b2 = i2c;
                            bdiff = uabs(i1c, i2c);
                        }
                    }
                }
            }
            
            //std::cout << i1 << " " << i2 << std::endl;
        }
        
        if(uabs(i1, i2) < bdiff){
            b1 = i1;
            b2 = i2;
            bdiff = uabs(i1, i2);
        }else if(uabs(i1, i2) == bdiff){
            if(i1 < b1 || (i1 == b1 && i2 < b2)){
                b1 = i1;
                b2 = i2;
                bdiff = uabs(i1, i2);
            }
        }
        
        std::cout << "Case #" << t << ": " << std::setfill('0') << std::setw(s1.size()) << b1 << " " << std::setfill('0') << std::setw(s1.size()) << b2;
        //std::cout << " " << s1 << " " << s2;
        std::cout << std::endl;
        //break;
    }
}
