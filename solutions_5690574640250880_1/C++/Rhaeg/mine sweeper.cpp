#include <cstdio>
#define SORT(A) sort(A.begin(),A.end())
#define fori(l,n) for(int l=1;l<=n;l++)
int main() {
	int I,IT,nada;
	//int p,q,ii,jj,res,;

//	int A[100][100],B[100],C[100];
   freopen("C-large.in","r",stdin);
   freopen("minesweeperlarge.out","w",stdout);
    char A[60][60];
    int R,C,M;    
    int i,j,ban,e;
    int L,LL,p;
    I=1;
    scanf("%d", &IT); 
    
    while(I<=IT){                 

       scanf("%d %d %d", &R, &C, &M); 
          fori(ii,R)
             fori(jj,C)
                A[ii][jj]='*';
       
       ban=1; e=R*C-M;
       if(e==1){
          ban=2;
       }
       
       if(ban==1 && C==1){
          fori(ii,e)
            A[ii][1]='.';
          ban=2;
       }
       
       if(ban==1 && R==1){
          fori(jj,e)
            A[1][jj]='.';
          ban=2;
       }
       
       if(ban==1 && C==2){
          if(e%2==0 && e>=4){
             fori(ii,e/2){
                A[ii][1]='.';
                A[ii][2]='.';
             }
             ban=2;
          }
          else{
             ban=0;
          }
       }
       if(ban==1 && R==2){
          if(e%2==0 && e>=4){
             fori(jj,e/2){
                A[1][jj]='.';
                A[2][jj]='.';
             }
             ban=2;
          }
          else{
             ban=0;
          }
       }
       //PRINCIPAL
       if(ban==1){  
          L=e/C;
          p=e%C;
          if(L>=3){
             fori(ii,L){
                fori(jj,C){
                   A[ii][jj]='.';
                }
             }
             if(p>1){
                fori(jj,p)
                 A[L+1][jj]='.';
             }
             else{
                if(p==1){
                   A[L+1][1]='.';
                   A[L+1][2]='.';
                   A[L][C]='*';
                }
              }
           ban=2;
          } 
          else{
             LL=e/3;
             
             switch(e){
                case 2:ban=0;break;
                case 3:ban=0;break;
                case 4:ban=2; A[1][1]='.';A[1][2]='.';A[2][1]='.';A[2][2]='.';break;
                case 5:ban=0;break;
                case 7:ban=0;break;
             }
             if(ban==1){
                fori(ii,3)
                   fori(jj,LL)
                      A[ii][jj]='.';
                p=e%3;
                if(p==1){
                   A[1][LL+1]='.';
                   A[2][LL+1]='.';
                   A[3][LL]='*';
                }
                else{
                   if(p==2){
                      A[1][LL+1]='.';
                      A[2][LL+1]='.';                   
                   }
                }
                ban=2;
             }
          
          }      
          
        }
      //RESPUESTA
       A[1][1]='c';
       
       if(ban==2){
         printf("Case #%d:\n",I);
          fori(ii,R){
             fori(jj,C)       
             printf("%c",A[ii][jj]);
             printf("\n");
             
          }     
       }
       else 
        printf("Case #%d:\nImpossible\n",I);
         // printf("Case #%d: %f\n",I,ta);          
      
       I++;
    }
    scanf("%d", &nada); 
	return 0;
}

