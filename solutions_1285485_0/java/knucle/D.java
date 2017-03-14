package knucle.y2012.D;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;

public class D {
	
	private static byte SELF = 1;
	private static byte SPACE = 2;
	private static byte MIRROR = 3;
	
	public static void main(String[] args) throws Exception {
		
		FileReader fr = new FileReader("small.in");
		BufferedReader br = new BufferedReader(fr);
		
		BufferedWriter bw = new BufferedWriter(new FileWriter("output.txt"));

		try {
			int currentCase = 1;
			int caseNum = Integer.parseInt(br.readLine());
			
			for(currentCase=1; currentCase<=caseNum; currentCase++){
				String line = br.readLine();
				
				//system.out.println("Case " + currentCase);
				
				bw.write("Case #");
				bw.write(Integer.toString(currentCase));
				bw.write(": ");
				
				String[] inputs = line.split(" ");
				int height = Integer.parseInt(inputs[0]);
				int width = Integer.parseInt(inputs[1]);
				double maxDistance = Double.parseDouble(inputs[2]);
				
				byte[][] setup = new byte[height][width];
				
				int selfX = 0;
				int selfY = 0;
				
				for(int i=0; i<height; i++){
					String row = br.readLine();
					
					for(int j=0; j<width; j++){
						char c = row.charAt(j);
						switch(c){
							case '#':
								setup[i][j] = MIRROR;
								break;
							case '.':
								setup[i][j] = SPACE;
								break;
							case 'X':
								setup[i][j] = SELF;
								selfX = j;
								selfY = i;
								break;
						}
					}
				}
				
				int hits = 0;
				
				boolean previousHit = false;
				boolean hit = false;
				
				for(double initAngle=0; initAngle<360; initAngle=round(initAngle+0.5)){
					//system.out.println("-> Init Angle " + initAngle);
					hit = false;
					
					double relativeX = 0.5;
					double relativeY = 0.5;
					int currentX = selfX;
					int currentY = selfY;
					double angle = initAngle;
					double traveledDistance = 0.0;
					
					do {
						double targetX;
						double targetY;
						if(angle >= 0 && angle < 90){
							targetX = 1.0;
							targetY = 1.0;
						} else if(angle >= 90 && angle < 180){
							targetX = 0.0;
							targetY = 1.0;
						} else if(angle >= 180 && angle < 270){
							targetX = 0.0;
							targetY = 0.0;
						} else {
							targetX = 1.0;
							targetY = 0.0;
						}
						
						//system.out.println("---> Before emit: " + angle);
						
						EmitResult result = emit(relativeX, relativeY, targetX, targetY, angle);
						
						int oldX = currentX;
						int oldY = currentY;
						
						currentX += result.coordinateXChange;
						currentY += result.coordinateYChange;
						
						relativeX += result.travelX;
						if(relativeX >= 1){
							relativeX -= 1;
						} else if(relativeX <= 0){
							relativeX += 1;
						}
						relativeY += result.travelY;
						if(relativeY >= 1){
							relativeY -= 1;
						} else if(relativeY <= 0){
							relativeY += 1;
						}
						
						traveledDistance += result.travelDistance;
						
						if(result.coordinateXChange != 0 && result.coordinateYChange != 0){
							//hit at point;
							
							if(setup[currentY][currentX] == MIRROR){
								if(setup[currentY][oldX] == MIRROR){
									if(setup[oldY][currentX] == MIRROR){
										//system.out.println("---> Point Direct Reflect");
										//|_
										angle = angle + 180;
										if(angle >= 360){
											angle -= 360;
										}
										
										currentY = oldY;
										currentX = oldX;
										
										relativeY = Math.abs(1.0-relativeY);
										relativeX = Math.abs(1.0-relativeX);
									} else {
										//system.out.println("---> Point Horizontal Reflect");
										//_
										angle = 360 - angle;
										if(angle == 360){
											angle = 0;
										}

										currentY = oldY;
										relativeY = Math.abs(1.0-relativeY);
									}
								} else if(setup[oldY][currentX] == MIRROR){
									//system.out.println("---> Point Vertical Reflect");
									//|
									angle = 180 - angle;
									if(angle < 0){
										angle += 360;
									}

									currentX = oldX;
									relativeX = Math.abs(1.0-relativeX);
								} else {
									//destroy
									break;
								}
							}
						} else {
							//hit at line
							if(setup[currentY][currentX] == MIRROR){
								if(result.coordinateXChange != 0){
									//system.out.println("---> Vertical Reflect");
									//|
									angle = 180 - angle;
									if(angle < 0){
										angle += 360;
									}

									currentX = oldX;
									relativeX = Math.abs(1.0-relativeX);
								} else {
									//system.out.println("---> Horizontal Reflect");
									//_
									angle = 360 - angle;
									if(angle == 360){
										angle = 0;
									}
									
									currentY = oldY;
									relativeY = Math.abs(1.0-relativeY);
								}
							}
						}
						
						//system.out.println("---> After emit: " + angle);
						
						if(setup[currentY][currentX] == SELF){
							if(angle >= 0 && angle <90){
								if(!(0.5 >= relativeX && 0.5 >= relativeY)){
									continue;
								}
							} else if(angle >= 90 && angle <180){
								if(!(0.5 <= relativeX && 0.5 >= relativeY)){
									continue;
								}
							} else if(angle >= 180 && angle <270){
								if(!(0.5 <= relativeX && 0.5 <= relativeY)){
									continue;
								}
							} else if(angle >= 270 && angle <360){
								if(!(0.5 >= relativeX && 0.5 <= relativeY)){
									continue;
								}
							}
							
							result = emit(relativeX, relativeY, 0.5, 0.5, angle);
							
							double posX = relativeX + result.travelX;
							double posY = relativeY + result.travelY;
							
							if(Math.abs(posX - 0.5) < 0.05 && Math.abs(posY - 0.5) < 0.05){
								if(traveledDistance + result.travelDistance <= maxDistance){
									if(!previousHit){
										hits++;
									}
									hit = true;
								}
								break;
							}
						}
						
					} while(traveledDistance < maxDistance);
					
					previousHit = hit;
				}
				
				bw.write(Integer.toString(hits));
				bw.write('\n');
			}
		} finally {
			br.close();
			bw.close();
		}
	}
	
