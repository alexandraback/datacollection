import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.io.LineNumberReader;
import java.io.PrintStream;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Iterator;
import java.util.List;

/***/
public class Lawnmower {
	public static Lawnmower inst=new Lawnmower();

	public static boolean possible=false;
	public static List<Cell> cells;

	/***/
	public class Cell{
		public Integer rowId;
		public Integer columnId;
		public Integer hTarget;
		public Integer hCurrent=100; 
		
		public Cell(int rowId,int columnId,int hTarget){
			this.rowId=rowId;
			this.columnId=columnId;
			this.hTarget=hTarget; 
		}
		
		public Cell clone(){
			Cell newCell=new Cell(this.rowId,this.columnId,this.hTarget);
			newCell.hCurrent=this.hCurrent;
			return newCell;
		}
	}
	public Cell newCell(int rowId,int columnId,int hTarget){ return new Cell(rowId,columnId,hTarget); }
	
	/**
	 */
	public static void main(String[] args) {

		try {

			LineNumberReader reader=new LineNumberReader(new FileReader(new File(args[0]))); // InputFile
			PrintStream printer=new PrintStream(new File(args[1])); // OutputFile
			
			Integer nTestCases=Integer.valueOf(reader.readLine().trim());
			for(int i=0;i!=nTestCases;i++){
				cells=Collections.synchronizedList(new ArrayList<Cell>());
				String[] nm=reader.readLine().trim().split(" ", 2);
				Integer nRows=Integer.valueOf(nm[0].trim());
				Integer nColumns=Integer.valueOf(nm[1].trim());
				for(int r=0;r!=nRows;r++){
					String[] s=reader.readLine().trim().split(" ", nColumns);
					for(int c=0;c!=nColumns;c++)
						cells.add(inst.newCell(r, c, Integer.valueOf(s[c].trim())));
				}
				
				possible=true;
				Iterator<Cell> iterCell=cells.iterator();
				while(possible&&iterCell.hasNext()){
					Cell cell=iterCell.next();
					if(cell.hTarget==1){
						// H
						int cColumns=0;
						for(int c=0;c!=nColumns;c++){
							if(cells.get((cell.rowId*nColumns)+c).hTarget==1)
								cColumns++;
						}
						// V
						int cRows=0;
						for(int r=0;r!=nRows;r++){
							if(cells.get((r*nColumns)+cell.columnId).hTarget==1)
								cRows++;
						}
						if((cColumns!=nColumns)&&(cRows!=nRows))
							possible=false;						
					}
				}
				
				// System.out.println("Case #"+(i+1)+": "+(possible?"YES":"NO"));
				printer.println("Case #"+(i+1)+": "+(possible?"YES":"NO"));
			}
			
			reader.close();
			printer.close();			
		} catch (FileNotFoundException e) {
			
			e.printStackTrace();
		} catch (IOException e) {
			
			e.printStackTrace();
		} 
		
	}
	
}