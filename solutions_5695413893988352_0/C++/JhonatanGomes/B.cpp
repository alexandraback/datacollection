#include <cstdio>
#include <cmath>
#include <cstring>
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <utility>
#include <queue>
#include <stack>
#include <vector>
using namespace std;


int main(){
    int t, TC=1;
    string c, J;
    set<int> all_c, all_J;

    scanf("%d", &t);

    while(t--){
        cin >> c >> J;
        //printf("%c\n", c[0]);
        if(c.size() == 1){
            if(c[0] == '?'){
                for(int i = 0 ; i < 10 ; i++)
                    all_c.insert(i);
            }
            else{
                all_c.insert(c[0]-'0');
            }
        }
        else if(c.size() == 2){
            if(c[0] == '?' && c[1] == '?'){
                for(int i = 0 ; i < 100 ; i++){
                    all_c.insert(i);
                }
            }
            else if(c[0] != '?' && c[1] != '?'){
                all_c.insert((c[0]-'0') * 10 + (c[1] - '0'));
            }
            else{
                if(c[0] == '?'){
                    for(int i = 0 ; i < 10 ; i++){
                        all_c.insert(i*10 + (c[1]-'0'));
                    }
                }
                else{
                    for(int i = 0 ; i < 10 ; i++){
                        all_c.insert((c[0]-'0')*10 + i);
                    }
                }
            }
        }
        else{
            if(c[0] == '?' && c[1] == '?' && c[2] == '?'){ /// 3 ?
                for(int i = 0 ; i < 1000 ; i++)
                    all_c.insert(i);
            }
            else if(c[0] != '?' && c[1] != '?' && c[2] != '?'){ /// 0 ?
                all_c.insert((c[0]-'0')*100 + (c[1]-'0')*10 + (c[2]-'0'));
            }
            else if((c[0] == '?' && c[1] != '?' && c[2] != '?') ||
                    (c[0] != '?' && c[1] == '?' && c[2] != '?') ||
                    (c[0] != '?' && c[1] != '?' && c[2] == '?') ){ /// 1 ?

                if((c[0] == '?' && c[1] != '?' && c[2] != '?')){
                    for(int i = 0 ; i < 10 ; i++){
                        all_c.insert(i*100 + (c[1]-'0')*10 + (c[2]-'0'));
                    }
                }
                else if((c[0] != '?' && c[1] == '?' && c[2] != '?')){
                    for(int i = 0 ; i < 10 ; i++){
                        all_c.insert((c[0]-'0')*100 + i*10 + (c[2]-'0'));
                    }
                }
                else{
                    for(int i = 0 ; i < 10 ; i++){
                        all_c.insert((c[0]-'0')*100 + (c[1]-'0')*10 + i);
                    }
                }

            }
            else{ /// 2 ?
                if(c[0] == '?' && c[1] == '?'){
                    for(int i = 0 ; i < 10 ; i++){
                        for(int j = 0 ; j < 10 ; j++){
                            all_c.insert(i*100 + j*10 + (c[2]-'0'));
                        }
                    }
                }
                else if(c[1] == '?' && c[2] == '?'){
                    for(int i = 0 ; i < 10 ; i++){
                        for(int j = 0 ; j < 10 ; j++){
                            all_c.insert((c[0]-'0')*100 + i*10 + j);
                        }
                    }
                }
                else{ /// c[0] e c[2]
                    for(int i = 0 ; i < 10 ; i++){
                        for(int j = 0 ; j < 10 ; j++){
                            all_c.insert(i*100 + (c[1]-'0')*10 + j);
                        }
                    }
                }
            }
        }


        /// for j
        if(J.size() == 1){
            if(J[0] == '?'){
                for(int i = 0 ; i < 10 ; i++)
                    all_J.insert(i);
            }
            else{
                all_J.insert(J[0]-'0');
            }
        }
        else if(J.size() == 2){
            if(J[0] == '?' && J[1] == '?'){
                for(int i = 0 ; i < 100 ; i++){
                    all_J.insert(i);
                }
            }
            else if(J[0] != '?' && J[1] != '?'){
                all_J.insert((J[0]-'0') * 10 + (J[1] - '0'));
            }
            else{
                if(J[0] == '?'){
                    for(int i = 0 ; i < 10 ; i++){
                        all_J.insert(i*10 + (J[1]-'0'));
                    }
                }
                else{
                    for(int i = 0 ; i < 10 ; i++){
                        all_J.insert((J[0]-'0')*10 + i);
                    }
                }
            }
        }
        else{
            if(J[0] == '?' && J[1] == '?' && J[2] == '?'){ /// 3 ?
                for(int i = 0 ; i < 1000 ; i++)
                    all_J.insert(i);
            }
            else if(J[0] != '?' && J[1] != '?' && J[2] != '?'){ /// 0 ?
                all_J.insert((J[0]-'0')*100 + (J[1]-'0')*10 + (J[2]-'0'));
            }
            else if((J[0] == '?' && J[1] != '?' && J[2] != '?') ||
                    (J[0] != '?' && J[1] == '?' && J[2] != '?') ||
                    (J[0] != '?' && J[1] != '?' && J[2] == '?') ){ /// 1 ?

                if((J[0] == '?' && J[1] != '?' && J[2] != '?')){
                    for(int i = 0 ; i < 10 ; i++){
                        all_J.insert(i*100 + (J[1]-'0')*10 + (J[2]-'0'));
                    }
                }
                else if((J[0] != '?' && J[1] == '?' && J[2] != '?')){
                    for(int i = 0 ; i < 10 ; i++){
                        all_J.insert((J[0]-'0')*100 + i*10 + (J[2]-'0'));
                    }
                }
                else{
                    for(int i = 0 ; i < 10 ; i++){
                        all_J.insert((J[0]-'0')*100 + (J[1]-'0')*10 + i);
                    }
                }

            }
            else{ /// 2 ?
                if(J[0] == '?' && J[1] == '?'){
                    for(int i = 0 ; i < 10 ; i++){
                        for(int j = 0 ; j < 10 ; j++){
                            all_J.insert(i*100 + j*10 + (J[2]-'0'));
                        }
                    }
                }
                else if(J[1] == '?' && J[2] == '?'){
                    for(int i = 0 ; i < 10 ; i++){
                        for(int j = 0 ; j < 10 ; j++){
                            all_J.insert((J[0]-'0')*100 + i*10 + j);
                        }
                    }
                }
                else{ /// J[0] e J[2]
                    for(int i = 0 ; i < 10 ; i++){
                        for(int j = 0 ; j < 10 ; j++){
                            all_J.insert(i*100 + (J[1]-'0')*10 + j);
                        }
                    }
                }
            }
        }

        int menor_dif = 100000, menor_c=0, menor_j=0;
        for(set<int>::iterator it_c = all_c.begin() ; it_c != all_c.end() ; it_c++){
             for(set<int>::iterator it_J = all_J.begin() ; it_J != all_J.end() ; it_J++){
                if(abs(*it_c - *it_J) < menor_dif){
                    menor_dif = abs(*it_c - *it_J);
                    menor_c = *it_c; menor_j = *it_J;
                }
             }
        }

        printf("Case #%d: %0*d %0*d\n", TC++, c.size(), menor_c, J.size(), menor_j);


        all_c.clear();
        all_J.clear();
    }

    return 0;
}
