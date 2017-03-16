/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package googlejam;

import java.io.*;

/**
 *
 * @author a.bogdanov
 */
public class GoogleJam_MinesweeperMaster {
    public static final String problemLetter = "C";
    
    public static void solve(BufferedReader reader, PrintWriter writer) throws IOException{
        int caseCount = Integer.parseInt(reader.readLine());
        for(int caseNum=1; caseNum<=caseCount; caseNum++){
            String[] str = reader.readLine().split(" ");
            int R = Integer.parseInt(str[0]);
            int C = Integer.parseInt(str[1]);
            int M = Integer.parseInt(str[2]);
            int empty = R*C - M;
            writer.println("Case #" + caseNum + ":");
            if(R==1 && C==1){
                writer.println("c");
            }else if(R==1){
                writer.print("c");
                for(int i=1;i<C;i++){
                	if(i<empty)
                		writer.print(".");
                	else
                		writer.print("*");
                }
        		writer.println("");
            }else if(C==1){
                writer.println("c");
                for(int i=1;i<R;i++){
                	if(i<empty)
                		writer.println(".");
                	else
                		writer.println("*");
                }
            }else if(R==2){
            	if(empty==1){
                    writer.print("c");
                    for(int i=1;i<C;i++){
                  		writer.print("*");
                    }
            		writer.println("");
                    for(int i=0;i<C;i++){
                  		writer.print("*");
                    }
            		writer.println("");
            	}else if(empty%2==0 && empty > 3){
                    writer.print("c");
                    for(int i=1;i<C;i++){
                    	if(i<empty/2)
                    		writer.print(".");
                    	else
                    		writer.print("*");
                    }
            		writer.println("");
                    for(int i=0;i<C;i++){
                    	if(i<empty/2)
                    		writer.print(".");
                    	else
                    		writer.print("*");
                    }
            		writer.println("");
            	}else{
            		writer.println("Impossible");
            	}
            }else if(C==2){
            	if(empty==1){
                    writer.println("c*");
                    for(int i=1;i<R;i++){
                  		writer.println("**");
                    }
            	}else if(empty%2==0 && empty > 3){
                    writer.println("c.");
                    for(int i=1;i<R;i++){
                    	if(i<empty/2)
                    		writer.println("..");
                    	else
                    		writer.println("**");
                    }
            	}else{
            		writer.println("Impossible");
            	}
            	
            }else{
            	if(empty==1){
                    for(int i=0;i<R;i++){
                        for(int j=0;j<C;j++){
                        	if(i==0&&j==0){
                                writer.print("c");
                        	}else{
                                writer.print("*");
                        	}
                        }
                        writer.println("");
                    }
            	}else if(empty < 4){
            		writer.println("Impossible");
            	}else if(empty == 4){
                    for(int i=0;i<R;i++){
                        for(int j=0;j<C;j++){
                        	if(i==0&&j==0){
                                writer.print("c");
                        	}else if(i<2&&j<2) {
                                writer.print(".");
                        	}else{
                                writer.print("*");
                        	}
                        }
                        writer.println("");
                    }
            		
            	}else if(empty==5){
            		writer.println("Impossible");
            	}else if(empty == 6){
                    for(int i=0;i<R;i++){
                        for(int j=0;j<C;j++){
                        	if(i==0&&j==0){
                                writer.print("c");
                        	}else if(i<2&&j<3) {
                                writer.print(".");
                        	}else{
                                writer.print("*");
                        	}
                        }
                        writer.println("");
                    }
            	}else if(empty==7){
            		writer.println("Impossible");
            	}else{
            		if(empty <= 3*C){
            			if(empty%3==0){
                            for(int i=0;i<R;i++){
                                for(int j=0;j<C;j++){
                                	if(i==0&&j==0){
                                        writer.print("c");
                                	}else if(i<3&&j<empty/3) {
                                        writer.print(".");
                                	}else{
                                        writer.print("*");
                                	}
                                }
                                writer.println("");
                            }
            			}else if(empty%3==1){
                            for(int i=0;i<R;i++){
                                for(int j=0;j<C;j++){
                                	if(i==0&&j==0){
                                        writer.print("c");
                                	}else if(i<2&&j<empty/3+1) {
                                        writer.print(".");
                                	}else if(i==2&&j<empty/3-1) {
                                        writer.print(".");
                                	}else{
                                        writer.print("*");
                                	}
                                }
                                writer.println("");
                            }
            			}else{
                            for(int i=0;i<R;i++){
                                for(int j=0;j<C;j++){
                                	if(i==0&&j==0){
                                        writer.print("c");
                                	}else if(i<2&&j<empty/3+1) {
                                        writer.print(".");
                                	}else if(i==2&&j<empty/3) {
                                        writer.print(".");
                                	}else{
                                        writer.print("*");
                                	}
                                }
                                writer.println("");
                            }
            			}
            		}else{
	            		boolean first = true;
	            		while(empty >= 2*C + 2){
	            			for(int i=0;i<2;i++){
	            				for(int j=0;j<C;j++){
	            					if(first&&i==0&&j==0){
	            						writer.print("c");
	            					}else{
	            						writer.print(".");
	            					}
	            				}
	            				writer.println("");
	            			}
	            			first = false;
	            			R -= 2;
	            			empty -= 2*C;
	            		}
	            		if(empty==2 || empty==3){
	        				for(int j=0;j<C;j++){
	        					if(j<empty) {
	        						writer.print(".");
	        					}else{
	        						writer.print("*");
	        					}
	        				}
	        				writer.println("");
	            			R--;
	            		}else if (empty==2*C+1){
	        				for(int j=0;j<C;j++){
        						writer.print(".");
	        				}
	        				writer.println("");
	        				R--;
	        				for(int j=0;j<C;j++){
	        					if(j < C-1 ){
	        						writer.print(".");
	        					}else{
	        						writer.print("*");
	        						
	        					}
	        				}
	        				writer.println("");
	        				R--;
	        				for(int j=0;j<C;j++){
	        					if(j < 2 ){
	        						writer.print(".");
	        					}else{
	        						writer.print("*");
	        						
	        					}
	        				}
	        				writer.println("");
	        				R--;
	            		}else{
	                		if(R==1){
	            				for(int j=0;j<C;j++){
	            					if(j<empty) {
	            						writer.print(".");
	            					}else{
	            						writer.print("*");
	            					}
	            				}
	            				writer.println("");
	                			R--;
	                		}else{
	                			if(empty%2==0){
	                				for(int j=0;j<C;j++){
	                					if(j<empty/2) {
	                						writer.print(".");
	                					}else{
	                						writer.print("*");
	                					}
	                				}
	                				writer.println("");
	                    			R--;
	                				for(int j=0;j<C;j++){
	                					if(j<empty/2) {
	                						writer.print(".");
	                					}else{
	                						writer.print("*");
	                					}
	                				}
	                				writer.println("");
	                    			R--;
	                			}else{
	                				for(int j=0;j<C;j++){
	                					if(j<empty/2 + 1) {
	                						writer.print(".");
	                					}else{
	                						writer.print("*");
	                					}
	                				}
	                				writer.println("");
	                    			R--;
	                				for(int j=0;j<C;j++){
	                					if(j<empty/2) {
	                						writer.print(".");
	                					}else{
	                						writer.print("*");
	                					}
	                				}
	                				writer.println("");
	                    			R--;
	                			}
	                		}
	            		}
	                    for(int i=0;i<R;i++){
	                        for(int j=0;j<C;j++){
	                            writer.print("*");
	                        }
	                        writer.println("");
	                    }
            		}
            	}
            }
            writer.flush();
        }
    }

    public static void main(String[] args) throws FileNotFoundException, IOException {
        File folder = new File(".");
        for(final File entry:folder.listFiles()){
            if(entry.getName().endsWith(".in") && entry.getName().startsWith(problemLetter)){
                BufferedReader reader = new BufferedReader(new FileReader(entry));
                String fileOut = entry.getName().substring(0, entry.getName().length()-3) + ".out";
                System.out.println(entry.getName() + " -> " + fileOut);
                PrintWriter writer = new PrintWriter(fileOut);
                solve(reader, writer);
                reader.close();
                writer.close();
            }
        }
    }
    
}
