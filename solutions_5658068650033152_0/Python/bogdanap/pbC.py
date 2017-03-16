input = open('input', 'r')
output = open('output', 'w')

def solve_for_k(max_dim, min_dim, k):
    min_r = float('inf')
    for x in xrange(0, k+3):
        if (x+2) > min_dim:
            break
        if (k+4) % (x+2) == 0:
            n = (k+4)/ (x+2)
            if n <= max_dim:
                r = 2*(n-2+x)
                if r < min_r:
                    min_r = r
    return min_r

def solve(a,b,k):
    min = float('inf')
    for x in xrange(5):
        r = solve_for_k(a,b,k-x)
        if min > r+x:
            min = r+x
    return min

testcases = int(input.readline().strip())
for testcase in xrange(1, testcases+1):
    inputs = input.readline().strip().split(" ")
    n,m,k = (int(x) for x in inputs)
    if n==1 or m ==1:
        if k <= 1:
            output.write("Case #%s: %d\n" % (testcase, k))
            continue
        else:
            output.write("Case #%s: %d\n" % (testcase, 2))
            continue
    if k <=4:
        output.write("Case #%s: %d\n" % (testcase, k))
        continue
    if n > m:
        res = solve(n,m,k)
    else:
        res = solve(m,n,k)
    if res == float('inf'):
        res = k
    output.write("Case #%s: %d\n" % (testcase, res))

input.close()
output.close()
