for case in range(input()):
    print "Case #"+str(case+1)+":",
    s_max, S=raw_input().split()
    S = map(int, list(S))
    part_sum = 0
    friends = 0
    for i, s in enumerate(S):
        if part_sum < i:
            friends += (i - part_sum)
            part_sum += (i - part_sum)
        part_sum += s
    print friends
