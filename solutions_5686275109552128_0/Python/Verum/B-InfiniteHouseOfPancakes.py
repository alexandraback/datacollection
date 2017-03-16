#input_filename = "B-test.txt"
#output_filename = "B-test-out.txt"

input_filename = "B-small-attempt2.in"
output_filename = "B-small-attempt2.out"

#input_filename = "B-large.in"
#output_filename = "B-large.out"

def memoize(f):
    memo = {}

    def helper(x):
        if x not in memo:
            memo[x] = f(x)
        return memo[x]
    return helper

@memoize
def cnt_down(params):
    n, mx = params
    if n <= mx:
        return 0
    else:
        return cnt_down( (n // 2, mx) ) + cnt_down( (n - n // 2, mx) ) + 1


#print(cnt_down( (5,2) ))
#exit(1)

def solve(xs):
    best = max(xs)
    bestmx = None
    for mx in range(1, max(xs)+1):
        b = sum([cnt_down( (x,mx) ) for x in xs]) + mx
        print("Down to %d = %d" % (mx, b))
        if b < best:
            best = b
            bestmx = mx
    print(bestmx)
    return best


with open(input_filename, "r") as ifile:
    with open(output_filename, "w") as ofile:
        T = int(ifile.readline())
        for case in range(1, T+1):
            _ = ifile.readline()
            data = ifile.readline().split()
            data = [int(s) for s in data]

            print("\nCase %d" % case)
            print("Task: %s" % str(data))

            result = solve(data)

            ofile.write("Case #%d: %d\n" % (case, result))
            print("Solve: %d" % result)

            assert result <= max(data)


