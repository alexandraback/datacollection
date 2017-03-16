package gcj13.qra;

import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.Component;
import java.awt.EventQueue;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigDecimal;
import java.math.BigInteger;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.PriorityQueue;
import java.util.StringTokenizer;
import java.util.Vector;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JScrollPane;
import javax.swing.JTable;
import javax.swing.table.AbstractTableModel;
import javax.swing.table.DefaultTableCellRenderer;

public class Erdem {

	//keywords: multi thread 
	static class A extends Thread {
		String result; // DON'T REMOVE
		
		char board[][] = new char[4][];
		
		public A() throws IOException {
			for (int i = 0; i < 4; i++) {
				String line = LINE();
				board[i] = line.toCharArray();
			}
			LINE();
		}
		
		char get(int j) {
			if( j < 16 ) {
				return board[j/4][j%4];
			} else if( j < 32 ) {
				j -= 16;
				return board[j%4][j/4];
			} else if( j < 36 ) {
				j -= 32;
				return board[j][j];
			} else {
				j -= 36;
				return board[j][3-j];
			} 
		}

		@Override
		public void run() {
			for (int j = 0; j < 40; j+=4) {
				char player = get(j);
				if( player == 'T' ) {
					player = get(j+1);
				}
				if( player == '.' ) {
					continue;
				}
				for (int g = 1; g < 4; g++) {
					final char c = get(j+g);
					if( player != c && c != 'T' ) {
						player = '.';
						break;
					}
				}
				if( player != '.' ) {
					result = player+" won";
					return;
				}
			}
			
			for (int i = 0; i < 4; i++) {
				for (int j = 0; j < 4; j++) {
					if( board[i][j] == '.' ) {
						result = "Game has not completed";
						return;
					}
				}
			}
				
			result = "Draw";
		}
	}

	public static void run() throws Exception {
		String qprefix = "B";
		/** /
		init(qprefix+"-large");
		/** /
		init(qprefix+"-large-practice");
		/** /
		init(qprefix + "-small-practice");
		/** /
		init("test");
		/**/
		init(null);
		/**/

		int cases = INT();
		for (int cc = 1; cc <= cases; cc++) {
			A a = new A();
			a.start();
			
			A b = null;
			if(!true) {
				if( cc < cases ) {
					b = new A();
					b.start();
				}
			}
			
			a.join();
			if( a.result == null ) {
				break;
			}
			println("Case #" + cc + ": "+a.result);
			if( b != null ) {
				b.join();
				if( b.result == null ) {
					break;
				}
				cc++;
				println("Case #" + cc + ": "+b.result);
			}
		}
	}

	static class Ct extends Thread {
		public void run() {
		}
	}

	static int[][] mapClone(int[][] map) {
		int[][] cmap = map.clone();
		for (int i = 0; i < cmap.length; i++) {
			cmap[i] = map[i].clone();
		}
		return cmap;
	}

	// *************************************************************************************
	// *********************************** FRAMEWORK
	// *************************************************************************************

	public static BufferedReader stdin = new BufferedReader(
			new InputStreamReader(System.in));
	public static boolean isStandardInput = false;

	public static File input;
	public static FileReader inputreader;
	public static BufferedReader in;

	public static File output;
	public static FileWriter outputwriter;
	public static BufferedWriter out;

	public static StringTokenizer st;

	public static void main(String[] args) throws Exception {
		doSTDIN(true);
		setOutput("test.out");
		run();
		close();
	}

