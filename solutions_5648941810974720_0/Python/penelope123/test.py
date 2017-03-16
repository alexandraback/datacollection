# f = open('input.txt')
f = open('/home/aaronm/Desktop/A-small-attempt0 (1).in')
# f = open('/home/aaronm/Desktop/B-large.in')
t = int(f.readline())

# digits = ["ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"]
digits = ["ZERO", "EIGHT", "SIX", "FOUR", "FIVE", "SEVEN", "TWO", "THREE", "ONE", "NINE"]
letters = ['Z','G','X','U','F','S','W','R','O','I']
values = ['0','8','6','4','5','7','2','3','1','9']

for case in range(t):
    # n = int(f.readline())
    s = f.readline().strip()
    # print s
    bits = []
    for i,l in enumerate(letters):
        count = 0
        for c in s:
            if c == l:
                count += 1

        # print 'found %s %s' % (count ,l)
        for c in digits[i]:
            s = s.replace(c,'',count)

        for j in range(count):
            bits.append(values[i])
        # print s
    # print bits
    # print sorted(bits)

    print "Case #%s: %s" % (case+1, "".join(sorted(bits)))    

    # tally = {}
    # for i in range((2*n) - 1):
    #     for j in f.readline().split():
    #         if j not in tally:
    #             tally[j] = 0
    #         tally[j] += 1

    # nums = []
    # for k,v in tally.items():
    #     if v%2 != 0:
    #         nums.append(int(k))

    # nums.sort()
    # string = ""
    # for c in nums:
    #     string += "%s " % c
