__author__ = 'siavash'
t = input()
for i in xrange(t):
    k, s = (raw_input()).split(" ")
    prev = 0
    sums = 0
    k = int(k)

    for idx in range(k + 1):
        num = ord(s[idx]) - ord('0')
        if prev < idx and idx != 0 and num != 0:
            sums += idx - prev
            prev += idx - prev
        prev += num
    print "Case #{0}: {1}".format(i + 1, sums)

