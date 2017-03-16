

def compress(line):
    if len(line) == 0:
        return ""

    l = line[0]
    j = 0
    for i in xrange(1, len(line)):
        if line[i] == l[j]:
            continue
        j += 1
        l += line[i]

    if l[-1] == '+':
        return l[:-1]
    return l


def reverse(line):
    #print "reversing " + line
    l = ""
    for i in range(len(line)-1, -1, -1):
        if line[i] == '+':
            l += '-'
        else:
            l += '+'
    return l
        

def calc(line):
    #print "calcing " + line
    if len(line) == 0:
        return 0

    if len(line) == 1:
        return 1

    if line[0] == '+':
        return 1 + calc(compress('-' + line[1:]))

    return 1 + calc(reverse(line)[:-1])
                                   
t = int(raw_input())
for i in xrange(1, t + 1):
    line = raw_input()
    #print line
    print("Case #{}: {}".format(i, calc(compress(line))))
