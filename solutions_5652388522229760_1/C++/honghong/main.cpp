//
//  main.cpp
//  Counting Sheep
//
//  Created by Hong Eunpyeong on 2016. 4. 9..
//  Copyright © 2016년  Hong Eunpyeong. All rights reserved.
//

#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, const char * argv[]) {
    int tc;
    long N;
    ifstream fin("input.txt");
    ofstream fout("output.txt");
    fin >> tc;
    bool num[10];
    bool flag;
    for(int i = 0; i < tc; i++){
        fin >> N;
        fout << "Case #" << i+1 << ": ";
        if(N == 0){
            fout << "INSOMNIA\n";
        } else{
            
            for(int j = 0; j < 10; j++) num[j] = false;
            
            long tmp, n;
            int k = 0;
            long result;
            
            while(true){
                k++;
                n = N*k;
                result = n;

                tmp = (n/10)*10;
                
                flag = false;
                
                while(n != 0){
                    if(num[n - tmp] == false){
                        num[n-tmp] = true;
                        flag = true;
                        for(int j = 0; j < 10; j++){
                            if(num[j] == false){
                                //fail
                                flag = false;
                                break;
                            }
                        }
                        if(flag) break;
                        else flag = false;
                    }
                    
                    n /= 10;
                    tmp = (n/10)*10;
                }
                if(flag) break;
            }
            fout << result << endl;
        }
    }
    return 0;
}
