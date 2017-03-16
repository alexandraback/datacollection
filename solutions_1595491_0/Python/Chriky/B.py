import sys

f = open(sys.argv[1])
T = int(f.readline())
for t in range(T):
    data = map(int, f.readline().split())
    N, S, p, totals = data[0], data[1], data[2], sorted(data[3:], reverse = True)
    answer = 0
    for total in totals:
        if total >= p + 2 * max(0, p - 1):                  # Could have best mark >= p normally
            answer += 1
        elif S > 0 and total >= p + 2 * max(0, p - 2):      # Could have best mark >= p suprisingly
            answer += 1
            S -= 1
    print "Case #%d:" % (t + 1), answer
    