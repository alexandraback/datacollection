import sys
sys.setrecursionlimit(100000)

def read_list_of(numtype):
    return map(numtype, raw_input().split())


def solve(n, computing):
    to_solve = [(1, 1, 'input')]

    while True:
        #print to_solve
        a, level, pred = to_solve[0]
        del to_solve[0]

        if a == n:
            return level


        if a + 1 not in computing:
            to_solve.append((a+1, level+1, '%d+1' % (a, )))
            computing[a+1] = True

        palin = int(str(a)[::-1], 10)
        if palin not in computing:
            to_solve.append((palin, level+1, 'palin %d' % (a, )))
            computing[palin] = True

def main():
    for case_number in xrange(int(raw_input())):
        n = int(raw_input())
        result = solve(n, {})

        print 'Case #%d: %d' % (case_number+1, result)

main()

#print solve(1234125, {})

# print solve(1, {})
# print solve(19, {})
# print solve(23, {})
# print solve(1012824, {})