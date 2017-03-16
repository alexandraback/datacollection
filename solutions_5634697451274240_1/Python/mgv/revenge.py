test_num = int(raw_input())
for test_i in xrange(1, test_num + 1):
    data = raw_input()
    count = 0
    num = len(data)
    if num > 1:
        for i in xrange(0, num-1):
            if data[i] != data[i+1]:
                count += 1
    if data[num-1] == '-':
        count += 1
    print "Case #{}: {}".format(test_i, count)