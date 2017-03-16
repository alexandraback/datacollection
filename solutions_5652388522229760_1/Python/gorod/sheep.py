

def last_number(N):
    if N == 0:
        return "INSOMNIA"
    cnt = 10;
    seen_digits = [0]*10;
    curN = N
    while cnt > 0:
        n = curN
        while n > 0:
            digit = n % 10
            if seen_digits[digit] == 0:
                cnt -= 1
                seen_digits[digit] = 1
            n = n / 10
        curN += N
        
    return curN - N
    
t = int(raw_input())
for i in xrange(1, t + 1):
    N = int(raw_input())
    print "Case #{}: {}".format(i, last_number(N))
