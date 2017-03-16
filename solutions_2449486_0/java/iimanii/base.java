/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package base;

import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.util.LinkedList;
import java.util.Queue;

/**
 *
 * @author Ahmed Tarek
 */
abstract public class base {
    static int QuickSortLimit = 50;
            
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
    
    /* mimic php functions */
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
    
    /* write a string to file with the following name */
    public static void writeFile(String filename, String content) throws IOException {
        File outputFile = new File(filename);
        if(!outputFile.exists()) 
            outputFile.createNewFile();
        FileOutputStream output = new FileOutputStream(outputFile);
        output.write(content.getBytes());
        output.close();
    }
    
    /* finds the index of an int in an unsorted array */
    public static int find(int[] array, int c) {
        for(int i=0; i < array.length; i++)
            if(array[i] == c)
               return i;
        return -1;
    }
    /* finds the index of an int in an unsorted array .. starting from s to end */
    public static int find(int[] array, int c, int s) {
        for(int i=s; i < array.length; i++)
            if(array[i] == c)
               return i;
        return -1;
    }
    
    /* returns sum of an int array */
    public static long sum(int[] array) {
        long sum = 0;
        for(int i=0; i < array.length; i++)
            sum += array[i];
        
        return sum;
    }
    public static long sum(long[] array) {
        long sum = 0;
        for(int i=0; i < array.length; i++)
            sum += array[i];
        
        return sum;
    }
    
    /* returns index of the "minimum element" of an int array */
    public static int min(int[] array) {
        int min = 0;
        for(int i=1; i < array.length; i++)
            if(array[i] < array[min])
               min = i;
            
        return min;
    }
    public static int min(long[] array) {
        int min = 0;
        for(int i=1; i < array.length; i++)
            if(array[i] < array[min])
               min = i;
            
        return min;
    }
    
    /* returns index of the "maximum element" of an int array */
    public static int max(int[] array) {
        int max = 0;
        for(int i=1; i < array.length; i++)
            if(array[i] > array[max])
               max = i;
            
        return max;
    }
    public static int max(long[] array) {
        int max = 0;
        for(int i=1; i < array.length; i++)
            if(array[i] > array[max])
               max = i;
            
        return max;
    }
    
    public static int gcd(int a, int b) {
        while(b != 0) {
            int c = b;
            b = a % c;
            a = c;
        }
        return a;
    }
    public static long gcd(long a, long b) {
        while(b != 0) {
            long c = b;
            b = a % c;
            a = c;
        }
        return a;
    }
    
    public static int lcm(int a, int b) {
        return a /gcd(a,b) * a;
    }
    public static long lcm(long a, long b) {
        return a / gcd(a,b) * b;
    }
    
    /* quick sort */
    public  static void quickSort(int[] array) {
        quickSort(array, 0, array.length-1);
    }
    private static void quickSort(int[] array, int left, int right) {
        if(right-left < QuickSortLimit) {
           insertionSort(array, left, right-left+1);
           return;
        }

        int pivot = left + (int)(Math.random() * ((right - left) + 1));
        
        int temp = array[left];
        array[left] = array[pivot];
        array[pivot] = temp;
        
        int i = left+1, j = right;
        while(i < j) {
            if(array[i] < array[left]) { i++; continue; }
            if(array[j] > array[left]) { j--; continue; }
            
            temp = array[i];
            array[i++] = array[j];
            array[j--] = temp;
        }
        
        temp = array[left];
        array[left] = array[i-1];
        array[i-1] = temp;

        quickSort(array, left, i-2);
        quickSort(array, i, right);
    }
    public  static void quickSort(long[] array) {
        quickSort(array, 0, array.length-1);
    }
    private static void quickSort(long[] array, int left, int right) {
        if(right-left < QuickSortLimit) {
           insertionSort(array, left, right-left+1);
           return;
        }

        int pivot = left + (int)(Math.random() * ((right - left) + 1));
        
        long temp = array[left];
        array[left] = array[pivot];
        array[pivot] = temp;
        
        int i = left+1, j = right;
        while(i < j) {
            if(array[i] < array[left]) { i++; continue; }
            if(array[j] > array[left]) { j--; continue; }
            
            temp = array[i];
            array[i++] = array[j];
            array[j--] = temp;
        }
        
        temp = array[left];
        array[left] = array[i-1];
        array[i-1] = temp;

        quickSort(array, left, i-2);
        quickSort(array, i, right);
    }
    
    /* insertion sort */
    public  static void insertionSort(int[] array) {
        insertionSort(array, 0, array.length);
    }
    private static void insertionSort(int[] array, int index, int length) {
        for(int i=index; i < index + length; i++) {
            int c = array[i];
            int j = i;
            while(j > 0 && c < array[j-1])
                  array[j] = array[j---1];
            
            array[j] = c;
        }
    }
    public  static void insertionSort(long[] array) {
        insertionSort(array, 0, array.length);
    }
    private static void insertionSort(long[] array, int index, int length) {
        for(int i=index; i < index + length; i++) {
            long c = array[i];
            int j = i;
            while(j > 0 && c < array[j-1])
                  array[j] = array[j---1];
            
            array[j] = c;
        }
    }
    
    /* calculate combination .. knuth */
    public static long choose(int n, int k) {
        if (k > n)
            return 0;

        long r = 1;
        for(int d = 1; d <= k; d++) {
            r *= n--;
            r /= d;
        }
        return r;
    }

    /* misc */
    public static void memoryUsage() {
        /* thanks to that guy http://viralpatel.net/blogs/getting-jvm-heap-size-used-memory-total-memory-using-java-runtime/ */
        int mb = 1024*1024;
         
        //Getting the runtime reference from system
        Runtime runtime = Runtime.getRuntime();
         
        System.out.println("##### Heap utilization statistics [MB] #####");
         
        //Print used memory
        System.out.println("Used Memory:"
            + (runtime.totalMemory() - runtime.freeMemory()) / mb);
 
        //Print free memory
        System.out.println("Free Memory:"
            + runtime.freeMemory() / mb);
         
        //Print total available memory
        System.out.println("Total Memory:" + runtime.totalMemory() / mb);
 
        //Print Maximum available memory
        System.out.println("Max Memory:" + runtime.maxMemory() / mb);
    }
    
    /* calculate primes from 1->n .. returns them in an array */
    @SuppressWarnings("empty-statement")
    public static long[] Eratosthenes(int n) {
        long[] p = new long[n+1];
        int c = 0;
        for(int i=2; i < n; c++) {
            for(int j=2; j*i < n; j++)
                p[i*j] = 1;
            
            while(p[++i] == 1);
        }
        
        long[] r = new long[c];
        
        for(int i=2, k=0; i < n; i++) 
           if(p[i] != 1) 
              r[k++] = i;
        
        p = null;
        System.gc();
        return r;
    }
    
    public static void checkDir(String dirname) {
        File dir = new File(dirname);
        
        if(dir.exists())
           return;
        
        dir.mkdirs();
    }
}
