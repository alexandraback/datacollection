import sys

def solve(start, end, vals):
    i = 0
    while start > vals[i][1]:
        i += 1
    count = 0
    while end >= vals[i][1]:
        count += 1
        i += 1
    return count

def main():
    vals = []
    for line in open('numlist.txt'):
        num, sq = [int(v) for v in line.strip().split()]
        vals.append((num, sq))

    count = int(sys.stdin.readline())
    for i in range(count):
        start, end = [int(v) for v in sys.stdin.readline().strip().split()]
        print "Case #%d: %d" % (i + 1, solve(start, end, vals))

main()
