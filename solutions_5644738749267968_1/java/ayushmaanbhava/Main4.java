import java.io.*;
class Main4
{
    public static void main(String args[]) throws IOException
    {
        String in = null;
        BufferedReader br = new BufferedReader(new FileReader("inp.txt"));
        BufferedWriter bw = new BufferedWriter(new FileWriter("out.txt"));
        int nooftest = Integer.parseInt(br.readLine());
        for(int l=0;l<nooftest;l++)
        {
            int z = Integer.parseInt(br.readLine());
            
            String hh[] = br.readLine().split(" ");
            double[] nums1 = new double[z];
            for (int i = 0; i < nums1.length; i++) {
                nums1[i] = Double.parseDouble(hh[i]);
            }
            
            hh = br.readLine().split(" ");
            double[] nums2 = new double[z];
            for (int i = 0; i < nums2.length; i++) {
                nums2[i] = Double.parseDouble(hh[i]);
            }
            
            insertionSort(nums1);
            insertionSort(nums2);
            
            int j = nums2.length -1;
            int ans1=0,ans2=0;
            for (int i = 0; i < nums2.length; i++)
                if(nums1[nums2.length -1 - i] > nums2[j])
                    ans2++;
                else
                    j--;
            
            //double nums3[] = new double[2*nums2.length];
            //System.arraycopy(nums1, 0, nums3, 0, nums2.length);
            //System.arraycopy(nums2, 0, nums3, nums2.length, nums2.length);
            
            //insertionSort(nums3);
            
            j = nums2.length -1;
            for (int i = 0; i < nums2.length; i++)
                if(nums2[nums2.length -1 - i] > nums1[j])
                    ans1++;
                else
                    j--;
                    
            bw.write("Case #"+(l+1)+": "+(nums2.length-ans1)+" "+ans2+"\n");
        }
        bw.flush();
        bw.close();
        System.out.println("done");
    }
    
    public static void insertionSort(double array[]) {
        int n = array.length;
        for (int j = 1; j < n; j++) {
            double key = array[j];
            int i = j-1;
            while ( (i > -1) && ( array [i] > key ) ) {
                array [i+1] = array [i];
                i--;
            }
            array[i+1] = key;
        }
    }
    
    private static double[] merge(double[] a, double[] b) {
        double[] c = new double[a.length + b.length];
        int i = 0, j = 0;
        for (int k = 0; k < c.length; k++) {
            if      (i >= a.length) c[k] = b[j++];
            else if (j >= b.length) c[k] = a[i++];
            else if (a[i] <= b[j])  c[k] = a[i++];
            else                    c[k] = b[j++];
        }
        return c;
    }

    public static double[] mergesort(double[] input) {
        int N = input.length;
        if (N <= 1) return input;
        double[] a = new double[N/2];
        double[] b = new double[N - N/2];
        for (int i = 0; i < a.length; i++) a[i] = input[i];
        for (int i = 0; i < b.length; i++) b[i] = input[i + N/2];
        return merge(mergesort(a), mergesort(b));
    }
}