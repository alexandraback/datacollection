package basicRound;

import java.io.BufferedReader;
import java.io.FileReader;

public class Jam3{
	
	public static boolean isEven(int num){
		return num%2 ==0;
	}

	
	private static class DiPlus{
		public int x,y,xp,yp;
		
		public DiPlus(int x, int y){
			this(x, y, 0, 0);
		}
		
		public DiPlus(int x, int y, int xp, int yp){
			this.x = x;
			this.y = y;
			this.xp = xp;
			this.yp = yp;
		}
		
		public String toString(){
			return "<<< x: "+x+", y: "+y+", xp: "+xp+", yp: "+yp+" >>>";
		}
	}
	
	public static DiPlus getRect(int row, int col, int space){
		
//		System.out.println("~~~~~~~~~~~~~ row:"+row+", col:"+col+", space: "+space+" ~~~~~`");
		
		if(row*col<space) return null;
		
		for(int i=2;i<=row;i++){
			for(int j=2;j<=col;j++){
				if(i*j==space) return new DiPlus(i,j);
			}
		}
		
		//not found
		return null;
	}
	
	public static DiPlus getRectPlus(int row, int col, int space){
		
		DiPlus rec = getRect(row,col,space);
		if(rec != null) return rec; 
		
		if(row*col<space) return null;
		
		for(int i=2;i<=row-1;i++){
			for(int j=2;j<=col;j++){
				
				for(int a=2; a<=j;a++){
					if(i*j+a == space) return new DiPlus(i,j,0,a);
				}
			}
		}
		
		for(int i=2;i<=row;i++){
			for(int j=2;j<=col-1;j++){
				
				for(int a=2; a<=i;a++){
					if(i*j+a == space) return new DiPlus(i,j,a,0);
				}
			}
		}
		
		for(int i=2;i<=row-1;i++){
			for(int j=2;j<=col-1;j++){
				
				for(int a=2; a<=i;a++){
					for(int b=2; b<=j; b++){
						if(i*j+a+b == space) return new DiPlus(i,j,a,b);
					}
				}
			}
		}
		
		// not found
		return null;
	}
	
