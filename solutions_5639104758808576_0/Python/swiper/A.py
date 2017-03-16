def solve(smax, s):
    smax = int(smax)
    shycounts = map(int, s)
    answer = 0
    standing = 0
    for shyness, number in enumerate(shycounts):
        answer = max(answer, shyness - standing)
        standing += number
    return answer

def main():
    from sys import stdin
    readline = stdin.readline
    T = int(readline())
    for case in range(T):
        print "Case #%d: %d" % (case+1, apply(solve, readline().split()))

main()
