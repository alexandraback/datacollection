package codejam2012;

import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.util.LinkedList;
import java.util.Queue;

public class EqualSums {
    public static void main(String[] args) throws IOException {
        String fileName = "C-small-attempt0";
        Queue<String> queue = file("input/"+fileName+".in");
        
        File outputFile = new File("result/"+fileName+".out");
        if(!outputFile.exists())
            outputFile.createNewFile();
        FileOutputStream output = new FileOutputStream(outputFile);
        
        int TestCases = Integer.parseInt(queue.poll());
        
        for(int i=0; i < TestCases; i++) {
            output.write(("Case #"+(i+1)+":\n").getBytes());
            int[] input = parseLine(queue.poll());
            
            /* algorithm here */
            /* small problem N = 20 */
            
            int numbers[] = new int[20];
            
            int sum = 0;
            for(int j=1; j < input.length; j++) {
                numbers[j-1] = input[j];
                sum += input[j];
            }
            
            sort(numbers);

            /* max sum is sum/2 */
            boolean l[] = new boolean[(sum+1)/2];
            String st[] = new String[(sum+1)/2];
            
            int subsets = (int)Math.pow(2, 20);
            StringBuilder nums = new StringBuilder();
            for(int j=1; j < subsets; j++) {
                int s = 0;
                nums.delete(0, nums.length());
                for(int k=0; k < 20; k++) {
                    if((j & (1 << k)) > 0) {
                       s += numbers[k];
                       nums.append(Integer.toString(numbers[k])).append(" ");
                    }
                }
                
                if(l[s]) {
                    output.write(st[s].getBytes());
                    output.write('\n');
                    output.write(nums.toString().getBytes());
                    break;
                } else {
                    l[s] = true;
                    st[s] = nums.toString();
                }
            }
            
            
            
            
            
            output.write('\n');
        }
    }
    
    public static int[] parseLine(String line) {
        String[] array = line.split("\\s");
        int[] result = new int[array.length];
        
        for(int i=0; i < result.length; i++)
            result[i] = Integer.parseInt(array[i]);
        
        return result;
    }
    
    /* mimic php file function */
    public static Queue<String> file(String filename) throws IOException {
        byte[] fileBytes = getFile(filename);
        Queue<String> queue = new LinkedList();
        
        StringBuilder builder = new StringBuilder();
        for(int i=0; i < fileBytes.length; i++) {
            if(fileBytes[i] == '\n') {
               queue.add(builder.toString());
               builder.delete(0, builder.length());
               continue;
            } else if(fileBytes[i] == '\r')
               continue;
            builder.append((char)fileBytes[i]);
        }
        
        return queue;
    }
    
    /* given a file name ... fetches the file from war folder */
    public static byte[] getFile(String fileName) throws IOException {
        FileInputStream in = new FileInputStream(fileName);
        int size = in.available();
        byte[] imageBytes = new byte[size];

        /* read the whole image into array */
        int read = 0;
        while(read < size)
              read += in.read(imageBytes, read, size-read);
        
        return imageBytes;
    }
    
    public static void sort(int[] array) {
          sort(array, 0, array.length);
    }
    
    public static void sort(int[] array, int start, int length) {
        if(length <= 1)
           return;
        
        sort(array, start, length/2);
        sort(array, start+length/2, length-length/2);
        int[] sorted = new int[length];
        
        int i=start, j=start+length/2, k=0;
        while(i < start+length/2 || j < start+length) {
            if(j == start+length || (i < start+length/2 && array[i] <= array[j]))
               sorted[k++] = array[i++];
            else {
               sorted[k++] = array[j++];
            }
        }
        
        System.arraycopy(sorted, 0, array, start, sorted.length);
    }
}
