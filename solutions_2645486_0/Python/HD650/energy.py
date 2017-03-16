import os, sys

infile = sys.stdin

def read(infile):
    E, R, N = [int(item) for item in infile.readline().split()]
    values = [int(item) for item in infile.readline().split()]
    return E, R, values

def fill_rmq_array(values):
    array = [0] * len(values)

    for i, v in enumerate(values):
        array[i] = list()
        length = 1
        while i + length - 1 < len(values):
            array[i].append(0)
            length *= 2
    
    length = 1
    while length < len(values):
        for i in xrange(len(values)):
            if i + length - 1 >= len(values):
                break
            if length == 1:
                cur = i
            else:
                half = length / 2
                a = values[array[i][half]]
                b = values[array[i+half][half]]
                if a >= b:
                    cur = array[i][half]
                else:
                    cur = array[i+half][half]
            array[i][length] = cur
        length *= 2
    return array
        
def solve(E, R, values):
    N = len(values)
    dp = [0] * N
    for i in xrange(N):
        dp[i] = [0] * (E + 1)

    for energy in xrange(E+1):
        dp[N-1][energy] = values[N-1] * energy

    for idx in range(N)[::-1]:
        if idx == N - 1:
            continue
        for energy in xrange(E+1):
            best = 0
            for spending in xrange(energy + 1):
                left = min(E, energy - spending + R)
                val = values[idx] * spending + dp[idx + 1][left]
                if val > best:
                    best = val
            dp[idx][energy] = best
    return dp[0][E]


if __name__ == "__main__":
    num = int(infile.readline())
    for i in xrange(num):
        E, R, values = read(infile)
        ret = solve(E, R, values)
        print "Case #%d: %d" % (i + 1, ret)
