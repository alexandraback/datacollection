import sys

T = int(sys.stdin.readline())
result = []
for i in range(T):
    input_list = [int(i) for i in sys.stdin.readline().strip().split()]
    N, S, p, total = input_list[0], input_list[1], input_list[2], input_list[3:]
    
    count = 0
    for i in range(N):
        avg = total[i] / 3
        rem = total[i] % 3
        if rem == 1:
            # Irrespective of whether the result is surprising or not,
            # the best score will always be avg+1
            count += ((avg + 1) >= p)
        elif rem == 2:
            if (avg + 1) >= p:
                count += 1
            elif S and ((avg + 2) >= p):
                # Since p is given to be within [0, 10], no need to check 
                # for the higher bound for (avg + 2)
                count += 1
                S -= 1
        else:
            if avg >= p:
                count += 1
            elif S and ((avg + 1) >= p) and ((avg - 1) >= 0):
                # Here we needed to check for the lower bound,
                # so that (avg - 1) stays non negative!
                count += 1
                S -= 1

    result.append(count)

for i, v in enumerate(result):
    print "Case #%d: %d" % (i+1, v)