	public static void init(String problemName) throws Exception {
		String className = Thread.currentThread().getStackTrace()[1].getClassName();
		String path = "src/" + className.replace('.', '/');
		path = path.substring(0, path.lastIndexOf('/'));
		File parent = new File(path);
		
		if(problemName == null) {
			String list[] = {"large", "small-attempt", "large-practice", "small-practice"};
			loop1:
			for (char a = 'D'; a >= 'A'; a--) {
				String fn1 = ""+a+'-';
				loop2:
				for (int i = 0; i < list.length; i++) {
					final String pf = fn1 + list[i];
					if( i == 1 ){
						for (int j = 0; true; j++) {
							if( new File(parent, pf + j + ".in").exists() ) {
								problemName = pf + j;
							} else {
								if( j > 0 ) {
									break loop1;
								} else {
									continue loop2;
								}
							}
						}
					} else {
						if( new File(parent, pf + ".in").exists() ) {
							problemName = pf;
							break loop1;
						}
					}
				}
			}
			if(problemName == null) {
				if( new File(parent, "test.in").exists() ) {
					problemName = "test";
				}
			}
		}
		doSTDIN(false);
		problemName = parent.getAbsolutePath() + "/" + problemName;
		setInput(problemName + ".in");
		setOutput(problemName + ".out");
	}

	// **************** PRINT METHODS **********************

	public static void println() throws IOException {
		out.write("\n");
		System.out.println();
	}

	public static void println(Object obj) throws IOException {
		out.write(obj.toString());
		out.write("\n");
		System.out.println(obj.toString());
	}

	public static void print(Object obj) throws IOException {
		out.write(obj.toString());
		System.out.print(obj.toString());
	}

	public static void println(long number) throws IOException {
		out.write(Long.toString(number));
		out.write("\n");
		System.out.println(number);
	}

	public static void print(long number) throws IOException {
		out.write(Long.toString(number));
		System.out.print(number);
	}

	public static void println(char c) throws IOException {
		out.write(Character.toString(c));
		out.write("\n");
		System.out.println(c);
	}

	public static void print(char c) throws IOException {
		out.write(Character.toString(c));
		System.out.print(c);
	}

	public static void println(String line) throws IOException {
		out.write(line);
		out.write("\n");
		System.out.println(line);
	}

	public static void print(String line) throws IOException {
		out.write(line);
		System.out.print(line);
	}

	public static void printf(String line, Object...arg) throws IOException {
		line = String.format(line, arg);
		out.write(line);
		System.out.print(line);
	}

	// ******************** INPUT DECLARATION ******************

	public static void doSTDIN(boolean standard) {
		isStandardInput = standard;
	}

	public static void setInput(String filename) throws IOException {
		input = new File(filename);
		inputreader = new FileReader(input);
		in = new BufferedReader(inputreader);
	}

	public static void setOutput(String filename) throws IOException {
		output = new File(filename);
		outputwriter = new FileWriter(output);
		out = new BufferedWriter(outputwriter);
	}

	public static void close() throws IOException {
		if (in != null)
			in.close();
		if (inputreader != null)
			inputreader.close();

		if (out != null)
			out.flush();
		if (out != null)
			out.close();
		if (outputwriter != null)
			outputwriter.close();
	}

	// ************************** INPUT READING *****************

	static String LINE() throws IOException {
		return isStandardInput ? stdin.readLine() : in.readLine();
	}

	static String TOKEN() throws IOException {
		while (st == null || !st.hasMoreTokens())
			st = new StringTokenizer(LINE());
		return st.nextToken();
	}

	static int INT() throws IOException {
		return Integer.parseInt(TOKEN());
	}

	static long LONG() throws IOException {
		return Long.parseLong(TOKEN());
	}

	static double DOUBLE() throws IOException {
		return Double.parseDouble(TOKEN());
	}

	static BigInteger BIGINT() throws IOException {
		return new BigInteger(TOKEN());
	}

}

class AF {
	private Object array;
	private int oa = 0;
	private int ob = 0;
	private int as = 10;
	private int bs = 10;

	public AF(Object array) {
		this.array = array;
	}

	public AF(Object array, int oa, int ob) {
		this.array = array;
		this.oa = oa;
		this.ob = ob;
	}

	public AF(Object array, int oa, int ob, int as, int bs) {
		this.array = array;
		this.oa = oa;
		this.ob = ob;
		this.as = as;
		this.bs = bs;
	}

	public String toString() {
		StringBuilder sb = new StringBuilder();
		for (int a = 0; a < as; a++) {
			sb.append(a + oa).append('[');
			for (int b = 0; b < bs; b++) {
				sb.append(get(a, b));
				if (b != bs - 1)
					sb.append(',');
			}
			sb.append("]\n");
		}
		return sb.toString();
	}

