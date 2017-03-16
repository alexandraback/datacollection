
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.InputStream;
import java.io.PrintStream;
import java.util.ArrayList;
import java.util.Collection;
import java.util.HashMap;
import java.util.Iterator;
import java.util.Scanner;


public class Main {
	public static void main(String[] args) {
		InputStream in = System.in;
		PrintStream out = System.out;
		if (args.length > 0) {
			try {
				in = new FileInputStream(args[0]);
			} catch (FileNotFoundException e) {
				e.printStackTrace();
			}
		}
		Scanner scanner = new Scanner(in);
		int cases = scanner.nextInt();
		for (int i = 1; i <= cases; ++i) {
			int nclasses = scanner.nextInt();
			HashMap<Integer, InheritanceLink> links = new HashMap<Integer, InheritanceLink>(nclasses);
			
			for (int j = 0; j < nclasses; ++j) {
				InheritanceLink link = new InheritanceLink();
				link.subject = j;
				link.supers = new int[scanner.nextInt()];
				for (int k = 0; k < link.supers.length; ++k) {
					link.supers[k] = scanner.nextInt()-1;
				}
				links.put(j, link);
			}
			
			for (int j = 0; j < nclasses; ++j) {
				InheritanceLink link = links.get(j);
				link.links = new InheritanceLink[link.supers.length];
				for (int k = 0; k < link.supers.length; ++k) {
					link.links[k] = links.get(link.supers[k]);
				}
				link.supers = null;
			}
			
			boolean diamond = false;
			for (int j = 0; j < nclasses; ++j) {
				InheritanceLink link = links.get(j);
				Collection<Integer> result = new ArrayList<Integer>();
				if (collectSupers(link, result)) {
					diamond = true;
					break;
				}
			}
			
			out.format("Case #%d: ",i);
			if (diamond) {
				out.print("Yes");
			} else {
				out.print("No");
			}
			out.println();
		}
	}
	
	private static boolean collectSupers(InheritanceLink link, Collection<Integer> result) {
		if (link.supers == null) {
			Collection<Integer> r = new ArrayList<Integer>();
			for (int i = 0; i < link.links.length; ++i) {
				InheritanceLink c = link.links[i];
				if (r.contains(c.subject)) {
					return true;
				} else {
					r.add(c.subject);
					if (collectSupers(c, r)) {
						return true;
					}
				}
			}
			link.supers = new int[r.size()];
			Iterator<Integer> it = r.iterator();
			for (int i = 0; it.hasNext() ; i++) {
				link.supers[i] = it.next();
			}
		}
		for (int i = 0; i < link.supers.length; ++i) {
			if (result.contains(link.supers[i])) {
				return true;
			}
			result.add(link.supers[i]);
		}
		return false;
	}
	
	private static class InheritanceLink {
		public int subject;
		public int[] supers;
		public InheritanceLink[] links;
	}
}