	private static EmitResult emit(double fromX, double fromY, double targetX, double targetY, double angle){
		if(angle == 0){
			return new EmitResult(targetX-fromX, 0, 1, 0); 
		} else if(angle == 90){
			return new EmitResult(0, targetY-fromY, 0, -1);
		} else if(angle == 180){
			return new EmitResult(targetX-fromX, 0, -1, 0);
		} else if(angle == 270){
			return new EmitResult(0, targetY-fromY, 0, 1);
		}
		
		double t = Math.tan(Math.toRadians(angle));
		
		double travelX = 0.0;
		double travelY = 0.0;
		int coordinateXChange = 0;
		int coordinateYChange = 0;
		
		travelX = targetX - fromX;
		travelY = round(t * travelX);
		
		double y = travelY + fromY;
		if(travelY > 0.0){
			if(y > targetY){
				travelY = targetY - fromY;
				travelX = round(travelY / t);
				coordinateYChange = -1;
			} else if(y < targetY){
				coordinateXChange = (travelX >= 0 ? 1 : -1);
			} else {
				coordinateXChange = (travelX >= 0 ? 1 : -1);
				coordinateYChange = -1;
			}
		} else if(travelY < 0.0){
			if(y < targetY){
				travelY = targetY - fromY;
				travelX = round(travelY / t);
				coordinateYChange = 1;
			} else if(y > targetY){
				coordinateXChange = (travelX >= 0 ? 1 : -1);
			} else {
				coordinateXChange = (travelX >= 0 ? 1 : -1);
				coordinateYChange = 1;
			}
		} else {
			coordinateXChange = 1;
		}
		
		return new EmitResult(travelX, travelY, coordinateXChange, coordinateYChange);
	}
	
	private static double round(double in){
		return Math.round(in*1000.0)/1000.0;
	}
	
	public static class EmitResult{
		double travelX;
		double travelY;
		int coordinateXChange;
		int coordinateYChange;
		double travelDistance;
		
		public EmitResult(double travelX, double travelY, int coordinateXChange, int coordinateYChange) {
			this.travelX = travelX;
			this.travelY = travelY;
			this.coordinateXChange = coordinateXChange;
			this.coordinateYChange = coordinateYChange;
			
			travelDistance = Math.sqrt(travelX*travelX + travelY*travelY);
		}
	}
}
