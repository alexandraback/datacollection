#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <set>

using namespace std;

int main(){
    
    int n,a,b,i,j,k,x,teste;
    char number[9];
    char aux;
    long long int cont;
    
    set < pair<int,int> > st;
    
    scanf("%d",&n);
    
    
    teste = 1;
    while(n--){
      scanf("%d %d",&a,&b);
      
      cont = 0LL;
      for(i=a;i<=b;i++){
        sprintf(number,"%d",i);
        for(j=0;j<strlen(number)-1;j++){
           aux = number[0];
           for(k=0;k<strlen(number)-1;k++){
             number[k] = number[k+1];
           }
           number[strlen(number)-1] = aux;
           sscanf(number,"%d",&x);
           if(x > i && x <= b){
                
                if(st.find(pair<int,int>(i,x)) == st.end() ){
                     st.insert(pair<int,int>(i,x));
										 cont++;
							  }
           }   
        }
      }
      
      printf("Case #%d: %lld\n",teste++,cont);
    	st.clear();
    
    
    }
    
    //system("PAUSE");

}
