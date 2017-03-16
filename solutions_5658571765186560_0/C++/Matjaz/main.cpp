#include <stdio.h>
#include <string>

using namespace std;

int number_of_cases;


string solve(int x,int c,int r){
    
    string lose="RICHARD";
    string win="GABRIEL";
    
  //  if (x==4) printf("%d %d %d\n",x,c,r);
    
    if (c>r) swap(c,r);
    
    if (x>=7) return lose;
    if ((r*c)%x!=0) return lose;
    
    if (x==1) return win;
    if (x==2) return win;
    if (x==3){
        if (r*c==3) return lose;
        return win;
    }
    
    if (x==4){
        
        if (r==4&&c==3) return win;
        if (r==4&&c==4) return win;
        return lose;
    
    }
    if (x==5){
        
        
    }
    if (x==6){
        
        
    }
    
    return win;
    
    
}

int main() {
    scanf("%d",&number_of_cases);
    
    for (int case_number=1;case_number<=number_of_cases;case_number++){
        int x,r,c;
        scanf("%d %d %d",&x,&r,&c);
        printf("Case #%d: %s\n",case_number,solve(x,c,r).c_str());
        
    }
    

    return 0;
}
