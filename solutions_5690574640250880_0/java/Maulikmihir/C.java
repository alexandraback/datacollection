package p3;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;

public class C {
	
	
		private static String IMPOSSIBLE = "Impossible" ;
		private static char STAR = '*' ;
		private static char DOT  = '.' ;
		private static char CLICK = 'c' ;
		
	
		public static void main(String args[]){
			
			try{
			
				BufferedReader br = new BufferedReader(new FileReader(args[0]));
				
				String strTmp = br.readLine();
				
				BufferedWriter bw = new BufferedWriter(new FileWriter( new File("output.txt"),false));
				
				
				int inputSize = Integer.parseInt(strTmp);
				
				
				for(int i=0;i<inputSize;i++  ){

				
					// processing inputline
					
					String[] inp = br.readLine().split(" ");
					int R = Integer.parseInt(inp[0]);
					int C = Integer.parseInt(inp[1]);
					int M = Integer.parseInt(inp[2]);
					
					// produce output
					boolean isImpossible = false;
					char[][] out = new char[R][C];
					
					for(int j=0;j<R;j++){
						for(int k=0;k<C;k++){
							out[j][k]=DOT ;
						}
					}
					out[R-1][C-1]=CLICK;
					
					
					// special cases first:
					if(M==0){
						isImpossible = false ;
					}else if(M==(R*C)-1){
						isImpossible = false ;
						
						for(int j=0;j<R;j++){
							for(int k=0;k<C;k++){
								out[j][k]=STAR ;
							}
						}
						out[R-1][C-1]=CLICK;
						
					}else if( (R==1 && C==1) || (R==1 && C==2) || (R==2 && C==1 ) || (R==2 && C==2)  ){
						isImpossible = true ;
					}else if ( R==1 ||  C==1  ) {
						
						if(R==1){
							int max = C-2 ;
							
							if(M>max){
								isImpossible = true;
							}else{
								isImpossible = false;
								int tmpM = M; 
								for(int j=0;j<C-2 &&tmpM>0;j++,tmpM--){
									out[0][j] = STAR ;
						        }
							}
						}else{
							int max = R-2 ;
							
							if(M>max){
								isImpossible = true;
							}else{
								isImpossible = false;
								int tmpM = M; 
								for(int j=0;j<R-2 &&tmpM>0;j++,tmpM--){
									out[j][0] = STAR ;
						        }
							}
						}
					}else if( R==2 || C==2 ){
						
						int max = 0;
								
						if(R==2){
							max = (C-2)*2 ;
						}else{ 
							max = (R-2)*2 ;
						}	
						
						if(M%2!=0 || M > max ){
							isImpossible = true ;
						}else{
							isImpossible = false ;
							int tmpM = M;
							if(R==2){
								for(int j=0;j<C-2 &&tmpM>0;j++,tmpM-=2){
									out[0][j] = STAR ;
									out[1][j] = STAR ;
						        }
							}else{
								for(int j=0;j<R-2 &&tmpM>0;j++,tmpM-=2){
									out[j][0] = STAR ;
									out[j][1] = STAR ;
						        }
							}
							
							
						}
					}else{
						
						int max = R*C - 4 ;
						int outRightYes = (R-2)*(C-2);
						
						if(M>max){
							isImpossible = true ;
						}else if (M <= outRightYes || (M-outRightYes)%2==0 ){
							isImpossible = false ;
							
							// place the star possition
							int tmpM = M ;
							
							// fill the R-2 and C-2 first
							for(int j=0;j<R-2 && tmpM>0 ;j++){
								for (int k=0;k<C-2 && tmpM>0;k++){
									out[j][k] = STAR ;
									tmpM-- ;
								}
							}
							
							// if STAR still remains then fill the last two column strip first
							if( tmpM>0 ){
								
								for(int j=0;j<R-2 && tmpM>0 ;j++){
								
									out[j][C-2] = STAR ;
									out[j][C-1] = STAR ;
									tmpM-=2 ;
									
								}
							}
							
							// if STAR still remains then fill the last two raw strip
							if( tmpM>0 ){
								
								for(int j=0;j<C-2 && tmpM>0 ;j++){
								
									out[R-2][j] = STAR ;
									out[R-1][j] = STAR ;
									tmpM-=2 ;
								}
							}
							
							
							
						}else{ // M > outRightYes && (M-outRightYes)%2!=0
							
							int RC = R*C ;
							
							if(M==(RC-7) || M==(RC-5)){
								isImpossible = true;
							}else{
								isImpossible = false;
								
								// place the star possition
								int tmpM = M ;
								
								// fill the R-2 and C-2 first
								for(int j=0;j<R-2 && tmpM>0 ;j++){
									for (int k=0;k<C-2 && tmpM>0;k++){
										out[j][k] = STAR ;
										tmpM-- ;
									}
								}
								
								if(M!=(RC-6) && M!=(RC-8)){
									out[R-3][C-3] = DOT ;
									tmpM++ ;
								}
								
								// if STAR still remains then fill the last two column strip first
								if( tmpM>0 ){
									
									for(int j=0;j<R-3 && tmpM>0 ;j++){
									
										out[j][C-2] = STAR ;
										out[j][C-1] = STAR ;
										tmpM-=2 ;
										
									}
								}
								
								// if STAR still remains then fill the last two raw strip
								if( tmpM>0 ){
									
									for(int j=0;j<C-3 && tmpM>0 ;j++){
									
										out[R-2][j] = STAR ;
										out[R-1][j] = STAR ;
										tmpM-=2 ;
									}
								}
								
								if(tmpM!=0){
									System.out.println("Something is wrong !");
								}
							}
						}
					}
					
					System.out.println("Case #"+(i+1)+": ");
					bw.write("Case #"+(i+1)+": ");
					bw.newLine();
					if(isImpossible){
						System.out.println(IMPOSSIBLE);
						bw.write(IMPOSSIBLE);
						bw.newLine();
					}else{
						
						for(int j=0;j<R;j++){
							for(int k=0;k<C;k++){
								System.out.print(out[j][k]);
								bw.write(out[j][k]);
							}
							System.out.println();
							bw.newLine();
						}
					}
				}
				
				bw.close();
				br.close();
			
			
			}catch(Exception ex){
				ex.printStackTrace();
			}
		}
		
		

}
