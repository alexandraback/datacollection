import sys
import collections


class TypewriterMonkey:


    def solve_case(self, f):
        k, l, s = map(int, f.readline().split())
        keyboard = f.readline().rstrip()
        keyboard_frequency = {}
        for key, c in collections.Counter(keyboard).iteritems():
            keyboard_frequency[key] = c / float(len(keyboard))
        target = list(f.readline().rstrip())

        if len(target) > s or len(set(target) - set(keyboard)) > 0:
            return 0.0

        tot = 0
        tot_e = 0.0

        e_stack = []
        tot_stack = []

        for i in xrange(s):
            e_stack.append((0, 1.0))
            tot_stack.append(0)

            c = target[tot_stack[0]]
            for j in reversed(xrange(len(tot_stack))):
                if c != target[tot_stack[j]]:
                    tot_stack.pop()
                else:
                    tot_stack[j] += 1
            while tot_stack and tot_stack[0] == len(target):
                tot += 1
                tot_stack.pop(0)

            for j in reversed(xrange(len(e_stack))):
                e_stack[j] = e_stack[j][0] + 1, keyboard_frequency[target[e_stack[j][0]]] * e_stack[j][1]
            while e_stack and e_stack[0][0] == len(target):
                tot_e += e_stack[0][1]
                e_stack.pop(0)

        return tot - tot_e

    def create_report(self, ci, r):
        r = ", ".join(map(str, r)) if not isinstance(r, str) and isinstance(r, (list, tuple)) else str(r)
        return "Case #" + str(ci) + ": " + r

    def solve(self, f):
        t = int(f.readline())
        results = []
        for c in range(t):
            results.append(self.solve_case(f))
        return "\n".join(map(lambda c: self.create_report(c[0] + 1, c[1]), enumerate(results)))

    def solve_and_save(self, out, f):
        out.write(self.solve(f))

if __name__ == "__main__":
    tm = TypewriterMonkey()

    if len(sys.argv) < 2:
        tm.solve_and_save(sys.stdout, sys.stdin)
    else:
        f = open("./in/" + sys.argv[1] + ".in", 'r')
        o = open("./out/" + sys.argv[1] + ".out", 'w')
        tm.solve_and_save(o, f)
        f.close()
        o.close()
