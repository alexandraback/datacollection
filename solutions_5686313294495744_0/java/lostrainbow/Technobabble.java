package codejam;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.HashSet;
import java.util.List;
import java.util.PriorityQueue;
import java.util.Set;

public class Technobabble {
	static private class Topic implements Comparable<Topic>{
		String first, second;
		Topic (String first, String second) {
			this.first = first;
			this.second = second;
		}
		@Override
		public int compareTo(Topic t) {
			// TODO Auto-generated method stub
			return first.compareTo(t.first) == 0 ? second.compareTo(t.second) : first.compareTo(t.first);
		}
		@Override
		public String toString() {
			return first + " " + second;
		}
	}
	static private class TopicSet {
		String first;
		List<Topic> topics = new ArrayList<Topic>();
		TopicSet (String first) {
			this.first = first;
		}
	}
	static String PATH = "/Users/chenji/Downloads/";
	public static void main(String[] args) throws IOException {
		BufferedReader reader = new BufferedReader(new FileReader(PATH + "C-small-attempt0.in"));
		PrintWriter writer = new PrintWriter(new BufferedWriter(new FileWriter(PATH + "C-small-attempt0.out")));
		/* ----------------------------------------- */
		/* codes */
		String[] words = new String[2];
		int N = Integer.parseInt(reader.readLine());
		for (int n = 0; n < N; n ++) {
			int T = Integer.parseInt(reader.readLine());
			PriorityQueue<Topic> topicList = new PriorityQueue<Topic>();
			for (int t = 0; t < T; t ++) {
				words = reader.readLine().split(" ");
				topicList.add(new Topic(words[0], words[1]));
			}
			String prev = "";
			Set<String> set = new HashSet<String>();
			List<TopicSet> topicGroup = new ArrayList<TopicSet>();
			TopicSet curSet = null;
			int count = 0;
			System.out.println();
			while (!topicList.isEmpty()) {
				Topic topic = topicList.poll();
				System.out.println(topic);
				if (!topic.first.equals(prev)) {
					prev = topic.first;
					curSet = new TopicSet(prev);
					topicGroup.add(curSet);
				}
				curSet.topics.add(topic);
				set.add(topic.second);
			}
			for (TopicSet s: topicGroup) {
				System.out.println(s.topics);
			}
			maxCover = 0;
			dp(topicGroup, 0, new HashSet<String>());
			System.out.println(maxCover);
			System.out.println(set.size());
			int extra = set.size() - maxCover;
			extra = extra > 0 ? extra : 0;
			System.out.println(extra);
			int minOrigin = topicGroup.size() + extra;
			System.out.println(minOrigin);
			count = T - minOrigin;
			System.out.println(count);
			writer.printf("Case #%d: %d\n", n+1, count);
		}
		writer.flush();
		writer.close();
	}
	static int maxCover = 0;
	public static void dp (List<TopicSet> topicGroup, int n, Set<String> set) {
		if (n == topicGroup.size()) {
			if (set.size() > maxCover)
				maxCover = set.size();
		} else {
			TopicSet cur = topicGroup.get(n);
			for (Topic t : cur.topics) {
				Set<String> nset = new HashSet<String>(set);
				nset.add(t.second);
				dp(topicGroup, n+1, nset);
			}
		}
		
	}
}
