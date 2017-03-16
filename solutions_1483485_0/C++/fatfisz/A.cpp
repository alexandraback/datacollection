#include <cstdio>                                                                
                                                                                 
char conv[27] = "yhesocvxduiglbkrztnwjpfmaq";                                    
                                                                                 
int main(void) {                                                                 
    int T;                                                                       
    char C;                                                                      
    scanf("%d\n", &T);                                                           
    for (int t = 1; t <= T; ++t) {                                               
        printf("Case #%d: ", t);                                                 
        for (;;) {                                                               
            scanf("%c", &C);                                                     
            if (C == '\n') {                                                     
                printf("\n");                                                    
                break;                                                           
            }                                                                    
            if (C == ' ') {                                                      
                printf(" ");                                                     
                continue;                                                        
            }                                                                    
            printf("%c", conv[C - 'a']);                                         
        }                                                                        
    }                                                                            
    return 0;                                                                    
}