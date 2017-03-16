using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace GCJ20121CC {
    class Program {
        int N, M;
        long[] toys, boxes;
        struct State {
            public int tIndex, bIndex;
            public long tUsed, bUsed;
        }
        long update(ref State st) {
            if (toys[st.tIndex * 2 + 1] == boxes[st.bIndex * 2 + 1]) {
                long tLeft = toys[st.tIndex * 2] - st.tUsed;
                long bLeft = boxes[st.bIndex * 2] - st.bUsed;
                if (tLeft == bLeft) {
                    st.tIndex++; st.bIndex++;
                    st.tUsed = 0; st.bUsed = 0;
                    return tLeft;
                }
                else if (tLeft < bLeft) {
                    st.tIndex++; st.tUsed = 0;
                    st.bUsed += tLeft;
                    return tLeft;
                }
                else if (bLeft < tLeft) {
                    st.bIndex++; st.bUsed = 0;
                    st.tUsed += bLeft;
                    return bLeft;
                }
            }
            return 0;
        }
        long RecSolve(State st) {
            long count = 0;
            do {
                count += update(ref st);
                if (st.bIndex >= boxes.Length / 2 || st.tIndex >= toys.Length / 2) return count;
            } while (toys[st.tIndex * 2 + 1] == boxes[st.bIndex * 2 + 1]);
            long count1 = -1, count2 = -1;
            int nextToy, nextBox;
            // Option 1: Select next toy matching box
            for (nextToy = st.tIndex + 1; nextToy < toys.Length / 2; ++nextToy) {
                if (boxes[st.bIndex*2+1] == toys[2 * nextToy + 1])
                    break;
            }
            if (nextToy < toys.Length/2) {
                State st1 = st;
                st1.tIndex = nextToy; st1.tUsed = 0;
                count1 = count + RecSolve(st1);
            }
            // Option 2: Select next toy matching box
            for (nextBox = st.bIndex + 1; nextBox < boxes.Length / 2; ++nextBox) {
                if (toys[st.tIndex*2+1] == boxes[2 * nextBox + 1])
                    break;
            }
            if (nextBox < boxes.Length/2) {
                State st1 = st;
                st1.bIndex = nextBox; st1.bUsed = 0;
                count2 = count + RecSolve(st1);
            }
            if (count1 < 0 && count2 < 0) return count;
            else if (count1 > count2) return count1;
            else return count2;
        }
        long Solve() {
            State st = new State();
            st.tIndex = 0;
            st.bIndex = 0;
            long result = RecSolve(st);
            return result;
        }
        Program() {
            int T = int.Parse(Console.ReadLine());
            for (int tt = 0; tt < T; ++tt) {
                int[] NM = Console.ReadLine().Split().Select(p => int.Parse(p)).ToArray();
                N = NM[0]; M = NM[1];
                toys = Console.ReadLine().Split().Select(p => long.Parse(p)).ToArray();
                boxes = Console.ReadLine().Split().Select(p => long.Parse(p)).ToArray();
                Console.WriteLine("Case #{0}: {1}", tt + 1, Solve());
            }
        }
        static void Main(string[] args) {
            new Program();
        }
    }
}
