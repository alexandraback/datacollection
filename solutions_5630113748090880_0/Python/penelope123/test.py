# f = open('input.txt')
f = open('/home/aaronm/Desktop/B-small-attempt0.in')
# f = open('/home/aaronm/Desktop/A-large.in')
t = int(f.readline())

for case in range(t):
    n = int(f.readline())

    tally = {}
    for i in range((2*n) - 1):
        for j in f.readline().split():
            if j not in tally:
                tally[j] = 0
            tally[j] += 1

    nums = []
    for k,v in tally.items():
        if v%2 != 0:
            nums.append(int(k))

    nums.sort()
    string = ""
    for c in nums:
        string += "%s " % c
    print "Case #%s: %s" % (case+1, string)