    public static void main(String[] args){
        try {
            BufferedReader fileIn = new BufferedReader(new FileReader("src/basicRound/C-small-attempt0.in"));
            
            String line = fileIn.readLine();
            int n = Integer.parseInt(line);
            
            for(int i=1; i<=n; i++){ //////////main loop
            	//first print case #
            	System.out.println("Case #"+ i +":");
            	
            	
            	line = fileIn.readLine();
                String[] numstr = line.split(" ");
                int[] nums = new int[3];
                for(int j=0;j<3;j++){
                	nums[j] = Integer.parseInt(numstr[j]);
                }
                
                
                // finished parsing
                
                int small = nums[0] < nums[1]? nums[0] : nums[1];
                int big = nums[0] > nums[1]? nums[0] : nums[1];
                int mine = nums[2];
                
                int space = small*big - mine;
                
                char[][] grid = new char[nums[0]][nums[1]];
                
                //special case: no mine!
                if(mine == 0){

                	for(int a=0; a< nums[0]-1;a++){
                		for(int b=0; b< nums[1];b++){
                			System.out.print(".");
                		}
                		System.out.println();
                	}
                	
                	for(int b=0; b< nums[1]-1;b++){
            			System.out.print(".");
            		}
                	System.out.println("c");
                	
                	//only 1 space left!
                } else if(space == 1){
                	
                	
                	for(int a=0; a< nums[0]-1;a++){
                		for(int b=0; b< nums[1];b++){
                			System.out.print("*");
                		}
                		System.out.println();
                	}
                	
                	for(int b=0; b< nums[1]-1;b++){
            			System.out.print("*");
            		}
                	System.out.println("c");
                	
                	//no space left!
                } else if(space == 0){
                	
                	
                	System.out.println("Impossible");
                	//1xA, Ax1
                } else if(small == 1){
            		
                	
                	//row = 1
            		if(nums[0] == 1){                			
            			for(int j =0; j< mine; j++){
            				System.out.print("*");
            			}
            			for(int j = mine; j < big-1; j++){
            				System.out.print(".");
            			}
            			
            			System.out.println("c");
            			// col = 1
            		} else{
            			for(int j =0; j< mine; j++){
            				System.out.println("*");
            			}
            			for(int j = mine; j < big-1; j++){
            				System.out.println(".");
            			}
            			
            			System.out.println("c");
            		}
                	
                } else if (small == 2){

                	//if does not have 4 space, or have odd # of space
                	if(2*big - mine < 4 || (2*big - mine)%2 == 1 ) System.out.println("Impossible");
                	
                	//row = 2
                	else if(nums[0] == 2){
                		
                		/// first row
                		for(int j =0; j< mine/2; j++){
            				System.out.print("*");
            			}
            			for(int j = mine/2; j < big-1; j++){
            				System.out.print(".");
            			}
            			
            			System.out.println("c");
            			
            			//2nd row
            			for(int j =0; j< mine/2; j++){
            				System.out.print("*");
            			}
            			for(int j = mine/2; j < big; j++){
            				System.out.print(".");
            			}
            			
            			System.out.println();
            			//col = 2
                	} else {
                		for(int j =0; j <big-2;j++){
                			if(mine>=2) {
                				System.out.println("**");
                				mine-=2;
                			} else {//mine == 0
                				System.out.println("..");
                			}
                		}
                		System.out.println("..");
                		System.out.println(".c");
                	}
                	// small >2
                } else{
                	
                	//if there is 2,3,5,or 7 space
                	if(space <4 || space == 5 || space == 7) System.out.println("Impossible");
                	
                	//rest of the cases!!
                	else{
                		DiPlus rect = getRectPlus(nums[0],nums[1],space);
                		
                		if(rect == null) System.out.println("Impossible");
                		
                		else{
                			//simply a rect
                			if(rect.yp==0 && rect.xp == 0){
                				
                				//things on top, full mine rows
                				for(int a=0; a<nums[0]-rect.x;a++){
                					for(int b=0; b< nums[1]; b++){
                						System.out.print("*");
                						mine--;
                					}
                					System.out.println();
                				}
                				
                				//not full mine rows; [a< nums[0] - 1 ;] because last row need to print 'c'
                				for(int a=nums[0]-rect.x; a< nums[0] - 1 ; a++){
                					for(int b=0;b<nums[1]-rect.y; b++){
                						System.out.print("*");
                						mine--;
                					}
                					
                					for(int b=nums[1]-rect.y;b<nums[1];b++){
                						System.out.print(".");
                					}
                					System.out.println();
                				}
                				
                				//last row
                				for(int b=0;b<nums[1]-rect.y; b++){
            						System.out.print("*");
            						mine--;
            					}
            					
            					for(int b=nums[1]-rect.y;b<nums[1]-1;b++){
            						System.out.print(".");
            					}
            					System.out.println("c");
                				
                				
            					// if not simple rect
                			} else{
                				if(rect.yp > 0 && rect.xp > 0){
                					//things on top, full mine rows; xtra -1 for yp
                    				for(int a=0; a<nums[0]-rect.x-1;a++){
                    					for(int b=0; b< nums[1]; b++){
                    						System.out.print("*");
                    						mine--;
                    					}
                    					System.out.println();
                    				}
                    				
                    				
                    				//yp row
                    				for(int b=0;b<nums[1]-rect.yp; b++){
                						System.out.print("*");
                						mine--;
                					}
                					
                					for(int b=nums[1]-rect.yp;b<nums[1];b++){
                						System.out.print(".");
                					}
                					System.out.println();
                    				
                					//not full mine rows; [a< nums[0] - 1 ;] because last row need to print 'c'
                    				for(int a=nums[0]-rect.x; a< nums[0] - 1 ; a++){
                    					
                    					//if there is xp
                    					if((nums[0])-(a)<=rect.xp){
                    						for(int b=0;b<nums[1]-rect.y-1; b++){
                        						System.out.print("*");
                        						mine--;
                        					}
                        					
                        					for(int b=nums[1]-rect.y-1;b<nums[1];b++){
                        						System.out.print(".");
                        					}
                        					System.out.println();
                        					
                    					} else{
                    						for(int b=0;b<nums[1]-rect.y; b++){
                        						System.out.print("*");
                        						mine--;
                        					}
                        					
                        					for(int b=nums[1]-rect.y;b<nums[1];b++){
                        						System.out.print(".");
                        					}
                        					System.out.println();
                    					}
                    					
                    				}
                    				
                    				//last row with c
                    				for(int b=0;b<nums[1]-rect.y-1; b++){
                						System.out.print("*");
                						mine--;
                					}
                					
                					for(int b=nums[1]-rect.y-1;b<nums[1]-1;b++){
                						System.out.print(".");
                					}
                					System.out.println("c");
                					
                					//System.out.println(rect);
                				} else if(rect.yp > 0){
                					//things on top, full mine rows; xtra -1 for yp
                    				for(int a=0; a<nums[0]-rect.x-1;a++){
                    					for(int b=0; b< nums[1]; b++){
                    						System.out.print("*");
                    						mine--;
                    					}
                    					System.out.println();
                    				}
                    				
                    				
                    				//yp row
                    				for(int b=0;b<nums[1]-rect.yp; b++){
                						System.out.print("*");
                						mine--;
                					}
                					
                					for(int b=nums[1]-rect.yp;b<nums[1];b++){
                						System.out.print(".");
                					}
                					System.out.println();
                					
                					//not full mine rows; [a< nums[0] - 1 ;] because last row need to print 'c'
                    				for(int a=nums[0]-rect.x; a< nums[0] - 1 ; a++){
                    					for(int b=0;b<nums[1]-rect.y; b++){
                    						System.out.print("*");
                    						mine--;
                    					}
                    					
                    					for(int b=nums[1]-rect.y;b<nums[1];b++){
                    						System.out.print(".");
                    					}
                    					System.out.println();
                    				}
                    				
                    				//last row
                    				for(int b=0;b<nums[1]-rect.y; b++){
                						System.out.print("*");
                						mine--;
                					}
                					
                					for(int b=nums[1]-rect.y;b<nums[1]-1;b++){
                						System.out.print(".");
                					}
                					System.out.println("c");
                					
                					//System.out.println(rect);
                					// xp >0
                				} else{
                					//things on top, full mine rows
                    				for(int a=0; a<nums[0]-rect.x;a++){
                    					for(int b=0; b< nums[1]; b++){
                    						System.out.print("*");
                    						mine--;
                    					}
                    					System.out.println();
                    				}
                    				
                    				//not full mine rows; [a< nums[0] - 1 ;] because last row need to print 'c'
                    				for(int a=nums[0]-rect.x; a< nums[0] - 1 ; a++){
                    					
                    					//if there is xp
                    					if((nums[0])-(a)<=rect.xp){
                    						for(int b=0;b<nums[1]-rect.y-1; b++){
                        						System.out.print("*");
                        						mine--;
                        					}
                        					
                        					for(int b=nums[1]-rect.y-1;b<nums[1];b++){
                        						System.out.print(".");
                        					}
                        					System.out.println();
                        					
                    					} else{
                    						for(int b=0;b<nums[1]-rect.y; b++){
                        						System.out.print("*");
                        						mine--;
                        					}
                        					
                        					for(int b=nums[1]-rect.y;b<nums[1];b++){
                        						System.out.print(".");
                        					}
                        					System.out.println();
                    					}
                    					
                    				}
                    				
                    				//last row with c
                    				for(int b=0;b<nums[1]-rect.y-1; b++){
                						System.out.print("*");
                						mine--;
                					}
                					
                					for(int b=nums[1]-rect.y-1;b<nums[1]-1;b++){
                						System.out.print(".");
                					}
                					System.out.println("c");
                    				
                				}
                			}
                		}
                		
                	}
                }
                
                
            }//main for
            
            
            
        } catch (Exception e) {
            // TODO Auto-generated catch block
            e.printStackTrace();
        }
        

    }
}    