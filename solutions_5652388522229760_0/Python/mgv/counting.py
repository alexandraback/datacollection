test_num = int(raw_input())
for test_i in xrange(1, test_num + 1):
    num = int(raw_input())
    if num == 0:
        print "Case #{}: INSOMNIA".format(test_i)
        continue
    digits = [0]*10;
    
    current = num
    while True:
        tmp = str(current)
        for c in tmp:
            digits[int(c)] = 1
        finished = sum(digits) == 10
        if finished:
            break
        current += num            
    print "Case #{}: {}".format(test_i, current)