import permutation

T = int(raw_input())
for t in xrange(1, T+1):
    N = int(raw_input())
    topics = []
    for n in xrange(1, N+1):
        topics.append(raw_input().strip())
    min_num_real = 20
    for i in xrange(0, N+1):
        all_combination = permutation.get_combination(i, topics)
        if i > min_num_real:
            break
        for comb in all_combination:
            comb_set = set(comb)
            num_real = len(comb)
            first = set()
            second = set()
            for w in comb:
                ws = w.split()
                first.add(ws[0])
                second.add(ws[1])
            for w in topics:
                if w in comb_set:
                    continue
                ws = w.split()
                if ws[0] in first and ws[1] in second:
                    continue
                num_real += 1
            if num_real < min_num_real:
                min_num_real = num_real
    max_num_fake = N - min_num_real
    print("Case #%d: %d" %(t, max_num_fake))







