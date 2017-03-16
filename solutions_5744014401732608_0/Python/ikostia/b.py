def read_input():
    b, m = map(int, raw_input().split())
    return b, m

def print_output(i, output):
    print "Case #%i: %s" % (i+1, output)

def solve(i, input):
    b, m = input
    if m > 2**(b-2):
        return "IMPOSSIBLE"
    a = [['0' for i in xrange(b)] for j in xrange(b)]
    if m == 2**(b-2):
        a[0][b-1] = '1'
        m -= 1

    i = b-2
    while i > 0:
        if m % 2: a[0][i] = '1'
        m = m / 2
        i = i - 1

    for j in xrange(1, b):
       i = j + 1
       while i < b:
           a[j][i] = '1'
           i = i + 1
  
    astr = "\n".join([''.join(row) for row in a])
    return "POSSIBLE\n" + astr

if __name__ == "__main__":
    t = int(raw_input())
    for i in xrange(t):
        input = read_input()
        output = solve(i, input)
        print_output(i, output)

