using System;
using System.Text;
using System.Linq;
using System.Collections.Generic;
using System.Threading.Tasks;
using System.IO;

class Program {

	static Encoding Enc = Encoding.GetEncoding("us-ascii");
	//static StreamReader Console = new StreamReader(@"C:\GoogleCodeJam\A-large.in", Enc);
	static StreamWriter writer = new StreamWriter(@"C:\GoogleCodeJam\Result.txt", false, Enc);

	static void Main(string[] args) {

		string not = "impossible";
		char[using System;
using System.Text;
using System.Linq;
using System.Collections.Generic;
using System.Threading.Tasks;
using System.IO;

class Program {

	static Encoding Enc = Encoding.GetEncoding("us-ascii");
	//static StreamReader Console = new StreamReader(@"C:\GoogleCodeJam\A-large.in", Enc);
	static StreamWriter writer = new StreamWriter(@"C:\GoogleCodeJam\Result.txt", false, Enc);

	static void Main(string[] args) {

		string not = "impossible";
		char[] cs = new char[] { ' ', ',' };
		int ncase = int.Parse(Console.ReadLine());

		for (int h = 0; h < ncase; h++) {
			int cnt = 0;
			string res = not;
			
			int n = int.Parse(Console.ReadLine());
			string[] str = Console.ReadLine().Split(cs);

			Permutation<string> perm = new Permutation<string>();
			string[][] re=perm.Perm(str);
			cnt=0;
			foreach (string[] s in re) {
				int bo = 0;
				for (int i = 0; i < s.Length-1; i++) {
					if (s[i][s[i].Length - 1] == s[i + 1][0]) {
						bo = 1;
					} else {
						if (bo == 0) { break; }
						bo = 0;
					}

				}
				if (bo == 0) { continue; }
				cnt++;
			}


			AnswerGCJ(h, ""+cnt);
			//AnswerGCJa(h, res.ToString(), pq[0], save[1]);
		}



		writer.Close();
		return;
	}



	static void AnswerGCJ(int i, string ans) {

		writer.WriteLine("Case #" + ( i + 1 ) + ": " + ans);
		return;
	}
	static void AnswerGCJa(int i, string ans, int a, int b) {

		writer.WriteLine("Case #" + ( i + 1 ) + ": " + ans+"    "+a+"/"+b);
		return;
	}
	//@String[]‚ðint[]‚É•ÏŠ·
	static int[] parseAry(String[] str) {
		int[] nums = new int[str.Length];
		for (int i = 0; i < str.Length; i++) { nums[i] = int.Parse(str[i]); }
		return nums;
	}
}
public class PriQ {
	public int rank { get; set; }
	public string rankstr { get; set; }
	public int num { get; set; }
	public int[] nums { get; set; }
	public Object obj { get; set; }
	public PriQ() { }
}

public class PriorityQueue {
	List<PriQ> list = new List<PriQ>();
	public PriorityQueue() { }
	public PriorityQueue(PriQ p) { list.Add(p); }
	public void Enqueue(PriQ item) { list.Insert(Binary_Search(item), item); }
	public void EnqueueStr(PriQ item) { list.Insert(Binary_Search_Str(item), item); }
	public PriQ Dequeue() { PriQ r = list[0]; list.RemoveAt(0); return r; }
	public PriQ DequeueLast() { PriQ r = list[list.Count - 1]; list.RemoveAt(list.Count - 1); return r; }
	public PriQ Peek() { return list[0]; }
	public PriQ Last() { return list[list.Count - 1]; }
	public int Count { get { return list.Count; } }

	private int Binary_Search(PriQ pq) {
		int Lower = 0;
		int Upper = list.Count - 1;
		while (Lower <= Upper) {
			int Center = ( Lower + Upper ) >> 1;
			if (pq.rank > list[Center].rank) {
				Lower = Center + 1;
			} else if (pq.rank < list[Center].rank) {
				Upper = Center - 1;
			} else {
				return Center;
			}
		}
		return Lower;
	}
	private int Binary_Search_Str(PriQ pq) {
		int Lower = 0;
		int Upper = list.Count - 1;
		while (Lower <= Upper) {
			int Center = ( Lower + Upper ) >> 1;
			if (string.CompareOrdinal(pq.rankstr, list[Center].rankstr) > 0) {
				Lower = Center + 1;
			} else if (string.CompareOrdinal(pq.rankstr, list[Center].rankstr) < 0) {
				Upper = Center - 1;
			} else {
				return Center;
			}
		}
		return Lower;
	}
}

public class Permutation<T> {
	private T[][] res;
	private int cnt = 0;
	private int len = 0;
	public T[][] Perm(T[] ad) {
		long size = 1;
		for (int i = 2; i <= ad.Length; i++) { size = size * i; }
		res = new T[size][];
		cnt = 0;
		len = ad.Length;
		List<T> li = new List<T>(ad);
		prm(new List<T>(), li);

		return res;
	}

	private void prm(List<T> now, List<T> li) {
		if (now.Count == len) {
			res[cnt] = now.ToArray();
			cnt++;
			return;
		}
		for (int i = 0; i < li.Count; i++) {
			List<T> t = new List<T>(now);
			List<T> e = new List<T>(li);
			t.Add(li[i]);
			e.RemoveAt(i);
			prm(t, e);
		}
		return;
	}
}] cs = new char[] { ' ', ',' };
		int ncase = int.Parse(Console.ReadLine());

		for (int h = 0; h < ncase; h++) {
			int cnt = 0;
			string res = not;
			long[] pq = parseAry(Console.ReadLine().Split('/'));
			long[] save = (long[])pq.Clone();

			if (pq[0] == pq[1]) { res = "0"; }
			while (pq[0] < pq[1]) {
				if (pq[1] % 2 == 1) {
					if (pq[0] != pq[1]) { res = not; break; }
				}
				cnt++;
				pq[1] /= 2;
				res = ""+cnt;
			}
			if (pq[0] != pq[1]) {
				long[] nex = { pq[0] - pq[1], pq[1] };
				if (cal(nex) == false) { res = not; }
			}
			AnswerGCJ(h, res.ToString());
			//AnswerGCJa(h, res.ToString(), pq[0], save[1]);
		}



		writer.Close();
		return;
	}

