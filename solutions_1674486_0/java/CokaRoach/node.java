import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.ArrayList;
import java.util.Dictionary;
import java.util.Hashtable;


public class node{
	public boolean seen = false;
	public ArrayList<node> children;
	
	public node(){
		children = new ArrayList<node>();
	}
	
}