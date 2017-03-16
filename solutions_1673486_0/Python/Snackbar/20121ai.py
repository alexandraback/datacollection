outfile = "output.txt"

def popinput(input):
    return int(input.readline().split()[0])


def solve(file):
    input = open(file, 'r')
    output = open(outfile, 'w')
    cases = popinput(input)
    for i in range(cases):
        output.write("Case #%(number)d: %(answer)s\n" % {"number":i + 1, "answer":solvecase(input)})

  

def solvecase(input):
    line = input.readline().split()
    a = line[0]
    b = line[1]
    probs = input.readline().split()
    ex = b + 2
    cprobs = {0:probs[0]}
    for i in range(1,a):
        cprobs[i] = cprobs[i-1] * probs[i]
    for i in range(a):
        ex = min(ex, cprobs[a-i] * (b - a + 1) + (1-cprobs[a-i]) * (b * 2 + 2 - a))
    return ex
