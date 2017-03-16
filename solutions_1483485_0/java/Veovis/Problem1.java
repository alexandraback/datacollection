package codeJam;

import java.awt.*;
import java.awt.event.*;
import java.io.*;
import java.util.*;

import javax.swing.*;

@SuppressWarnings("serial")
public class Problem1 extends JFrame
{
	//TODO Set file names
	static final String INFILE = "codeJam/inFile1.txt";
	static final String OUTFILE = "codeJam/outFile1.txt";
	
	// variable declaration
	JTextArea inText, outText;
	
	public static void main(String[] args)
	{
		new Problem1();
	}
	
	public Problem1()
	{
		DefaultHandler aHandler = new DefaultHandler();
		
		setTitle("Title");
		Container content = this.getContentPane();
		content.setLayout(null);
		
		//////////////////////////////////////////////////////////////////////// LABELS ////////
		JLabel aLabel = new JLabel("Input:");
		aLabel.setBounds(258, 5, 50, 20);
		content.add(aLabel);
		
		aLabel = new JLabel("Output:");
		aLabel.setBounds(791, 5, 50, 20);
		content.add(aLabel);
		
		/////////////////////////////////////////////////////////////////////// TEXTAREAS //////
		inText = new JTextArea();
		JScrollPane scroll = new JScrollPane(inText);
		scroll.setBounds(33, 33, 500, 200);
		content.add(scroll);
		
		outText = new JTextArea();
		scroll = new JScrollPane(outText);
		scroll.setBounds(566, 33, 500, 200);
		content.add(scroll);
		
		//////////////////////////////////////////////////////////////////////// BUTTONS ///////
		JButton aButton = new JButton("Test File");
		aButton.addActionListener(aHandler);
		aButton.setBounds(33, 250, 233, 40);
		content.add(aButton);
		
		aButton = new JButton("Run File");
		aButton.addActionListener(aHandler);
		aButton.setBounds(300, 250, 233, 40);
		content.add(aButton);
		
		aButton = new JButton("Test TextBox");
		aButton.addActionListener(aHandler);
		aButton.setBounds(566, 250, 233, 40);
		content.add(aButton);
		
		aButton = new JButton("Run TextBox");
		aButton.addActionListener(aHandler);
		aButton.setBounds(833, 250, 233, 40);
		content.add(aButton);
		
		setSize(1100, 325);
		setResizable(false);
		setLocation(100, 100);
		setVisible(true);
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
	}
	
	private class DefaultHandler implements ActionListener
	{
		public void actionPerformed(ActionEvent e)
		{
			if (e.getActionCommand().equals("Test File"))
			{
				ArrayList<String> fileContents = new ArrayList<String>();
				
				Scanner scanner;
				try
				{
					scanner = new Scanner(new File(INFILE));
					
					while (scanner.hasNextLine())
						fileContents.add(scanner.nextLine());
					
					scanner.close();
				}
				catch (FileNotFoundException e1)
				{
					e1.printStackTrace();
				}
				
				String[] output = new String[fileContents.size()];
				fileContents.toArray(output);
				
				outText.setText("");
				for (int i = 0; i < output.length; i++)
					outText.setText(outText.getText() + "." + output[i] + "." + "\n");
			}
			else if (e.getActionCommand().equals("Run File"))
			{
				ArrayList<String> fileContents = new ArrayList<String>();
				
				Scanner scanner;
				try
				{
					scanner = new Scanner(new File(INFILE));
					
					while (scanner.hasNextLine())
						fileContents.add(scanner.nextLine());
					
					scanner.close();
				}
				catch (FileNotFoundException e1)
				{
					e1.printStackTrace();
				}
				
				String[] output = new String[fileContents.size()];
				fileContents.toArray(output);
				
				String[] answer = myAlgorithm(output);
				
				
				Writer out;
				
				try
				{
					out = new OutputStreamWriter(new FileOutputStream(OUTFILE));
					
					for (int i = 0; i < answer.length; i++)
						out.write(answer[i] + "\n");
					
					out.close();
				}
				catch (FileNotFoundException e1)
				{
					e1.printStackTrace();
				}
				catch (IOException e1)
				{
					e1.printStackTrace();
				}
				
				outText.setText("File Written");
			}
			else if (e.getActionCommand().equals("Test TextBox"))
			{
				String[] output = inText.getText().split("\n");
				
				outText.setText("");
				for (int i = 0; i < output.length; i++)
					outText.setText(outText.getText() + "." + output[i] + "." + "\n");
			}
			else if (e.getActionCommand().equals("Run TextBox"))
			{
				String[] output = inText.getText().split("\n");
				
				String[] answer = myAlgorithm(output);
				
				outText.setText("");
				for (int i = 0; i < answer.length; i++)
					outText.setText(outText.getText() + answer[i] + "\n");
			}
		}
		
		
		// IMPORTANT NOTE:: INFILE is read and OUTFILE is written
		//					in the Project Directory.
		
		// TODO:: Write all of your algorithm code here
		// 		  String[] myData is the lines of input
		//		  You must return a String[]
		public String[] myAlgorithm(String[] myData)
		{
			int numProbs = Integer.parseInt(myData[0]);
			
			String[] workSet = new String[numProbs];
			for (int i = 0; i < numProbs; i++)
			{
				// mess with myData[i + 1] here and output to workSet[i]
				String test = myData[i + 1];
				String output = "";
				
				for (int j = 0; j < test.length(); j++)
				{
					if (test.charAt(j) == 'a')
						output += 'y';
					if (test.charAt(j) == 'b')
						output += 'h';
					if (test.charAt(j) == 'c')
						output += 'e';
					if (test.charAt(j) == 'd')
						output += 's';
					if (test.charAt(j) == 'e')
						output += 'o';
					if (test.charAt(j) == 'f')
						output += 'c';
					if (test.charAt(j) == 'g')
						output += 'v';
					if (test.charAt(j) == 'h')
						output += 'x';
					if (test.charAt(j) == 'i')
						output += 'd';
					if (test.charAt(j) == 'j')
						output += 'u';
					if (test.charAt(j) == 'k')
						output += 'i';
					if (test.charAt(j) == 'l')
						output += 'g';
					if (test.charAt(j) == 'm')
						output += 'l';
					if (test.charAt(j) == 'n')
						output += 'b';
					if (test.charAt(j) == 'o')
						output += 'k';
					if (test.charAt(j) == 'p')
						output += 'r';
					if (test.charAt(j) == 'q')
						output += 'z';
					if (test.charAt(j) == 'r')
						output += 't';
					if (test.charAt(j) == 's')
						output += 'n';
					if (test.charAt(j) == 't')
						output += 'w';
					if (test.charAt(j) == 'u')
						output += 'j';
					if (test.charAt(j) == 'v')
						output += 'p';
					if (test.charAt(j) == 'w')
						output += 'f';
					if (test.charAt(j) == 'x')
						output += 'm';
					if (test.charAt(j) == 'y')
						output += 'a';
					if (test.charAt(j) == 'z')
						output += 'q';
					if (test.charAt(j) == ' ')
						output += ' ';
				}
				
				workSet[i] = output;
			}
			
			String[] myOutput = new String[numProbs];
			for (int i = 0; i < numProbs; i++)
				myOutput[i] = "Case #" + (i + 1) + ": " + workSet[i];
			
			return myOutput;
		}
	}
}