	private String get(int a, int b) {
		a += oa;
		b += ob;
		String s = " ";
		try {
			if (array instanceof int[][]) {
				int[][] na = (int[][]) array;
				s = Integer.toString(na[a][b]);
			} else if (array instanceof byte[][]) {
				byte[][] na = (byte[][]) array;
				s = Byte.toString(na[a][b]);
			} else if (array instanceof Object[][]) {
				Object[][] na = (Object[][]) array;
				s = na[a][b].toString();
			}
		} catch (Exception e) {
		}
		while (s.length() < 2) {
			s = " " + s;
		}
		return s;
	}
}

class AF2 extends JFrame implements ActionListener {
	static Object lock = new Object();

	private JTable jt;

	public AF2(String title, int[][] data) {
		super(title);
		setSize(150, 150);
		addWindowListener(new WindowAdapter() {
			public void windowClosing(WindowEvent we) {
				dispose();
				System.exit(0);
			}
		});
		jt = new JTable(new ITableModel(data));
		jt.setDefaultRenderer(Integer.class, new CustomTableCellRenderer());

		// jt.setAutoResizeMode(JTable.AUTO_RESIZE_OFF);
		JScrollPane pane = new JScrollPane(jt,
				JScrollPane.VERTICAL_SCROLLBAR_AS_NEEDED,
				JScrollPane.HORIZONTAL_SCROLLBAR_AS_NEEDED);
		getContentPane().add(pane);
		
		JButton button = new JButton("Continue");
		getContentPane().add(button, BorderLayout.SOUTH);
		button.addActionListener(this);
		
		pack();
		setVisible(true);
	}

	public void updateData(int[][] data) {
		((ITableModel) jt.getModel()).updateData(data);
		/*synchronized (lock) {
			try {
				lock.wait();
			} catch (InterruptedException e) {
			}
		}*/
		return;
	}

	public void actionPerformed(ActionEvent arg0) {
		synchronized (lock) {
			lock.notify();
		}
	}
}

class ITableModel extends AbstractTableModel {
	int[][] data;
	int[][] old_data;

	public ITableModel(int[][] data) {
		if (data != null)
			this.data = data;
		else
			this.data = new int[1][1];
	}

	public void updateData(int[][] p_data) {
		if( p_data.length == data.length && p_data[0].length == data[0].length ) {
			old_data = data;
		} else {
			old_data = null;
		}
		this.data = p_data;
		EventQueue.invokeLater(new Runnable() {
			public void run() {
				fireTableStructureChanged();
			}
		});
	}

	public int getColumnCount() {
		return data[0].length + 1;
	}

	public int getRowCount() {
		return data.length;
	}

	public String getColumnName(int column) {
		return Integer.toString(column - 1);
	}

	public Object getValueAt(int rowIndex, int columnIndex) {
		if (columnIndex == 0)
			return rowIndex;
		if( old_data != null && data[rowIndex][columnIndex - 1] != old_data[rowIndex][columnIndex - 1] ) {
			return ""+old_data[rowIndex][columnIndex - 1]+" -> "+data[rowIndex][columnIndex - 1];
		}
		return data[rowIndex][columnIndex - 1];
	}

	public Class<?> getColumnClass(int arg0) {
		return getValueAt(0, arg0).getClass();
	}
}

class CustomTableCellRenderer extends DefaultTableCellRenderer {
	public Component getTableCellRendererComponent(JTable table, Object value,
			boolean isSelected, boolean hasFocus, int row, int column) {
		Component cell = super.getTableCellRendererComponent(table, value,
				isSelected, hasFocus, row, column);
		if (column == 0) {
			cell.setBackground(Color.gray);
		} else if (value instanceof Integer) {
			Integer amount = (Integer) value;
			if (amount.intValue() <= 0) {
				cell.setBackground(Color.red);
			} else {
				cell.setBackground(Color.white);
			}
		} else {
			cell.setBackground(Color.yellow);
		}
		return cell;
	}
}
