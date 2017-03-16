#include <cstdlib>
#include <fstream>
#include <string>
#include <cmath>

using namespace std;

ofstream fout;
int R, C, M;


void draw(int dotNum){
   for(int i = 0; i < dotNum; i++){
      fout << ".";
   }
   for(int i = 0; i < C - dotNum; i++){
      fout << "*";
   }
   fout << "\n";
}

void drawEx(int dotNum){
   for(int i = 0; i < dotNum; i++){
      fout << ".";
   }
   for(int i = 0; i < C - dotNum - 1; i++){
      fout << "*";
   }
   fout << "\n";
}


int main(){

   ifstream fin("C-large.in");
   fout.open("C-large.out");

   string buf;

   getline(fin, buf);
   int T = atoi(buf.c_str());

   for(int i = 0; i < T; i++){
      fout << "Case #" << (i + 1) << ":\n";

      getline(fin, buf, ' ');
      R = atoi(buf.c_str());
      getline(fin, buf, ' ');
      C = atoi(buf.c_str());
      getline(fin, buf, '\n');
      M = atoi(buf.c_str());

      if(M == R * C - 1){
         fout << "c";
	 drawEx(0);
         for(int j = 1; j < R; j++){
	    draw(0);
	 }
      }
      else if(R == 1){
         if(M < C - 1){
	    fout << "c";
	    drawEx(C - M - 1);
	 }
	 else{
            fout << "Impossible\n";
	 }
      }
      else if(C == 1){
         if(M < R - 1){
	    fout << "c\n";
	    for(int j = 0; j < R - M - 1; j++){
               fout << ".\n";
	    }    
            for(int j = 0; j < M; j++){
               fout << "*\n";
	    }
	 }
	 else{
            fout << "Impossible\n";
	 }
      }
      else if(R == 2){
         if(M < 2 * C - 2 && M % 2 == 0){
	    fout << "c";
	    drawEx(C - M / 2 - 1);
	    draw(C - M / 2);
	 }
	 else{
            fout << "Impossible\n";
	 }
      }
      else if(C == 2){
         if(M < 2 * R - 2 && M % 2 == 0){
	    fout << "c.\n";
	    for(int j = 0; j < R - M / 2 - 1; j++){
               fout << "..\n";
	    }
            for(int j = 0; j < M / 2; j++){
               fout << "**\n";
	    }
	 }
	 else{
            fout << "Impossible\n";
	 }
      }
      else{
         int restSpace = R * C - M;
	 if(restSpace == 2 || restSpace == 3 || restSpace == 5 || restSpace == 7){
            fout << "Impossible\n";
	 }
	 else{
	    fout << "c";
            int minRC = min(R, C);
	    int sqrtRestSpace = static_cast<int>(sqrt(restSpace));
	    int restSpaceR, restSpaceC;
	    if(sqrtRestSpace * (sqrtRestSpace + 1) < restSpace){
	       restSpaceR = restSpaceC = sqrtRestSpace + 1;  
	    }
	    else{
               restSpaceR = restSpaceC = sqrtRestSpace;
	    }
	    if(minRC == R){
               if(restSpaceR < R){
		  restSpaceC = restSpace / restSpaceR;
                  int rem = restSpace % restSpaceR;
		  if(rem == 1){
		     drawEx(restSpaceC);
		     draw(restSpaceC + 1);
                     for(int j = 0; j < restSpaceR - 3; j++){
			draw(restSpaceC);
		     }
		     draw(restSpaceC - 1);
		     for(int j = 0; j < R - restSpaceR; j++){
                        draw(0);
		     }
		  }
		  else{
		     drawEx(restSpaceC - ((rem > 0)? 0 : 1));
		     for(int j = 0; j < rem - 1; j++){
			draw(restSpaceC + 1);
		     }
                     for(int j = 0; j < restSpaceR - rem - ((rem > 0)? 0 : 1); j++){
			draw(restSpaceC);
		     }
		     for(int j = 0; j < R - restSpaceR; j++){
			draw(0);
		     }
		  }
	       }
	       else{
                  int rem = restSpace % R;
		  restSpaceC = restSpace / R;
		  if(rem == 1){
                     drawEx(restSpaceC);
		     draw(restSpaceC + 1);
		     for(int j = 0; j < R - 3; j++){
                        draw(restSpaceC);
		     }
		     draw(restSpaceC - 1);
		  }
		  else{
                     drawEx(restSpaceC - 1 + ((rem > 0)? 1 : 0));
		     for(int j = 0; j < rem - 1; j++){
                        draw(restSpaceC + 1);
		     }
		     for(int j = 0; j < R - rem - ((rem > 0)? 0 : 1); j++){
                        draw(restSpaceC);
		     }
		  }
	       }
	    }
	    //minRC == C
	    else{
	       if(sqrtRestSpace < C){
		  restSpaceR = restSpace / restSpaceC;
                  int rem = restSpace % restSpaceC;
		  if(rem == 1){
		     drawEx(restSpaceC - 1);
                     for(int j = 0; j < restSpaceR - 2; j++){
			draw(restSpaceC);
		     }
		     draw(restSpaceC - 1);
		     draw(2);
		     for(int j = 0; j < R - restSpaceR - 1; j++){
                        draw(0);
		     }
		  }
		  else{
		     drawEx(restSpaceC - 1);
		     for(int j = 0; j < restSpaceR - 1; j++){
			draw(restSpaceC);
		     }
                     if(rem > 0){
                        draw(rem);
		     }
		     for(int j = 0; j < R - restSpaceR - ((rem > 0)? 1 : 0); j++){
                        draw(0);
		     }
		  }
	       }
	       else{
                  int rem = restSpace % C;
		  restSpaceR = restSpace / C;
		  if(rem == 1){
                     drawEx(C - 1);
		     for(int j = 0; j < restSpaceR - 2; j++){
                        draw(C);
		     }
		     draw(C - 1);
		     draw(rem + 1);
		     for(int j = 0; j < R - restSpaceR - 1; j++){
                        draw(0);
		     }
		  }
		  else{
                     drawEx(C - 1);
		     for(int j = 0; j < restSpaceR - 1; j++){
                        draw(C);
		     }
		     if(rem > 0){
		        draw(rem);
		     }
		     for(int j = 0; j < R - restSpaceR - ((rem > 0)? 1 : 0); j++){
                        draw(0);
		     }
		  }
	       }
	    }
	 }
      }
   }


   fin.close();
   fout.close();
}
