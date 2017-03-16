import java.io.BufferedReader;
import java.io.FileOutputStream;
import java.io.FileReader;

@SuppressWarnings("CallToThreadDumpStack")
public class Utils
{
    private static FileOutputStream outStream;
    private static BufferedReader reader;
    private static boolean debug = false;

    public static void openOutFile(String str, boolean debug)
    {
        Utils.debug = debug;
        try { outStream = new FileOutputStream(str, false); }
	catch (Exception e) { e.printStackTrace(); }
    }

    public static void openInFile(String str)
    {
        try { reader = new BufferedReader(new FileReader(str)); }
	catch (Exception e) { e.printStackTrace(); }
    }

    public static void closeOutFile()
    {
        try { outStream.close(); }
	catch (Exception e) { e.printStackTrace(); }
    }

    public static void closeInFile()
    {
        try { outStream.close(); }
	catch (Exception e) { e.printStackTrace(); }
    }

    public static String readFromFile()
    {
        try { return reader.readLine(); }
        catch (Exception e) { e.printStackTrace(); }
        return null; // shouldn't get here
    }
    public static void writeToFile(String str)
    {
        if (debug) System.out.println(str);
        try
        {
            for(int k=0; k<str.length(); k++)
            {
                outStream.write(str.charAt(k));
            }
            outStream.write(13);
            outStream.write(10);
        }
	catch (Exception e)
            { e.printStackTrace(); }
    }

}
