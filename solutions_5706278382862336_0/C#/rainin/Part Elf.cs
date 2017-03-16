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
		char[] cs = new char[] { ' ', ',' };
		int ncase = int.Parse(Console.ReadLine());

		for (int h = 0; h < ncase; h++) {
			int cnt = 0;
			string res = not;
			int[] pq = parseAry(Console.ReadLine().Split('/'));
			int[] save = (int[])pq.Clone();
			if (pq[0] == pq[1]) { res = "0"; }
			while (pq[0] < pq[1]) {
				if (pq[1] % 2 == 1) {
					if (pq[0] != pq[1]) { res = not; break; }
				}
				cnt++;
				pq[1] /= 2;
				res = ""+cnt;
			}

			AnswerGCJ(h, res.ToString());
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
		for (int i = 0; i < str.Length; i++) {
			nums[i] = int.Parse(str[i]);
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
