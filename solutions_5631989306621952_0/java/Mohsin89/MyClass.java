import java.io.File;
import java.io.IOException;
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.BufferedWriter;
import java.io.FileWriter;
import java.util.HashSet;
import java.util.ArrayList;
import java.util.*;
import java.lang.StringBuilder;
import java.lang.Math;
class MyClass 
{



public static void main(String[] arguments) throws Exception
{
BufferedReader br=new BufferedReader(new FileReader(new File("C:\\Java\\A-small-attempt0.in")));
BufferedWriter bw=new BufferedWriter(new FileWriter(new File("C:\\Java\\A-large.out")));
BufferedWriter bw2=new BufferedWriter(new FileWriter(new File("C:\\Java\\PractiseData2.out")));	

int T = java.lang.Integer.parseInt(br.readLine());
String Line;
//double divisor;
for(int t=0;t<T;++t)
{
Line=br.readLine();
char car = Line.charAt(0);
String tem = ""+car;
for(int i=1;i<Line.length();i++)
{
if (Line.charAt(i)<car)
tem= tem+Line.charAt(i);
else
{
if (Line.charAt(i)==car)
{
if(tem.charAt(0) > Line.charAt(i))
{
tem= tem+Line.charAt(i);

}
else
{
tem= Line.charAt(i)+tem;
}
}
else
tem= Line.charAt(i)+tem;
}

car = tem.charAt(0);
}

bw.write("Case #"+(t+1)+": "+tem);
bw.newLine();

}
bw.close();
bw2.close();
}
}