	static bool cal(long[] pq) {

		if (pq[0] == pq[1]) { return true; }
		while (pq[0] < pq[1]) {
			if (pq[1] % 2 == 1) {
				if (pq[0] != pq[1]) { return false; }
			}
			pq[1] /= 2;
		}
		if (pq[0] != pq[1]) {
			long[] nex = { pq[0] - pq[1], pq[1] };
			if (cal(nex) == true) { return true; } else { return false; }
		}
		return true;
	}


	static void AnswerGCJ(int i, string ans) {

		writer.WriteLine("Case #" + ( i + 1 ) + ": " + ans);
		return;
	}
	static void AnswerGCJa(int i, string ans, int a, int b) {

		writer.WriteLine("Case #" + ( i + 1 ) + ": " + ans+"    "+a+"/"+b);
		return;
	}

	//@String[]‚ðint[]‚É•ÏŠ·
	static long[] parseAry(String[] str) {
		long[] nums = new long[str.Length];
		for (int i = 0; i < str.Length; i++) {
			nums[i] = long.Parse(str[i]);
		}
		return nums;
	}
}
public class PriQ {
	public int rank { get; set; }
	public string rankstr { get; set; }
	public int num { get; set; }
	public int[] nums { get; set; }
	public Object obj { get; set; }
	public PriQ() { }
}

public class PriorityQueue {
	List<PriQ> list = new List<PriQ>();
	public PriorityQueue() { }
	public PriorityQueue(PriQ p) { list.Add(p); }
	public void Enqueue(PriQ item) { list.Insert(Binary_Search(item), item); }
	public void EnqueueStr(PriQ item) { list.Insert(Binary_Search_Str(item), item); }
	public PriQ Dequeue() { PriQ r = list[0]; list.RemoveAt(0); return r; }
	public PriQ DequeueLast() { PriQ r = list[list.Count - 1]; list.RemoveAt(list.Count - 1); return r; }
	public PriQ Peek() { return list[0]; }
	public PriQ Last() { return list[list.Count - 1]; }
	public int Count { get { return list.Count; } }

	private int Binary_Search(PriQ pq) {
		int Lower = 0;
		int Upper = list.Count - 1;
		while (Lower <= Upper) {
			int Center = ( Lower + Upper ) >> 1;
			if (pq.rank > list[Center].rank) {
				Lower = Center + 1;
			} else if (pq.rank < list[Center].rank) {
				Upper = Center - 1;
			} else {
				return Center;
			}
		}
		return Lower;
	}
	private int Binary_Search_Str(PriQ pq) {
		int Lower = 0;
		int Upper = list.Count - 1;
		while (Lower <= Upper) {
			int Center = ( Lower + Upper ) >> 1;
			if (string.CompareOrdinal(pq.rankstr, list[Center].rankstr) > 0) {
				Lower = Center + 1;
			} else if (string.CompareOrdinal(pq.rankstr, list[Center].rankstr) < 0) {
				Upper = Center - 1;
			} else {
				return Center;
			}
		}
		return Lower;
	}
}
