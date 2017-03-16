def parse_input(items):
    return items[0]

def run(items):
    S = parse_input(items)
    #print S
    
    result = list()
    for s in S:
        if result:
            if s >= result[0]:
                result.insert(0, s)
            else:
                result.append(s)
        else:
            result.append(s)

    r = ""
    for x in result:
        r += str(x)
    return r


# raw_input() reads a string with a line of input, stripping the '\n' (newline) at the end.
# This is all you need for most Google Code Jam problems.
t = int(raw_input())  # read a line with a single integer
for i in xrange(1, t + 1):
    items = raw_input().split(" ")
    result = run(items)
    print "Case #{}: {}".format(i, result)
    # check out .format's specification for more formatting options
