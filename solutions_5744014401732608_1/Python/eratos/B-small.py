import fileinput, sys, operator

def construct(o):
    matrix = ""
    b = len(o)

    for i in range(0, b):
        if o[i] == 2 ** (b-i-2):
            format_string = "{0:0%db}" % (b-1)
            matrix += format_string.format(o[i]-1)
            matrix += "1"
        else:
            format_string = "{0:0%db}" % (b-1)
            matrix += format_string.format(o[i])
            matrix += "0"
        if i != b - 1:
            matrix += '\n'
    return matrix

def solve(s):
    b, m = s.rstrip().split()
    b = int(b)
    m = int(m)

    #print("B:%d M:%d" % (b, m))

    outdegrees = {}

    upper_limit = 2 ** (b-2)
    if m > upper_limit:
        output = "IMPOSSIBLE"
    else:
        for i in range(0,b-2):
            lower_limit = 2 ** (b-i-3)
            if m <= lower_limit:
                outdegrees[i] = lower_limit
            else:
                outdegrees[i] = m
                m = lower_limit
        outdegrees[b-2] = 1
        outdegrees[b-1] = 0

        #print(outdegrees)
        output = "POSSIBLE\n"
        output += construct(outdegrees)

    return output

index = 0
for line in fileinput.input():
    index += 1
    if index == 1:
        continue
    print("Case #%d: %s" % ((index - 1), solve(line)))
