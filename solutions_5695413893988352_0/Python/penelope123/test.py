from decimal import Decimal
# f = open('input.txt')
f = open('/home/aaronm/Desktop/B-small-attempt2.in')
# f = open('/home/aaronm/Desktop/A-large (1).in')
t = int(f.readline())

for case in range(t):
    # n = int(f.readline())
    s = f.readline().strip()
    n1, n2 = s.split()
    # print
    # print n1,n2

    nn1, nn2 = '',''

    for i,c1 in enumerate(n1):
        c2 = n2[i]

        # c1
        if c1 != '?':
            nn1 += c1
        else:
            #compare lasts
            try:
                # last1 = nn1[i-1]
                # last2 = nn2[i-1]
                last1 = nn1[:i]
                last2 = nn2[:i]
            except:
                last1 = '0'
                last2 = '0'

            if last1 < last2:
                nn1 += '9'
            elif last1 > last2:
                nn1 += '0'
            else:
                # look next
                # nn1 += '0'
                something1 = n1[i+1:].split('?')[0]
                something2 = n2[i+1:].split('?')[0]
                length = min([len(something1), len(something2)])
                # print length
                # next1 = "0." + n1[i+1:].split('?')[0]
                # next2 = "0." + n2[i+1:].split('?')[0]
                next1 = "0." + something1[:length]
                next2 = "0." + something2[:length]
                diff = Decimal(next2) - Decimal(next1)
                # print "diff is"
                # print diff
                if diff < 0:
                    diff = 0
                if diff == Decimal(".5"):
                    diff = 0
                # print round(diff)
                # print next1, next2
                # print float(next1), float(next2)
                if c2 == "?":
                    nn1 += str(int(round(diff)))
                else:
                    nn1 += str(int(c2) + int(round(diff)))

        # c2
        if c2 != '?':
            nn2 += c2
        else:
            #compare lasts
            try:
                # last1 = nn1[i-1]
                # last2 = nn2[i-1]
                last1 = nn1[:i]
                last2 = nn2[:i]
            except:
                last1 = '0'
                last2 = '0'

            # print "last is ", last1, last2

            if last1 < last2:
                nn2 += '0'
            elif last1 > last2:
                nn2 += '9'
            else:
                # look next
                something1 = n1[i+1:].split('?')[0]
                something2 = n2[i+1:].split('?')[0]
                length = min([len(something1), len(something2)])
                # print length
                # next1 = "0." + n1[i+1:].split('?')[0]
                # next2 = "0." + n2[i+1:].split('?')[0]
                next1 = "0." + something1[:length]
                next2 = "0." + something2[:length]
                diff = Decimal(next1) - Decimal(next2)
                # print "diff is"
                # print diff
                if diff < 0:
                    diff = 0
                if diff == Decimal(".5"):
                    diff = 0
                # print round(diff)
                # print next1, next2
                # print float(next1), float(next2)
                if c1 == "?":
                    nn2 += str(int(round(diff)))
                else:
                    nn2 += str(int(c1) + int(round(diff)))

    # print nn1, nn2
    print "Case #%s: %s %s" % (case+1, nn1, nn2)

    # # print s
    # bits = []
    # for i,l in enumerate(letters):
    #     count = 0
    #     for c in s:
    #         if c == l:
    #             count += 1

    #     # print 'found %s %s' % (count ,l)
    #     for c in digits[i]:
    #         s = s.replace(c,'',count)

    #     for j in range(count):
    #         bits.append(values[i])
    #     # print s
    # # print bits
    # # print sorted(bits)

    # print "Case #%s: %s" % (case+1, "".join(sorted(bits)))    

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
