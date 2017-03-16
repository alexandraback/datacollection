def allcorrect(rprobs):
    prod = 1.0
    for e in rprobs:
        prod = prod * e
    return prod

def firsterror(rprobs, k):
    """ probability that the first error is the kth letter."""
    prod = 1.0
    for i in range(k-1):
        prod *= rprobs[i]
    return prod*(1-rprobs[k-1])

# read file
f = open("A-large.in", "r")
g = open("A-large.txt", "w")

N = int(f.readline())  # number of cases
k = 0
while k < N:
    temp = f.readline()
    templst = temp.split()
    A, B = templst[0], templst[1]  # A: no typed, B: total length
    A, B = int(A), int(B)
    temp = f.readline()
    rprobs = temp.split()
    if type(rprobs) is not list:
        rprobs = [rprobs]
    rprobs = [float(e) for e in rprobs]

    # if press enter
    press_enter = 1 + B + 1  # no of strokes needed for enter

    # if keep typing
    allc = allcorrect(rprobs)
    keep_t = (B-A+1)*allc + (B-A+1+B+1)*(1-allc)

    d = {} # d[i]: first error occurs among first d[i] terms
    d[1] = 1-rprobs[0]
    for i in range(2,A+1):
        if 1-rprobs[i-2] == 0:
            d[i] = d[i-1] + d[i-1]*rprobs[i-2]*(1-rprobs[i-1])
        else:
            d[i] = d[i-1] + d[i-1]/(1-rprobs[i-2])*rprobs[i-2]*(1-rprobs[i-1])

    # backspaces
    costs = {}
    for i in range(1,A):  # backspace i times
        cost_backspace = 2*i+B-A+1
        costs[i] = d[A-i]*(cost_backspace+B+1) + (1-d[A-i])*cost_backspace
    costs[A] = A+B+1

    mincosts = min(costs.values())
    lowest = min(press_enter, keep_t, mincosts)
    print lowest
    
    g.write("Case #" + str(k+1) + ": " + str(lowest) + "\n")
    k += 1
