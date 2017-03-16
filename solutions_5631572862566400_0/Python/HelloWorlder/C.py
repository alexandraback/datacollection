def run(N, BFF_map):
    final_steps_map = [1 for i in range(N)]
    #print BFF_map

    for n in range(N):
        if final_steps_map[n] > 1:
            continue
        
        find_a_path = False
        cur_path = list()
        steps_map = [1 for i in range(N)]
        while True:
            cur_path.append(n)
            BFF = BFF_map[n]
            #print "n=%s" % (n)
            if BFF in cur_path:
                find_a_path = True
                num_in_loop = cur_path.index(n) - cur_path.index(BFF) + 1
                #print "TEST n=%s num_in_loop=%s steps_map=%s" % (n, num_in_loop, steps_map)
                if num_in_loop == 2:
                    break
                node = BFF
                steps_map = [1 for i in range(N)]
                for i in range(num_in_loop):
                    #if num_in_loop > steps_map[node]:
                    steps_map[node] = num_in_loop
                    node = BFF_map[node]
                #print "TEST num_in_loop=%s steps_map=%s" % (num_in_loop, steps_map)
                # handle loop
                break
            elif steps_map[n] + 1 > steps_map[BFF]:
                steps_map[BFF] = steps_map[n] + 1
                #print "TEST cur_path: %s" % cur_path
                #print "TEST steps_map: %s" % steps_map
            else:
                break
            n = BFF
        if find_a_path:
            for x in range(N):
                if steps_map[x] > final_steps_map[x]:
                    final_steps_map[x] = steps_map[x]

    #print "final_steps_map: %s" % final_steps_map
    result = 0
    for n in range(N):
        BFF = BFF_map[n]
        #print n, BFF, BFF_map[BFF]
        if n == BFF_map[BFF]:
            for other_n in range(n):
                if other_n != n and other_n != BFF and BFF_map[other_n] == n:
                    if final_steps_map[n] + final_steps_map[other_n] > result:
                        result = final_steps_map[n] + final_steps_map[other_n]
        elif final_steps_map[n] > result:
            result = final_steps_map[n]
    return result


# raw_input() reads a string with a line of input, stripping the '\n' (newline) at the end.
# This is all you need for most Google Code Jam problems.
t = int(raw_input())  # read a line with a single integer
for i in xrange(1, t + 1):
    N = int(raw_input())
    BFF_map = [int(x) - 1 for x in raw_input().split(' ')]
    #if i != 4:
    #    continue
    result = run(N, BFF_map)
    print "Case #{}: {}".format(i, result)
    #break
    # check out .format's specification for more formatting options
