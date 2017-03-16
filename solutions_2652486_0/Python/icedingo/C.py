import itertools

raw_input()
R, N, M, K = map(int, raw_input().split())

numbers = range(2, M+1)
products = {}
for i in xrange(N):
    i += 1
    for comb in itertools.combinations_with_replacement(numbers, i):
        prod = reduce(lambda x,y : x*y, comb)
        if prod not in products:
            products[prod] = []
        products[prod].append(''.join(map(str, comb)))

print 'Case #1:'
for r in xrange(R):
    numset = map(int, raw_input().split())
    possible = []
    must = []
    for num in numset:
        if num in products:
            blah = products[num]
            if len(blah) == 1:
                must += blah
            else:
                possible += blah
    must.sort(key=lambda x:-len(x))
    possible.sort(key=len)

    result = None

    for maybe in must:
        if len(maybe) == N:
            result = maybe
            break
        done = len(maybe)
        for rest in must:
            if len(rest) == N - done:
                result = maybe + rest
                break
        for rest in possible:
            if len(rest) == N - done:
                result = maybe + rest
                break
    else:
        counts = {}
        for rest in possible:
            if rest not in counts:
                counts[rest] = 0
            counts[rest] += 1
        count_list = sorted(counts.items(), key=lambda x:x[1])
        if count_list:
            result = count_list[0][0]
        else:
            result = '222'
        done = False
        if len(result) == N:
            done = True
        if not done:
            for thing in count_list:
                if len(result) + len(thing[0]) == N:
                    result = result + thing[0]
                    done = True
                    break
            else:
                result = '222'
    if result is None:
        result = '222'


    print result
