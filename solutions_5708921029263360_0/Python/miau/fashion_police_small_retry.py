from heapq import heapify, heappop, heappush

def main():
    cases = int(input())
    for case in range(cases):
        j, p, s, k = map(int, input().split())
        result = solve(j, p, s, k)
        print("Case #%d: %s" % (case + 1, result))

def solve(jj, pp, ss, k):
    results = []
    jpcount = {}
    pscount = {}
    jscount = {}
    s_heap = []
    for s in range(ss):
        heappush(s_heap, (0, s))

    for j in range(jj):
        for p in range(pp):
            for i, entry in enumerate(s_heap):
                count, s = entry
                jp = "{0}{1}".format(j, p)
                ps = "{0}{1}".format(p, s)
                js = "{0}{1}".format(j, s)
                if jp not in jpcount:
                    jpcount[jp] = 0
                if ps not in pscount:
                    pscount[ps] = 0
                if js not in jscount:
                    jscount[js] = 0
                if jpcount[jp] < k and pscount[ps] < k and jscount[js] < k:
                    jpcount[jp] += 1
                    pscount[ps] += 1
                    jscount[js] += 1
                    results.append("{0} {1} {2}".format(j + 1, p + 1, s + 1))
                    s_heap[i] = (count + 1, s)
            heapify(s_heap)

    return str(len(results)) + "\n" + "\n".join(results)

main()
