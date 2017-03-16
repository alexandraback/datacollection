#include <cstdio>
#include <cstring>
#include <vector>
#include <string>
#include <cstdlib>

using namespace std;

#define INF (1ll << 60)

char C[20], J[20], tmpc[20], tmpj[20];

int main(){
    int T, tc = 0;
    scanf("%d", &T);
    
    while(T--){
        scanf("%s%s", C, J);
        
        tmpc[strlen(C)] = '\0';
        tmpj[strlen(J)] = '\0';
        
        long long A = INF, B = 0;
        
        for(int i=0; C[i]!='\0'; i++){
            //printf("pos = %d\n", i);
            
            if(C[i] == '?' and J[i] == '?'){
                tmpc[i] = '0'; tmpj[i] = '1';
                
                for(int j=i+1; C[j]!='\0'; j++){
                    tmpc[j] = C[j];
                    tmpj[j] = J[j];
                    if(C[j] == '?') tmpc[j] = '9';
                    if(J[j] == '?') tmpj[j] = '0';
                }
                
                long long a = atoll(tmpc), b = atoll(tmpj);
                
                if(abs(a-b) < abs(A-B)){
                    A = a; B = b;
                } else if(abs(a-b) == abs(A-B)){
                    if(a < A or a == A and b < B){
                        A = a; B = b;
                    }
                }
                
                //printf("%s %s or ", tmpc, tmpj);
                tmpc[i] = '1'; tmpj[i] = '0';
                
                for(int j=i+1; C[j]!='\0'; j++){
                    tmpc[j] = C[j];
                    tmpj[j] = J[j];
                    if(C[j] == '?') tmpc[j] = '0';
                    if(J[j] == '?') tmpj[j] = '9';
                }
                
                a = atoll(tmpc), b = atoll(tmpj);
                
                if(abs(a-b) < abs(A-B)){
                    A = a; B = b;
                } else if(abs(a-b) == abs(A-B)){
                    if(a < A or a == A and b < B){
                        A = a; B = b;
                    }
                }
                
                //printf("%s %s\n", tmpc, tmpj);
                tmpc[i] = tmpj[i] = '0';
                continue;
            }
            
            if(C[i] == '?'){
                tmpc[i] = tmpj[i] = J[i];
                
                if(J[i] < '9'){                
                    tmpc[i]++;
                    
                    for(int j=i+1; C[j]!='\0'; j++){
                        tmpc[j] = C[j];
                        tmpj[j] = J[j];
                        if(C[j] == '?') tmpc[j] = '0';
                        if(J[j] == '?') tmpj[j] = '9';
                    }
                    
                    long long a = atoll(tmpc), b = atoll(tmpj);
                    
                    if(abs(a-b) < abs(A-B)){
                        A = a; B = b;
                    } else if(abs(a-b) == abs(A-B)){
                        if(a < A or a == A and b < B){
                            A = a; B = b;
                        }
                    }
                }
                
                //printf("%s %s or ", tmpc, tmpj);
                tmpc[i] = tmpj[i] = J[i];
                
                if(J[i] > '0'){
                    tmpc[i]--;
                    
                    for(int j=i+1; C[j]!='\0'; j++){
                        tmpc[j] = C[j];
                        tmpj[j] = J[j];
                        if(C[j] == '?') tmpc[j] = '9';
                        if(J[j] == '?') tmpj[j] = '0';
                    }
                    
                    long long a = atoll(tmpc), b = atoll(tmpj);
                    
                    if(abs(a-b) < abs(A-B)){
                        A = a; B = b;
                    } else if(abs(a-b) == abs(A-B)){
                        if(a < A or a == A and b < B){
                            A = a; B = b;
                        }
                    }
                }
                
                //printf("%s %s\n", tmpc, tmpj);
                tmpc[i] = tmpj[i] = J[i];                
                continue;
            }
            
            if(J[i] == '?'){
                tmpc[i] = tmpj[i] = C[i];
                
                if(C[i] < '9'){                
                    tmpj[i]++;
                    
                    for(int j=i+1; C[j]!='\0'; j++){
                        tmpc[j] = C[j];
                        tmpj[j] = J[j];
                        if(C[j] == '?') tmpc[j] = '9';
                        if(J[j] == '?') tmpj[j] = '0';
                    }
                    
                    long long a = atoll(tmpc), b = atoll(tmpj);
                    
                    if(abs(a-b) < abs(A-B)){
                        A = a; B = b;
                    } else if(abs(a-b) == abs(A-B)){
                        if(a < A or a == A and b < B){
                            A = a; B = b;
                        }
                    }
                }
                
               // printf("%s %s or ", tmpc, tmpj);
                tmpc[i] = tmpj[i] = C[i];
                
                if(C[i] > '0'){
                    tmpj[i]--;
                    
                    for(int j=i+1; C[j]!='\0'; j++){
                        tmpc[j] = C[j];
                        tmpj[j] = J[j];
                        if(C[j] == '?') tmpc[j] = '0';
                        if(J[j] == '?') tmpj[j] = '9';
                    }
                    
                    long long a = atoll(tmpc), b = atoll(tmpj);
                    
                    if(abs(a-b) < abs(A-B)){
                        A = a; B = b;
                    } else if(abs(a-b) == abs(A-B)){
                        if(a < A or a == A and b < B){
                            A = a; B = b;
                        }
                    }
                }
                
                //printf("%s %s\n", tmpc, tmpj);
                tmpc[i] = tmpj[i] = C[i];                
                continue;
            }
            
            if(C[i] < J[i]){
                for(int j=i; C[j]!='\0'; j++){
                    tmpc[j] = C[j];
                    tmpj[j] = J[j];
                    if(C[j] == '?') tmpc[j] = '9';
                    if(J[j] == '?') tmpj[j] = '0';
                }
            
                long long a = atoll(tmpc), b = atoll(tmpj);
                
                if(abs(a-b) < abs(A-B)){
                    A = a; B = b;
                } else if(abs(a-b) == abs(A-B)){
                    if(a < A or a == A and b < B){
                        A = a; B = b;
                    }
                }
                
                break;
            }
            
            if(C[i] > J[i]){
                for(int j=i; C[j]!='\0'; j++){
                    tmpc[j] = C[j];
                    tmpj[j] = J[j];
                    if(C[j] == '?') tmpc[j] = '0';
                    if(J[j] == '?') tmpj[j] = '9';
                }
            
                long long a = atoll(tmpc), b = atoll(tmpj);
                
                if(abs(a-b) < abs(A-B)){
                    A = a; B = b;
                } else if(abs(a-b) == abs(A-B)){
                    if(a < A or a == A and b < B){
                        A = a; B = b;
                    }
                }
                
                break;
            }
            
            tmpc[i] = tmpj[i] = C[i];
        }
        
        long long a = atoll(tmpc), b = atoll(tmpj);
                
        if(abs(a-b) < abs(A-B)){
            A = a; B = b;
        } else if(abs(a-b) == abs(A-B)){
            if(a < A or a == A and b < B){
                A = a; B = b;
            }
        }
        
        printf("Case #%d: ", ++tc);
        
        int sz = !A ? 1 : 0;
        long long tmp = A;
        while(tmp){
            tmp /= 10;
            sz++;
        }
        
        for(int i=0; i<strlen(C)-sz; i++) printf("0");
        printf("%lld ", A);
        
        sz = !B ? 1 : 0;
        tmp = B;
        while(tmp){
            tmp /= 10;
            sz++;
        }
        
        for(int i=0; i<strlen(C)-sz; i++) printf("0");
        printf("%lld\n", B);
    }
}
